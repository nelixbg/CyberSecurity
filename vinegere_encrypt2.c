#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt2(char* plaintext, char* key)
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
    FILE *fileptr=fopen("","r");
    char text[MAXN];
    fgets(text,sizeof(text), fileptr);
    printf("Encrypted: %s", text);
    int key;
    scanf("%d", &key);
    char* cipher = vigenere_encrypt2(text,key);
    printf("Decrypted: %s",cipher);
    fclose(fileptr);
    free(cipher);
    return EXIT_SUCCESS;
}