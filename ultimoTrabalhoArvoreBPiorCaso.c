#include <time.h>
#include <stdlib.h>
#include "arvore-b.c"

#define MAX 1000

int main()
{
    int r;
    int m = 0;
    float media = 0;
    ArvoreB *arvore = criaArvore(1);
    contador = 0;

    for (int i = 0; i < MAX; i++) // 1 - 1000
    {
        for (int j = 0; j <= i; j++)
        {
            adicionaChave(arvore, i + 1);
        }
        if (m == 0)
        {
            printf("%d", contador);
            m++;
        }
        else
        {
            printf(";%d", contador);
        }
    }
    free(arvore);
}