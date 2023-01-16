#define N1 6
#define N2 5

#define O 1
#define S 2
#define vacia 0


#define MAX 0
#define MIN 1

typedef struct
{
    int tablero[N1][N2];
    int vacias;
    int puntuacion[2];
}tNodo;

typedef struct
{
    int letra;
    int fila,col;
}tJugada;

static int matini[N1][N2] = 
{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

tNodo* crearEstado(int m[N1][N2]);