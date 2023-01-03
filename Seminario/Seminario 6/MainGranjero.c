#include "Granjero.c"

int main()
{
    int op = 1;
    tEstado* ini = estadoInicial();
    while(op != 0 && !testObjetivo(ini))
    {
        dispEstado(ini);
        printf("INTRODUCE UN MOVIMIENTO: (1: mover granjero de orilla | 2: mover granjero y lobo de orilla | 3. mover granjero y cabra de orilla | 4. mover granjero y lechuga de orilla : ");
        scanf("%i",&op);    
        if(esValido(op,ini))
        {

            ini = aplicaOperador(op,ini);
        }
        else
        {
            printf("OPERACION NO VALIDA, INTENTE OTRA\n");
        }
    }
    if(testObjetivo(ini))
    {
        printf("FELICIDADES GANASTE\n");
        dispEstado(ini);
    }
    if(op == 0)
    {
        printf("ADIOS\n");
    }
}