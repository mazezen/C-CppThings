/*
 * @Author: mazezen
 * @Date: 2026-05-19
 * @LastEditors: mazezen
 * @LastEditTime: 2026-05-19
 * @FilePath: /practice-c-cpp/cppreference/c/stdlib/realloc.c
 * @Description: realloc 重新分配给定的内存区域
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void print_storage_info(const int *next, const int *prev, int ints)
{
    if (next)
        printf("%s location: %p. Size: %d ints (%ld bytes). \n",
               (next != prev ? "New" : "Old"), (void *)next, ints, ints * sizeof(int));
    else
        printf("Allocation failed.\n");
}

int main(void)
{
    const int pattern[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int pattern_size = sizeof pattern / sizeof(int);
    int *next = NULL, *prev = NULL;
    if ((next = (int *)malloc(pattern_size * sizeof *next))) // 分配数组
    {
        memcpy(next, pattern, sizeof pattern); // 填充数组
        print_storage_info(next, prev, pattern_size);
    }
    else
    {
        return EXIT_FAILURE;
    }

    // 以如下各值作为新的存储大小, 在循环中重新分配
    const int realloc_size[] = {10, 12, 512, 32768, 65536, 32768};
    for (int i = 0; i != sizeof realloc_size / sizeof(int); ++i)
        if ((next = (int *)realloc(prev = next, realloc_size[i] * sizeof(int))))
        {
            print_storage_info(next, prev, realloc_size[i]);
            assert(!memcmp(next, pattern, sizeof pattern)); // 持有模式内容
        }
        else // 若realloc 失败, 则需要释放原指正
        {
            free(prev);
            return EXIT_FAILURE;
        }

    free(next); // 最终释放
    return EXIT_SUCCESS;
}
