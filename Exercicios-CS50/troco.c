#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float troco;
    do{
        troco = get_float ("Valor do troco: ");
    } while (troco <= 0);
    int cent = round(troco*100);
    int moedas = 0;
    while(cent >= 25)
    {
        cent = cent - 25;
        moedas ++;
    }
     while(cent >= 10)
    {
        cent = cent - 10;
        moedas ++;
    }
     while(cent >= 5)
    {
        cent = cent - 5;
        moedas ++;
    }
     while(cent >= 1)
    {
        cent = cent - 1;
        moedas ++;
    }
    printf ("Total de moedas: %i", moedas);
}
