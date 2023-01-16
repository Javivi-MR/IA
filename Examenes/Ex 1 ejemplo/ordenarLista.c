/**********************************************************************************/
/* 		    ordenarLista y funciones auxilia          **/
/*						                              **/
/* Asignatura: Inteligencia Artificial                **/
/* Grado en Ingenieria Informatica - UCA              **/
/**********************************************************************************/

#include "busqueda.h"
#include "listaia.c"


int comparaV (tNodo *e, tNodo *nuevo){
    return (e->valHeuristica < nuevo->valHeuristica);
}
int comparaA (tNodo *e, tNodo *nuevo){
    return (e->valHeuristica + e->costeCamino < nuevo->valHeuristica + nuevo->costeCamino);
}

int (*menor[])(tNodo *, tNodo*)={comparaV, comparaA};

LISTA insertarOrdenado(LISTA c, tNodo *n, int tipo){
    LISTA res=VACIA;
    tNodo *naux=calloc(1,sizeof(tNodo));
    if (esVacia(c)){
        InsertarUltimo(&res,(tNodo*) n,sizeof(tNodo));}
    else{
        ExtraerPrimero(c,naux,sizeof(tNodo));
        while ((menor[tipo](naux,n)) && (c!=NULL)) {
            InsertarUltimo(&res,(tNodo*) naux,sizeof(tNodo));
            c=c->next;
            if (!(esVacia(c)))
                ExtraerPrimero(c,naux,sizeof(tNodo));
        }//while
        InsertarUltimo(&res,(tNodo*) n,sizeof(tNodo));
        if (!esVacia(c))
            res=Concatenar(res,c);
    }//else
    return res;
}


LISTA ordenarLista(LISTA Ab, LISTA q, int tipo){
/* Ab es una lista de nodos que está Vacía o está ORDENADA */
/* q es una lista de nodos (la lista de Sucesores) */
/* tipo 0 para Voraz y tipo 1 para A estrella */
/* Insercion ordenada de nodos sucesores en la lista ordenada Ab */
/* Devuelve Ab, lista de nodos ordenados en función del tipo de búsqueda */

    tNodo *n=calloc(1,sizeof(tNodo));
    while (!esVacia(q)){
        
        ExtraerPrimero(q,n,sizeof(tNodo));
        Ab=insertarOrdenado(Ab,n,tipo);
        q=q->next;
    }
    return(Ab);
}//ordenarLista