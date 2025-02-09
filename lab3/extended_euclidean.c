#include <stdio.h>

// Function to implement the Extended Euclidean Algorithm
int extended_euclidean(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_euclidean(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, b, x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extended_euclidean(a, b, &x, &y);

    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients x and y are %d and %d respectively\n", x, y);

    return 0;
}