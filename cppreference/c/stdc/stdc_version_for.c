#include <stdio.h>

int main(void)
{
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
    // C99 以及以后版本支持的代码
    for (int i = 0; i < 5; i++)
    {
        printf("%d", i);
    }
#else
    // C89 / C90 兼容的代码
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d", i);
    }

#endif

    return 0;
}
