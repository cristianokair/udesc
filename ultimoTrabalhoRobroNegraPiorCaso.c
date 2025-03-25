//analisar esforço computacional
//Curva logaritimica
//NÃO PODE TER NUMEROS REPETIDOS
#include <time.h>
#include <stdlib.h>
#include "arvore-rubro-negra.c"

#define MAX 1000

int main()
{
    int r;
    int m = 0;
    float media = 0;
    Arvore *arvore = criar();
    contador = 0;

    for (int i = 0; i < MAX; i++) // 1 - 1000
    {
        for (int j = 0; j <= i; j++)
        {
            adicionar(arvore, i + 1);
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