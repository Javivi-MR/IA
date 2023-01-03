/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/* Busquedas mejoradas por Fco. Javier MR  */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include "puzleAlum.c"
//#include "listaia.c"
//#include "busqueda.h"
#include "ordenarLista.c"

int repetido(tNodo* Actual,LISTA Cerrados)
{
    LISTA aux = (LISTA ) malloc(sizeof(LISTA)+2); //Puntero a ListaNodos
    int flag = 0;
    aux->next = Cerrados; //el puntero siguiente de aux es el prinicipio de la lista cerrados
    tNodo* repe = (tNodo*) malloc (sizeof(tNodo));
    if (!esVacia(Cerrados)) //Si hay algo que buscar en cerrados
    {
        while (aux->next!= NULL && flag == 0) //si el puntero siguiente de aux es NO nulo y flag es 0 
        {
            aux = aux->next;    //Aux es igual al puntero siguiente de aux (piensa en la primera iteracion, aux se convierte en el principio de la lista cerrados)
            ExtraerPrimero(aux,repe,sizeof(tNodo)); //extraemos el primer nodo que encontremos en aux (Aux es igual al puntero siguiente de aux (piensa en la primera iteracion, extraemos la primera posicion de la lista cerrados y lo guardamos en el nodo repe)
            if(iguales(Actual->estado,repe->estado)) //si repe y actual son iguales 
                flag = 1;   //EL ESTADO ES REPETIDO!!
        }
        
    }
    return flag;    //Returnea 1 si es Repetido y 0 si no :)
}


//añadido p6
int maximo (int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}



void solucionFin(int res){
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}
void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}
void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo ra�z. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   inicial->valHeuristica = HeuristicaPiezasMalColocadas(inicial->estado);
   return inicial;
}

LISTA expandir(tNodo *nodo){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
        if (esValido(op,nodo->estado))
        {
            s=calloc(1,sizeof(tEstado));
            s=aplicaOperador(op,nodo->estado);
            nuevo->estado=s;
            nuevo->padre=nodo;
            nuevo->operador=op;
            nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
            nuevo->profundidad=nodo->profundidad+1;
            nuevo->valHeuristica = HeuristicaPiezasMalColocadas(nuevo->estado);
            InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

int busqueda(){
    int objetivo=0, visitados=0, maximoNodosAbiertos = 0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados=VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        visitados++;
        if (!objetivo && !repetido(Actual,Cerrados))
        {   
            Sucesores = expandir(Actual);
            /*Abiertos=Concatenar(Abiertos,Sucesores); //PARA ANCHURA ABIERTOS,SUCESORES | PARA PROFUNDIDAD SUCESORES,ABIERTOS*/
            Abiertos = ordenarLista(Abiertos,Sucesores,1); //1 para a* 0 para voraz
            maximoNodosAbiertos = maximo(maximoNodosAbiertos,numElementos(Abiertos)); //añadido p6
            InsertarPrimero(&Cerrados,Actual,sizeof(tNodo));
        }
   }
   
    printf("\nVisitados= %d\n", visitados);
    printf("Maximo Nodos Abiertos= %d\n", maximoNodosAbiertos);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//PROFUNDIDAD LIMITADA
// l es el limite de profundidad a poder visitar y d la profundidad optima donde se encuentra la solucion 
//-> ademas: es Incompleta cuando l<d y No es óptima si l>d
int busquedaLimitadas(int l){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados=VACIA;

    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo && !repetido(Actual,Cerrados) && Actual->profundidad < l) //No dejamos expandir los nodos con profundidad l o mayor de l (ej l = 3 se expanden y comprueban los nodos de prof 2 y solo se comprueban los de prof 3)
        {   
            visitados++;
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Sucesores,Abiertos); 
            InsertarPrimero(&Cerrados,Actual,sizeof(tNodo));
        }
   }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//------------------------------------------------------------------------------------

