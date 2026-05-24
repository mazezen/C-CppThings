#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *fname = "unique_name.txt";
    int is_ok = EXIT_FAILURE;

    FILE *fp = fopen(fname, "w+");
    if (!fp)
    {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!\n", fp);
    rewind(fp);

    int c; // 处理 EOF 需要int 非 char
    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    if (ferror(fp))
        puts("读取时发生 I/O 错误");
    else if (feof(fp))
    {
        puts("成功抵达文件末尾");
        is_ok = EXIT_SUCCESS;
    }
    fclose(fp);
    remove(fname);

    return is_ok;
}
