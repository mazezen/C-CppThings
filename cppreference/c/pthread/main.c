#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 线程执行的函数
void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;
    printf("你好, 我是子线程 %d. \n", thread_id);
    pthread_exit(NULL); // 线程退出
}

// clang main.c -o main.out -lpthread
int main(void)
{
    // 线程标识符
    pthread_t thread_id;
    int arg = 1;

    // 1. 创建线程
    int result = pthread_create(&thread_id, NULL, thread_function, (void *)&arg);
    if (result != 0)
    {
        perror("线程创建失败");
        exit(1);
    }

    // 2. 主线程等待子线程执行完毕
    pthread_join(thread_id, NULL);

    printf("主线程结束。\n");
    return 0;
}
