# include <stdio.h>
# include <cs50.h>

int main (void)
{
    int inicio, fim, tot, i;
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
    while (tot < fim){
        tot = (inicio + (inicio/3) - (inicio/4));
        i ++;
    }
    printf (tot)

}