#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******** Config the program ********/
#define SORT_ARRAY
#define ARRAY_SZIE (32 * 1024)
/***********************************/

#ifdef SORT_ARRAY
static int cmpfunc (const void * a, const void * b)
{
   return (*(int *)a - *(int *)b);
}
#endif

static double time_diff_ms(struct timespec start, struct timespec end)
{
    struct timespec ret;

    if (start.tv_nsec > end.tv_nsec) {
        ret.tv_sec = end.tv_sec - start.tv_sec - 1;
        ret.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        ret.tv_sec = end.tv_sec - start.tv_sec;
        ret.tv_nsec = end.tv_nsec - start.tv_nsec;
    }

    return ((ret.tv_sec * 1000.0) + (ret.tv_nsec / 1000000.0));
}

int main(void)
{
    int array[ARRAY_SZIE];
    struct timespec start_time, end_time;
    long long sum = 0;

    for (int i = 0; i < ARRAY_SZIE; i++) {
        array[i] = rand() % 256;
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);
#ifdef SORT_ARRAY
    qsort(array, ARRAY_SZIE, sizeof(int), cmpfunc);
#endif

    for (int i = 0; i < 30000; i++)
    {
        for (int j = 0; j < ARRAY_SZIE; j++) {
            if (array[j] >= 128)
                sum += array[j];
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    printf("Execution time: %f ms\n", time_diff_ms(start_time, end_time));

    return 0;
}
