#include "matriz_esparsa.h"

int compara_matriz_esparsa( void *x, void *y ){
    EntradaMatriz *a = x, *b = y; // void* --> EntradaMatriz*
    return a->coluna - b->coluna;
}

void mostra_EntradaMatriz( void *x ){     // mostra um float...
    EntradaMatriz *p = x;
    printf("(%d,%d)\n", p->coluna, p->info); // a partir de um void*
}

void inicializa_matriz_esparsa( MatrizEsparsa *ml, int linhas, int colunas ){
    int i;
    inicializa_lista( &ml->multiLista, sizeof(Lista));
    for (i = 0; i < linhas; i++) {
        Lista c1;
        inicializa_lista( &c1, sizeof(EntradaMatriz) );
		insere_fim( &ml->multiLista, &c1 );
    }
    ml->numColunas = colunas;
}

void set_matriz_esparsa( MatrizEsparsa *ml, int lin, int col, int data ){
    Lista linha;
    le_valor( ml->multiLista, &linha, lin );

    EntradaMatriz entrada, aux;
    entrada.info = data;
    entrada.coluna = col;

    int index = busca( linha, &entrada, compara_matriz_esparsa);
    if (index != -1){
        if(data == 0)
            remove_pos(&linha, &entrada, index);
        else
            modifica_valor(linha, &entrada, index);
    }
    else{
        if (data != 0)
            insere_ordem(&linha, &entrada, compara_matriz_esparsa);
    }
    modifica_valor( ml->multiLista, &linha, lin);
}

void mostra_matriz_esparsa( MatrizEsparsa m){
    int i, j, k, vazio;
    Lista l;
    EntradaMatriz x;
	printf("Dados da matriz (%dx%d):\n", m.multiLista.qtd, m.numColunas);
	for( i = 0; i < m.multiLista.qtd ; i++){
        Lista linha;
        le_valor(m.multiLista, &linha, i);
        int col_atual = 0;
        vazio = lista_vazia(linha);
        for(j=0;j<linha.qtd;j++){
            vazio = le_valor( linha, &x, j);
            for( k = col_atual ; k < x.coluna ; k++){
                printf("%3d", 0);
            }
            printf("%3d", x.info);
            col_atual += x.coluna + 1;
        }
        for(k = col_atual; k < m.numColunas; k++)
            printf("%3d", 0);
        printf("\n");
    }
}

void desaloca_matriz_esparsa( MatrizEsparsa *m) {
    int i;
    for(i=0;i< m->multiLista.qtd; i++){
        Lista linha;
        le_valor(m->multiLista, &linha, i);
        desaloca_lista( &linha );
    }
    desaloca_lista( &m->multiLista );
}

int get_matriz_esparsa( MatrizEsparsa *m, int lin, int col){
    Lista l;
    le_valor( m->multiLista, &l,  lin);
    EntradaMatriz x;
    x.coluna = col;
    int i = busca( l, &x, compara_matriz_esparsa);
    le_valor( l, &x, i);
    return x.info;
    /*
    for(int i = 0; i <= col; i++){
        le_valor( l, &x, i );
        if(x.coluna == col) return x.info;
    }
    return 0;
    */
}

MatrizEsparsa soma_matrizes_esparsa( MatrizEsparsa a, MatrizEsparsa b, int lin, int col ){
    int i, j, soma, val1, val2;
    Lista l1, l2;
    EntradaMatriz x1, x2;
    MatrizEsparsa m;
    inicializa_matriz_esparsa(&m,lin,col);
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            val1 = get_matriz_esparsa( &a, i, j );
            val2 = get_matriz_esparsa( &b, i, j );
            soma = val1 + val2;
            if(soma){
                set_matriz_esparsa(&m,i,j,soma);
            }
        }
    }
    return m;
}