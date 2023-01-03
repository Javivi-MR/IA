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
tNodo* poda_ab(tNodo *t);
int valorMin_ab(tNodo *t, int prof, int alfa, int beta);
int valorMax_ab(tNodo *t, int prof, int alfa, int beta);