#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height, i, j;
    do
    {
        height = get_int ("Altura: ");
    }
    while (height < 1 || height > 8);
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height; j++)
        {
            printf ("#");
        }

        printf ("\n");
    }
}