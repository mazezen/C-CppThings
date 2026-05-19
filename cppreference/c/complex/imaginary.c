#include <stdio.h>
#include <complex.h>

int main(void)
{
    double complex z = 1.0 - 2.0 * I; // pure real + pure imaginary
    printf("z = %.1f%+.1fi\n", creal(z), cimag(z));
}