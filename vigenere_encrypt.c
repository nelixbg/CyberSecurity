#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc (sizeof(char)*(text_length + 1));
    memset(cipher,'\0', sizeof(char)* (text_length + 1));

    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length])- 'a';
            if(islower(plaintext[i]))
            {
                cipher[i] = (plaintext[i] + shift - 'a') %26 + 'a';
            }
            else
            {
                cipher[i] = (plaintext[i] + shift - 'A') %26 + 'A';
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher [text_length] = '\0';
    return cipher;
}

int main()
{
    char plaintext [MAXN];
    scanf("%s", plaintext);
    char key[MAXN];
    scanf("%s",key);
    char* cipher = vigenere_encrypt (plaintext, key);
    printf("%s", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}