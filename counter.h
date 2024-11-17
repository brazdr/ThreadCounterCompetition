#ifndef COUNTER_H
#define COUNTER_H

#include <windows.h>

void initialize_counter(int max_count, int num_threads);
void destroy_counter();
void start_counting();

#endif
