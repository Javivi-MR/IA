#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fichasHuidizas.h"

tNodo* nodoInicial()
{
    tNodo* s = (tNodo*)malloc(sizeof(tNodo));
    s->tablero[0][0] = MAX;
    s->tablero[0][1] = VACIA;
    s->tablero[0][2] = VACIA;
    s->tablero[1][0] = MAX;
    s->tablero[1][1] = VACIA;
    s->tablero[1][2] = VACIA;
    s->tablero[2][0] = VACIA;
    s->tablero[2][1] = MIN;
    s->tablero[2][2] = MIN;

    return s;
}

int esValida(tJugada jugada,tNodo* t)
{
    if(jugada.fila >= 0 && jugada.fila < 3 && jugada.col >= 0 && jugada.col < 3)
    {
        
    }
}