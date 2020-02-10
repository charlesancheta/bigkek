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
#include <stdlib.h>
#include <string.h>

int main(void) {

    float f_value = 0.001;
    double d_value = 0.001;
    double difference;

    f_value = f_value * 1000000000.0f;
    d_value = d_value * 1000000000.0f;
    difference = f_value - d_value;

    printf("first: %f\n", f_value);
    printf("second: %f\n", d_value);
	printf("%f\n", difference);

	return 0;

}
