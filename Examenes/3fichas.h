#define N 3

#define B 1
#define Ne -1
#define V 0

#define B1A 0
#define B1D 1
#define B1I 2
#define B2A 3
#define B2D 4
#define B2I 5
#define B3A 6
#define B3D 7
#define B3I 8

typedef struct
{
    int celdas[N][N];
    int blancas[N][2];
    int negras[N][2];
}tNodo;

int esValida(tNodo* t,int jugada ,int jugador)
{
    switch(jugada)
    {
        case B1A:
        if(t->blancas[0][0] < 2)
            return jugador == B && t->celdas[t->blancas[0][0]+1][t->blancas[0][1]] == V;
        else
            return 0;
        break;

        case B1D:
        if(t->blancas[0][0] < 2 && t->blancas[0][1] < 2)
            return jugador == B && t->celdas[t->blancas[0][0]+1][t->blancas[0][1]+1] == Ne;
        else
            return 0;
        break;
    }
}