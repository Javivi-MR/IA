#include "jarras.c"
#include <stdio.h>

int main()
{
    int op = 1;
    tEstado *s;
    s = estadoInicial();
    printf("Partimos desde este estado: \n");
    dispEstado(s);
    while(!testObjetivo(s) && op != 0)
    {
        printf("\n\nSelecciona un movimiento: \n  1.(llenar 3)\n  2.(llenar 4)\n  3.(vaciar 3)\n  4.(vaciar 4)\n  5.(pasar3a4)\n  6.(pasar4a3)\n  0.(acabar)\nseleccion: ");
        scanf("%i",&op);
        if(op != 0)
        {
            if(esValido(op,s))
            {
                printf("\n\nOperacion Realizada con Exito!\n");
                s = aplicaOperador(op,s);
                dispMovimiento(op);
                
                dispEstado(s);
            }
            else
            {
                printf("\n\nMovimiento no valido, Intentelo de nuevo\n");
            }
        }
        if(testObjetivo(s))
        {
            printf("\n FELICIDADES, GANASTE EL JUEGO :)");
        }
    }
    return 0;
}