#define MAX 1
#define MIN -1
#define MESA 0
#define CARTAS 12
#define PALOS 2
#define ORO 0
#define BASTOS 1


typedef struct
{
    int juego[CARTAS][PALOS];
    int cart_MAX, cart_MIN;
}tNodo;

typedef struct 
{
    int carta,palo;
}tJugada;

int esValida();
tNodo* aplicaJugada();
int terminal();
int utilidad();