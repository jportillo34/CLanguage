#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "puerto.h"
#include "buque.h"

/* ----------------------------------------------------------------------------- *
 * Programa: GestFlota - Gestiona los Movimientos de una Flota                   *
 *                                                                               *
 * Comentarios: - Se asume que los Puertos y Buques existen durante la ejecucion *
 *                del programa. No se hace uso del almacenamiento en disco.      *
 *                                                                               *
 *              - Este programa utiliza el procedimiento system() para ejecutar  *
 *                el comando "cls" de MSDOS para limpiar la pantalla.            *
 * ----------------------------------------------------------------------------- */
int main() {
   puertos listaPuertos;   /* Lista de puertos disponibles. */
   buques  flota;          /* Flota de buques disponibles. */
   char    resp = ' ';     /* Opcion seleccionada por el usuario. */


   /* Inicializa la lista de puertos y la flota de buques. */
   iniciaListaPuertos(listaPuertos);
   iniciaFlota(flota);

   /* Limpia la pantalla y consulta al usuario. */
   while(resp != 'S') {
      /* Muestra menu principal de GestFlota. */
      system("cls");
      printf("\n\nGestFlota: Gestion de Movimientos de una Flota\n");
      printf("==============================================\n\n");
      printf("       Editar Puerto                      (Pulsar P)\n");
      printf("       Editar Buque                       (Pulsar B)\n");
      printf("       Estado Buques                      (Pulsar E)\n");
      printf("       Operar Buque                       (Pulsar O)\n");
      printf("       Resumen Mensual Buque              (Pulsar R)\n");
      printf("       Salir                              (Pulsar S)\n\n");
      printf("Teclear una opcion valida (P|B|E|O|R|S)?");

      /* Lee y procesa la opcion elegida por el usuario. */
      resp = toupper(getchar());

      switch(resp) {
         case 'P': editaPuerto(listaPuertos);         /* Edicion de Puerto. */
                   break;
         case 'B': editaBuque(listaPuertos, flota);   /* Edicion de Buque. */
                   break;
         case 'E': estadobuques(listaPuertos, flota); /* Estado de buques. */
                   break;
         case 'S': return 0;                          /* Termina el programa. */
                   break;
      }

      resp = ' ';
   }
}
