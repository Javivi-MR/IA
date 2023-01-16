#include "oso.h"


tNodo* crearEstado(int m[N1][N2])
{
    int i,j;
    tNodo* t = (tNodo*) malloc (sizeof(tNodo));
    for(i = 0 ; i < N1 ; i++)
    {
        for(j = 0 ; j < N2 ; j++)
        {
            t->tablero[i][j] = m[i][j];
        }
    }
    t->vacias = 30;
    t->puntuacion[MAX] = 0;
    t->puntuacion[MIN] = 0;

    return t;
}

int esValida(tNodo* t,tJugada jugada, int jugador)
{
    if(jugada.col >= 0 && jugada.col < 5 && jugada.fila >= 0 && jugada.fila < 6)
    {
        return t->tablero[jugada.fila][jugada.col] == vacia;
    }
    else
    {
        return 0;
    }
}

tNodo* aplicaJugada (tNodo* actual, tJugada jugada, int jugador)
{
    tNodo* t = (tNodo*) malloc(sizeof(tNodo));
    memcpy(t, actual, sizeof(tNodo));

    t->tablero[jugada.fila][jugada.col] = jugada.letra;

    if(jugada.letra == S)
    {
        if(jugada.fila > 0 && jugada.fila < 5)
        {
            if(t->tablero[jugada.fila-1][jugada.col] == O && t->tablero[jugada.fila+1][jugada.col] == O)
            {
                t->puntuacion[jugador] += 1;
            }
        }
        if(jugada.col > 0 && jugada.fila < 4)
        {
            if(t->tablero[jugada.fila][jugada.col-1] == O && t->tablero[jugada.fila][jugada.col+1] == O)
            {
                t->puntuacion[jugador] += 1;
            }
        }

    }
    if(jugada.letra == O)
    {
        if(jugada.col == 0 || jugada.col == 1)
        {
            if(t->tablero[jugada.fila][jugada.col+1] == S && t->tablero[jugada.fila][jugada.col+2] == O)
            {
                t->puntuacion[jugador] += 1;
            }
        }

        if(jugada.col == 2)
        {
            if(t->tablero[jugada.fila][jugada.col+1] == S && t->tablero[jugada.fila][jugada.col+2] == O && t->tablero[jugada.fila][jugada.col-1] == S && t->tablero[jugada.fila][jugada.col-2] == O)
            {
                t->puntuacion[jugador] += 1;
            }
        }

        if(jugada.col == 3 || jugada.col == 4)
        {
            if(t->tablero[jugada.fila][jugada.col-1] == S && t->tablero[jugada.fila][jugada.col-2] == O)
            {
                t->puntuacion[jugador] += 1;
            }
        }

        //cont

    }

    t->vacias--;

    return t;
}

int heurística (tNodo* Nodo)
{
    return Nodo->puntuacion[MAX]*100 - Nodo->puntuacion[MIN]*100;
}

int utilidad(tNodo* Nodo)
{
    return heurística(Nodo);
}

int terminal(tNodo* Nodo)
{
    return Nodo->vacias == 0;
}