#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cipher(int index, int rows);
void makeArray(int col, int rows);
int findMin();

char arr[22][22], darr[22][22], emessage[111], retmessage[111], key[55];
char temp[55], temp2[55];
int k = 0;

int main() {
    char message[111];
    int i, j, klen, emlen, r, c, index, rows;
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    
    printf("Enter message to be ciphered: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    
    strcpy(temp, key);
    klen = strlen(key);
    
    k = 0;
    for (i = 0;; i++) {
        for (j = 0; j < klen; j++) {
            if (message[k] == '\0') {
                arr[i][j] = 'X';
            } else {
                arr[i][j] = message[k++];
            }
        }
        if (message[k] == '\0') break;
    }
    
    r = i + 1;
    c = klen;
    
    k = 0;
    for (i = 0; i < klen; i++) {
        index = findMin();
        cipher(index, r);
    }
    
    emessage[k] = '\0';
    printf("\nEncrypted message: %s\n", emessage);
    
    emlen = strlen(emessage);
    rows = emlen / klen;
    
    strcpy(temp, key);
    j = 0;
    for (i = 0, k = 1; emessage[i] != '\0'; i++, k++) {
        temp2[j++] = emessage[i];
        if ((k % rows) == 0) {
            temp2[j] = '\0';
            index = findMin();
            makeArray(index, rows);
            j = 0;
        }
    }
    
    k = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            retmessage[k++] = darr[i][j];
        }
    }
    retmessage[k] = '\0';
    
    printf("\nDecrypted message: %s\n", retmessage);
    return 0;
}

void cipher(int i, int r) {
    for (int j = 0; j < r; j++) {
        emessage[k++] = arr[j][i];
    }
}

void makeArray(int col, int row) {
    for (int i = 0; i < row; i++) {
        darr[i][col] = temp2[i];
    }
}

int findMin() {
    int min = temp[0], index = 0;
    for (int j = 1; temp[j] != '\0'; j++) {
        if (temp[j] < min) {
            min = temp[j];
            index = j;
        }
    }
    temp[index] = 127;
    return index;
}
