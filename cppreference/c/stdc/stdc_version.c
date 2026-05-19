#include <stdio.h>

int main(void)
{
#if defined(__STDC_VERSION__)
    printf("C standard version: %ld\n", __STDC_VERSION__);

#if (__STDC_VERSION__ >= 202311L)
    printf("C23 or later\n");
#elif (__STDC_VERSION__ >= 202000L)
    printf("C20 or later");
#elif (__STDC_VERSION__ >= 201710L)
    printf("C17 or later\n");
#elif (__STDC_VERSION__ >= 201112L)
    printf("C11\n");
#elif (__STDC_VERSION__ >= 199901L)
    printf("C99\n");
#else
    printf("C94 or C95\n");
#endif
#else
    printf("C89/C90 or earlier\n");
#endif

    return 0;
}