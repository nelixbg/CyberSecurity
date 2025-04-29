#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_LETTER 10

char* cezar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = (cipher[i] - '0' - key + 10) % 10 + '0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }
    plaintext[length] = '\0';
    return plaintext;
}
int* count_frequencies (char* cipher)
{
    int length = strlen(cipher);
    int* counts = (int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(counts, 0, sizeof(int)*ALPHA_LENGTH);
    for(int i = 0; i < length; i++)
    {
        char symbol = tolower(cipher[i]);
        if(symbol >= 'a' && symbol <= 'z')
        {
            int position = symbol - 'a';
            counts[position]++;
        }
    }
    return counts;

}


int read_cipher(char* filename, char* cipher)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

int get_max_index(int* frequencies)
{
    int max_index = 0;
    for(int i = 0; i < ALPHA_LENGTH; i++)
    {
        if(frequencies[i] > frequencies[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

int main()
{
    char cipher[MAXN];
    read_cipher("cezar.txt", cipher);
    char common_letters[COMMON_LETTER] =
        {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'l'};

        int* frequencies = count_frequencies(cipher);
        char most_common_letter = get_max_index(frequencies) + 'a';
        for(int i = 0; i < COMMON_LETTER; i++)
        {
            int key = abs(most_common_letter - common_letters[i]);
            char* plaintext = cezar_decipher(cipher, key);
            printf("Key = %d -> %s\n", key, plaintext);
            free (plaintext);
        }
        return EXIT_SUCCESS;
}