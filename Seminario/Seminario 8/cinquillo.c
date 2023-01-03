#include "cinquillo.h"
#include <stdio.h>

int esValida(tNodo* actual,int jugador, tJugada* jugada)
{
    int valido;
    if(actual->juego[jugada->carta][jugada->palo] == jugador)
    {
        if(jugada->carta < 5)
        {
            valido = actual->juego[jugada->carta + 1][jugada->palo] == MESA;
        }
        else
        {
            if(jugada->carta > 5)
            {
                valido = actual->juego[jugada->carta - 1][jugada->palo] == MESA;
            }
            else
            {
                valido = actual->juego[jugada->carta][jugada->palo] == MESA;
            }
        }
    }
    return valido;
}