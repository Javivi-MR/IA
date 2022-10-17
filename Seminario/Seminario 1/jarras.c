#include "jarras.h"
#include <stdlib.h>
#include <string.h>

tEstado* estadoInicial()
{
    tEstado* estado = (tEstado*) malloc (sizeof(tEstado));
    estado->jarra3 = 0;
    estado->jarra4 = 0;
    return estado;
}

int testObjetivo(tEstado* t)
{
    return t->jarra4 == 2;
}

int esValido(unsigned op,tEstado* t)
{
    switch(op)
    {
        case llenar3:
            return t->jarra3 == 0;
            break;
        case llenar4:
            return t->jarra4 == 0;
            break;
        case vaciar3:
            return t->jarra3 > 0;
            break;
        case vaciar4:
            return t->jarra4 > 0;
            break;
        case pasar3a4:
            return t->jarra3 > 0 && t->jarra4 < 4;
            break;
        case pasar4a3:
            return t->jarra4 > 0 && t->jarra3 < 3;
            break;
        default:
            printf("ERROR FATAL, Operador desconocido");
            break;
    }
}

tEstado *aplicaOperador(unsigned op, tEstado *s)
{
    tEstado *t = (tEstado*) malloc (sizeof(tEstado));
    memcpy(t,s,sizeof(tEstado));
    switch(op)
    {
        case llenar3:
            t->jarra3 = 3;
            break;
        case llenar4:
            t->jarra4 = 4;
            break;
        case vaciar3:
            t->jarra3 = 0;
            break;
        case vaciar4:
            t->jarra4 = 0;
            break;
        case pasar3a4:
            while(t->jarra3 > 0 && t->jarra4 < 4)
            {
                t->jarra3--;
                t->jarra4++;
                
            }
            break;
        case pasar4a3:
            while(t->jarra4 > 0 && t->jarra3 < 3)
            {
                t->jarra4--;
                t->jarra3++;
            }
            break;
        default:
            printf("ERROR FATAL, Operador desconocido");
            break;
    }
    return t;
}

void dispEstado(tEstado* t)
{
    printf("Estado actual: \n");
    printf("Jarra 3 : %i litros\n",t->jarra3);
    printf("Jarra 4 : %i litros\n",t->jarra4);
}

void dispMovimiento(unsigned op)
{
    switch (op)
    {
    case llenar3:
        printf("Has llenado la jarra 3 completamente\n");
        break;
    case llenar4:
        printf("Has llenado la jarra 4 completamente\n");
        break;
    case vaciar3:
        printf("Has vaciado la jarra 3 completamente\n");
        break;
    case vaciar4:
        printf("Has vaciado la jarra 4 completamente\n");
        break;
    case pasar3a4:
        printf("Vas a pasar todo lo que puedas de la jarra 3 hacia la 4\n");
        break;        
    case pasar4a3:
        printf("Vas a pasar todo lo que puedas de la jarra 4 hacia la 3\n");
        break;   
    default:
        break;
    }
}