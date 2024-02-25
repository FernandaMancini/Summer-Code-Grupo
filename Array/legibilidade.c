#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main (void){
    string texto = get_string("Texto: ");

    int letras = 0;
    for (int i = 0; i < strlen(texto); i++){
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z' )){
            letras++;
        }
    }

    int palavras = 1;
     for (int i = 0; i < strlen(texto); i++){
        if (texto[i] == ' ')
            palavras++;
        }

    int frases = 0;
    for (int i = 0; i < strlen(texto); i++){
        if (texto[i] == '.' || texto[i] == '?' || texto[i] == '!')
            frases ++;
    }

    float calculo = ((0.0588 * letras/palavras * 100) - (0.296 * frases/palavras * 100)) - 15.8;
    int index = round(calculo);

    if (index < 1){
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16){
        printf("Grade 16+\n");
        return 0;
    }else{
        printf("Grade %i\n", index);
    }

}