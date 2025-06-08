#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int areRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (areRelativelyPrime(num1, num2)) {
        printf("%d and %d are relatively prime.\n", num1, num2);
    } else {
        printf("%d and %d are not relatively prime.\n", num1, num2);
    }

    return 0;
}