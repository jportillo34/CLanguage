#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "puerto.h"
#include "buque.h"


/* ===================== DEFINICION DE PROCEDIMIENTOS Y FUNCIONES ===================== */
/* Realiza el alta de una Operacion para un Buque especifico. */
void asignaOperacion(int inId, tipoCarga inCrg, int inPi, int inPd, int inDc, int inDt, int inDd, int inDi, int inMi, int inAi, int inDf, int inMf, int inAf, buque & inBuque) {
   int indiceOp;


   indiceOp = inBuque.cntOper;                      /* Toma e incrementa el contador de operaciones del Buque. */

   inBuque.oprdelBuque[indiceOp].carga = inCrg;     /* Asigna el tipo de Carga. */
   inBuque.oprdelBuque[indiceOp].puertoI = inPi;    /* Asigna el Puerto de Inicio. */
   inBuque.oprdelBuque[indiceOp].puertoD = inPd;    /* Asigna el Puerto destino. */
   inBuque.oprdelBuque[indiceOp].duraC   = inDc;    /* Asigna duracion de la carga en dias. */
   inBuque.oprdelBuque[indiceOp].duraT   = inDt;    /* Asigna duracion del traslado en dias. */
   inBuque.oprdelBuque[indiceOp].duraD   = inDd;    /* Asigna duracion de la descarga en dias. */
   inBuque.oprdelBuque[indiceOp].diaI    = inDi;    /* Asigna dia de inicio de Operacion. */
   inBuque.oprdelBuque[indiceOp].mesI    = inMi;    /* Asigna mes de inicio de Operacion. */
   inBuque.oprdelBuque[indiceOp].anoI    = inAi;    /* Asigna anno de inicio de Operacion. */
   inBuque.oprdelBuque[indiceOp].diaF    = inDf;    /* Asigna dia fin de Operacion. */
   inBuque.oprdelBuque[indiceOp].mesF    = inMf;    /* Asigna mes fin de Operacion. */
   inBuque.oprdelBuque[indiceOp].anoF    = inAf;    /* Asigna anno fin de Operacion. */

   inBuque.cntOper++;
}

/* Realiza el alta de un Buque en el sistema de gestion. */
void asignaBuque(idBuque inId, nomBuq inNom, int inDi, int inMi, int inAi, int inPi, buque & inBuque) {
   inBuque.id = inId;   /* Asigna Id del Buque. */

   strcpy(inBuque.nomB, "                   ");
   strncpy(inBuque.nomB, inNom, 19);   /* Asigna el nombre del Buque. */

   inBuque.fId = inDi;   /* Dia de inicio en el sistema. */
   inBuque.fIm = inMi;   /* Mes de inicio en el sistema. */
   inBuque.fIa = inAi;   /* Anno de inicio en el sistema. */
   inBuque.pIid = inPi;  /* ID del Puerto inicial (al dar de alta al Buque o al finalizar una Operacion.  */
}

/* Procedimiento para inicializar la flota de buques. */
void iniciaFlota(buques & lista) {
   nomBuq nomIni = "                   ";

   for(int i = 0; i < numBuques; i++) {
      asignaBuque(X, nomIni, 0, 0, 0, 0, lista[i]);

      lista[i].cntOper = 0;   /* Inicializa el contador de operaciones del Buque. */

      /* Inicializa el vector de operaciones del buque. */
      for(int j = 0; j < maxOperaciones; j++) {
         asignaOperacion(lista[i].id, vacio, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, lista[i]);
      }

      lista[i].cntOper = 0;   /* Inicializa el contador de operaciones del Buque. */
   }

   /* carga inicial de buques para las pruebas. */
   strcpy(nomIni, "CARGUERO DEL NORTE ");
   asignaBuque(A, nomIni, 1, 1, 2022, 1, lista[0]);
   asignaOperacion(A, fuel, 1, 3, 1, 0, 0, 0, 0, 0, 1, 1, 2022, lista[0]);

   strcpy(nomIni, "BEATRIZ UNO        ");
   asignaBuque(B, nomIni, 10, 5, 2022, 1, lista[1]);
   asignaOperacion(B, gasolina, 2, 4, 0, 0, 0, 0, 0, 0, 10, 5, 2022, lista[1]);

   strcpy(nomIni, "SOUTH OIL TANKER   ");
   asignaBuque(C, nomIni, 2, 11, 2022, 1, lista[2]);
   asignaOperacion(C, crudo, 4, 1, 0, 3, 0, 0, 0, 0, 26, 12, 2022, lista[2]);
}

