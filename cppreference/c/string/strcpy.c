#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *src = "Take the test.";
    char dst[strlen(src) + 1];
    strcpy(dst, src);
    dst[0] = 'M';

    printf("src = %s\ndst = %s", src, dst);

    return 0;
}