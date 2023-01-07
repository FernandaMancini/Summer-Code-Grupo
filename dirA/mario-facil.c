#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height, row, j, space;
    do
    {
        height = get_int ("Altura: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++)
    {
        for (space = 0; space < space - height - row-1; space ++)
        {
            printf (" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}