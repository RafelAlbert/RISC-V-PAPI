/*
 * Copyright (c) 2023 INESC-ID, Instituto Superior Técnico, Universidade de Lisboa
 * Created by Tiago Rocha <tiagolopesrocha@tecnico.ulisboa.pt>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Copyright (c) 2026 BSC
 * Contributed by Rafel Albert Bros Esqueu <rafel.brosesqueu@bsc.es>
*/

/* private headers */
#include "pfmlib_priv.h" /* library private */
#include "pfmlib_riscv_priv.h"
#include "pfmlib_perf_event_priv.h"

#include <limits.h>
#include <stdio.h>

static int find_pmu_type_by_name(const char *name)
{
    char filename[PATH_MAX];
    FILE *fp;
    int ret, type;

    if (!name) return PFM_ERR_NOTSUPP;

    sprintf(filename, "/sys/bus/event_source/devices/%s/type", name);

    fp = fopen(filename, "r");
    if (!fp) return PFM_ERR_NOTSUPP;

    ret = fscanf(fp, "%d", &type);
    fclose(fp);

    if (ret != 1) return PFM_ERR_NOTSUPP;

    return type;
}

int pfm_riscv_get_perf_encoding(void *this, pfmlib_event_desc_t *e)
{
    pfmlib_pmu_t *pmu = this;
    pfm_riscv_reg_t reg;
    struct perf_event_attr *attr = e->os_data;
    int ret;

    if (!pmu->get_event_encoding[PFM_OS_NONE])
        return PFM_ERR_NOTSUPP;

    ret = pmu->get_event_encoding[PFM_OS_NONE](this, e);
    if (ret != PFM_SUCCESS)
        return ret;

    if (e->count > 1)
    {
        DPRINT("%s: unsupported count=%d\n", e->count);
        return PFM_ERR_NOTSUPP;
    }

    if (pmu->perf_name) 
    {
        ret = find_pmu_type_by_name(pmu->perf_name);
        if (ret < 0)
            return ret;
        attr->type = ret;
    } 
    else 
        attr->type = PERF_TYPE_RAW;

    reg.val = e->codes[0];
    attr->config = reg.val;

    attr->exclude_hv = 0;
    attr->exclude_kernel = 0;
    attr->exclude_user = 0;

    return PFM_SUCCESS;
}
