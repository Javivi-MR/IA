#include "puzle3piezas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tEstado *estadoInicial()
{
    tEstado* ini = (tEstado*) malloc (sizeof(tEstado));
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            ini->celdas[i][j] = estado_inicial[i][j];
        }
    }
    ini->filas[A] = 3; ini->cols[A] = 1;
    ini->filas[B] = 4; ini->cols[B] = 4;
    ini->filas[C] = 1; ini->cols[C] = 3;

    return ini;
}

int coste (unsigned op)
{
    return 1;
}

int testObjetivo(tEstado *estado)
{
    return iguales(estado,estadoObjetivo());
}

tEstado* estadoObjetivo()
{
    tEstado* fin = (tEstado*) malloc (sizeof(tEstado));
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fin->celdas[i][j] = estado_final[i][j];
        }
    }
    fin->filas[A] = 4; fin->cols[A] = 1;
    fin->filas[B] = 5; fin->cols[B] = 3;
    fin->filas[C] = 4; fin->cols[C] = 5;

    return fin;
}

int iguales(tEstado* actual,tEstado* final)
{
    return actual->filas[A] == final->filas[A] &&
           actual->cols[A] == final->cols[A] &&
           actual->filas[B] == final->filas[B] && 
           actual->cols[B] == final->cols[B] &&
           actual->filas[C] == final->filas[C] && 
           actual->cols[C] == final->cols[C];
}

int esValido(unsigned op, tEstado*s)
{
    switch (op)
    {
    case ARRIBA_A:
            if(s->filas[A]-2 >= 0)
                return s->celdas[s->filas[A]-1][s->cols[A]-1] == 0 && 
                s->celdas[s->filas[A]-1][s->cols[A]+1] == 0 &&
                s->celdas[s->filas[A]-2][s->cols[A]] == 0;
            else
                return 0;
        break;
    case ABAJO_A:
            if(s->filas[A]+2 < N)
                return s->celdas[s->filas[A]+1][s->cols[A]-1] == 0 && 
                s->celdas[s->filas[A]+1][s->cols[A]+1] == 0 &&
                s->celdas[s->filas[A]+2][s->cols[A]] == 0;
            else
                return 0;        
        break;
    case DERECHA_A:
            if(s->cols[A+2] < N)
                return s->celdas[s->filas[A]-1][s->cols[A]+1] == 0 && 
                s->celdas[s->filas[A]+1][s->cols[A]+1] == 0 &&
                s->celdas[s->filas[A]][s->cols[A]+2] == 0;
            else
                return 0;
        break;
    case IZQUIERDA_A:
            if(s->cols[A]-2 >= 0)
                return s->celdas[s->filas[A]-1][s->cols[A]-1] == 0 && 
                s->celdas[s->filas[A]+1][s->cols[A]-1] == 0 &&
                s->celdas[s->filas[A]][s->cols[A]-2] == 0;
            else
                return 0;
        break;
    case ARRIBA_B:
            if(s->filas[B]-2 >= 0)
                return s->celdas[s->filas[B]-1][s->cols[B]-1] == 0 && 
                s->celdas[s->filas[B]-1][s->cols[B]+1] == 0 &&
                s->celdas[s->filas[A]-2][s->cols[A]] == 0;
            else
                return 0;
        break;
    case ABAJO_B:
            if(s->filas[B]+1 < N)
                return s->celdas[s->filas[B]+1][s->cols[B]-1] == 0 && 
                s->celdas[s->filas[B]+1][s->cols[B]] == 0 &&
                s->celdas[s->filas[B]+1][s->cols[B]+1] == 0;
            else
                return 0;
        break;
    case DERECHA_B:
            if(s->cols[B] + 2 < N)
                return s->celdas[s->filas[B]-1][s->cols[B]+1] == 0 && 
                s->celdas[s->filas[B]][s->cols[B]+2] == 0;
            else
                return 0;
        break;
    case IZQUIERDA_B:
            if(s->cols[B] - 2 >= 0)
                return s->celdas[s->filas[B]-1][s->cols[B]-1] == 0 && 
                s->celdas[s->filas[B]][s->cols[B]-2] == 0;
            else
                return 0;
        break;
    case ARRIBA_C:
            if(s->filas[C] - 2 >= 0)
                return s->celdas[s->filas[C]-2][s->cols[C]] == 0;
            else
                return 0;
        break;
    case ABAJO_C:
            if(s->filas[C] + 2 >= 0)
                return s->celdas[s->filas[C]+2][s->cols[C]] == 0;
            else
                return 0;
        break;
    case DERECHA_C:
            if(s->cols[C] + 1 < N)
                return s->celdas[s->filas[C]-1][s->cols[C]+1] == 0 &&
                       s->celdas[s->filas[C]][s->cols[C]+1] == 0 && 
                       s->celdas[s->filas[C]+1][s->cols[C]+1] == 0;
            else
                return 0;
        break;
    case IZQUIERDA_C:
            if(s->cols[C] - 1 >= 0)
                return s->celdas[s->filas[C]-1][s->cols[C]-1] == 0 &&
                       s->celdas[s->filas[C]][s->cols[C]-1] == 0 && 
                       s->celdas[s->filas[C]+1][s->cols[C]-1] == 0;
            else
                return 0;
        break;
    default:
        printf("ERROR, No se conoce dicho movimiento\n");
        break;
    }
}

