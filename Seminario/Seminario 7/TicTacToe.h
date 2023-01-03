#include <stdio.h>

#define N 3


typedef struct 
{
    int tablero[N][N];
    int vacias = 0;
    //int colocadas = N*N;
}tNodo;

typedef struct //solo hacer en el caso que haga falta varios datos (no solo 1)
{
    int fila,col;
}tJugada;

int terminal(tNodo* t);
int utilidad(tNodo* t);