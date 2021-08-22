/*
Dupla: Cristiano , Haidi
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"
#include <locale.h>

void menu();
void menu_programa();
void cria_matriz();
void mostra_matriz();
void modifica_matriz();
void remove_matriz();
void soma_matrizes();

typedef struct {
     int indice;
     MatrizEsparsa *ponteiro;
} Matrizes;

int indice = 0;
int linhas, colunas;
Matrizes matrizes[100];

void main(int argc, char *argv[]){
	int i, j, get;
    menu();
}
void menu() {
    int menu;
    printf("Digite a opcao desejada: \n 1 - Criar matriz \n 2 - Mostrar matriz \n 3 - Modificar matriz \n 4 - Somar matrizes \n 5 - Remover matriz \n 6 - Sair \n");
    printf("Opcao: ");
    scanf("%d", &menu);

    switch(menu) {
        case 1: {
            cria_matriz();
            break;
        }
        case 2: {
           mostra_matriz();
           break;
        }
        case 3: {
            modifica_matriz();
            break;
        }
        case 4: {
            soma_matrizes();
            break;
        }
        case 5: {
            remove_matriz();
            break;
        }
        case 6: {
            printf("---- Sair ----");
            break;
        }
        default: {
            printf("Opcao desconhecida, o programa sera encerrado \n");
            break;
        }
    }
}

void menu_programa() {
    int opcao_menu;
    printf("Digite a opcao desejada: \n 1 - Retornar para o menu \n 2 - Sair \nOpcao: ");
    scanf("%d", &opcao_menu);
    if (opcao_menu == 1) {
        menu();
    }
    else {
        printf(" -- fim --  \n");
    }
}

void cria_matriz() {
    MatrizEsparsa me;

	printf("Digite o numero de linhas: ");
	scanf("%d", &linhas);
	printf("Digite o numero de colunas: ");
	scanf("%d", &colunas);

    inicializa_matriz_esparsa(&me, linhas, colunas);
    mostra_matriz_esparsa(me);
    indice++;
    printf("\nMatriz %d criada com sucesso \n", indice);
    matrizes[indice].indice = indice;
    matrizes[indice].ponteiro = &me;
    menu_programa();
}

void mostra_matriz() {
    int i, matriz_escolhida, existe = 0;
    printf("Matrizes existentes:\n");
    for (i = 1; i <= indice; i++) {
        if (matrizes[i].indice == i) {
           existe++;
           printf("Matriz: %d\n", i);
        }
    }
    if (existe == 0) {
        printf("Nenhuma matriz disponivel\n");
    }
    else {
        printf("Digite a matriz que deseja visualizar: ");
        scanf("%d", &matriz_escolhida);
        printf("\n ");
        for (i = 0; i <= indice; i++) {
            if (matrizes[i].indice == matriz_escolhida) {
                MatrizEsparsa *m = matrizes[i].ponteiro;
                mostra_matriz_esparsa(*m);
            }
        }
    }
    menu_programa();
}

void modifica_matriz() {
    int lin, col, valor, i, matriz_escolhida, existe = 0;

    printf("Matrizes existentes:\n");
    for (i = 1; i <= indice; i++) {
        if (matrizes[i].indice == i) {
           existe ++;
           printf("Matriz: %d \n", i);
        }
    }
    if (existe == 0) {
        printf("Nenhuma matriz disponivel");
    }
    else {
        printf("Digite a matriz que deseja alterar: ");
        scanf("%d", &matriz_escolhida);
        printf("\n ");
        for (i = 0; i <= indice; i++) {
            if (matrizes[i].indice == matriz_escolhida) {
                printf("Defina a posicao a ser alterada \n");
                printf("Linha: ");
                scanf("%d", &lin);
                printf("Coluna: ");
                scanf("%d", &col);
                printf("\nValor a ser inserido na posicao %d %d: ", lin, col);
                scanf("%d", &valor);
                printf("\n");
                set_matriz_esparsa(matrizes[i].ponteiro, lin, col, valor);
            }
        }
    }

    menu_programa();
}

void soma_matrizes() {
    int valor, i, matriz_escolhida1, matriz_escolhida2, existe = 0;
    MatrizEsparsa *a, *b, matriz_soma;
    printf("Matrizes existentes: ");
    for (i = 1; i <= indice; i++) {
        if (matrizes[i].indice == i) {
           existe++;
           printf("Matriz: %d \n", i);
        }
    }
    if (existe < 2) {
        printf("Nao ha duas ou mais matrizes disponiveis para soma \n");
    }
    else {
        printf("Digite a matriz 1 que deseja somar: ");
        scanf("%d", &matriz_escolhida1);
        printf("\n");

        printf("Digite a matriz 2 que deseja somar: ");
        scanf("%d", &matriz_escolhida2);
        printf("\n");

        for (i = 0; i <= indice; i++) {
            if (matrizes[i].indice == matriz_escolhida1) {
                a = matrizes[i].ponteiro;
            }
            if (matrizes[i].indice == matriz_escolhida2) {
                b = matrizes[i].ponteiro;
            }
        }

        matriz_soma = soma_matrizes_esparsa( *a, *b, linhas, colunas);
        indice++;
        printf("\nMatriz %d criada com sucesso \n", indice);
        matrizes[indice].indice = indice;
        matrizes[indice].ponteiro = &matriz_soma;

    }
    menu_programa();
}

void remove_matriz() {
    int i, matriz_escolhida, existe = 0;

    printf("Matrizes existentes: ");
    for (i = 1; i <= indice; i++) {
        if (matrizes[i].indice == i) {
           existe++;
           printf("Matriz: %d \n", i);
        }
    }
    if (existe == 0) {
        printf("Nenhuma matriz disponivel \n");
    }
    else {
        printf("Digite a matriz que deseja excluir: ");
        scanf("%d", &matriz_escolhida);
        printf("\n ");
        for (i = 0; i <= indice; i++) {
            if (matrizes[i].indice == matriz_escolhida) {
                desaloca_matriz_esparsa(matrizes[i].ponteiro);
            }
        }
    }
    menu_programa();
}