tEstado *aplicaOperador(unsigned op,tEstado *s)
{

    tEstado* t = (tEstado*) malloc (sizeof(tEstado));
    switch (op)
    {
    case ARRIBA_A:
            //Dejamos libres celdas
            t->celdas[t->filas[A]+1][t->cols[A]] = 0; t->celdas[t->filas[A]][t->cols[A]-1] = 0; t->celdas[t->filas[A]][t->cols[A]+1] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[A]-1][t->cols[A]-1] = A; t->celdas[t->filas[A]-1][t->cols[A]+1] = A; t->celdas[t->filas[A]-2][t->cols[A]] = A;
            //Cambiamos representante
            t->filas[A] = t->filas[A] - 1; 
        break;
    case ABAJO_A:
            //Dejamos libres celdas
            t->celdas[t->filas[A]-1][t->cols[A]] = 0; t->celdas[t->filas[A]][t->cols[A]-1] = 0; t->celdas[t->filas[A]][t->cols[A]+1] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[A]+1][t->cols[A]-1] =A; t->celdas[t->filas[A]+1][t->cols[A]+1] = A; t->celdas[t->filas[A]+2][t->cols[A]] = A;
            //Cambiamos representante
            t->filas[A] = t->filas[A] + 1; 
        break;
    case DERECHA_A:
            //Dejamos libres celdas
            t->celdas[t->filas[A]][t->cols[A]-1] = 0; t->celdas[t->filas[A]-1][t->cols[A]] = 0; t->celdas[t->filas[A]+1][t->cols[A]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[A]-1][t->cols[A]+1] = A; t->celdas[t->filas[A]+1][t->cols[A]+1] = A; t->celdas[t->filas[A]][t->cols[A]+2] = A;
            //Cambiamos representante
            t->cols[A] = t->cols[A] + 1;
        break;
    case IZQUIERDA_A:
            //Dejamos libres celdas
            t->celdas[t->filas[A]][t->cols[A]+1] = 0; t->celdas[t->filas[A]-1][t->cols[A]] = 0; t->celdas[t->filas[A]+1][t->cols[A]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[A]-1][t->cols[A]-1] = A; t->celdas[t->filas[A]+1][t->cols[A]-1] = A;  t->celdas[t->filas[A]][t->cols[A]-2] = A;
            //Cambiamos representante
            t->cols[A] = t->cols[A] - 1;
        break;
    case ARRIBA_B:
            //Dejamos libres celdas
            t->celdas[t->filas[B]][t->cols[B]-1] = 0; t->celdas[t->filas[B]][t->cols[B]] = 0; t->celdas[t->filas[B]][t->cols[B]+1] = 0; 
            //Ocupamos nuevas celdas
            t->celdas[t->filas[B]-1][t->cols[B]-1] = B; t->celdas[t->filas[B]-1][t->cols[B]+1] = B; t->celdas[t->filas[A]-2][t->cols[A]] = B;
            //Cambiamos representante
            t->filas[B] = t->filas[B] - 1;
        break;
    case ABAJO_B:
            //Dejamos libres celdas
            t->celdas[t->filas[B]][t->cols[B]-1] = 0; t->celdas[t->filas[B]][t->cols[B]+1] = 0; t->celdas[t->filas[B]-1][t->cols[B]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[B]+1][t->cols[B]-1] = B; t->celdas[t->filas[B]+1][t->cols[B]] = B; t->celdas[t->filas[B]+1][t->cols[B]+1] = B;
            //Cambiamos representante
            t->filas[B] = t->filas[B] + 1;
        break;
    case DERECHA_B:
            //Dejamos libres celdas
            t->celdas[t->filas[B]][t->cols[B]-1] = 0; t->celdas[t->filas[B]-1][t->cols[B]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[B]-1][t->cols[B]+1] = B; t->celdas[t->filas[B]][t->cols[B]+2] = B;
            //Cambiamos representante
            t->cols[B] = t->cols[B] + 1;
        break;
    case IZQUIERDA_B:
            //Dejamos libres celdas
            t->celdas[t->filas[B]][t->cols[B]+1] = 0; t->celdas[t->filas[B]-1][t->cols[B]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[B]-1][t->cols[B]-1] = B; t->celdas[t->filas[B]][t->cols[B]-2] = B;
            //Cambiamos representante
            t->cols[B] = t->cols[B] - 1;
        break;
    case ARRIBA_C:
            //Dejamos libres celdas
            t->celdas[t->filas[C]+1][t->cols[C]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[C]-2][t->cols[C]] = C;
            //Cambiamos representante
            t->filas[C] = t->filas[C] - 1;
        break;
    case ABAJO_C:
            //Dejamos libres celdas
            t->celdas[t->filas[C]-1][t->cols[C]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[C]+2][t->cols[C]] = C;
            //Cambiamos representante
            t->filas[C] = t->filas[C] + 1;
        break;
    case DERECHA_C:
            //Dejamos libres celdas
            t->celdas[t->filas[C]-1][t->cols[C]] = 0; t->celdas[t->filas[C]][t->cols[C]] = 0; t->celdas[t->filas[C]+1][t->cols[C]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[C]-1][t->cols[C]+1] = C; t->celdas[t->filas[C]][t->cols[C]+1] = C; t->celdas[t->filas[C]+1][t->cols[C]+1] = C;
            //Cambiamos representante
            t->cols[C] = t->cols[C] + 1;
        break;
    case IZQUIERDA_C:
            //Dejamos libres celdas
            t->celdas[t->filas[C]-1][t->cols[C]] = 0; t->celdas[t->filas[C]][t->cols[C]] = 0; t->celdas[t->filas[C]+1][t->cols[C]] = 0;
            //Ocupamos nuevas celdas
            t->celdas[t->filas[C]-1][t->cols[C]-1] = C; t->celdas[t->filas[C]][t->cols[C]-1] = C; t->celdas[t->filas[C]+1][t->cols[C]-1] = C;
            //Cambiamos representante
            t->cols[C] = t->cols[C] - 1;
        break;
    default:
        printf("ERROR, No se conoce dicho movimiento\n");
        break;
    }
}

