#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct EntradaMatriz {
    int coluna, info;
}EntradaMatriz;

typedef struct MatrizEsparsa {
    Lista multiLista;
    int numColunas;
}MatrizEsparsa;

void inicializa_matriz_esparsa( MatrizEsparsa *me, int l, int c );
void mostra_matriz_esparsa( MatrizEsparsa m);
void set_matriz_esparsa( MatrizEsparsa *multi, int lin, int col, int data);
int get_matriz_esparsa( MatrizEsparsa *multi, int lin, int col);
MatrizEsparsa soma_matrizes_esparsa( MatrizEsparsa a, MatrizEsparsa b, int lin, int col );
void desaloca_matriz_esparsa( MatrizEsparsa *p );