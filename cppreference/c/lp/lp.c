#include <stdio.h>
#include <stdint.h>

int main(void)
{

#ifdef __LP64__
    printf("%d\n", __LP64__);
    printf("__WORDSIZE = %d\n", __WORDSIZE);
#else
    printf("%d\n", __LP64__);
    printf("__WORDSIZE = %d\n", __WORDSIZE);
#endif

    return 0;
}