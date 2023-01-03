/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

tNodo *jugadaAdversario(tNodo *t);
tNodo *PSEUDOminimax(tNodo *Nodo);
tNodo* minimax(tNodo* t, int jugador);
int minimo(int a, int b);
int valorMin(tNodo* t,int jugador);
int maximo(int a, int b);
int valorMax(tNodo* t,int jugador);