/* Procedimiento de tratamiento de la opcion "Editar Buque". */
void editaBuque(puertos listPuertos, buques & lista) {
   idBuque    idB = A;
   char       idBq;
   nomBuq     nombre = "                   ";
   char       resp = ' ';
   int        diaIni;
   int        mesIni;
   int        anoIni;
   int        puertoI;

   system("cls");
   printf("Editar Buque:\n\n");

   /* Lee el Id del Buque. */
   fflush(stdin);
   printf("       Identificador(letra entre A y E)?");
   idBq = toupper(getchar());
   fflush(stdin);
   //getchar(); /* Para consumir el caracter nueva linea que deja scanf en el buffer. */

   /* Lee el nombre del Buque. */
   printf("       Nombre(entre 1 y 20 caracteres)?");
   scanf("%19[^\n]s", nombre);
   //fgets(nombre, longNbuque, stdin);
   fflush(stdin);
   //while((getchar()) != '\n') {};
   //nombre[strcspn(nombre, "\n")] = 0; /* Elimina el caracter '\n' que deja el ENTER del usuario */

   /* Lee Fecha inicio: Dia. */
   printf("       Fecha inicio: Dia?");
   scanf("%d", &diaIni);
   fflush(stdin);
   //while((getchar()) != '\n') {};

   /* Lee Fecha inicio: Mes. */
   printf("       Fecha inicio: Mes?");
   scanf("%d", &mesIni);
   fflush(stdin);
   //while((getchar()) != '\n') {};

   /* Lee Fecha inicio: Anno. */
   printf("       Fecha inicio: Anno?");
   scanf("%d", &anoIni);
   fflush(stdin);
   //while((getchar()) != '\n') {};

   /* Lee el Puerto de Inicio. */
   printf("Puertos posibles para la ubicacion inicial del buque:\n");

   /* Muestra la lista de puertos disponibles. */
   for(int k = 0; k < numPuertos; k++) {
      if(listPuertos[k].id != 0) {
         printf("     %d-", listPuertos[k].id);
         //printf("%19s   ", listPuertos[k].nomP);

         for(int x = 0; x < longNpuerto; x++) {
           printf("%c", listPuertos[k].nomP[x]);
         }

         printf("   Tipo: ");
         switch(listPuertos[k].tipo) {
            case yacimiento: printf("Yacimiento");
                             break;
            case refineria:  printf("Refineria");
                             break;
            case deposito:   printf("Deposito");
                             break;
            case sinAsignacion: printf("sinAsignacion");
                                break;
         }
         printf("\n");
      }
   }
   printf("Identificador de puerto inicio?");
   scanf("%d", &puertoI);
   while((getchar()) != '\n') {};


   /* Limpia la pantalla y consulta al usuario. */
   while(resp != 'S' && resp != 'N') {
      system("cls");
      printf("\n\nId....: %c\n", idBq);
      printf("Nombre: %s\n", nombre);
      printf("Dia Inicio: %d\n", diaIni);
      printf("Mes Inicio: %d\n", mesIni);
      printf("Anno Inicio: %d\n", anoIni);
      printf("Puerto inicio: %d\n", puertoI);
      printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.\n");
      printf("Son correctos los nuevos datos(S/N)?");
      resp = toupper(getchar());
   }

   if(resp == 'S') {
      switch(idBq) {
         case 'A': idB = A;
                   break;
         case 'B': idB = B;
                   break;
         case 'C': idB = C;
                   break;
         case 'D': idB = D;
                   break;
         case 'E': idB = E;
                   break;
      }

      /* Asigna el Buque usando los datos leidos. */
      asignaBuque(idB, nombre, diaIni, mesIni, anoIni, puertoI-1, lista[idB]);

/*DEBUG - OJO ELIMINAR LA SIGUIENTE SENTENCIA!!!!! */
      asignaOperacion(C, gasolina, 1, 3, 0, 3, 0, 0, 0, 0, 04, 11, 1967, lista[idB]);
/* DEBUG */

/* DEBUG */
      for(int k = 0; k < numBuques; k++) {
         printf("Id: %d,   ", lista[k].id);
         printf("Nombre: %s,   ", lista[k].nomB);
         printf("Fecha Inicio: %d-%d-%d,   ", lista[k].fId, lista[k].fIm, lista[k].fIa);
         printf("Puerto Inicio: %d", lista[k].pIid);
         printf("\n");
      }
/*DEBUG - Muestra la lista de puertos.*/


      getchar();
      fflush(stdin);
      getchar();
   }
}

