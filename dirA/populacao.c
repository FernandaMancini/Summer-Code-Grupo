# include <stdio.h>
# include <cs50.h>

int main (void)
{
    int inicio, fim, i;
    inicio = 0;
    do
    {
        inicio = get_int ("Inicio: ");
    }
    while (inicio < 9);
    do
    {
        fim = get_int ("Fim: ");
    }
    while (fim < inicio);
    while (inicio < fim){
        inicio = inicio + (inicio/3) - (inicio/4);
        i ++;
    }
    printf (tot)

}