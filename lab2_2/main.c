#include <stdio.h>
#include <math.h>
#include "get_double.h"

int calc(double x, double eps) {
    double sinx = sin(x);
    double current = 0, fact = 1;
    int i = 0;
    while (fabs(sinx - current) > eps) {
        current += (i % 2 == 0 ? 1 : -1) * pow(x, (double)2 * (i + 1) - 1) / fact; 
        i++;
        fact *= (double)i * 2;
        fact *= (double)i * 2 + 1;
    }
    return i;
}

int main() {
    
    double left, right, step, i, eps;
    while (1) {
        puts("Enter left border");
        left = get_double();
        puts("Enter right border");
        right = get_double();
        if (right < left) {
            puts("right border should be bigger than the left border! Try again\n");
            continue;
        }
        break;
    }
    puts("Eneter the step");
    while (1) {
        step = get_udouble();
        if (step == 0) {
            puts("Number of steps shouldn't be equal to 0");
            continue;
        }
        break;
    }

    puts("");
    printf("eps =             ");
    int kol = 1;
    for (eps = 0.1; eps > 1e-10; eps/= 10)
        printf("%3d%s%d", 1, "e-", kol++);
    for (; eps > 1e-15; eps /= 10)
        printf("%2d%s%d", 1, "e-", kol++);
    puts("");

    for (i = left; i <= right; i += step) {
        printf("x = %10lf : ", i);
        for (eps = 0.1; eps > 1e-15; eps /= 10) {
            printf("%6ld", calc(i, eps));
        }
        puts("");
    }
    return 0;
}