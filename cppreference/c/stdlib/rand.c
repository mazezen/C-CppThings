/*
 * @Author: mazezen
 * @Date: 2026-05-19
 * @LastEditors: mazezen
 * @LastEditTime: 2026-05-19
 * @FilePath: /practice-c-cpp/cppreference/c/stdlib/rand.c
 * @Description: 返回 0 与 RAND_MAX 间的随机整数值（包含 0 与 RAND_MAX）
 * RAND_MAX:  2147483647  HEX: 0x7fffffff
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    printf("%d\n", RAND_MAX);
    printf("%d\n", 0x7fffffff);

    int randInt = rand();
    printf("rand int: %d\n", randInt);

    srand(time(NULL)); // 以当前时间为随机生成器的种子
    int random_variable = rand();
    printf("Random value on [0 %d]: %d\n", RAND_MAX, random_variable);

    // 扔 6 面色子 20 次
    for (int n = 0; n != 20; n++)
    {
        int x = 7;
        while (x > 6)
            x = 1 + rand() / ((RAND_MAX + 1u)); // 注意: 1 +rand() % 6 有偏差
        printf("%d ", x);
    }
    printf("\n");

    printf("rand int: %d\n", arc4random_uniform(10));

    return 0;
}
