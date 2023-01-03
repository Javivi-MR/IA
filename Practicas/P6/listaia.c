/*******************************************/
/*             LISTAIA .C                  */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaia.h"

int esVacia( LISTA c){
    return (c==VACIA);
}//esVacia

void InsertarPrimero(LISTA *c, void *n, int size){
    LISTA p=(LISTA ) malloc(sizeof(LISTA)+size);
    memcpy((void *)p->nodo,(void*)n, size);
    p->next=(*c);
    *c=p;
}//InsertarPrimero


void ExtraerPrimero(LISTA c, void *n, int size){
    memcpy((void *) n, (void *) c->nodo,size);
}//Extraer primer elemento


void EliminarPrimero(LISTA *c){
    LISTA p;
    p=*c;
    *c=p->next;
    free(p);
}//Eliminar primer elemento de la lista

void InsertarUltimo(LISTA *c, void *n, int size){
    LISTA p=malloc(sizeof(LISTA)+size);
    LISTA aux=VACIA;
    //creando el nodo
    memcpy((void*)(p->nodo),(void *) n, size);
    p->next=NULL;
    if (esVacia(*c)){
        *c=p;
    }
    else{
        aux=*c;
        while (aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=p;
    }
}//InsertarUltimo

LISTA Concatenar(LISTA c,LISTA p){
    LISTA aux;
    if (esVacia(c))
        c= p;
    else {
        aux=c;
        while (aux->next!= NULL) {
            aux = aux->next;
        }
        aux->next=p;
    }
    return c;
}//Concatenar

//AÑADIDA P6
int numElementos (LISTA c)
{
    int cont = 0;
    while (c != NULL) //si el puntero siguiente de aux es NO nulo y flag es 0 
    {
        c = c->next;    //Aux es igual al puntero siguiente de aux (piensa en la primera iteracion, aux se convierte en el principio de la lista cerrados)
        cont++;
    }

    return cont;    //Returnea 1 si es Repetido y 0 si no :)
}