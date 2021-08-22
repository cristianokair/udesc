#include <stdio.h>
#include <string.h>
#include <locale.h>
/*
void main()
{
    int n, maior_par = 0, qtde = 0, pares = 0;
    printf("Quantas luvas?: \n");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        printf("Insira o tamanho da %d luva: \n", i + 1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] > maior_par)
        {
            maior_par = v[i];
        }
    }

    for (int i = 1; i <= maior_par; i++)
    {
        qtde = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                qtde++;
            }
            if (qtde == 2)
            {
                pares++;
                qtde = 0;
            }
        }
    }

    printf("Total de pares: %d\n", pares);
}
*/
// int min(int a, int b, int c)
// {
//     if (a <= b && a <= c)
//     {
//         return a;
//     }
//     else if (b <= a && b <= c)
//     {
//         return b;
//     }
//     else if (c <= a && c <= b)
//     {
//         return c;
//     }
// }

// int levenshtein(char *s1, char *s2)
// {
//     unsigned int x, y, s1len, s2len;
//     s1len = strlen(s1);
//     s2len = strlen(s2);
//     unsigned int matrix[s2len + 1][s1len + 1];
//     matrix[0][0] = 0;
//     for (x = 1; x <= s2len; x++)
//         matrix[x][0] = matrix[x - 1][0] + 1;
//     for (y = 1; y <= s1len; y++)
//         matrix[0][y] = matrix[0][y - 1] + 1;
//     for (x = 1; x <= s2len; x++)
//         for (y = 1; y <= s1len; y++)
//             matrix[x][y] = min(matrix[x - 1][y] + 1, matrix[x][y - 1] + 1, matrix[x - 1][y - 1] + (s1[y - 1] == s2[x - 1] ? 0 : 1));

//     return (matrix[s2len][s1len]);
// }

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *s1, char *s2)
{
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len + 1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++)
    {
        column[0] = x;
        for (y = 1, lastdiag = x - 1; y <= s1len; y++)
        {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y - 1] + 1, lastdiag + (s1[y - 1] == s2[x - 1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return column[s1len];
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int i = levenshtein("teste", "tessia");
    printf("numero de operações: %d", i);
}