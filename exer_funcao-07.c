#include <stdlib.h>
#include <stdio.h>
/*
7. Considere uma escadaria com n degraus e você pode subir 1 ou 2 degraus por vez. Faça um
programa que, dado n, retorne o número de maneiras únicas para subir a escada.
○ Exemplo, dado n = 4, existem 5 maneiras exclusivas
n = 1 [1]
n = 2 [1,1], [2]
n = 3 [1,1,1], [2,1], [1,2]
n = 4 [1,1,1,1], [2,1,1], [1,2,1], [1,1,2], [2, 2]
n = 5 [1,1,1,1,1], [2,1,1,1], [1,2,1,1], [1,1,2,1], [1,1,1,2], [2,2,1], [2,1,2], [1,2,2]
*/

int fibo(int base)
{
    if (base <= 1)
        return base;

    return fibo(base - 2) + fibo(base - 1);
}

void main()
{
    int n = 0;
    printf("digite um termo: ");
    scanf("%d", &n);
    int f = fibo(n);
    printf("existem %d maneiras exclusivas", f);
}