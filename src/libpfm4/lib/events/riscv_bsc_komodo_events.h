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
 * Author(s)  : Rafel Bros Esqueu
 * Contact(s) : rafel.brosesqueu@bsc.es
 */

/*
 * BSC Komodo (Lagarto Ox + VPU) RISC-V Core
 */

static const riscv_entry_t riscv_bsc_komodo_pe[] = {
  /* Branch predictor events */
  {
  	.name = "recoveryB",
  	.code = 0x0033,
  	.desc = "Recoveries"
  },
  {
  	.name = "cond_br_recovery",
  	.code = 0x0043,
  	.desc = "Recoveries produced by branches, conditionalbranch misprediction"
  },
  {
  	.name = "uncond_br_recovery",
  	.code = 0x0053,
  	.desc = "Unconditional branch misprediction"
  },
  {
  	.name = "cond_br_executed_0",
  	.code = 0x0063,
  	.desc = "Conditional branches executed but not necessarily commited in BRU0"
  },
  {
  	.name = "uncond_br_executed_0",
  	.code = 0x0073,
  	.desc = "Unconditional branches executed but not necessarily commited in BRU0"
  },
  {
  	.name = "cond_br_taken_0",
  	.code = 0x0083,
  	.desc = "Taken branches executed but not necessarily commited in BRU0"
  },
  {
  	.name = "cond_br_executed_1",
  	.code = 0x0093,
  	.desc = "Conditional branches executed but not necessarily commited in BRU1"
  },
  {
  	.name = "uncond_br_executed_1",
  	.code = 0x00a3,
  	.desc = "Unconditional branches executed but not necessarily commited in BRU1"
  },
  {
  	.name = "cond_br_taken_1",
  	.code = 0x00b3,
  	.desc = "Taken branches executed but not necessarily commited in BRU1"
  },
  {
  	.name = "cond_br_executed_2",
  	.code = 0x00c3,
  	.desc = "Conditional branches executed but not necessarily commited in BRU2 (not used)"
  },
  {
  	.name = "uncond_br_executed_2",
  	.code = 0x00d3,
  	.desc = "Unconditional branches executed but not necessarily commited in BRU2 (not used)"
  },
  {
  	.name = "cond_br_taken_2",
  	.code = 0x00e3,
  	.desc = "Taken branches executed but not necessarily commited in BRU2 (not used)"
  },
  {
  	.name = "ras_buff_stall",
  	.code = 0x00f3,
  	.desc = "Cycles stalled by RAS"
  },
  {
  	.name = "ghr_buff_stall",
  	.code = 0x0103,
  	.desc = "Cycles stalled by GHR"
  },
  /* Cache events */
  {
  	.name = "icache_req",
  	.code = 0x0032,
  	.desc = "Instruction cache requests"
  },
  {
  	.name = "icache_kill",
  	.code = 0x0042,
  	.desc = "Instruction cache kills"
  },
  {
  	.name = "icache_misses",
  	.code = 0x0052,
  	.desc = "Instruction cache misses"
  },
  {
  	.name = "icache_imiss_kill",
  	.code = 0x0062,
  	.desc = "Instruction cache miss kills"
  },
  {
  	.name = "icache_busy",
  	.code = 0x0072,
  	.desc = "Instruction cache misses"
  },
  {
  	.name = "icache_miss_l2_hit",
  	.code = 0x0082,
  	.desc = "L1 Instruction cache miss and L2 hit"
  },
  {
  	.name = "dcache_stall",
  	.code = 0x0092,
  	.desc = "Data cache stalls"
  },
  {
  	.name = "dcache_stall_refill",
  	.code = 0x00a2,
  	.desc = "Data cache stalls refill"
  },
  {
  	.name = "dcache_rtab_rollback",
  	.code = 0x00b2,
  	.desc = "Data cache rollbacks"
  },
  {
  	.name = "dcache_req_onhold",
  	.code = 0x00c2,
  	.desc = "Data cache request onhold"
  },
  {
  	.name = "dcache_prefetch_req",
  	.code = 0x00d2,
  	.desc = "Data cache prefetch requests"
  },
  {
  	.name = "dcache_read_req",
  	.code = 0x00e2,
  	.desc = "Data cache read requests"
  },
  {
  	.name = "dcache_write_req",
  	.code = 0x00f2,
  	.desc = "Data cache write requests"
  },
  {
  	.name = "dcache_cmo_req",
  	.code = 0x0102,
  	.desc = "Data cache cmo requests"
  },
  {
  	.name = "dcache_uncached_req",
  	.code = 0x0112,
  	.desc = "Data cache uncached requests"
  },
  {
  	.name = "dcache_miss_read_req",
  	.code = 0x0122,
  	.desc = "Data cache read misses"
  },
  {
  	.name = "dcache_miss_write_req",
  	.code = 0x0132,
  	.desc = "Data cache write misses"
  },
  {
  	.name = "l2_accesses",
  	.code = 0x0142,
  	.desc = "Accesses to L2 cache"
  },
  {
  	.name = "l2_misses",
  	.code = 0x0152,
  	.desc = "L2 misses"
  },
  /* Datapath events */
  {
  	.name = "late_page_recovery",
  	.code = 0x0034,
  	.desc = "Recoveries to late page"
  },
  {
  	.name = "fetch_deco_full",
  	.code = 0x0044,
  	.desc = "Cycles with Fetch-Deco Inter-stage full"
  },
  {
  	.name = "fetch_deco_empty",
  	.code = 0x0054,
  	.desc = "Cycles with Fetch-Deco Inter-stage empty"
  },
  {
  	.name = "deco_rnm_full",
  	.code = 0x0064,
  	.desc = "Cycles with Deco-Rename Inter-stage full"
  },
  {
  	.name = "deco_rnm_empty",
  	.code = 0x0074,
  	.desc = "Cycles with Deco-Rename Inter-stage empty"
  },
  {
  	.name = "store_buffer_full",
  	.code = 0x0084,
  	.desc = "Cycles with store buffer full"
  },
  {
  	.name = "rnm_disp_full_0",
  	.code = 0x0094,
  	.desc = "Cycles with queue 0 of dispatch full"
  },
  {
  	.name = "rnm_disp_empty_0",
  	.code = 0x00a4,
  	.desc = "Cycles with queue 0 of dispatch empty"
  },
  {
  	.name = "backend_full_0",
  	.code = 0x00b4,
  	.desc = "Cycles with backend queue full 0"
  },
  {
  	.name = "rnm_disp_full_1",
  	.code = 0x00c4,
  	.desc = "Cycles with queue 1 of dispatch full"
  },
  {
  	.name = "rnm_disp_empty_1",
  	.code = 0x00d4,
  	.desc = "Cycles with queue 1 of dispatch empty"
  },
  {
  	.name = "backend_full_1",
  	.code = 0x00e4,
  	.desc = "Cycles with backend queue full 1"
  },
  {
  	.name = "rnm_disp_full_2",
  	.code = 0x00f4,
  	.desc = "Cycles with queue 2 of dispatch full"
  },
  {
  	.name = "rnm_disp_empty_2",
  	.code = 0x0104,
  	.desc = "Cycles with queue 2 of dispatch empty"
  },
  {
  	.name = "backend_full_2",
  	.code = 0x0114,
  	.desc = "Cycles with backend queue full 2"
  },
  {
  	.name = "rnm_disp_full_3",
  	.code = 0x0124,
  	.desc = "Cycles with queue 3 of dispatch full"
  },
  {
  	.name = "rnm_disp_empty_3",
  	.code = 0x0134,
  	.desc = "Cycles with queue 3 of dispatch empty"
  },
  {
  	.name = "backend_full_3",
  	.code = 0x0144,
  	.desc = "Cycles with backend queue full 3"
  },
  /* Memory events */
  {
  	.name = "recoveryA",
  	.code = 0x0031,
  	.desc = "Recoveries"
  },
  {
  	.name = "mem_recovery",
  	.code = 0x0041,
  	.desc = "Recoveries produced by memory path, memory order violations"
  },
  {
  	.name = "icache_miss",
  	.code = 0x0051,
  	.desc = "L1 Instruction instruction cache misses"
  },
  {
  	.name = "dcache_miss",
  	.code = 0x0061,
  	.desc = "L1 Data cache misses"
  },
  {
  	.name = "itlb_access",
  	.code = 0x0071,
  	.desc = "Instruction TLB accesses"
  },
  {
  	.name = "dtlb_access",
  	.code = 0x0081,
  	.desc = "Data TLB accesses"
  },
  {
  	.name = "itlb_miss",
  	.code = 0x0091,
  	.desc = "Instruction TLB misses"
  },
  {
  	.name = "dtlb_miss",
  	.code = 0x00a1,
  	.desc = "Data TLB misses"
  },
  {
  	.name = "page_fault",
  	.code = 0x00b1,
  	.desc = "Page fault exceptions"
  },
  {
  	.name = "stb_full",
  	.code = 0x00c1,
  	.desc = "Cycles with store buffer full"
  },
  {
  	.name = "l15_access",
  	.code = 0x00d1,
  	.desc = "Accesses to L1.5 cache"
  },
  {
  	.name = "l15_miss",
  	.code = 0x00e1,
  	.desc = "L1.5 misses"
  },
  {
  	.name = "l2_access",
  	.code = 0x00f1,
  	.desc = "Accesses to L2 cache"
  },
  {
  	.name = "l2_miss",
  	.code = 0x0101,
  	.desc = "L2 misses"
  },
  {
  	.name = "ptw_cache_hit",
  	.code = 0x0111,
  	.desc = "PTW cache hits"
  },
  {
  	.name = "ptw_cache_miss",
  	.code = 0x0121,
  	.desc = "PTW cache misses"
  },
  {
  	.name = "ld_dcache_req_without_ready",
  	.code = 0x0131,
  	.desc = "Cycles where there is a STORE request to L1 data cache without ready"
  },
  {
  	.name = "st_dcache_req_without_ready",
  	.code = 0x0141,
  	.desc = "Cycles where there is a LOAD request to L1 data cache without ready"
  },
  {
  	.name = "dreq_rdy_1c",
  	.code = 0x0151,
  	.desc = "Request to L1 data cache with 1 cycle response"
  },
  {
  	.name = "dreq_load",
  	.code = 0x0161,
  	.desc = "LOAD request to L1 dcache"
  },
  {
  	.name = "dreq_store",
  	.code = 0x0171,
  	.desc = "STORE request to L1 dcache"
  },
  {
  	.name = "ld_bypass",
  	.code = 0x0181,
  	.desc = "LOAD bypasses"
  },
  {
  	.name = "ld_fwrd",
  	.code = 0x0191,
  	.desc = "LOAD forwards"
  },
  {
  	.name = "spec_lsdu_alloc_fail",
  	.code = 0x01a1,
  	.desc = "Speculative allocation failures in LSU, bank full"
  },
  {
  	.name = "spec_agu_fail",
  	.code = 0x01b1,
  	.desc = "Speculative failures in AGU"
  },
  /* Miscellaneous events */
  {
  	.code = 0x0035,
  	.name = "noc1_packet",
  	.desc = "Packets in NOC1"
  },
  {
  	.code = 0x0045,
  	.name = "noc2_packet",
  	.desc = "Packets in NOC2"
  },
  {
  	.code = 0x0055,
  	.name = "noc3_packet",
  	.desc = "Packets in NOC3"
  },
  {
  	.code = 0x0065,
  	.name = "noc1_stall",
  	.desc = "Stalls of NOC1"
  },
  {
  	.code = 0x0075,
  	.name = "noc2_stall",
  	.desc = "Stalls of NOC2"
  },
  {
  	.code = 0x0085,
  	.name = "noc3_stall",
  	.desc = "Stalls of NOC3"
  },
  /* VPU events */
  {
  	.name = "issue_valid",
  	.code = 0x0036,
  	.desc = "Valid instruction issued to the VPU on the BVI"
  },
  {
  	.name = "completed_valid",
  	.code = 0x0046,
  	.desc = "Valid instruction completed by the VPU on the BVI"
  },
  {
  	.name = "commit_valid",
  	.code = 0x0056,
  	.desc = "Valid instruction commit flagged to the VPU on the BVI"
  },
  {
  	.name = "vpu_active",
  	.code = 0x0066,
  	.desc = "The VPU is executing some instruction across all lanes/all functional units"
  },
  {
  	.name = "kill",
  	.code = 0x0076,
  	.desc = "Kill flagged through BVI, processed by the VPU"
  },
  {
  	.name = "arith_instr",
  	.code = 0x0086,
  	.desc = "An arithmetic instruction is issued to the lanes"
  },
  {
  	.name = "mem_instr",
  	.code = 0x0096,
  	.desc = "A memory instruction is issued to the lanes"
  },
  {
  	.name = "load_instr",
  	.code = 0x00a6,
  	.desc = "A vector load starts execution"
  },
  {
  	.name = "store_instr",
  	.code = 0x00b6,
  	.desc = "A vector store starts execution"
  },
  {
  	.name = "indexed_instr",
  	.code = 0x00c6,
  	.desc = "An indexed vector memory instruction starts execution"
  },
  {
  	.name = "fp_instr",
  	.code = 0x00d6,
  	.desc = "A floating-point arithmetic instruction starts execution"
  },
  {
  	.name = "narrowing_instr",
  	.code = 0x00e6,
  	.desc = "A narrowing instruction starts"
  },
  {
  	.name = "widening_instr",
  	.code = 0x00f6,
  	.desc = "A widening instruction starts"
  },
  {
  	.name = "fu_0_active",
  	.code = 0x0106,
  	.desc = "Functional unit 0 (FPU 0) across all the lanes is executing"
  },
  {
  	.name = "fu_1_active",
  	.code = 0x0116,
  	.desc = "Functional unit 1 (FPU 1) across all the lanes is executing"
  },
  {
  	.name = "fu_2_active",
  	.code = 0x0126,
  	.desc = "Functional unit 2 (FPU 2) across all the lanes is executing"
  },
  {
  	.name = "fu_3_active",
  	.code = 0x0136,
  	.desc = "Functional unit 3 (FPU 3) across all the lanes is executing"
  },
  {
  	.name = "fu_4_active",
  	.code = 0x0146,
  	.desc = "Functional unit 4 (ALU) across all the lanes is executing"
  },
  {
  	.name = "fu_5_active",
  	.code = 0x0156,
  	.desc = "Functional unit 5 (MERGER) across all the lanes is executing"
  },
  {
  	.name = "fu_6_active",
  	.code = 0x0166,
  	.desc = "Functional unit 6 (PERM) across all the lanes is executing"
  },
  {
  	.name = "load_tx",
  	.code = 0x0176,
  	.desc = "The VPU is transmitting data on the BVI.LOAD"
  },
  {
  	.name = "store_tx",
  	.code = 0x0186,
  	.desc = "The VPU is receiving data on the BVI.STORE"
  },
  {
  	.name = "index_tx",
  	.code = 0x0196,
  	.desc = "The VPU is transmitting data on the BVI.INDEX"
  },
  {
  	.name = "mask_tx",
  	.code = 0x01a6,
  	.desc = "The VPU is transmitting data on the BVI.MASK"
  },
  {
  	.name = "frl_empty",
  	.code = 0x01b6,
  	.desc = "The FRL in the VPU is empty"
  },
  {
  	.name = "fml_empty",
  	.code = 0x01c6,
  	.desc = "The FML in the VPU is empty"
  }
};
