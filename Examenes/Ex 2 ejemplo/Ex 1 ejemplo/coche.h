#define NUM_OPERADORES 14
#define abatir2 1
#define abatir3 2
#define abatir4 3
#define abatir5 4
#define abatir6 5
#define desabatir2 6
#define desabatir3 7
#define desabatir4 8
#define desabatir5 9
#define desabatir6 10
#define desplazar1 11
#define desplazar2 12
#define desdesplazar1 13 
#define desdesplazar2 14

#define normal 1
#define abatido 2
#define desplazado 3

typedef struct
{
    int asientos[6];
}tEstado;

tEstado* estadoInicial();
tEstado* estodoFinal();
int iguales(tEstado* actual,tEstado* final);

int esValido(unsigned op, tEstado* t);
tEstado* aplicaOperador(unsigned op, tEstado* t);

int coste(unsigned op, tEstado* t);
int heuristica(tEstado* t);

void dispEstado(tEstado* t);
void dispOperador(unsigned op);