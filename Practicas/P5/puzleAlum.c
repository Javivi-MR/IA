#include "puzle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//  creacion de Estado estatico
tEstado* crearEstado(int puzle_ini[N][N])
{
    int i,j;
    tEstado* ini = (tEstado*) malloc (sizeof(tEstado));
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            ini->celdas[i][j] = puzle_ini[i][j];
            if(ini->celdas[i][j] == 0)
            {
                ini->fila = i;
                ini->col = j;
            }
        }
    }
    return ini;
}

tEstado* estadoInicial()
{
    return crearEstado(puzle_inicial);
}

tEstado* estadoObjetivo()
{
    return crearEstado(puzle_final);
}


/*
//DINAMICA
tEstado* crearEstado()
{
    int i,j;
    tEstado* ini = (tEstado*) malloc (sizeof(tEstado));
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("Introduce el numero correspondiente a la posicion %i,%i del puzle: ",i,j);
            scanf("%i",&ini->celdas[i][j]);
            if(ini->celdas[i][j] == 0)
            {
                ini->fila = i;
                ini->col = j;
            }
        }
    }

    return ini;
}


tEstado* estadoInicial()
{
    return crearEstado();
}
*/

int coste (unsigned op,tEstado *s)
{
    return 1;
}

int testObjetivo(tEstado *estado)
{
    tEstado* estadof;
    estadof = estadoObjetivo();

    return iguales(estado,estadof);
}
/*
tEstado* estadoObjetivo()
{
    return crearEstado();
}
*/
int iguales(tEstado* actual,tEstado* final)
{
    int i=0,j=0,sol=1;
    while(i<N && sol !=0)
    {
        while(j<N && sol !=0)
        {
            if(actual->celdas[i][j] != final->celdas[i][j])
            {
                sol = 0;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return sol;
}

int esValido(unsigned op, tEstado* s)
{
    switch (op)
    {
    case ARRIBA:
        return (s->fila != 0);
        break;
    case ABAJO:
        return (s->fila < N-1);
        break;
    case IZQUIERDA:
        return (s->col != 0);
        break;
    case DERECHA:
        return (s->col < N-1);
    default:
        printf("ERROR FATAL, operacion desconocida");
        break;
    }
}

tEstado *aplicaOperador(unsigned op,tEstado *s)
{
    int aux;
    tEstado* t = (tEstado*) malloc (sizeof(tEstado));

    memcpy(t,s,sizeof(tEstado));
    switch (op)
    {
        case ARRIBA:
            t->fila--;
            break;
        case ABAJO:
            t->fila++;
            break;
        case IZQUIERDA:
            t->col--;
            break;
        case DERECHA:
            t->col++;
            break;
        default:
            printf("ERROR FATAL, operacion desconocida");
            break;
    }
    aux = t->celdas[s->fila][s->col];
    t->celdas[s->fila][s->col] = t->celdas[t->fila][t->col];
    t->celdas[t->fila][t->col] = aux;

    return t;
}

void dispEstado(tEstado* s)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%i ",s->celdas[i][j]);
        }
        printf("\n");
    }
    //printf("\n\n");   
    //printf("POSICION DE LA FICHA: x = %i , y = %i \n\n",s->fila,s->col);
}

void dispOperador(unsigned op)
{
    switch (op)
    {
    case ARRIBA:
        printf("Aplicando el operador Arriba\n");
        break;
    case ABAJO:
        printf("Aplicando el operador Abajo\n");
        break;
    case IZQUIERDA:
        printf("Aplicando el operador Izquierda\n");
        break;
    case DERECHA:
        printf("Aplicando el operador Derecha\n");
        break;
    default:
        printf("ERROR FATAL, operacion desconocida");
        break;
    }
}

int HeuristicaPiezasMalColocadas(tEstado* s)
{
    int i,j,cont = 0;

    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            if(s->celdas[i][j] != puzle_final[i][j])
                cont++;
        }
    }
    return cont;
}