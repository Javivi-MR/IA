#define MAX 1
#define MIN -1
#define VACIA 0
#define N 3

typedef struct
{
    int tablero[N][N];
}tNodo;

typedef struct
{
    int fila,col;
}tJugada;


tNodo* nodoInicial();

tNodo* aplicaJugada(tNodo* actual, int jugador, tJugada jugada);

int esValida(tNodo* actual,tJugada jugada);

int terminal(tNodo* actual);

void dispNodo(tNodo* actual);
int opuesto(int jugador);
int heuristica(tNodo* actual);
int heuristicaux(tNodo* actual);