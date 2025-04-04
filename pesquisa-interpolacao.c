#include <stdio.h>

int interpolacao(int chave, int v[], int n)
{
    int ini = 0, meio, fim = n - 1;
    int cont = 0;

    while (ini <= fim)
    {
        cont++;
        meio = ini + ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);

        if (chave < v[meio])
        {
            fim = meio - 1;
        }
        else if (chave > v[meio])
        {
            ini = meio + 1;
        }
        else
        {
            return cont;
        }
    }

    return cont;
}