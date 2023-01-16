// <------------------------------------> solo para que funcione <------------------------------------>
#include "busqueda.h"
#define VACIA NULL

typedef struct ListaNodos {
    struct ListaNodos *next;
    int nodo[];
    
}ListaNodos;

typedef struct ListaNodos *LISTA;
int repetido(tNodo* Actual,LISTA Cerrados);
void solucionFin(int res);
void dispNodo(tNodo *nodo);
void dispCamino(tNodo *nodo);
void dispSolucion(tNodo *nodo);
tNodo *nodoInicial();
LISTA expandir(tNodo *nodo);
int busqueda();
void InsertarPrimero(LISTA *c, void *n, int size);
int esVacia( LISTA c);
void ExtraerPrimero(LISTA c, void *n, int size);
void EliminarPrimero(LISTA *c);
void InsertarUltimo(LISTA *c, void *n, int size);
LISTA Concatenar(LISTA c,LISTA p);
// <------------------------------------> solo para que funcione <------------------------------------>



int busqueda()
{
    int objetivo = 0, visitados = 0;
    tNodo* actual = (tNodo*) calloc (1,sizeof(tNodo));
    tNodo* Inicial = nodoInicial();

    LISTA abiertos = VACIA;
    LISTA sucesores = VACIA;
    LISTA cerrados = VACIA;

    InsertarPrimero(&abiertos,(tNodo*)Inicial,sizeof(tNodo));

    while(!esVacia(abiertos) && !objetivo) 
    {
        actual = (tNodo*) calloc (1,sizeof(tNodo));
        ExtraerPrimero(abiertos,actual,sizeof(tNodo));
        EliminarPrimero(&abiertos);
        objetivo = testObjetivo(actual->estado);
        if(!objetivo && !repetido(actual,cerrados))
        {
            sucesores = expandir(actual);
            Concatenar(abiertos,sucesores);
            insertarPrimero(&cerrados,actual,sizeof(tNodo));
        } 
    }

    if(objetivo)
    {
        dispSolucion(actual);
    }

    //...disp extras
    
    return objetivo;
}

LISTA expandir(tNodo* actual)
{
    int i;
    LISTA sucesores = VACIA;
    tNodo* t = (tNodo*) malloc (sizeof(tNodo));
    tEstado* s = (tEstado*) malloc(sizeof(tEstado));
    for(i = 1 ; i <= NUM_OPERADORES ; i++)
    {
        if(esValido(i,actual->estado))
        {
            s = aplicaOperador(i,actual->estado);
            t->padre = actual;
            t->estado = s;
            t->profundidad = actual->padre + 1;
            t->operador = i;
            t->costeCamino = coste(i,actual->estado);
            t->valHeuristica = HeuristicaPiezasMalColocadas(s);
            InsertarUltimo(&sucesores,(tNodo*) t,sizeof(tNodo));
        }
    }
    return sucesores;
}