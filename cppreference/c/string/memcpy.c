/*
 * @Author: mazezen
 * @Date: 2026-05-19
 * @LastEditors: mazezen
 * @LastEditTime: 2026-05-19
 * @FilePath: /practice-c-cpp/cppreference/c/string/memcpy.c
 * @Description: memcpy 从 src 所指向的对象复制 count 个字符到 dest 所指向的对象
 */

#define __STDC_WANT_LTB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // 简单用法
    char source[] = "once upon a midnight dreary...", dest[4];
    memcpy(dest, source, sizeof dest);
    for (size_t n = 0; n < sizeof dest; n++)
        putchar(dest[n]);

    // 设置分配的内存的有效类型为 int
    int *p = malloc(3 * sizeof(int)); // 分配的内存无有类型
    int arr[3] = {1, 2, 3};
    memcpy(p, arr, 3 * sizeof(int)); // 分配的内存现在拥有有效类型

    // reinterpreting data
    double d = 0.1;
    int64_t n;
    memcpy(&n, &d, sizeof d); // ok
    printf("\n%a is %" PRIx64 "as an int64_t\n", d, n);

#ifdef __STDC_LIB_EXT1__
    set_constraint_handler_s(ignore_handler_s);
    char src[] = "aaaaaaaaaa";
    char dst[] = "xyxyxyxyxy";
    int r = memcpy_s(dst, sizeof dst, src, 5);
    printf("dst = \"%s\", r =  %d\n", dst, r);
    r = memcpy_s(dst, 5, src, 10); // coutn 大于 destsz
    print("dst = \"");
    for (size_t ndx = 0; ndx < sizeof dst; ++ndx)
    {
        char c = dst[ndx];
        c ? printf("%c", c) : printf("\\0");
    }
    printf("\", r = %d\n", r);
#endif

    return 0;
}
