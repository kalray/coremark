#ifndef K1C_CYCLES_H__
#define K1C_CYCLES_H__

#include <hal/cos_diagnostic.h>

// __cos_get_frequency() should be used to get the frequency but it is not ready
// yet. In the meantime, we use a default frequency of 1 GHz.
#define K1C_BOARD_FREQUENCY 1000000000
#define K1C_NSECS_PER_SEC K1C_BOARD_FREQUENCY

typedef unsigned long cycle_t;

static inline void cycle_count_config(void) {
  __cos_counter_reset_all();
  __cos_counter_start(0, _COS_PM_PCC);
}

static inline cycle_t get_cycle(void) {
  return __cos_counter_num(0);
}

#endif
