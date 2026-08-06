/*
 * =============================================================================
 *
 *                   Copyright (c) 2026 BSC
 *                             All rights reserved
 *
 * This file contains BSC proprietary and confidential information and has
 * been developed by BSC within the EPI-SGA1 Project (GA 826647).
 * The permission rights for this file are governed by the EPI Grant Agreement
 * and the EPI Consortium Agreement.
 *
 * ===============================[ INFORMATION ]===============================
 *
 * Author(s)  : Rafel Albert Bros Esqueu
 * Contact(s) : rafel.brosesqueu@bsc.es
 * File: src/libpfm4/lib/pfmlib_riscv_eupilot_l2hn.c
 * Description: Registers four distinct PMUs, one per each L2 cache 
 * monitor instance, using the DEFINE_L2HN(n) macro.
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* private headers */
#include "pfmlib_priv.h"
#include "pfmlib_riscv_priv.h"
#include "events/riscv_eupilot_l2hn_events.h"

/*
 * Detect if a specific l2_cache_monitor PMU instance exists by
 * checking for its sysfs type file.
 */
static int pfm_riscv_detect_l2hn(void *this)
{
	pfmlib_pmu_t *pmu = this;
	char filename[PATH_MAX];
	FILE *fp;

	if (!pmu->perf_name) return PFM_ERR_NOTSUPP;

	sprintf(filename, "/sys/bus/event_source/devices/%s/type",
		pmu->perf_name);

	fp = fopen(filename, "r");
	if (!fp) return PFM_ERR_NOTSUPP;
	fclose(fp);

	return PFM_SUCCESS;
}

#define DEFINE_L2HN(n)                                        \
pfmlib_pmu_t riscv_eupilot_l2hn##n##_support = {              \
	.desc	= "EUPILOT L2 Cache Monitor "#n,                      \
	.name	= "l2_cache_monitor"#n,                               \
	.perf_name = "l2_cache_monitor"#n,                          \
	.pmu = PFM_PMU_RISCV_EUPILOT_L2HN##n,                       \
	.pme_count = LIBPFM_ARRAY_SIZE(riscv_eupilot_l2hn_pe),      \
	.type	= PFM_PMU_TYPE_UNCORE,                                \
	.supported_plm = 0,                                         \
	.pe	= riscv_eupilot_l2hn_pe,                                \
	.pmu_detect	= pfm_riscv_detect_l2hn,                        \
	.num_cntrs = 1,                                             \
	.num_fixed_cntrs	= 0,                                      \
	.max_encoding	= 1,                                          \
	.get_event_encoding[PFM_OS_NONE] = pfm_riscv_get_encoding,  \
	PFMLIB_ENCODE_PERF(pfm_riscv_get_perf_encoding),                       \
	.get_event_first = pfm_riscv_get_event_first,               \
	.get_event_next	 = pfm_riscv_get_event_next,                \
	.event_is_valid	 = pfm_riscv_event_is_valid,                \
	.validate_table	 = pfm_riscv_validate_table,                \
	.get_event_info	 = pfm_riscv_get_event_info,                \
}

DEFINE_L2HN(0);
DEFINE_L2HN(1);
DEFINE_L2HN(2);
DEFINE_L2HN(3);
