#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t SAMPLE;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Uso: ./volume fator entrada.wav saida.wav\n");
        return 1;
    }

    float factor = atof(argv[1]);

    // Abrir o arquivo de entrada
    FILE *input = fopen(argv[2], "r");
    if (input == NULL)
    {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abrir o arquivo de saída
    FILE *output = fopen(argv[3], "w");
    if (output == NULL)
    {
        printf("Não foi possível criar o arquivo de saída.\n");
        fclose(input);
        return 1;
    }
  
    BYTE header[44];
    fread(header, sizeof(BYTE), 44, input);
    fwrite(header, sizeof(BYTE), 44, output);

    SAMPLE buffer;
    while (fread(&buffer, sizeof(SAMPLE), 1, input))
    {
        buffer = (SAMPLE)(buffer * factor);
        fwrite(&buffer, sizeof(SAMPLE), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
