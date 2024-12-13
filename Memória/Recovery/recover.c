#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE; // Definição de BYTE como um alias para uint8_t

int main(int argc, char *argv[])
{
    // Verifica uso inválido
    if (argc != 2)
    {
        printf("Uso: recover <nomeDoCartao>\n");
        return 1;
    }

    char *infile = argv[1];

    // Abre o arquivo de entrada
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Erro: não foi possível abrir o arquivo %s\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int imageCount = 0;      

    char filename[8];        
    FILE *outFile = NULL;  

    while (true)
    {
        // Lê um bloco de memória
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        bool containsJpegHeader = 
            buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff && 
            (buffer[3] & 0xf0) == 0xe0;

        // Se encontrar um novo JPEG enquanto outro arquivo está aberto, fecha o arquivo atual
        if (containsJpegHeader && outFile != NULL)
        {
            fclose(outFile);
            imageCount++;
        }

        // Se encontrar um cabeçalho de JPEG, cria um novo arquivo para a imagem
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            outFile = fopen(filename, "w");
            if (outFile == NULL)
            {
                printf("Erro: não foi possível criar o arquivo %s\n", filename);
                fclose(inptr);
                return 1;
            }
        }
      
        if (outFile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outFile);
        }
    }

    // Fecha o arquivo de saída, se estiver aberto
    if (outFile != NULL)
    {
        fclose(outFile);
    }

    fclose(inptr);
  
    return 0;
}
