#include "puzle3piezas.c"

int main()
{
    int i;
    tEstado* s = (tEstado*) malloc (sizeof(tEstado));
    s = estadoInicial();
    for(i = 1; i <= NUM_OPERADORES ; i++)
    {
        if(esValido(i,s))
        {
            s = aplicaOperador(i,s);
            dispOperador(i);
            dispEstado(s);
        }
    }
    return 0;
}