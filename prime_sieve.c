#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sieve_of_eratosthenes(int max_num, int *is_prime)
{
    memset(is_prime, 1, (max_num + 1) * sizeof(int));

        is_prime[0] = is_prime[1] = 0;

        for (int p = 2; p * p <= max_num; p ++)
            {
                if (is_prime[p]){

                    for (int i = p * p ; i <= max_num; i += p){

                        is_prime[i] = 0;

                    }
                }
            }
        }

        int main() {

            FILE *file;
            int num, max_num = 0;
            int numbers[100];
            int count = 0;
            
            file = fopen("number.txt", "r");
            if (file == NULL) {

                printf("Error opening file.\n");

                    return 1;

            }

            while (fscanf(file, "%d", &num) !=EOF)
            {
                numbers[count++] = num;
                if (num > max_num) {
                    max_num= num;
                }

                while (fgetc(file) == ','){


                }

            }

            int *is_prime = (int *) malloc((max_num + 1) * sizeof(int));
            sieve_of_eratosthenes(max_num, is_prime);

            printf("Prime numbers found in the file:\n");

            for (int i = 0; i < count; i++) {
                if (numbers[i] <= max_num && is_prime[numbers[i]]) {
                    printf("%d ", numbers[i]);
                }
            }

            printf("\n");

            free(is_prime);
            fclose(file);
            return 0;
            

        }