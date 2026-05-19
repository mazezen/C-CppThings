#include <signal.h>
#include <stdio.h>

void signal_handler(int signal)
{
    printf("Received signal %d\n", signal);
}

int main(void)
{
    signal(SIGTERM, signal_handler);

    printf("Sending signal %d\n", SIGTERM);
    raise(SIGTERM);
    printf("Exit main()\n");
}
