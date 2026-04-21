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
 */

/*
 * L2HN counters
 *
 * These are uncore counters exposed by the l2hn_counters kernel driver
 * as perf PMU events in the path "/sys/devices/l2_cache_monitor<N>/".
 *
 * Event codes match the kernel driver config values found in
 * /sys/devices/l2_cache_monitor0/events/<EVENT_NAME>.
 */

static const riscv_entry_t riscv_eupilot_l2hn_pe[] = {
  /* Basic cache counters */
  {.name = "CACHE_NUM_HIT",
   .code = 0x1E,
   .desc = "L2 cache number of hits"},
  {.name = "CACHE_NUM_MISS",
   .code = 0x1F,
   .desc = "L2 cache number of misses"},
  {.name = "CACHE_NUM_PENDTRANS",
   .code = 0x1A,
   .desc = "L2 cache number of pending transactions"},

  /* CHI credits */
  {.name = "CHI_CREDITS",
   .code = 0x17,
   .desc = "CHI credits"},

  /* CHI RXDAT (received data) */
  {.name = "CHI_NUM_RXDAT",
   .code = 0x02,
   .desc = "CHI number of received data messages"},
  {.name = "CHI_NUM_RXDAT_CORE_SNPS",
   .code = 0x0F,
   .desc = "CHI number of received data messages from core snoops"},
  {.name = "CHI_NUM_RXDAT_CORE_WRITES",
   .code = 0x0E,
   .desc = "CHI number of received data messages from core writes"},
  {.name = "CHI_NUM_RXDAT_MEM",
   .code = 0x10,
   .desc = "CHI number of received data messages from memory"},

  /* CHI RXREQ (received requests) */
  {.name = "CHI_NUM_RXREQ",
   .code = 0x00,
   .desc = "CHI number of received requests"},
  {.name = "CHI_NUM_RXREQ_ATOMICS",
   .code = 0x09,
   .desc = "CHI number of received atomic requests"},
  {.name = "CHI_NUM_RXREQ_CMOS",
   .code = 0x0A,
   .desc = "CHI number of received cache maintenance operation requests"},
  {.name = "CHI_NUM_RXREQ_DATALESS_NON_CMO",
   .code = 0x08,
   .desc = "CHI number of received dataless non-CMO requests"},
  {.name = "CHI_NUM_RXREQ_READS",
   .code = 0x06,
   .desc = "CHI number of received read requests"},
  {.name = "CHI_NUM_RXREQ_WRITES",
   .code = 0x07,
   .desc = "CHI number of received write requests"},

  /* CHI RXRSP (received responses) */
  {.name = "CHI_NUM_RXRSP",
   .code = 0x01,
   .desc = "CHI number of received responses"},
  {.name = "CHI_NUM_RXRSP_CORE",
   .code = 0x0B,
   .desc = "CHI number of received responses from core"},
  {.name = "CHI_NUM_RXRSP_CORE_SNPS",
   .code = 0x0C,
   .desc = "CHI number of received snoop responses from core"},
  {.name = "CHI_NUM_RXRSP_MEM",
   .code = 0x0D,
   .desc = "CHI number of received responses from memory"},

  /* CHI TXDAT (transmitted data) */
  {.name = "CHI_NUM_TXDAT",
   .code = 0x05,
   .desc = "CHI number of transmitted data messages"},
  {.name = "CHI_NUM_TXDAT_CORE",
   .code = 0x13,
   .desc = "CHI number of transmitted data messages to core"},
  {.name = "CHI_NUM_TXDAT_MEM",
   .code = 0x14,
   .desc = "CHI number of transmitted data messages to memory"},

  /* CHI TXREQ (transmitted requests) */
  {.name = "CHI_NUM_TXREQ",
   .code = 0x03,
   .desc = "CHI number of transmitted requests"},
  {.name = "CHI_NUM_TXREQ_READS",
   .code = 0x11,
   .desc = "CHI number of transmitted read requests"},
  {.name = "CHI_NUM_TXREQ_WRITES",
   .code = 0x12,
   .desc = "CHI number of transmitted write requests"},

  /* CHI TXRSP (transmitted responses) */
  {.name = "CHI_NUM_TXRSP",
   .code = 0x04,
   .desc = "CHI number of transmitted responses"},

  /* CHI TXSNP (transmitted snoops) */
  {.name = "CHI_NUM_TXSNP_NOT_VALID",
   .code = 0x16,
   .desc = "CHI number of transmitted invalid snoops"},
  {.name = "CHI_NUM_TXSNP_VALID",
   .code = 0x15,
   .desc = "CHI number of transmitted valid snoops"},

  /* Internal signals */
  {.name = "INTERNAL0",
   .code = 0x18,
   .desc = "Internal signal 0"},
  {.name = "INTERNAL1",
   .code = 0x19,
   .desc = "Internal signal 1"},
  {.name = "INTERNAL2",
   .code = 0x1B,
   .desc = "Internal signal 2"},
  {.name = "INTERNAL3",
   .code = 0x1C,
   .desc = "Internal signal 3"},
  {.name = "INTERNAL4",
   .code = 0x1D,
   .desc = "Internal signal 4"},
  {.name = "INTERNAL5",
   .code = 0x20,
   .desc = "Internal signal 5"},
  {.name = "INTERNAL6",
   .code = 0x21,
   .desc = "Internal signal 6"},
  {.name = "INTERNAL7",
   .code = 0x22,
   .desc = "Internal signal 7"},
  {.name = "INTERNAL8",
   .code = 0x23,
   .desc = "Internal signal 8"},
  {.name = "INTERNAL9",
   .code = 0x24,
   .desc = "Internal signal 9"},
  {.name = "INTERNAL10",
   .code = 0x25,
   .desc = "Internal signal 10"},
  {.name = "INTERNAL11",
   .code = 0x26,
   .desc = "Internal signal 11"},
};
