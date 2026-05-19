#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    char src[] = "hi";
    char dest[7] = "abcdef";
    printf("length of dest: %ld\n", strlen(dest));
    strncpy(dest, src, 5);
    printf("strncpy(dest, stc, 5) to a 6-byte dest gives: \n");
    printf("size of dest : %ld\n", sizeof dest);

    for (size_t n = 0; n < sizeof dest; ++n)
    {
        char c = dest[n];
        c ? printf("'%c'", c) : printf("'\\0'");
    }
    printf("\n");

    return 0;
}