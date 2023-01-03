#include "puzleAlum.c"

int main() {
    int op = 1;
    tEstado *n,*a;
    a=estadoInicial();
    while(op != 0)
    {
        printf("La situacion del puzle es la siguiente: \n");
        dispEstado(a);
        printf("operacion a hacer (1: Arriba | 2: Abajo | 3: Izquierda | 4: Derecha | 0: salir ): ");
        scanf("%i",&op);
        if(op != 0)
        {
            if(esValido(op,a))
            {
                printf("Movimiento valido!! \n \n");
                a = aplicaOperador(op,a);
                dispOperador(op);
            }
            else
            {
                printf("Movimiento NO valido!! El puzle se queda igual \n \n");
            }
        }
        else
        {
            printf("Hasta la proxima!");
        }
    }


    return 0; 
}