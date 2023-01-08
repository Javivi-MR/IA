#include "ej1_puzle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// <--------------------------------------------- B -------------------------------------------->

tEstado* estadoInicial()
{
    int i,j;
    tEstado* t = (tEstado*)malloc(sizeof(tEstado));
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            t->tablero[i][j] = estado_inicial[i][j];
        }
    }

    t->filas[A] = 3; t->cols[A] = 1;
    t->filas[B] = 4; t->cols[B] = 4;
    t->filas[C] = 1; t->cols[C] = 3;

    return t;
}

tEstado* estadoOjetivo()
{
    int i,j;
    tEstado* t = (tEstado*)malloc(sizeof(tEstado));
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            t->tablero[i][j] = estado_final[i][j];
        }
    }

    t->filas[A] = 4; t->cols[A] = 1;
    t->filas[B] = 5; t->cols[B] = 3;
    t->filas[C] = 4; t->cols[C] = 5;

    return t;
}

// <--------------------------------------------- C -------------------------------------------->

int esValido(unsigned op,tEstado* t)
{
    switch(op)
    {
        case ARRIBA_B:
            return (t->tablero[t->filas[B]-2][t->cols[B]] == 0 && t->tablero[t->filas[B]-1][t->cols[B]-1] == 0 && t->tablero[t->filas[B]-1][t->cols[B]+1] == 0);
        break;
        case ABAJO_B:
            return (t->tablero[t->filas[B]+1][t->cols[B]] == 0 && t->tablero[t->filas[B]+1][t->cols[B]-1] == 0 && t->tablero[t->filas[B]+1][t->cols[B]+1] == 0);
        break;
    }
}

// <--------------------------------------------- D -------------------------------------------->

tEstado* aplicarOperador(unsigned op, tEstado* t)
{
    tEstado* s = (tEstado*) malloc (sizeof(tEstado));
    s = memcpy(s,t,sizeof(tEstado));

    switch(op)
    {
        case ARRIBA_B:
            //casillas libres
            s->tablero[t->filas[B]][t->cols[B]] = 0; s->tablero[t->filas[B]][t->cols[B]-1] = 0; s->tablero[t->filas[B]][t->cols[B]+1] = 0;
            //ocupamos la nueva casilla para la posicion B
            s->filas[B] = s->filas[B] - 1; 
            //casillas ocupadas
            s->tablero[t->filas[B]][t->cols[B]-1] = B; s->tablero[t->filas[B]][t->cols[B]+1] = B; s->tablero[t->filas[B]-1][t->cols[B]] = B;  
        break;
        
        case ABAJO_B:
            //casillas libres
            s->tablero[t->filas[B]][t->cols[B]-1] = 0; s->tablero[t->filas[B]][t->cols[B]+1] = 0; s->tablero[t->filas[B]-1][t->cols[B]] = 0;
            //ocupamos la nueva casilla para la posicion B
            s->filas[B] = s->filas[B] + 1; 
            //casillas ocupadas
            s->tablero[t->filas[B]][t->cols[B]] = B; s->tablero[t->filas[B]][t->cols[B]-1] = B; s->tablero[t->filas[B]][t->cols[B]+1] = B;
        break;
    }

    return s;
}

// <--------------------------------------------- E -------------------------------------------->

int testObjetivo(tEstado* t)
{
    return iguales(t,estadoOjetivo());
}

int iguales(tEstado* actual,tEstado* final)
{
    return 
        actual->filas[A] == final->filas[A] && actual->cols[A] == final->cols[A] &&
        actual->filas[B] == final->filas[B] && actual->cols[B] == final->cols[B] &&
        actual->filas[C] == final->filas[C] && actual->cols[C] == final->cols[C];
}

// <--------------------------------------------- F -------------------------------------------->
int abs(int a)
{
    if(a < 0)
        a*=-1;
    return a;
}


int heuristica(tEstado* t)
{
    tEstado* s = (tEstado*)malloc(sizeof(tEstado));
    s = estadoOjetivo();
    return abs(t->filas[A] - s->filas[A]) + abs(t->cols[A] - s->cols[A]) +
    abs(t->filas[B] - s->filas[B]) + abs(t->cols[B] - s->cols[B]) +
    abs(t->filas[C] - s->filas[C]) + abs(t->cols[C] - s->cols[C]);
}

// <--------------------------------------------- G -------------------------------------------->

//Construir arbol