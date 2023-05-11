#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_key(int length, unsigned char *key) {

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
}

void xor_bytes(unsigned char *a, unsigned char *b, int length, unsigned char *result) {

    for (int i = 0; i < length; i++) {
        result[i] = a[i] ^ b[i];
    }
}

void encrypt(unsigned char *plaintext, int length, unsigned char *key, unsigned char *ciphertext) {

    xor_bytes(plaintext, key, length, ciphertext);
}

void decrypt(unsigned char *ciphertext, int length, unsigned char *key, unsigned char *plaintext) {

    xor_bytes(ciphertext, key, length, plaintext);
}

int main() {
    unsigned char plaintext[100] = "Hello, World!";
    unsigned char key[100];
    unsigned char ciphertext[100];
    unsigned char decrypted_plaintext[100];

    int plaintext_length = strlen((char *)plaintext);

    generate_key(plaintext_length, key);

    encrypt(plaintext, plaintext_length, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, plaintext_length, key, decrypted_plaintext);
    printf("Decrypted message: %s\n", decrypted_plaintext);

    return 0;
}
