#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    setlocale(LC_COLLATE, "cs_CZ.utf8");

    const char *s1 = "hrnec";
    const char *s2 = "chrt";
    if (strcoll(s1, s2) < 0)
        printf("s1:[%s] before s2:[%s]\n", s1, s2);

    else if (strcoll(s1, s2) > 0)
        printf("s1:[%s] after s2:[%s]\n", s1, s2);

    else
        printf("s1:[%s] after s2:[%s]\n", s1, s2);

    return 0;
}