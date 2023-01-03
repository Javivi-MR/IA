#define N 9
#define NUM_OPERADORES 2
#define DERECHA 1
#define IZQUIERDA 2

typedef struct
{
    int banca[N];
    int izquierda;
    int derercha;
    int banco,ladrones;
}tEstado;

tEstado *estadoInicial();
int coste (unsigned op,tEstado* s);

int testObjetivo(tEstado *estado);
int iguales(tEstado* actual,tEstado* final);

int esValido(unsigned op, tEstado*s);
tEstado *aplicaOperador(unsigned op,tEstado *s);

static int banca_inicial [N] = {4,3,2,5,7,1,8,6,9};