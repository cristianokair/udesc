#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------
Dado um vetor de números inteiros v de tamanho n e um número k, retorne verdadeiro
se a soma de qualquer par de números em v for igual a k.
○ Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17
--------------------------------------------------------------
int main()
{
    int n = 4, k = 17;
    int v[4] = {10, 15, 3, 7};
    for (int i = 0; i < n - 1; i++) // N iterações
    {
        for (int j = i + 1; j < n; j++) // N iterações
        {
            if (v[i] + v[j] == k) //N * N = N²
            {
                printf("%d + %d = %d\n", v[i], v[j], k);
                printf("verdadeiro\n");
                return 0;
            }
        }
    }
}
*/

int compara(const void *i, const void *j)
{
    return *(int *)i - *(int *)j;
}

int soma(int vetor[], int tamanho, int k)
{
    qsort(vetor, tamanho, sizeof(int), *compara); //N log N

    for (int i = 0; i < tamanho - 1; i++)
    {
        int j = pesquisabinaria(vetor, tamanho, k - vetor[i]); //Log N

        if (j < tamanho && i != j)
        {
            return 1;
        }
    }
}

int main()
{
    int n = 4, k = 17;
    int v[4] = {10, 15, 3, 7};
    for (int i = 0; i < n - 1; i++) // N iterações
    {
        if (k - v[i] ==)
        {
            printf("%d + %d = %d\n", v[i], v[j], k);
            printf("verdadeiro\n");
            return 0;
        }
    }
}