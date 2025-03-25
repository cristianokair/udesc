#include <time.h>
#include <stdlib.h>
#include "arvore-b.c"

#define MAX 100
#define AMOSTRA 10

int verificaArray(int val, int *arr);

int main()
{
    int r;
    int m = 0;
    int arr[] = {};
    float media;

    srand(time(NULL));            // Initialization, should only be called once.
    for (int i = 0; i < MAX; i++) // 1 - 1000
    {
        media = 0;
        for (int j = 0; j < AMOSTRA; j++) // 10 amostras
        {
            ArvoreB *arvore = criaArvore(1);
            contador = 0;
            int *arr = ((int *)(malloc(i * sizeof(int))));
            for (int k = 0; k <= i; k++)
            {
                r = rand() % 999;
                if (!verificaArray(r, arr))
                {
                    arr[k] = r;
                }
                else
                {
                    k--;
                }
            }
            for (int l = 0; l <= i; l++)
            {
                adicionaChave(arvore, arr[l]);
            }
            free(arr);
            free(arvore);
            media += contador;
        }
        if (m == 0)
        {
            printf("%.1f", media / AMOSTRA);
            m++;
        }
        else
        {
            printf(";%.1f", media / AMOSTRA);
        }
    }
}

int verificaArray(int val, int *arr)
{
    int i;
    for (i = 0; i < sizeof(*arr); i++)
    {
        if (*arr + i == val)
        {
            return 1;
        }
    }
    return 0;
}