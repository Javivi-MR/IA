// <--------------------------------------------- A -------------------------------------------->

#define A 1 //Representacion pieza A
#define B 2 //Representacion pieza B
#define C 3 //Representacion pieza C
#define O -1 //Representacion DE OBSTACULO

#define N 6 //Tam puzle

#define NUM_OPERADORES 12 //NUMERO DE OPERADORES
//DEFINICION DE OPERADORES
#define ARRIBA_A 1
#define ABAJO_A 2
#define DERECHA_A 3
#define IZQUIERDA_A 4
#define ARRIBA_B 5
#define ABAJO_B 6
#define DERECHA_B 7
#define IZQUIERDA_B 8
#define ARRIBA_C 9
#define ABAJO_C 10
#define DERECHA_C 11
#define IZQUIERDA_C 12

typedef struct
{
    int tablero[N][N];
    int filas[4]; // 1 para A etc..
    int cols[4]; // 1 para A etc..
}tEstado;

tEstado* estadoInicial(); //devolvera el estado inicial
tEstado* estadoOjetivo(); //devolvera el estado final

int testObjetivo(tEstado* t); //devuelve 0 si no es obj y 1 sisi
int iguales(tEstado* actual, tEstado* final); //devuelve 0 si los dos estados son iguales y 1 sisi

int esValido(unsigned op, tEstado* t); //devuelve 0 si la op no es valida y 1 sisi
tEstado* aplicarOperador(unsigned op, tEstado* t); //devuelve el estado nuevo

void dispEstado(tEstado* t);
void dispOperador(unsigned op);
int coste(unsigned op, tEstado* t);

static int estado_inicial[N][N] = 
{
    {O,0,0,C,0,0},
    {O,0,0,C,0,0},
    {0,A,0,C,0,0},
    {A,A,A,O,B,0},
    {0,A,0,B,B,B},
    {0,0,0,0,0,0}
};

static int estado_final[N][N] = 
{
    {O,0,0,0,0,0},
    {O,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,A,0,O,0,C},
    {A,A,A,B,0,C},
    {0,A,B,B,B,C}
};