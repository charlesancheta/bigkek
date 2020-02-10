/*
 ============================================================================
 Name        : lecture-02.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <complex.h>

int main(void) {

	double complex z1 = 1.0 + 3.0*I;
	double complex z2 = 1.0 - 4.0*I;
	double complex zz;

	zz = z1 + z2;

	printf("z1 = %.2f + %.2fi\nz2 = %.2f + %.2fi\n",
			creal(z1), cimag(z1), creal(z2), cimag(z2));
	printf("z1+z2 = %.2f + %.2fi\n ", creal(zz), cimag(zz));

	return 0;
}
