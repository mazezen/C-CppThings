#include <stdio.h>
#include <assert.h>
#include <math.h>

#define TEST(...) __VA_ARGS__

int main(void)
{
    // assert(2 + 2 == 5);

    double x = -1.0;
    // assert(x >= 0.0);
    printf("sqrt(x) = %f\n", sqrt(x));
    printf("sqrt(x) = %f\n", sqrt(x));

    assert(TEST(x >= 0.0));

    return 0;
}
