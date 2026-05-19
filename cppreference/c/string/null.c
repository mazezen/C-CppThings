#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *p = NULL;
    printf("p ptr = %p\n", (void *)p);

    struct S *s = NULL;
    printf("s ptr = %p\n", s);

    void (*f)(int, double) = NULL;
    printf("%p %p %p\n", (void *)p, (void *)p, (void *)(long)f);

    char *ptr = malloc(0xFULL);
    printf("size of ptr = %ld\n", sizeof(ptr));
    if (ptr == NULL)
    {
        printf("out of memory");
    }
    else
    {
        printf("ptr = %#" PRIxPTR "\n", (uintptr_t)ptr);
    }
    free(ptr);
    ptr = NULL;

    return 0;
}