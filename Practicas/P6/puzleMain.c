#include "listaia.c"

int main() {
    LISTA a = VACIA;
    int b = 3;
    int* c = &b;
    InsertarPrimero(&a,c,sizeof(int*));
    *c = 2;
    InsertarPrimero(&a,c,sizeof(int));
    *c = 1;
    InsertarPrimero(&a,c,sizeof(int));
    
    printf("%i ", numElementos(a));


    return 0; 
}