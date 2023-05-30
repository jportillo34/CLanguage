
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "puerto.h"
#include "buque.h"


void ayudaGestFlota() {
   system("cls");
   printf("GestFlota - AYUDA DEL SISTEMA\n");
   printf("=============================\n\n");
   printf("- Esta aplicacion utiliza el comando MS-DOS cls.\n\n");
   printf("- La aplicacion utiliza los TAD: Puerto, Buque y Calendario, cada uno con\n");
   printf("  sus procedimientos, funciones y propiedades.\n\n");
   printf("- La opcion Operar Buque administra la secuencia de eventos, desde la Carga\n");
   printf("  del Buque hasta su arribo a Puerto destino.\n\n");
   printf("- Esta aplicacion no simula un sistema de puertos y buques. No utiliza el tiempo\n");
   printf("  del sistema operativo. El cambio de estado de un Buque se hace a traves de la\n");
   printf("  opcion Operar Buque, la cual se diseno para asegurar la secuencia de estados:\n");
   printf("  carga-traslado-descarga o solo traslado, registrando la fecha de la ultima\n");
   printf("  Operacion como fecha Inicio Operacion + duracion en dias. \n\n");
   printf("- La aplicacion fue configurada para que cada Operacion nueva tenga una fecha\n");
   printf("  posterior a la fecha de la ultima Operacion del Buque.\n\n");
   printf("- Al no existir instruccion (dentro del lenguaje C mas menos) para colocar\n");
   printf("  el cursor en un punto especifico de la pantalla, el sistema no valida algunas\n");
   printf("  entradas del usuario para corregir. Para compensar esto, el sistema ofrece \n");
   printf("  una serie de advertencias y ayudas al usuario.\n\n");
   printf("- Un Buque vacio puede trasladarse a cualquier puerto, incluso pudiera\n");
   printf("  viajar entre puertos estando vacio.\n");
   printf("\nPresione ENTER para regresar al menu GestFlota...");
   fflush(stdin);
   getchar();
}

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
      printf("       Ayuda de la Aplicacion             (Pulsar A)\n");
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
         case 'A': ayudaGestFlota();                    /* Muestra la ayuda del sistema. */
                   break;
         case 'S': return 0;                            /* Termina el programa. */
                   break;
      }
   }while(resp != 'S');
}
