#include "Granjero.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tEstado *estadoInicial()
{
    tEstado* t = (tEstado*) malloc (sizeof(tEstado));
    int i;
    for(i = 0 ; i < NUM_OPERADORES ; i++)
    {
        t->orilla[i] = IZQ;
    }
    return t;
}

int coste (unsigned op,tEstado *s)
{
    return 1;
}

int testObjetivo(tEstado *estado)
{
    return iguales(estado,estadoObjetivo());
}

tEstado* estadoObjetivo()
{
    tEstado* t = (tEstado*) malloc (sizeof(tEstado));
    int i;
    for(i = 0 ; i < NUM_OPERADORES ; i++)
    {
        t->orilla[i] = DER;
    }
    return t;
}

int iguales(tEstado* actual,tEstado* final)
{
    int i,c=1;
    for(i = 0 ; i < NUM_OPERADORES ; i++)
    {
        if(actual->orilla[i] != final->orilla[i])
        {
            c = 0;
        }        
    }
    return c;
}


int esValido(unsigned op, tEstado*s)
{
    switch (op)
    {
    case GRANJ:
        return (s->orilla[CABRA-1] != s->orilla[LECH-1] && s->orilla[LOBO-1] != s->orilla[CABRA-1]);
    break;
    case LOBO:
        return (s->orilla[CABRA-1] != s->orilla[LECH-1] && s->orilla[GRANJ-1] == s->orilla[LOBO-1]);
    break;
    case CABRA:
        return (s->orilla[GRANJ-1] == s->orilla[CABRA-1]);
    break;
    case LECH:
        return (s->orilla[CABRA-1] != s->orilla[LOBO-1] && s->orilla[GRANJ-1] == s->orilla[LECH-1]);
    break;
    default:
        printf("OPERACION DESCONOCIDA");
        break;
    }
}



tEstado *aplicaOperador(unsigned op,tEstado *t)
{
    tEstado* s = (tEstado*) malloc (sizeof(tEstado));
    memcpy(s,t,sizeof(tEstado));
    switch (op)
    {
    case GRANJ:
        s->orilla[GRANJ-1] *= -1;
    break;
    case LOBO:
        s->orilla[GRANJ-1] *= -1;
        s->orilla[LOBO-1] *= -1;
    break;
    case CABRA:
        s->orilla[GRANJ-1] *= -1;
        s->orilla[CABRA-1] *= -1;
    break;
    case LECH:
        s->orilla[GRANJ-1] *= -1;
        s->orilla[LECH-1] *= -1;
    break;
    default:
        printf("OPERACION DESCONOCIDA");
        break;
    }
    return s;
}

void dispEstado(tEstado* s)
{
    printf("ESTADO ACTUAL DEL JUEGO: (1 es IZQUIERDA y -1 es DERECHA\n");
    printf("EL GRANJERO SE ENCUENTRA EN LA ORILLA: %i\n",s->orilla[GRANJ-1]);
    printf("EL LOBO SE ENCUENTRA EN LA ORILLA: %i\n",s->orilla[LOBO-1]);
    printf("LA CABRA SE ENCUENTRA EN LA ORILLA: %i\n",s->orilla[CABRA-1]);
    printf("EL LECHUGA SE ENCUENTRA EN LA ORILLA: %i\n",s->orilla[LECH-1]);
}

int PiezasMalColocadas(tEstado* s)
{
    int cont = 0,i;
    for(i = 0 ; i < NUM_OPERADORES ; i++)
    {
        if(s->orilla[i] != IZQ)
        {
            cont += 2;
        }
    }
}