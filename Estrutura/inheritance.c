#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Código que representa uma pessoa
typedef struct person
{
    struct person *parents[2];
    int genes;
} person;

person *create_family(int generations);
int random_gene_from_parent(int parent_genes);
void print_family(person *p, int generation);
void free_family(person *p);

int main(void)
{
    srand(time(0));
    // Criar uma família com 3 gerações
    person *p = create_family(3);
    print_family(p, 0);
    free_family(p);

    return 0;
}

person *create_family(int generations)
{
    // Alocar memória para uma nova pessoa
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        fprintf(stderr, "Erro: Não foi possível alocar memória.\n");
        exit(1);
    }

    if (generations > 1)
    {
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // Atribuir genes aleatoriamente com base nos genes dos pais
        p->genes = random_gene_from_parent(p->parents[0]->genes) +
                   random_gene_from_parent(p->parents[1]->genes);
    }
    else
    {
        // Não há gerações anteriores (esta pessoa não tem pais)
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->genes = rand() % 3;
    }

    return p;
}

// Escolhe aleatoriamente um gene de um dos pais
int random_gene_from_parent(int parent_genes)
{
    if (parent_genes == 2)
    {
        return rand() % 2;
    }
    else if (parent_genes == 1)
    {
        return rand() % 2;
    }
    else
    {
        return 0;
    }
}

void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // Indentação para representar as gerações
    for (int i = 0; i < generation; i++)
    {
        printf("  ");
    }
    printf("Generation %i, genes: %i\n", generation, p->genes);

    // Chama recursivamente para os pais
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    free(p);
}
