#include <stdio.h>

int main(void)
{

// #ifdef __STDC
#if defined __STDC__
    printf("This compiler supports ANSI C.\n");
    printf("__STDC__ is defined as : %d\n", __STDC__);

#else
    printf("This compiler may not fully support ANSI C.\n");

#endif

    return 0;
}