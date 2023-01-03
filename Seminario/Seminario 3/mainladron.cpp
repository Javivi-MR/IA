#include "ladron.c"

int main()
{
    tEstado* s = estadoInicial();
    int i = 1;
    dispEstado(s);
    for(i = 1; i < NUM_OPERADORES + 1 ; i++)
    {
        if(esValido(i,s))
        {
            s = aplicaOperador(i,s);
        }
        dispEstado(s);
    }
    return 0;
}