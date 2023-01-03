#define NUM_OPERADORES 4
#define GRANJ 1
#define LOBO 2
#define CABRA 3
#define LECH 4
#define IZQ 1
#define DER -1

typedef struct 
{
    int orilla[NUM_OPERADORES];
}tEstado;

tEstado *estadoInicial();
int coste (unsigned op,tEstado *s);

int testObjetivo(tEstado *estado);
tEstado* estadoObjetivo();
int iguales(tEstado* actual,tEstado* final);

int esValido(unsigned op, tEstado*s);
tEstado *aplicaOperador(unsigned op,tEstado *s);

void dispEstado(tEstado* s);
int PiezasMalColocadas(tEstado* s); //distancia de hamming