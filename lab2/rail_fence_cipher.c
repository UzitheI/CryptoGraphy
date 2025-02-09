#include <stdio.h>
#include <string.h>

void encryptRailFence(char *message, int key) {
    int len = strlen(message);
    char rail[key][len];
    memset(rail, '\n', sizeof(rail));
    
    int row = 0, dir_down = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key - 1) 
            dir_down = !dir_down;
        rail[row][i] = message[i];
        row += dir_down ? 1 : -1;
    }
    
    printf("Encrypted Message: ");
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
}

void decryptRailFence(char *cipher, int key) {
    int len = strlen(cipher);
    char rail[key][len];
    memset(rail, '\n', sizeof(rail));
    
    int row = 0, dir_down = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key - 1) 
            dir_down = !dir_down;
        rail[row][i] = '*';
        row += dir_down ? 1 : -1;
    }
    
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];
    
    printf("Decrypted Message: ");
    row = 0, dir_down = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key - 1) 
            dir_down = !dir_down;
        printf("%c", rail[row][i]);
        row += dir_down ? 1 : -1;
    }
    printf("\n");
}

int main() {
    char message[100];
    int key;
    
    printf("Enter message: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    
    encryptRailFence(message, key);
    decryptRailFence(message, key);
    
    return 0;
}