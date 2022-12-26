#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "puerto.h"

/* ===================== DEFINICION DE PROCEDIMIENTOS Y FUNCIONES ===================== */
/* Realiza el registro de un Puerto en el sistema de gestion. */
void asignaPuerto(int inId, nomPrt inNom, tipoPuerto inTipo, puerto & inPuerto) {
   inPuerto.id = inId; /* Asigna el ID del Puerto. */

   for(int j = 0; j < longNpuerto; j++) {
      /* Asigna nombre del puerto. */
      inPuerto.nomP[j] = inNom[j];
   }

   inPuerto.tipo = inTipo;   /* Asigna el tipo de Puerto. */
}

/* Procedimiento para inicializar la lista de puertos. */
void iniciaListaPuertos(puertos & lista) {
   nomPrt nomIni = "                   ";

   for(int i = 0; i < numPuertos; i++) {
      asignaPuerto(0, nomIni, sinAsignacion, lista[i]);
   }

   /* carga inicial de puertos para las pruebas. */
   strcpy(nomIni, "VILLAGARCIA DE AROSA");
   asignaPuerto(1, nomIni, deposito, lista[0]);

   strcpy(nomIni, "LONXA DE CARRIL     ");
   asignaPuerto(2, nomIni, deposito, lista[1]);

   strcpy(nomIni, "AMUAY               ");
   asignaPuerto(3, nomIni, refineria, lista[2]);

   strcpy(nomIni, "POZO VIEJO          ");
   asignaPuerto(4, nomIni, yacimiento, lista[3]);
}

/* Procedimiento de tratamiento de la opcion "Editar Puerto". */
void editaPuerto(puertos & lista) {
   int        idPuerto = 0;
   nomPrt     nombre = "                   ";
   char       tipoOpc;
   tipoPuerto tipo = sinAsignacion;
   char       resp = ' ';

   system("cls");
   printf("Editar Puerto:\n\n");

   /* Lee el Id del Puerto. */
   printf("       Identificador(numero entre 1 y 10)?");
   scanf("%d", &idPuerto);
   fflush(stdin);
   //getchar(); /* Para consumir el caracter nueva linea que deja scanf en el buffer. */
   // while((getchar()) != '\n') {};

   /* Lee el nombre del Puerto. */
   printf("       Nombre(entre 1 y 20 caracteres)?");
   scanf("%[^\n]s", nombre);
   fflush(stdin);
   // fgets(nombre, longNpuerto, stdin);
   //while((getchar()) != '\n') {};
   //nombre[strcspn(nombre, "\n")] = 0; /* Elimina el caracter '\n' que deja el ENTER del usuario */

   /* Lee el tipo del Puerto. */
   printf("       Tipo(Y-Yacimiento, R-Refineria, D-deposito)?");
   tipoOpc = toupper(getchar());

   /* Limpia la pantalla y consulta al usuario. */
   while(resp != 'S' && resp != 'N') {
      system("cls");
      printf("Id....: %d\n", idPuerto);
      printf("Nombre: %s\n", nombre);

/*PRUEBA
      printf("Nombre: ");
      for(int x = 0; x < longNpuerto; x++) {
         printf("%c", nombre[x]);
      }
      printf("XX\n");
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
 E  S  T  E     E  S     U  N     P  U  E  R  T  O     G  R  ANDE
45 53 54 45 20 45 53 20 55 4e 20 50 55 45 52 54 4f 20 47 52

 A  M  U  A  Y
41 4d 55 41 59 02 02 02 02 02 02 02 02 02 02 02 02 02 00

 B  E  A  T  R  I  Z     U  N  O
42 45 41 54 52 49 5a 20 55 4e 4f 02 02 02 02 02 02 02 00

 B  E  A  T  R  I  Z     B
42 45 41 54 52 49 5a 20 42 00 00 00 00 00 0

 B  E  A  T  R  I  Z     B
42 45 41 54 52 49 5a 20 42 02 02 02 02 02 02 02 02 02 00

 B  E  A  T  R  I  Z     B  y  y  y  y  y  y  y  y  yXX
42 45 41 54 52 49 5a 20 42 02 02 02 02 02 02 02 02 02 00


Nombre: BEATRIZ B         XX
Nombre: 4245415452495a204202020202020202020200
Nombre: LA CASA DEL ORO   XX
Nombre: 4c4120434153412044454c204f524f02020200
Nombre: AMUAY             XX
Nombre: 414d5541590202020202020202020202020200


Id: 1,   Nombre: AMUAY             ,   Tipo: Deposito
Id: 2,   Nombre: BEATRIZ B         ,   Tipo: Deposito
Id: 3,   Nombre: LA CASA DEL ORO   ,   Tipo: Refineria


 A  A  A  A  A  A ES NL NL NL NL NL NL
41 41 41 41 41 41 20 00 00 00 00 00 00  0                   -->  6 + ESP
41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 --> 20
41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 20  0 --> 18 + ESP
41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 41 20 --> 19 + ESP
41 41 41 41 41 41 41 41 41 41 00 00 00 00 00 -----------------> 10
41 41 41 41 41 41 41 41 00 00 00 00 00 00 -------------------->  8

      printf("Nombre: ");
      for(int x = 0; x < longNpuerto; x++) {
        printf("%x", nombre[x]);
      }
      printf("\n");
*/
/*PRUEBA*/


      printf("Tipo..: %c", tipoOpc);
      printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.\n");
      printf("Son correctos los nuevos datos(S/N)?");
      resp = toupper(getchar());
      fflush(stdin);
   }

   if(resp == 'S') {
      /* Tipo de Puerto. */
      switch(tipoOpc) {
         case 'Y': tipo = yacimiento;
                   break;
         case 'R': tipo = refineria;
                   break;
         case 'D': tipo = deposito;
                   break;
      }

      /* Asigna el Puerto usando los datos leidos. */
      asignaPuerto(idPuerto, nombre, tipo, lista[idPuerto-1]);


/*DEBUG - Muestra la lista de puertos.*/
      for(int k = 0; k < numPuertos; k++) {
         printf("Id: %d,   ", lista[k].id);

         printf("Nombre: ");
         for(int x = 0; x < longNpuerto; x++) {
            printf("%c", lista[k].nomP[x]);
         }

         printf(",   Tipo: ");
         switch(lista[k].tipo) {
            case yacimiento: printf("Yacimiento");
                             break;
            case refineria:  printf("Refineria");
                             break;
            case deposito:   printf("Deposito");
                             break;
            default:         printf("SinAsignacion");
         }
         printf("\n");
      }
/*DEBUG - Muestra la lista de puertos.*/

      getchar();
   }
}
/* ===================== DEFINICION DE PROCEDIMIENTOS Y FUNCIONES ===================== */
