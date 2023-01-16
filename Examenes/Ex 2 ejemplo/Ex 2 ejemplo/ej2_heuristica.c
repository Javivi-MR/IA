#include "tictac.c"

int heuristica(tNodo* t)
{
    return heuristicaux(t,MAX) - heuristicaux(t,MIN);
}

int heuristicaux(tNodo* t,unsigned jugador)
{
    int soluciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int total = 0,i;

    for(i= 0 ; i < N ; i++)
    {
        if
        (
            t->celdas[soluciones[i][0]] != opuesto(jugador) &&
            t->celdas[soluciones[i][1]] != opuesto(jugador) &&
            t->celdas[soluciones[i][0]] != opuesto(jugador) 
        )
        {
            total++;
        }
    }
    return total;
}