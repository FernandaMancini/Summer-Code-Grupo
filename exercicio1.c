#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height;
    do
    {
        height = get_int ("Altura: ");
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf ("#");
        }

        printf ("\n");
    }
}