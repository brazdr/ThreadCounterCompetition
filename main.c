#include "counter.h"

#define MAX_COUNT 100
#define NUM_THREADS 10

int main() {
    initialize_counter(MAX_COUNT, NUM_THREADS);
    start_counting();
    destroy_counter();

    return 0;
}
