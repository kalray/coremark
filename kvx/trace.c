#include <stdio.h>
#include "cycles.h"

void __cyg_profile_func_enter(void *func, void *callsite) {
  fprintf(stderr, "> %p %p %lu\n", callsite, func, get_cycle());
}

void __cyg_profile_func_exit(void *func, void *callsite) {
  fprintf(stderr, "< %p %p %lu\n", func, callsite, get_cycle());
}
