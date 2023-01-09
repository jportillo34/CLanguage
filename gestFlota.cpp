/************************************
* NOMBRE: #Jose Rafael#
* PRIMER APELLIDO: #Portillo#
* SEGUNDO APELLIDO: #Lugo#
* DNI: #Y7489057H#
* EMAIL: #jportillo89@alumno.uned.es#
*************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "puerto.h"
#include "buque.h"


/* ----------------------------------------------------------------------------- *
 * Programa: GestFlota - Gestiona los Movimientos de una Flota                   *
 *                                                                               *
 * Comentarios: - Se asume que los Puertos y Buques existen durante la ejecucion *
 *                del programa. No hace uso del almacenamiento en disco.         *
 *                                                                               *
 *              - Este programa utiliza el procedimiento system() para ejecutar  *
 *                el comando "cls" de MSDOS para limpiar la pantalla.            *
 * ----------------------------------------------------------------------------- */
int main() {
   Puertos gestPuertos;   /* Lista de puertos simulados. */
   flota   gestFlota;     /* Flota de buques simulada. */
   char    resp;


   /* Inicializa la lista de puertos y la flota de buques. */
   gestPuertos.iniciaListaPuertos();
   gestFlota.iniciaFlota();

   /* Muestra el menu de opciones y consulta al usuario. */
   do {
      resp = ' ';

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
         case 'P': gestPuertos.editaPuerto();           /* Edicion de Puerto. */
                   break;
         case 'B': gestFlota.editaBuque(gestPuertos);   /* Edicion de Buque. */
                   break;
         case 'E': gestFlota.estadoBuques(gestPuertos); /* Estado de buques. */
                   break;
         case 'O': gestFlota.operaBuque(gestPuertos);   /* Operar Buque. */
                   break;
         case 'R': gestFlota.resumenBuque(gestPuertos); /* Resumen mensual para un Buque. */
                   break;
         case 'S': return 0;                            /* Termina el programa. */
                   break;
      }
   }while(resp != 'S');
}
