#include <stdio.h>
#include <limits.h>

#ifndef BOOL_MAX
#define BOOL_MAX 1
#endif

int main(void)
{
    printf("BOOL_WIDTH = %d\n", BOOL_WIDTH);
    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);
    printf("CHAR_WIDTH  = %d\n", CHAR_WIDTH);
    printf("CHAR_MIN  = %d\n", CHAR_MIN);
    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("SCHAR_WIDTH = %d\n", SCHAR_WIDTH);
    printf("SHRT_WIDTH = %d\n", SHRT_WIDTH);
    printf("INT_WIDTH = %d\n", INT_WIDTH);
    printf("LONG_WIDTH = %d\n", LONG_WIDTH);
    printf("LLONG_WIDTH = %d\n", LLONG_WIDTH);

    printf("SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("SHRT_MIN = %d\n", SHRT_MIN);
    printf("SHRT_MAX = %d\n", SCHAR_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MIN = %d\n", INT_MAX);
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MIN = %lld\n", LLONG_MIN);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    printf("UCHAR_WIDTH = %d\n", UCHAR_WIDTH);
    printf("USHRT_WIDTH = %d\n", USHRT_WIDTH);
    printf("UINT_WIDTH = %d\n", UINT_WIDTH);
    printf("ULONG_WIDTH = %d\n", ULONG_WIDTH);
    printf("ULLONG_WIDTH = %d\n", ULLONG_WIDTH);

    printf("UCHAR_MAX = %d\n", UCHAR_MAX);
    printf("USHRT_MAX = %d\n", UCHAR_MAX);
    printf("UINT_MAX = %d\n", UINT_MAX);
    printf("ULONG_MAX = %ld\n", ULONG_MAX);
    printf("ULLONG_MAX = %lld\n", ULLONG_MAX);

    printf("BOOL_MAX = %d\n", BOOL_MAX);

    return 0;
}