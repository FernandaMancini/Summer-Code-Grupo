#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para embaralhar uma string
void shuffle(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        int random_index = rand() % len;
        char temp = word[i];
        word[i] = word[random_index];
        word[random_index] = temp;
    }
}

int main(void)
{
    srand(time(NULL));

    string words[] = {"memory", "pointer", "array", "dynamic", "string", "malloc", "free"};
    int num_words = sizeof(words) / sizeof(words[0]);

    printf("Bem-vindo ao jogo Scramble!\n");

    int score = 0;

    // Loop através das palavras
    for (int i = 0; i < num_words; i++)
      {
        char scrambled[strlen(words[i]) + 1];
        strcpy(scrambled, words[i]);
        shuffle(scrambled);

        printf("Palavra embaralhada: %s\n", scrambled);

        string guess = get_string("Qual é a palavra original? ");

        if (strcmp(guess, words[i]) == 0)
        {
            printf("Correto!\n");
            score++;
        }
        else
        {
            printf("Errado! A resposta correta era: %s\n", words[i]);
        }
    }

    // Pontuação final
    printf("Você acertou %d de %d palavras.\n", score, num_words);
    return 0;
}
