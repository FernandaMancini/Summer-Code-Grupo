#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[]){
    if (argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];

    for (int i = 0; i <strlen(argv[1]); i++){
        if (!isdigit(argv[1][i])){
            printf("Usage: .caesar key\n");
            return 1;
        }
    }

    string texto = get_string("Texto: ");
    int k = atoi(key);
    printf("Criptrografado: ");

    for (int i = 0; i <strlen(texto); i++){
        if (isupper(texto[i])){
            printf("%c", (((texto[i] - 65) + k) %26) + 65);
        }
        else if (islower(texto[i])){
            printf("%c", (((texto[i] - 97) + k) %26) + 97);
        }
        else{
            printf("%c", texto[i]);
        }
    } printf("\n");
}
