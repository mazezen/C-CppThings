#include <stdio.h>
#include <string.h>

int main()
{

    char szSomeFileName[] = "foo/bar/foobar.txt";
    char *pLastSlash = strrchr(szSomeFileName, '/');
    char *pszBaseName = pLastSlash ? pLastSlash + 1 : szSomeFileName;
    printf("Base Name: %s", pszBaseName);
    return 0;
}