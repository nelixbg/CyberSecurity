#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char* plaintext, char* key, char* ciphertext){
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int keyIndex = 0;
    
    for (int i=0; i < textLen; i++){
        char c = plaintext[i];
        if (isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            char keyChar = toupper (key[keyIndex % keyLen]) - 'A';
            ciphertext[i] = ((c - base + keyChar) % 26) + base;
            keyIndex++;
            } else {
                ciphertext[i] = c;
            }
        }
    ciphertext[textLen] = '\0';
}

char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file){
        printf("Neuspeshno otvarqne na faila: %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] ='\0';

    fclose(file);
    return buffer;
}
void writeFile(const char* filename, const char* text){
    FILE* file = fopen(filename, "w");
    if (!file){
        printf("Neuspeshno zapisvane vuv faila: %s\n", filename);
        exit(1);
    }
    fputs(text, file);
    fclose(file);
}

int main() {
    char* plaintext = readFile("plain.txt");
    char* key = readFile("key.txt");

    char* ciphertext = (char*)malloc(strlen(plaintext) + 1);
    vigenereEncrypt(plaintext, key, ciphertext);

    writeFile("cipher.txt", ciphertext);

    printf("Shifriraneto e uspeshno! Vij 'cipher.txt'\n");

    free(plaintext);
    free(key);
    free(ciphertext);

    return 0;
} 