#include "coche.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tEstado* estadoInicial()
{
    tEstado* t = (tEstado*)malloc(sizeof(tEstado));
    t->asientos[0] = desplazado;
    t->asientos[1] = desplazado;
    t->asientos[2] = normal;
    t->asientos[3] = normal;
    t->asientos[4] = abatido;
    t->asientos[5] = abatido;

    return t;
}


tEstado* estadoFinal()
{
    tEstado* t = (tEstado*)malloc(sizeof(tEstado));
    t->asientos[0] = normal;
    t->asientos[1] = normal;
    t->asientos[2] = abatido;
    t->asientos[3] = abatido;
    t->asientos[4] = normal;
    t->asientos[5] = normal;

    return t;
}

int testObjetivo(tEstado* actual)
{
    return iguales(actual,estadoFinal());
}

int iguales(tEstado* actual,tEstado* final)
{
    int sol = 1; 
    for(int i = 0 ; i < 6 ; i++)
    {
        if(actual->asientos[i] != final->asientos[i])
            sol =0;
    }
    return sol;
}

int esValido(unsigned op, tEstado* t)
{
    switch(op)
    {
        case abatir2:
            return t->asientos[3] == abatido && t->asientos[1] == normal;
        break;

        case abatir3: 
            return t->asientos[2] == normal && t->asientos[0] == normal;
        break;

        case abatir4: 
            return t->asientos[3] == normal && t->asientos[1] == normal;
        break;
        
        case abatir5: 
            return t->asientos[4] == normal;
        break;
        
        case abatir6:
            return t->asientos[5] == normal;
        break;

        case desabatir2:
            return t->asientos[1] == abatido;
        break;

        case desabatir3:
            return t->asientos[2] == abatido;
        break;

        case desabatir4:
            return t->asientos[3] == abatido && t->asientos[1] == normal;
        break;

        case desabatir5:
            return t->asientos[4] == abatido;
        break;

        case desabatir6:
            return t->asientos[5] == abatido;
        break;

        case desplazar1:
            return t->asientos[2] == normal && t->asientos[0] == normal;
        break;

        case desplazar2:
            return t->asientos[3] == normal && t->asientos[1] == normal;
        break;

        case desdesplazar1:
            return t->asientos[0] == desplazado && t->asientos[2] == normal;
        break;

        case desdesplazar2:
            return t->asientos[1] == desplazado && t->asientos[3] == normal;
        break;

        default:
            printf("ERROR, operador desconocido");
            return -1;
        break;
    }
}

tEstado* aplicaOperador(unsigned op, tEstado* t)
{
    tEstado* s = (tEstado*)malloc(sizeof(tEstado));
    memcpy(s,t,sizeof(tEstado));
    switch(op)
    {
        case abatir2:
            s->asientos[1] = abatido;
        break;

        case abatir3: 
            s->asientos[2] = abatido;
        break;

        case abatir4: 
            s->asientos[3] = abatido;
        break;
        
        case abatir5: 
            s->asientos[4] = abatido;
        break;
        
        case abatir6:
            s->asientos[5] = abatido;
        break;

        case desabatir2:
            s->asientos[1] = normal;
        break;

        case desabatir3:
            s->asientos[2] = normal;
        break;

        case desabatir4:
            s->asientos[3] = normal;
        break;

        case desabatir5:
            s->asientos[4] = normal;
        break;

        case desabatir6:
            s->asientos[5] = normal;
        break;

        case desplazar1:
            s->asientos[0] = desplazado;
        break;

        case desplazar2:
            s->asientos[1] = desplazado;
        break;

        case desdesplazar1:
            s->asientos[0] = normal;
        break;

        case desdesplazar2:
            s->asientos[1] = normal;
        break;

        default:
            printf("ERROR, operador desconocido");
        break;
    }
    return s;
}

int coste(unsigned op, tEstado* t)
{
    if(op == abatir2 || op == abatir3 || op == abatir4 || op == abatir5 || op == abatir6 || op == desabatir2 || op == desabatir3 || op == desabatir4 || op == desabatir5 || op == desabatir6)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int heuristica(tEstado* t)
{
    int i, total = 0;
    
    if(t->asientos[0] != normal)
    {
        total +=1;
    }
    if(t->asientos[1] != normal)
    {
        total +=3;
    }
    if(t->asientos[4] != normal)
    {
        total +=2;
    }
    if(t->asientos[5] != normal)
    {
        total +=2;
    }
    if(t->asientos[2] != abatido)
    {
        total +=2;
    }
    if(t->asientos[3] != abatido)
    {
        total +=2;
    }
    return total;
}

void dispEstado(tEstado* t)
{
    printf("--Frontal--\n");
    printf("%i      %i\n",t->asientos[0],t->asientos[1]);
    printf("--Medio--\n");
    printf("%i      %i\n",t->asientos[2],t->asientos[3]);
    printf("--Final--\n");
    printf("%i      %i\n",t->asientos[4],t->asientos[5]);
}

void dispOperador(unsigned op)
{
    switch(op)
        {
            case abatir2:
                printf("Abatiendo asiento 2");
            break;

            case abatir3: 
                printf("Abatiendo asiento 3");
            break;

            case abatir4: 
                printf("Abatiendo asiento 4");
            break;
            
            case abatir5: 
                printf("Abatiendo asiento 5");
            break;
            
            case abatir6:
                printf("Abatiendo asiento 6");
            break;

            case desabatir2:
                printf("Desbatiendo asiento 2");
            break;

            case desabatir3:
                printf("Desbatiendo asiento 3");
            break;

            case desabatir4:
                printf("Desbatiendo asiento 4");
            break;

            case desabatir5:
                printf("Desbatiendo asiento 5");
            break;

            case desabatir6:
                printf("Desbatiendo asiento 6");
            break;

            case desplazar1:
                printf("Desplazando asiento 1");
            break;

            case desplazar2:
                printf("Desplazando asiento 2");
            break;

            case desdesplazar1:
                printf("Desdesplazando asiento 1");
            break;

            case desdesplazar2:
                printf("Desdesplazando asiento 2");
            break;

            default:
                printf("ERROR, operador desconocido");
            break;
        }
}