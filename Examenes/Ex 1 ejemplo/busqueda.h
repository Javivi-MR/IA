/*******************************************/
/* 		    BUSQUEDA.H                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include "coche.c"

#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif

int busqueda(void);
void solucionFin(int res);
