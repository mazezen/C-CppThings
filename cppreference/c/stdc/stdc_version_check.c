#include <stdio.h>

void check_c_standard()
{
#if defined(__STDC_VERSION__)
    switch (__STDC_VERSION__)
    {
    case 202311L:
        printf("Compiler C23...");
        break;
    case 202000L:
        printf("Compiler C20...");
        break;
    case 201710L:
        printf("Compiler C17...");
        break;
    case 201112L:
        printf("Compiler C11...");
        break;
    case 199901L:
        printf("Compiler C99...");
        break;
    default:
        printf("Compiled with an unknown C standard version: %ld\n", __STDC_VERSION__);
        break;
    }
#else
    printf("Compiled with C89/C90 or earlier standard\n");
#endif
}

int main(void)
{

    check_c_standard();

    return 0;
}