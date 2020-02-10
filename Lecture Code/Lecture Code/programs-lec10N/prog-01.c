//
// prog-01.c
//

#include <stdio.h>

int main(void) {

    double cleo = 1.0;
    double patrick = 0.0;
    int i;

    for (i=1; i<4; i++) {
        double q = cleo * i;
        patrick += q;
    }

    printf("partick=%.2f\n", patrick);
    return 0;
}