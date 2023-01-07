#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height, row, colum, space;
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
        for (colum = 0; colum <= row; colum++)
        {
            printf ("#");
        }
        printf ("\n");
    }
}