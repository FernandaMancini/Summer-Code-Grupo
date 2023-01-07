#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int altura;
    do{
        altura = get_int("Altura: ");
    } while (altura < 1 || altura > 8);


}