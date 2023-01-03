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


tNodo* poda_ab(tNodo *t) 
{
      int max_actual,jugada = 0,mejor_jugada,prof,v,alfa,beta;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo));
      alfa = MENOSINFINITO; beta = MASINFINITO; prof = 0;
      while(jugada < N)
      {
            if(esValida(t,jugada))
            {
                  intento = aplicaJugada(t,MAX,jugada);
                  v = valorMin_ab(intento, prof +1, alfa, beta);
                  if(v > alfa)
                  {
                        alfa = v;
                        mejor_jugada = jugada;
                  }
            }
            jugada++;
      }
      t = aplicaJugada(t,MAX,mejor_jugada);
      return t;
}

int valorMin_ab(tNodo *t, int prof, int alfa, int beta)
{
      int vmin, jugada = 0;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo));
      if(terminal(t))
      {
            vmin = terminal(t);
      }
      else
      {
            if(prof == LIMITE)
            {
                  vmin = heuristica(t);
            }
            else
            {
                  while(jugada < N && alfa < beta)
                  {
                        if(esValida(t,jugada))
                        {
                              intento = aplicaJugada(t,MIN,jugada);
                              beta = minimo(beta,valorMax_ab(intento,prof+1,alfa,beta));

                        }
                        jugada++;
                  }
                  vmin = beta;
            }
      }
      return vmin;
}

int valorMax_ab(tNodo *t, int prof, int alfa, int beta)
{
      int vmax, jugada = 0;
      tNodo* intento = (tNodo*) malloc (sizeof(tNodo));
      if(terminal(t))
      {
            vmax = terminal(t);
      }
      else
      {
            if(prof == LIMITE)
            {
                  vmax = heuristica(t);
            }
            else
            {
                  while(jugada < N && alfa < beta)
                  {
                        if(esValida(t,jugada))
                        {
                              intento = aplicaJugada(t,MAX,jugada);
                              alfa = maximo(alfa,valorMin_ab(intento,prof+1,alfa,beta));
                        }
                        jugada++;
                  }
                  vmax = alfa;
            }
      }
      return vmax;
}