#include <stdio.h>

int additive_inverse(int num) {
    int inverse = (-num) % 26;
    if (inverse < 0) {
        inverse += 26;
    }
    return inverse;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int inverse = additive_inverse(num);
    printf("The additive inverse of %d in Z26 is: %d\n", num, inverse);

    return 0;
}