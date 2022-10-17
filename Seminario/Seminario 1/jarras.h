#include <stdio.h>
#define NUM_OPERADORES 6
#define llenar3 1
#define llenar4 2
#define vaciar3 3
#define vaciar4 4
#define pasar3a4 5
#define pasar4a3 6

typedef struct
{
    int jarra4;
    int jarra3;
}tEstado;

int esValido(unsigned op, tEstado *estado);
tEstado *aplicaOperador(unsigned op, tEstado *s);
int testObjetivo(tEstado *estado);
void dispEstado(tEstado* t);
void dispMovimiento(unsigned op);