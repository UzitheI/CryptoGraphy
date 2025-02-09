#include <stdio.h>
#include <ctype.h>

void caesar_cipher_encrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base + (shift % 26) + 26) % 26 + base;
        }
    }
}

void caesar_cipher_decrypt(char text[], int shift) {
    caesar_cipher_encrypt(text, -shift);
}

int main() {
    char text[100];
    int shift;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    caesar_cipher_encrypt(text, shift);
    printf("Encrypted text: %s\n", text);


    caesar_cipher_decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    return 0;
}
