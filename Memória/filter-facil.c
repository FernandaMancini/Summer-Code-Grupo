#include "helpers.h"
#include <math.h>

// Converte imagem para escala de cinza
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
         {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
          {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Aplica um efeito de desfoque na imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

                   
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += temp[ni][nj].rgbtRed;
                        greenSum += temp[ni][nj].rgbtGreen;
                        blueSum += temp[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
          
            image[i][j].rgbtRed = round(redSum / (float)count);
            image[i][j].rgbtGreen = round(greenSum / (float)count);
            image[i][j].rgbtBlue = round(blueSum / (float)count);
        }
    }
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Filtros de Sobel
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redGx = 0, greenGx = 0, blueGx = 0;
            int redGy = 0, greenGy = 0, blueGy = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redGx += temp[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        greenGx += temp[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        blueGx += temp[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];

                        redGy += temp[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                        greenGy += temp[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        blueGy += temp[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            int red = round(sqrt(redGx * redGx + redGy * redGy));
            int green = round(sqrt(greenGx * greenGx + greenGy * greenGy));
            int blue = round(sqrt(blueGx * blueGx + blueGy * blueGy));
          
            image[i][j].rgbtRed = red > 255 ? 255 : red;
            image[i][j].rgbtGreen = green > 255 ? 255 : green;
            image[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }
}
