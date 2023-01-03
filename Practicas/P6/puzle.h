#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4

#define NUM_OPERADORES 4

#define N 3

typedef struct 
{
    int celdas[N][N];
    int fila, col;
} tEstado;

tEstado *estadoInicial();
int coste (unsigned op,tEstado *s);

int testObjetivo(tEstado *estado);
tEstado* estadoObjetivo();
int iguales(tEstado* actual,tEstado* final);

int esValido(unsigned op, tEstado*s);
tEstado *aplicaOperador(unsigned op,tEstado *s);

void dispEstado(tEstado* s);
int numPiezasMalColocadas(tEstado* s);

static int puzle_inicial [N][N] = 
{
    {1,3,0},
    {6,2,4},
    {8,7,5} 
};

static int puzle_final [N][N] =
{
    {1,2,3},
    {8,0,4},
    {7,6,5}
};