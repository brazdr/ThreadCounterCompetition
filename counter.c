#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "counter.h"

static int max_count;
static HANDLE* threads;
static int num_threads;
static int winner_thread = -1;
static CRITICAL_SECTION mutex;
static LARGE_INTEGER start_time, end_time, frequency;

DWORD WINAPI count_up(LPVOID arg) {
    long thread_id = (long)arg;
    int local_count = 0;

    while (local_count < max_count) {
        local_count++;  // Incrementa a contagem local da thread
        printf("Thread %ld: Contagem %d\n", thread_id, local_count);

        // Verifica se esta thread foi a primeira a atingir o max_count
        if (local_count == max_count) {
            EnterCriticalSection(&mutex);
            if (winner_thread == -1) {  // Apenas a primeira thread a chegar em 100 será registrada como vencedora
                winner_thread = thread_id;
                QueryPerformanceCounter(&end_time); // Marca o tempo quando a primeira thread atinge max_count
                printf("Thread %ld foi a primeira a atingir %d!\n", thread_id, max_count);
            }
            LeaveCriticalSection(&mutex);
        }

        // Pequeno atraso para simular um tempo de execução e tornar a competição mais visível
        Sleep(rand() % 10);  
    }
    return 0;
}

void initialize_counter(int max_count_value, int num_threads_value) {
    max_count = max_count_value;
    num_threads = num_threads_value;
    threads = malloc(sizeof(HANDLE) * num_threads);
    InitializeCriticalSection(&mutex);
    QueryPerformanceFrequency(&frequency);     // Obtém a frequência do contador
    QueryPerformanceCounter(&start_time);      // Marca o tempo inicial
}

void start_counting() {
    for (long i = 0; i < num_threads; i++) {
        threads[i] = CreateThread(NULL, 0, count_up, (LPVOID)i, 0, NULL);
    }

    WaitForMultipleObjects(num_threads, threads, TRUE, INFINITE);
}

void destroy_counter() {
    for (int i = 0; i < num_threads; i++) {
        CloseHandle(threads[i]);
    }
    DeleteCriticalSection(&mutex);
    free(threads);

    if (winner_thread != -1) {
        double elapsed_time = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
        printf("\nA thread vencedora foi: %d\n", winner_thread);
        printf("Tempo gasto pela thread vencedora para atingir %d: %.6f segundos\n", max_count, elapsed_time);
    } else {
        printf("\nNenhuma thread completou a contagem.\n");
    }
}
