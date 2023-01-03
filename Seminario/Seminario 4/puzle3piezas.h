#define N 6
#define NUM_OPERADORES 12
#define A 1
#define B 2
#define C 3

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
    int celdas[N][N];
    int filas[4];
    int cols[4];
}tEstado;

static int estado_inicial[N][N] =
{
    {-1,0,0,C,0,0},
    {-1,0,0,C,0,0},
    {0,A,0,C,0,0},
    {A,A,A,-1,B,0},
    {0,A,0,B,B,B},
    {0,0,0,0,0,0}
};

static int estado_final[N][N] =
{
    {-1,0,0,0,0,0},
    {-1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,A,0,-1,0,C},
    {A,A,A,B,0,C},
    {0,A,B,B,B,C}
};

tEstado *estadoInicial();
int coste (unsigned op);

int testObjetivo(tEstado *estado);
tEstado* estadoObjetivo();
int iguales(tEstado* actual,tEstado* final);

int esValido(unsigned op, tEstado*s);
tEstado *aplicaOperador(unsigned op,tEstado *s);

void dispEstado(tEstado* s);
void dispOperador(unsigned op);