void dispEstado(tEstado* s)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(s->celdas[i][j] == A)
                printf("a ");
            if(s->celdas[i][j] == B)
                printf("b ");
            if(s->celdas[i][j] == C)
            {
                printf("c ");
            }
            if(s->celdas[i][j] == -1)
            {
                printf("o ");
            }
            if(s->celdas[i][j] == 0)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void dispOperador(unsigned op)
{
    switch(op)
    {
        case ARRIBA_A:
            printf("Moviendo la ficha A hacia arriba\n");
        break;
        case ABAJO_A:
            printf("Moviendo la ficha A hacia abajo\n");
        break;
        case DERECHA_A:
            printf("Moviendo la ficha A hacia derecha\n");
        break;
        case IZQUIERDA_A:
            printf("Moviendo la ficha A hacia izquierda\n");
        break;
        case ARRIBA_B:
            printf("Moviendo la ficha B hacia arriba\n");
        break;
        case ABAJO_B:
            printf("Moviendo la ficha B hacia abajo\n");
        break;
        case DERECHA_B:
            printf("Moviendo la ficha B hacia derecha\n");
        break;
        case IZQUIERDA_B:
            printf("Moviendo la ficha B hacia izquierda\n");
        break;
        case ARRIBA_C:
            printf("Moviendo la ficha C hacia arriba\n");
        break;
        case ABAJO_C:
            printf("Moviendo la ficha C hacia abajo\n");
        break;
        case DERECHA_C:
            printf("Moviendo la ficha C hacia derecha\n");
        break;
        case IZQUIERDA_C:
            printf("Moviendo la ficha C hacia izquierda\n");
        break;
    }
}