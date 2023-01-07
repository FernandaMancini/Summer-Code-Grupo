#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int altura, fileira, coluna, espaco;
    do
    {
        altura = get_int ("Altura: ");
    }
    while (altura < 1 || altura > 8);

    for (fileira = 0; fileira < altura; fileira++)
    {
        for (espaco = 0; espaco < altura - fileira - 1; espaco ++)
        {
            printf (" ");
        }
        for (coluna = 0; coluna <= fileira; coluna++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}