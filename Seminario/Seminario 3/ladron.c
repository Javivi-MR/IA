#include "ladron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vacio(int banca[N])
{
    int i,aux = 1;
    for(i = 0; i < N ; i++)
    {
        if(banca[i] != 0)
        {
            aux = 0;
        }
    }
    return aux;
}

int coste (unsigned op,tEstado* s)
{
    return 1;
}

tEstado* estadoInicial()
{
    int i = 0;
    tEstado* nuevo = (tEstado*) malloc (sizeof(tEstado));
    nuevo->banco = 0;
    nuevo->ladrones = 0;
    for(i = 0; i < N ; i++)
    {
        nuevo->banca[i] = banca_inicial[i];
    }
    nuevo->derercha = N-1;
    nuevo->izquierda = 0;
    return nuevo;
}

int testObjetivo(tEstado *estado)
{
    return estado->ladrones > estado->banco && estado->derercha == estado->izquierda;
}

int esValido(unsigned op, tEstado* estado)
{
    return estado->derercha != estado->izquierda;
}

tEstado *aplicaOperador(unsigned op,tEstado *s)
{
    int aux;
    tEstado* t = (tEstado*) malloc (sizeof(tEstado));

    memcpy(t,s,sizeof(tEstado));

    if(op == IZQUIERDA)
    {
        t->ladrones += t->banca[t->izquierda];
        t->banco += t->banca[t->derercha];
        t->banca[t->izquierda] = 0;
        t->banca[t->derercha] = 0;
        t->derercha -= 1;
        
        t->izquierda += 1;
    }
    else
    {
        t->ladrones += t->banca[t->derercha];
        t->banca[t->derercha] = 0;
        if(t->derercha > 0)
        {
        t->derercha -= 1;
        }
        t->banco += t->banca[t->derercha];
        t->banca[t->derercha] = 0;
        t->derercha -= 1;
        
    }
    if(t->derercha < 0)
    {
        t->derercha = 0;
    }
    if(vacio(t->banca))
    {
        t->derercha = 0;
        t->izquierda = 0;
    }
    return t;
}

void dispEstado(tEstado* s)
{
    int i = 0;

    printf("------------Estado actual------------\n");
    printf("Total Ladrones: %i\n",s->ladrones);
    printf("Total Banco: %i\n",s->banco);
    printf("Estado actual de la banca: [");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", s->banca[i]);
    }
    printf("]\n");
}

void dispOperdador(tEstado* s);