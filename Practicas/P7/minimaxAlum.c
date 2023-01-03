/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.c"
#include "minimaxAlum.h"



tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < 9; ++i){
      if (esValida(t,i)) {
            intento=aplicaJugada(t,1,i); //Intenta jugada
            temp =terminal(intento); // Calcula el valor minimax
            if(temp > puntos) {
              puntos = temp;
              mejorJugada = i;
            }
      }}//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

tNodo* minimax(tNodo* t, int jugador)
{
      int max,max_actual,jugada,mejorjugadam,i;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo*));
      //<--------------------Inicio-------------------->
      max = -10000;
      printf("\n Mi turno: \n");
      for(i = 0; i < N; i++)
      {
            if(esValida(t,i))
            {
                  intento = aplicaJugada(t,1,i);
                  max_actual = valorMin(intento,-1);
                  if(max_actual > max)
                  {
                        max = max_actual;
                        jugada = i;
                  }
            }
      }
      intento = aplicaJugada(t,1,jugada);
      return intento;
}

int minimo(int a, int b)
{
      if(a <= b)
      {
            return a;
      }
      else
      {
            return b;
      }
}


int valorMin(tNodo* t,int jugador)
{
      int valor_min,jugada,aux,i;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo*));
      //<--------------------Inicio-------------------->
      if(terminal(t) || lleno(t))
      {
            valor_min = terminal(t);
      }
      else
      {
            valor_min = 10000;
            for(i = 0; i < N; i++)
            {
                  if(esValida(t,i))
                  {
                        intento = aplicaJugada(t,-1,i);
                        aux = valorMax(intento,1);
                        valor_min = minimo(valor_min,aux);
                  }
            }
      }
      return valor_min;
}

int maximo(int a, int b)
{
      if(a >= b)
      {
            return a;
      }
      else
      {
            return b;
      }
}



int valorMax(tNodo* t,int jugador)
{
      int valor_max,jugada,aux,i;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo*));
      //<--------------------Inicio-------------------->
      if(terminal(t)|| lleno(t))
      {
            valor_max = terminal(t);
      }
      else
      {
            valor_max = -10000;
            for(i = 0; i < N; i++)
            {
                  if(esValida(t,i))
                  {
                        intento = aplicaJugada(t,1,i);
                        aux = valorMin(intento,-1);
                        valor_max = maximo(valor_max,aux);
                  }
            }
      }
      return valor_max;
}