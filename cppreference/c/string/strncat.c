#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    strncat(str, "Goodbye World!", 3);
    strncat(str, " ", 1);
    strncat(str, str2, -1);
    puts(str);

    return 0;
}