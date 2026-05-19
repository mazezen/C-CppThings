#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s1[20] = "Hello, ";
    char s2[20] = "World!";
    strcat(s1, s2);
    puts(s1);
    puts(s2);

    return 0;
}