/* Procedimiento de tratamiento de la opcion "Operar Buque". */
void operaBuque(buques & lista) {
}

/* Procedimiento de tratamiento de la opcion "Estado Buque". */
void estadobuques(puertos listaPuertos, buques & lista) {
   char       idBq = ' ';
   nomBuq     nombre = "                   ";
   int        diaFin;
   int        mesFin;
   int        anoFin;
   int        ultOper;
   int        puertoAct;
   nomPrt     nomPrtAct = "                   ";
   tipoCarga  cargadBuque;
   nomCarga   nombreCarga = "        ";


   system("cls");
   printf("                       ESTADO DE BUQUES\n\n");
   printf("* - Ultimo Puerto visitado por el Buque.\n\n");
   printf("ID NOMBRE              PUERTO(*)           ULTIMA FEC CARGA   \n");
   printf("-- ------------------- ------------------- ---------- --------\n");

   /* Itera a traves de la lista de buques de la flota. Toma la ultima Operacion registrada. */
   for(int i = 0; i < numBuques; i++) {
      if(lista[i].id != X) {
         /* Toma el ID del Buque. */
         switch(lista[i].id) {
            case A: idBq = 'A';
                    break;
            case B: idBq = 'B';
                    break;
            case C: idBq = 'C';
                    break;
            case D: idBq = 'D';
                    break;
            case E: idBq = 'E';
                    break;
            case X: break;
         }

         /* Toma el nombre del Buque. */
         strncpy(nombre, lista[i].nomB, 19);

         /* Toma el ultimo Puerto visitado (Puerto inicial de la ultima Operacion. */
         ultOper = 0;
         ultOper = lista[i].cntOper - 1;

         /* Toma la fecha fin de la Operacion. */
         diaFin = lista[i].oprdelBuque[ultOper].diaF;
         mesFin = lista[i].oprdelBuque[ultOper].mesF;
         anoFin = lista[i].oprdelBuque[ultOper].anoF;

         /* Toma la Carga del Buque durante la Operacion. */
         cargadBuque = lista[i].oprdelBuque[ultOper].carga;

         switch(cargadBuque) {
            case 0: strcpy(nombreCarga, "crudo   ");
                    break;
            case 1: strcpy(nombreCarga, "fuel    ");
                    break;
            case 2: strcpy(nombreCarga, "gasoil  ");
                    break;
            case 3: strcpy(nombreCarga, "gasolina");
                    break;
            case 4: strcpy(nombreCarga, "vacio   ");
                    break;
         }

         /* Toma el ultimo Puerto visitado por el Buque. */
         puertoAct = lista[i].oprdelBuque[ultOper].puertoI - 1;
         strcpy(nomPrtAct, "                   ");
         strncpy(nomPrtAct, listaPuertos[puertoAct].nomP, 19);

         /* Imprime registro con el estado del Buque. */
         printf("%2c %19s %16s %02d/%02d/%4d %s\n", idBq, nombre, nomPrtAct, diaFin, mesFin, anoFin, nombreCarga);
      }
   }

   fflush(stdin);
   getchar();
}
/* ===================== DEFINICION DE PROCEDIMIENTOS Y FUNCIONES ===================== */
