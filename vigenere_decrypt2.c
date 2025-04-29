#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt2(char* cipher, char* key)
{
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);

    char* plaintext = (char*) malloc(sizeof(char) * (cipher_length + 1));
    memset(plaintext, '\0', sizeof(char) * (cipher_length + 1));
    for(int i = 0; i < cipher_length; i++)
    {
        if(isalpha(cipher[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if(islower(cipher[i]))
            {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            }
            else
            {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }
    plaintext[cipher_length] = '\0';
    return plaintext;
}

int main()
{
    FILE *fileptr=fopen("vinegere.txt","r");
    char text[MAXN];
    fgets(text,sizeof(text), fileptr);
    printf("Encrypted: %s", text);
    int key;
    scanf("%d", &key);
    char* cipher = vigenere_decrypt2(text,key);
    printf("Decrypted: %s",cipher);
    fclose(fileptr);
    free(cipher);
    return EXIT_SUCCESS;
}