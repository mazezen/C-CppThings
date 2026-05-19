#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    const size_t N = 101;
    int numbers[N];
    size_t sum = 0;
    for (size_t ndx = 0; ndx < N; ++ndx)
    {
        sum += numbers[ndx] = ndx;
    }
    size_t size = sizeof numbers;
    printf("sum = %zu\n", sum);
    printf("size = %zu\n", size);
    printf("SIZE_MAX = %zu\n", SIZE_MAX);
    // printf("int max = %u\n", __INT_MAX__);

    return 0;
}