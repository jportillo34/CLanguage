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
#include<string.h>
#include "puerto.h"
#include "buque.h"
#include "calendario.h"


/* ---------------------------------------------------------- *
 * Realiza el alta de una Operacion para un Buque especifico. *
 * Incrementa el contador de operaciones para el Buque.       *
 * Calcula Fecha Fin de Operacion.                            *
 *                                                            *
 * Parametros: - Carga                (de entrada)            *
 *             - Puerto inicio        (de entrada)            *
 *             - Puerto destino       (de entrada)            *
 *             - Duracion de Carga    (de entrada)            *
 *             - Duracion de Traslado (de entrada)            *
 *             - Duracion de Descarga (de entrada)            *
 *             - Dia inicio de Oper.  (de entrada)            *
 *             - Mes inicio de Oper.  (de entrada)            *
 *             - Anno inicio de Oper. (de entrada)            *
 *             - Status de Oper.      (de entrada)            *
 * ---------------------------------------------------------- */
void operacion::asignaOperacion(tipoCarga inCrg, int inPi, int inPd, int inDc, int inDt, int inDd, int inDi, int inMi, int inAi, int inStatus) {
   calendario calOpera;
   int        incr = 0;

   carga   = inCrg;   /* Asigna el tipo de Carga. */
   puertoI = inPi;    /* Asigna el Puerto de Inicio. */
   puertoD = inPd;    /* Asigna el Puerto destino. */
   duraC   = inDc;    /* Asigna duracion de la carga en dias. */
   duraT   = inDt;    /* Asigna duracion del traslado en dias. */
   duraD   = inDd;    /* Asigna duracion de la descarga en dias. */
   diaI    = inDi;    /* Asigna dia de inicio de Operacion. */
   mesI    = inMi;    /* Asigna mes de inicio de Operacion. */
   anoI    = inAi;    /* Asigna anno de inicio de Operacion. */

   /* Calcula la fecha fin de Operacion = Fecha Inicio + duracion de la Operacion. */
   if(duraC) {
      incr = duraC;
   }else if(duraT) {
      incr = duraT;
   }else if(duraD) {
      incr = duraD;
   }
   diaF    = diaI;    /* Asigna dia fin de Operacion. */
   mesF    = mesI;    /* Asigna mes fin de Operacion. */
   anoF    = anoI;    /* Asigna anno fin de Operacion. */
   /* Calcula el incremento (en dias). */
   calOpera.incrementaFecha(diaF, mesF, anoF, incr);
   status  = inStatus; /* Asigna status de Operacion: 1-->en curso, 0-->finalizada. */
}

/* ------------------------------------------------------ *
 * Realiza el alta de un Buque en el sistema de gestion.  *
 * Devuelve un elemento de tipo Buque.                    *
 *                                                        *
 * Parametros: - ID del Buque      (de entrada)           *
 *             - Nombre del Bque   (de entrada)           *
 *             - Dia Inicio        (de entrada)           *
 *             - Mes Inicio        (de entrada)           *
 *             - Anno Inicio       (de entrada)           *
 *             - Puerto inicio     (de entrada)           *
 * ------------------------------------------------------ */
void buque::asignaBuque(idBuque inId, nomBuq inNom, int inDi, int inMi, int inAi, int inPi) {
   id = inId;   /* Asigna Id del Buque. */

   strcpy(nomB, "                   ");
   strncpy(nomB, inNom, 19);   /* Asigna el nombre del Buque. */

   fId = inDi;   /* Dia de inicio en el sistema. */
   fIm = inMi;   /* Mes de inicio en el sistema. */
   fIa = inAi;   /* Anno de inicio en el sistema. */
   pIid = inPi;  /* ID del Puerto inicial (al dar de alta al Buque o al finalizar una Operacion.  */
}

/* Procedimiento de tratamiento de la opcion "Editar Buque". */
void flota::editaBuque(Puertos & listaPuertos) {
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

   /* Acepta (unicamente) id valido para el Buque. */
   if(idBq == 'A' || idBq == 'B' || idBq == 'C' || idBq == 'D' || idBq == 'E') {
     /* Lee el nombre del Buque. */
     printf("       Nombre(entre 1 y 20 caracteres)?");
     scanf("%19[^\n]s", nombre);
     fflush(stdin);

     /* Lee Fecha inicio: Dia. */
     printf("       Fecha inicio: Dia?");
     scanf("%d", &diaIni);
     fflush(stdin);

     /* Lee Fecha inicio: Mes. */
     printf("       Fecha inicio: Mes?");
     scanf("%d", &mesIni);
     fflush(stdin);

     /* Lee Fecha inicio: Anno. */
     printf("       Fecha inicio: Anno?");
     scanf("%d", &anoIni);
     fflush(stdin);

     /* Lee el Puerto de Inicio. */
     printf("Puertos posibles para la ubicacion inicial del buque:\n");

     /* Muestra la lista de puertos disponibles. */
     for(int k = 0; k < numPuertos; k++) {
        if(listaPuertos.lista[k].id != 0) {
           printf("     %d-", listaPuertos.lista[k].id);

           for(int x = 0; x < longNpuerto; x++) {
             printf("%c", listaPuertos.lista[k].nomP[x]);
           }

           printf("   Tipo: ");
           switch(listaPuertos.lista[k].tipo) {
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
        vectorBuques[idB].asignaBuque(idB, nombre, diaIni, mesIni, anoIni, puertoI);

        /* Inicializa el vector de operaciones del Buque. */
        for(int j = 0; j < maxOperaciones; j++) {
          vectorBuques[idB].oprdelBuque[j].asignaOperacion(vacio, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }

        vectorBuques[idB].cntOper = 0;

        vectorBuques[idB].oprdelBuque[0].asignaOperacion(vacio, puertoI, 0, 0, 0, 0, diaIni, mesIni, anoIni, 0);
        vectorBuques[idB].cntOper++;

/* DEBUG */
      //for(int k = 0; k < numBuques; k++) {
      //   printf("Id: %d,   ", vectorBuques[k].id);
      //   printf("Nombre: %s,   ", vectorBuques[k].nomB);
      //   printf("Fecha Inicio: %d-%d-%d,   ", vectorBuques[k].fId, vectorBuques[k].fIm, vectorBuques[k].fIa);
      //   printf("Puerto Inicio: %d", vectorBuques[k].pIid);
      //   printf("\n");
      //}
/*DEBUG - Muestra la lista de puertos.*/


        getchar();
        fflush(stdin);
        getchar();
   }
   }else {
      printf("\n\nERROR: Debe introducir un ID entre A y E. ENTER para regresar al menu...");
      fflush(stdin);
      getchar();
   }
}

/* Procedimiento de tratamiento de la opcion "Operar Buque".

   Comentarios:

1.- Buque VACIO y EN PUERTO
    1.0.- Mostrar menu de OPERACIONES posibles,

         ---------------------------------------------------------------
          Operar Buque

          Identificador del Buque(letra entre A y E)?C

          El buque XXXXXXX se encuentra vacio en YYYYYYYYYYYYYY, puede
          C.- CARGAR BUQUE
          T.- TRASLADAR BUQUE
          R.- REGRESAR AL MENU GestFlota

          Indique el tipo de Operacion?A
         ---------------------------------------------------------------

    1.1.- Puede CARGAR   (goto 2.-)

    NOTA: SI EL PUERTO ES UN YACIMIENTO, ENTONCES SOLO PUEDE CARGAR crudo
          SI EL PUERTO ES REFINERIA, ENTONCES PUEDE CARGAR fuel, gasoil o gasolina
          SI EL PUERTO ES DEPOSITO, ENTONCES PUEDE CARGAR fuel, gasoil o gasolina

    1.2.- Puede TRASLADAR (estando VACIO) a cualquier PUERTO   (goto 3.-)


2.- Buque CARGADO y EN PUERTO
    2.0.- Mostrar menu de OPERACIONES posibles,

         SI ultima Operacion fue CARGAR, entonces muestra el menu,

         ---------------------------------------------------------------
          Operar Buque

          Identificador del Buque(letra entre A y E)?C

          El buque XXXXXXX se encuentra en YYYYYYYY cargado con ZZZZ, puede
          T.- TRASLADAR BUQUE
          R.- REGRESAR AL MENU GestFlota

          Indique el tipo de Operacion?A
         ---------------------------------------------------------------

         SI ultima Operacion fue TRASLADO, entonces muestra el menu,

         ---------------------------------------------------------------
          Operar Buque

          Identificador del Buque(letra entre A y E)?C

          El buque XXXXXXX se encuentra en YYYYYYYY cargado con ZZZZ, puede
          D.- DESCARGAR BUQUE
          R.- REGRESAR AL MENU GestFlota

          Indique el tipo de Operacion?A
         ---------------------------------------------------------------


    2.1.- Crea registro nuevo indicando tipo de CARGA y duracion de la OPERACION (en dias)
    2.1.- Si OPERACION ANTERIOR fue CARGAR, entonces
    2.2.- Si OPERACION ANTERIOR fue TRASLADO, entonces puede DESCARGAR


3.- TRASLADAR Buque
    3.1.- Puede TRASLADAR a ciertos puertos (no incluido el actual) dependiendo del tipo de CARGA
    3.1.- Se declara la llegada al PUERTO DESTINO
    3.2.- Si esta CARGADO, entonces puede DESCARGAR   (goto 4.-)

    NOTA: SI EL PUERTO ES UN YACIMIENTO, ENTONCES NO PUEDE DESCARGAR
          SI EL PUERTO ES UNA REFINERIA O UN DEPOSITO, ENTONCES NO PUEDE DESCARGAR CRUDO


4.- DESCARGAR Buque
    4.1.- Crea registro nuevo indicando PUERTO INICIO el puerto actual
    4.2.- Coloca tipo de carga VACIO   (goto 1.-)

    NOTA: LA DESCARGA NO PUEDE HACERSE SI EL PUERTO ES UN YACIMIENTO!


Busca en el vector operaciones del Buque para conocer la situacion del Buque:

       - Si duraC <> 0 y status = 1, la Operacion carga esta en curso
       - Si duraC <> 0 y status = 0, la Operacion carga se ha completado
       - Si duraT <> 0 y status = 1, la Operacion trasladado esta en curso
       - Si duraT <> 0 y status = 0, la Operacion trasladado se ha completado
       - Si duraD <> 0 y status = 1, la Operacion descarga esta en curso
       - Si duraD <> 0 y status = 0, la Operacion descarga se ha completado
*/
void flota::operaBuque(Puertos & listaPuertos) {
   char       idBqC;
   idBuque    iBuque = A;
   int        ultOper = 0;
   tipoCarga  tipoCg = vacio;
   int        opcCarga = 4;
   int        statBuque = 0;
   nomBuq     nombre = "                   ";
   nomPrt     puertoAct = "                   ";
   nomPrt     puertoDst = "                   ";
   nomCarga   nombreCrg = "        ";
   int        idP = 0;       /* Puerto actual del Buque. */
   int        idPd = 0;      /* Puerto destino nuevo del Buque. */
   int        duraCd = 0;    /* Duracion de la carga (en dias). */
   int        duraTd = 0;    /* Duracion del traslado (en dias). */
   int        dia    = 0;    /* Dia de la fecha solicitada por el usuario. */
   int        mes    = 0;    /* Mes de la fecha solicitada por el usuario. */
   int        anno   = 0;    /* Anno de la fecha solicitada por el usuario. */
   calendario calBuque;
   fecha      fecha1 = {0, 0, 0};   /* Fecha de la Operacion mas reciente. */
   fecha      fecha2 = {1, 1, 1};   /* Fecha introducida por el usuario. */
   char       resp = ' ';


   /* Limpia la pantalla y consulta al usuario. */
   system("cls");

   printf("Operar Buque:\n\n");
   fflush(stdin);

   /* Solicita ID del Buque, mes y anno. */
   printf("Identificador del Buque(letra entre A y E)?");
   idBqC = toupper(getchar());
   fflush(stdin);

   /* Acepta unicamente ID valido para el Buque. */
   if(idBqC == 'A' || idBqC == 'B' || idBqC == 'C' || idBqC == 'D' || idBqC == 'E') {
     switch(idBqC) {
        case 'A': iBuque = A;
                  break;
        case 'B': iBuque = B;
                  break;
        case 'C': iBuque = C;
                  break;
        case 'D': iBuque = D;
                  break;
        case 'E': iBuque = E;
                  break;
     }

     /* Busca la ultima operacion registrada para el Buque seleccionado. */
     strcpy(nombre, vectorBuques[iBuque].nomB);                      /* Lee nombre del Buque. */

     ultOper = 0;
     ultOper = vectorBuques[iBuque].cntOper-1;
     tipoCg = vectorBuques[iBuque].oprdelBuque[ultOper].carga;       /* Lee el Tipo de la Carga. */
     statBuque = vectorBuques[iBuque].oprdelBuque[ultOper].status;   /* Lee el status de Operacion. */
     idP = vectorBuques[iBuque].oprdelBuque[ultOper].puertoI-1;      /* Lee el Puerto de Inicio. */
     idPd = vectorBuques[iBuque].oprdelBuque[ultOper].puertoD-1;     /* lee el Puerto Destino. */
     strncpy(puertoAct, listaPuertos.lista[idP].nomP, 18);           /* Lee el nombre del Puerto actual. */

     /* Lee la fecha Fin de la ultima Operacion registrada. */
     fecha1.d = vectorBuques[iBuque].oprdelBuque[ultOper].diaF;
     fecha1.m = vectorBuques[iBuque].oprdelBuque[ultOper].mesF;
     fecha1.a = vectorBuques[iBuque].oprdelBuque[ultOper].anoF;


/*DEBUG*/
        //printf("ENTRA A OPERAR BUQUE");
        //printf("\nOperacion actual:ultOper\n");
        //printf("Carga:%d, Puerto Inicio:%d, Puerto Destino:%d, duraC:%d, duraT:%d, duraD:%d, status:%d", vectorBuques[iBuque].oprdelBuque[ultOper].carga, vectorBuques[iBuque].oprdelBuque[ultOper].puertoI, vectorBuques[iBuque].oprdelBuque[ultOper].puertoD, vectorBuques[iBuque].oprdelBuque[ultOper].duraC, vectorBuques[iBuque].oprdelBuque[ultOper].duraT, vectorBuques[iBuque].oprdelBuque[ultOper].duraD, vectorBuques[iBuque].oprdelBuque[ultOper].status);
        //printf("\nOperacion Anterior:ultOper-1\n");
        //printf("Carga:%d, Puerto Inicio:%d, Puerto Destino:%d, duraC:%d, duraT:%d, duraD:%d, status:%d", vectorBuques[iBuque].oprdelBuque[ultOper-1].carga, vectorBuques[iBuque].oprdelBuque[ultOper-1].puertoI, vectorBuques[iBuque].oprdelBuque[ultOper-1].puertoD, vectorBuques[iBuque].oprdelBuque[ultOper-1].duraC, vectorBuques[iBuque].oprdelBuque[ultOper-1].duraT, vectorBuques[iBuque].oprdelBuque[ultOper-1].duraD, vectorBuques[iBuque].oprdelBuque[ultOper-1].status);
        //fflush(stdin);
        //getchar();
/*DEBUG*/


     /* --------------------------------- *
      * Comprueba la situacion del Buque. *
      * --------------------------------- */
     if(vectorBuques[iBuque].oprdelBuque[ultOper].puertoI && !vectorBuques[iBuque].oprdelBuque[ultOper].puertoD && vectorBuques[iBuque].oprdelBuque[ultOper].carga == vacio) {
        /* ----------------------- *
         * Buque EN PUERTO y VACIO *
         * ----------------------- */

        /* Muestra el menu de operaciones en Puerto. */
        printf("\nEl Buque %s se encuentra vacio en %s\n", nombre, puertoAct);
        printf("\nC.- CARGAR BUQUE");
        printf("\nT.- TRASLADAR BUQUE");
        printf("\nR.- REGRESAR AL MENU GestFlota");
        printf("\n\nIndique la accion a realizar(C, T, R)?");
        fflush(stdin);
        resp = toupper(getchar());

        if(resp == 'C' || resp == 'T') {
           /* Solicita la fecha de la Operacion. */
           printf("\nFecha de ultima Operacion del Buque: %2d-%2d-%4d\n\n", fecha1.d, fecha1.m, fecha1.a);
           printf("ATENCION: La fecha que introduzca debe ser mayor que la fecha de ultima Operacion...\n\n");
           printf("Fecha de comienzo operacion: Dia?");
           scanf("%d", &dia);
           printf("Fecha de comienzo operacion: Mes?");
           scanf("%d", &mes);
           printf("Fecha de comienzo operacion: Anno?");
           scanf("%d", &anno);
           fflush(stdin);

           /* Fecha solicitada para el comienzo de la Operacion nueva. */
           fecha2.d = dia;
           fecha2.m = mes;
           fecha2.a = anno;
        }

        /* Comprueba que la fecha introducida sea valida. */
        if(calBuque.diferenciaFechas(fecha1, fecha2) < 0) {
           printf("\n\nDebe introducir una fecha igual o posterior a la ultima Operacion del Buque. ENTER para regresar al menu...");
           fflush(stdin);
           getchar();
        }else {
           /* ---------------------------------------- *
            * Realiza la Operacion de Carga del Buque. *
            * ---------------------------------------- */
           if(resp == 'C') {
              /* Verifica que puede cargarse en el Puerto actual. */
              if(listaPuertos.lista[idP].tipo == yacimiento) {
                 printf("\nSe puede cargar: crudo\n");
                 opcCarga = 0;
              }else if(listaPuertos.lista[idP].tipo == refineria || listaPuertos.lista[idP].tipo == deposito) {
                 printf("\nSe puede cargar: 1-fuel 2-gasoil 3-gasolina\n");
                 printf("\nopcion(1, 2 o 3)?");
                 fflush(stdin);
                 opcCarga = getchar() - '0';
              }
              printf("quiere realizar la carga(S/N)?");
              fflush(stdin);
              resp = ' ';
              resp = toupper(getchar());

              if(resp == 'S') {
                 printf("Duracion de la carga en dias?");
                 fflush(stdin);
                 duraCd = getchar() - '0';

                 /* Crea registro de Operacion de carga con los parametros solicitados. */
                 switch(opcCarga) {
                    case 0: tipoCg = crudo;
                            break;
                    case 1: tipoCg = fuel;
                            break;
                    case 2: tipoCg = gasoil;
                            break;
                    case 3: tipoCg = gasolina;
                            break;
                 }
                 ultOper++;
                 idP++;
                 vectorBuques[iBuque].oprdelBuque[ultOper].asignaOperacion(tipoCg, idP, 0, duraCd, 0, 0, dia, mes, anno, 0);
                 vectorBuques[iBuque].cntOper++;
              }
           /* ------------------------------------------- *
            * Realiza la Operacion de Traslado del Buque. *
            * ------------------------------------------- */
           }else if(resp == 'T') {
              printf("\nPuertos de posible destino del buque:\n");

              /* Muestra la lista de puertos destino. */
              for(int k = 0; k < numPuertos; k++) {
                 if(listaPuertos.lista[k].id != 0) {
                    /* Puede trasladarse a cualquier Puerto (excepto al Puerto actual). */
                    if(listaPuertos.lista[k].id != idP+1) {
                       printf("     %d-", listaPuertos.lista[k].id);

                       for(int x = 0; x < longNpuerto; x++) {
                          printf("%c", listaPuertos.lista[k].nomP[x]);
                       }

                       printf("   Tipo: ");
                       switch(listaPuertos.lista[k].tipo) {
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
              }

              /* Solicita Puerto destino para esta Operacion. */
              printf("\nIdentificador del puerto destino?");
              fflush(stdin);
              idPd = getchar() - '0';

              /* Solicita la duracion (en dias) de esta Operacion. */
              printf("Duracion del traslado en dias?");
              fflush(stdin);
              duraTd = getchar() - '0';

              /* Crea registro de Operacion de traslado con los parametros solicitados. */
              ultOper++;
              idP++;
              vectorBuques[iBuque].oprdelBuque[ultOper].asignaOperacion(tipoCg, idP, idPd, 0, duraTd, 0, dia, mes, anno, 0);
              vectorBuques[iBuque].cntOper++;
           }
        }
     }else if(vectorBuques[iBuque].oprdelBuque[ultOper].puertoI && !vectorBuques[iBuque].oprdelBuque[ultOper].puertoD && vectorBuques[iBuque].oprdelBuque[ultOper].carga != vacio) {
        /* ------------------------- *
         * Buque EN PUERTO y CARGADO *
         * ------------------------- */
        switch(tipoCg) {
           case crudo:    strcpy(nombreCrg, "crudo");
                          break;
           case fuel:     strcpy(nombreCrg, "fuel");
                          break;
           case gasoil:   strcpy(nombreCrg, "gasoil");
                          break;
           case gasolina: strcpy(nombreCrg , "gasolina");
                          break;
           case vacio:    strcpy(nombreCrg, "vacio");
                          break;
        }

        /* Muestra el menu de operaciones en Puerto. */
        //if(vectorBuques[iBuque].oprdelBuque[ultOper-1].duraC && !vectorBuques[iBuque].oprdelBuque[ultOper-1].status) {
        if(vectorBuques[iBuque].oprdelBuque[ultOper].duraC && !vectorBuques[iBuque].oprdelBuque[ultOper].status) {
           /* Ultima Operacion fue CARGAR. */
           printf("\nEl Buque %s se encuentra cargado con %s en %s\n", nombre, nombreCrg, puertoAct);
           printf("\nT.- TRASLADAR BUQUE");
           printf("\nR.- REGRESAR AL MENU GestFlota");
           printf("\n\nIndique la accion a realizar(T, R)?");
           fflush(stdin);
           resp = toupper(getchar());

           /* ------------------------------------------- *
            * Realiza la Operacion de Traslado del Buque. *
            * ------------------------------------------- */
           if(resp == 'T') {
              /* Solicita la fecha de la Operacion. */
              printf("\n\nFecha de ultima Operacion del Buque: %2d-%2d-%4d\n\n", fecha1.d, fecha1.m, fecha1.a);
              printf("ATENCION: La fecha que introduzca debe ser mayor que la fecha de ultima Operacion...\n\n");
              printf("Fecha de comienzo operacion: Dia?");
              scanf("%d", &dia);
              printf("Fecha de comienzo operacion: Mes?");
              scanf("%d", &mes);
              printf("Fecha de comienzo operacion: Anno?");
              scanf("%d", &anno);
              fflush(stdin);

              /* Fecha solicitada para el comienzo de la Operacion nueva. */
              fecha2.d = dia;
              fecha2.m = mes;
              fecha2.a = anno;

              /* Comprueba que la fecha introducida sea valida. */
              if(calBuque.diferenciaFechas(fecha1, fecha2) < 0) {
                 printf("\n\nDebe introducir una fecha igual o posterior a la ultima Operacion del Buque. ENTER para regresar al menu...");
                 fflush(stdin);
                 getchar();
              }else {
                 printf("\nPuertos de posible destino del buque:\n");

                 /* Muestra la lista de posibles puertos destino en base al tipo de Carga. */
                 for(int k = 0; k < numPuertos; k++) {
                    if(listaPuertos.lista[k].id != 0) {
                       if((listaPuertos.lista[k].id != vectorBuques[iBuque].oprdelBuque[ultOper].puertoI) &&
                          (vectorBuques[iBuque].oprdelBuque[ultOper].carga == vacio ||
                          (vectorBuques[iBuque].oprdelBuque[ultOper].carga == fuel && listaPuertos.lista[k].tipo == deposito) ||
                          (vectorBuques[iBuque].oprdelBuque[ultOper].carga == gasoil && listaPuertos.lista[k].tipo == deposito) ||
                          (vectorBuques[iBuque].oprdelBuque[ultOper].carga == gasolina && listaPuertos.lista[k].tipo == deposito) ||
                          (vectorBuques[iBuque].oprdelBuque[ultOper].carga == crudo && listaPuertos.lista[k].tipo == refineria))) {

                          printf("     %d-", listaPuertos.lista[k].id);

                          for(int x = 0; x < longNpuerto; x++) {
                             printf("%c", listaPuertos.lista[k].nomP[x]);
                          }

                          printf("   Tipo: ");
                          switch(listaPuertos.lista[k].tipo) {
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
                 }

                 /* Solicita Puerto destino para esta Operacion. */
                 printf("\nIdentificador del puerto destino?");
                 fflush(stdin);
                 idPd = getchar() - '0';

                 /* Solicita la duracion (en dias) de esta Operacion. */
                 printf("Duracion del traslado en dias?");
                 fflush(stdin);
                 duraTd = getchar() - '0';

                 /* Crea registro de Operacion de traslado con los parametros solicitados. */
                 ultOper++;
                 idP++;
                 vectorBuques[iBuque].oprdelBuque[ultOper].asignaOperacion(tipoCg, idP, idPd, 0, duraTd, 0, dia, mes, anno, 0);
                 vectorBuques[iBuque].cntOper++;
              }
           }
        }else if(vectorBuques[iBuque].oprdelBuque[ultOper-1].duraT && !vectorBuques[iBuque].oprdelBuque[ultOper-1].status) {
           /* Ultima Operacion fue TRASLADAR. El Buque arribo al Puerto. */
           printf("\nEl Buque %s arribo a %s cargado con %s\n", nombre, puertoAct, nombreCrg);
           printf("\nD.- DESCARGAR BUQUE");
           printf("\nR.- REGRESAR AL MENU GestFlota");
           printf("\n\nIndique la accion a realizar(D, R)?");
           fflush(stdin);
           resp = ' ';
           resp = toupper(getchar());

           /* ------------------------------------------- *
            * Realiza la Operacion de Descarga del Buque. *
            * ------------------------------------------- */
           if(resp == 'D') {
              /* Solicita la fecha de la Operacion. */
              printf("\n\nFecha de ultima Operacion del Buque: %2d-%2d-%4d\n\n", fecha1.d, fecha1.m, fecha1.a);
              printf("ATENCION: La fecha que introduzca debe ser mayor que la fecha de ultima Operacion...\n\n");
              printf("Fecha de comienzo operacion: Dia?");
              scanf("%d", &dia);
              printf("Fecha de comienzo operacion: Mes?");
              scanf("%d", &mes);
              printf("Fecha de comienzo operacion: Anno?");
              scanf("%d", &anno);
              fflush(stdin);

              /* Fecha solicitada para el comienzo de la Operacion nueva. */
              fecha2.d = dia;
              fecha2.m = mes;
              fecha2.a = anno;

              /* Crea registro de Operacion de descarga con los parametros solicitados. */
              tipoCg = vacio;   /* Declara el Buque como vacio. */
              ultOper++;
              idP++;
              idPd = 0;         /* Limpia Puerto Destino. */
              vectorBuques[iBuque].oprdelBuque[ultOper].asignaOperacion(tipoCg, idP, idPd, 0, duraTd, 0, dia, mes, anno, 0);
              vectorBuques[iBuque].cntOper++;
           }
        }
     }else if(vectorBuques[iBuque].oprdelBuque[ultOper].puertoI && vectorBuques[iBuque].oprdelBuque[ultOper].puertoD && vectorBuques[iBuque].oprdelBuque[ultOper].duraT) {
        /* -------------------------------------- *
         * Buque en TRASLADO HACIA PUERTO DESTINO *
         * -------------------------------------- */

        /* El Buque esta en viaje desde Puerto de Inicio rumbo al Puerto Destino. */
        strcpy(puertoDst, listaPuertos.lista[idPd].nomP);   /* Lee el nombre del Puerto Destino proximo . */
        switch(tipoCg) {
        /* Nombre de la Carga. */
           case crudo:    strcpy(nombreCrg, "crudo");
                          break;
           case fuel:     strcpy(nombreCrg, "fuel");
                          break;
           case gasoil:   strcpy(nombreCrg, "gasoil");
                          break;
           case gasolina: strcpy(nombreCrg , "gasolina");
                          break;
           case vacio:    strcpy(nombreCrg, "vacio");
                          break;
        }
        printf("\nEl Buque %s esta proximo a ", nombre);
        for(int i = 0; i < 15; i++) {
           printf("%c", puertoDst[i]);
        }
        printf(" cargado con %s\n", nombreCrg);
        printf("\nA.- DECLARAR ARRIBO");
        printf("\nR.- REGRESAR AL MENU GestFlota");
        printf("\n\nIndique la accion a realizar(A, R)?");
        fflush(stdin);
        resp = ' ';
        resp = toupper(getchar());

        /* ------------------------------------------- *
         * Realiza la Operacion de Descarga del Buque. *
         * ------------------------------------------- */
        if(resp == 'A') {
           /* IMPORTANTE: En este punto, el programa simula el arribo a Puerto Destino,
                          - Coloca en status cero(0) Operacion de Traslado.
                          - Puerto Inicial ----> Puerto Destino de la Operacion anterior (TRASLADO)
                          - Puerto Destino ----> cero (0)                                           */
           vectorBuques[iBuque].oprdelBuque[ultOper].status = 0;   /* Indica que finalizo Operacion de Traslado. */

           ultOper++;
           //idPd = idP;
           //idPd++;
           idPd++;

           printf("\n\nidPd:%d\n", idPd);

           vectorBuques[iBuque].oprdelBuque[ultOper].asignaOperacion(tipoCg, idPd, 0, 0, 0, 0, fecha1.d, fecha1.m, fecha1.a, 0);
           vectorBuques[iBuque].cntOper++;
        }
     }
   }
}

/* Procedimiento de tratamiento de la opcion "Resumen mensual Buque". */
void flota::resumenBuque(Puertos & listaPuertos) {
   tipoCarga  tCarga   = vacio;
   int        contador = 0;
   int        duraDias = 0;
   int        contaTra = 0;
   int        contaCar = 0;
   int        contaDes = 0;
   int        indexPue = 0;
   nomPrt     puertoInicio;
   nomPrt     puertoDestino;
   char       idBq;
   idBuque    id = A;
   nomBuq     nombre = "                   ";
   int        mes    = 0;
   int        anno   = 0;
   int        buscaMes;
   int        buscaAno;
   char       resp;
   calendario calBuque;
   int        cntCargas = 0;   /* Contador de cargas (en dias). */
   int        cntTrasla = 0;   /* Contador de traslados (en dias). */
   int        cntDescar = 0;   /* Contador de descargas (en dias). */
   vectorDias diasCalenda; /* Vector de dias de Carga, Traslado, Descarga y dias libres. */


   do{
      resp = ' ';

      /* Limpia la pantalla y consulta al usuario. */
      system("cls");

      printf("Resumen mensual Buque:\n");
      fflush(stdin);

      /* Solicita ID del Buque, mes y anno. */
      printf("Identificador del Buque(letra entre A y E)?");
      idBq = toupper(getchar());
      fflush(stdin);

      printf("Seleccion Mes?");
      scanf("%d", &mes);

      printf("Seleccion Anno?");
      scanf("%d", &anno);
      fflush(stdin);

      switch(idBq) {
         case 'A': id = A;
                   break;
         case 'B': id = B;
                   break;
         case 'C': id = C;
                   break;
         case 'D': id = D;
                   break;
         case 'E': id = E;
                   break;
      }

      strcpy(nombre, vectorBuques[id].nomB);

      printf("\n\nResumen Buque: %s\n\n", nombre);

      /* Inicializa el vector de dias del mes con la cuenta de dias. */
      for(int i = 1; i <= 32; i++) {
         diasCalenda[i].nroDia = i;
         diasCalenda[i].hito = 0;
      }

      /* Busca, dentro de la lista de Operaciones del Buque, todas las operaciones
         cuya fecha coincida con el mes y anno solicitados.                        */
      for(int i = 0; i < maxOperaciones; i++) {
         buscaAno = vectorBuques[id].oprdelBuque[i].anoI;
         buscaMes = vectorBuques[id].oprdelBuque[i].mesI;

         if(buscaAno == anno && buscaMes == mes) {
            /* Es una Operacion de Carga. */
            if(vectorBuques[id].oprdelBuque[i].duraC) {
               /* Incrementa el contador de cargas. */
               cntCargas = cntCargas + vectorBuques[id].oprdelBuque[i].duraC;

               contador = vectorBuques[id].oprdelBuque[i].diaI;
               duraDias = vectorBuques[id].oprdelBuque[i].duraC;

               contaCar++;   /* Cuenta las cargas (CX). */

               for(int k = 0; k < duraDias; k++) {
                  diasCalenda[contador].tipoPeracion = 'C';
                  diasCalenda[contador].cntTras = contaCar;
                  contador++;
               }
               contador = 0;
               duraDias = 0;
            /* Es una Operacion de Traslado. */
            }else if(vectorBuques[id].oprdelBuque[i].duraT) {
               /* Incrementa el contador de traslados. */
               cntTrasla = cntTrasla + vectorBuques[id].oprdelBuque[i].duraT;

               contador = vectorBuques[id].oprdelBuque[i].diaI;
               duraDias = vectorBuques[id].oprdelBuque[i].duraT;

               contaTra++;   /* Cuenta los traslados (TX). */

               /* Toma el nombre de los puertos (Inicio y Destino). */
               indexPue = vectorBuques[id].oprdelBuque[i].puertoI-1;
               strncpy(puertoInicio, "                   ", 20);
               strncpy(puertoInicio, listaPuertos.lista[indexPue].nomP, 20);
               indexPue = vectorBuques[id].oprdelBuque[i].puertoD-1;
               strncpy(puertoDestino, "                   ", 20);
               strncpy(puertoDestino, listaPuertos.lista[indexPue].nomP, 20);

               /* Monta los datos basicos para imprimir el Calendario. */
               for(int k = 0; k < duraDias; k++) {
                  diasCalenda[contador].tipoPeracion = 'T';
                  diasCalenda[contador].cntTras = contaTra;
                  strncpy(diasCalenda[contador].prtIni, "                   ", 20);
                  strcpy(diasCalenda[contador].prtIni, puertoInicio);
                  strncpy(diasCalenda[contador].prtDst, "                   ", 20);
                  strcpy(diasCalenda[contador].prtDst, puertoDestino);
                  tCarga = vectorBuques[id].oprdelBuque[i].carga;

                  switch(tCarga) {
                     case crudo:     strcpy(diasCalenda[contador].nCarga, "crudo");
                                     break;
                      case fuel:     strcpy(diasCalenda[contador].nCarga, "fuel");
                                     break;
                      case gasoil:   strcpy(diasCalenda[contador].nCarga, "gasoil");
                                     break;
                      case gasolina: strcpy(diasCalenda[contador].nCarga, "gasolina");
                                     break;
                      case vacio:    strcpy(diasCalenda[contador].nCarga, "vacio");
                                     break;
                  }

                  if(!k) {
                     diasCalenda[contador].hito = 1;   /* Indica que empieza una Operacion de Traslado. */
                  }

                  contador++;
               }
               contador = 0;
               duraDias = 0;
            /* Es una Operacion de Descarga. */
            }else if(vectorBuques[id].oprdelBuque[i].duraD) {
               /* Incrementa el contador de descargas. */
               cntDescar = cntDescar + vectorBuques[id].oprdelBuque[i].duraD;

               contador = vectorBuques[id].oprdelBuque[i].diaI;
               duraDias = vectorBuques[id].oprdelBuque[i].duraD;

               contaDes++;   /* Cuenta las descargas (DX). */

               for(int k = 0; k < duraDias; k++) {
                  diasCalenda[contador].tipoPeracion = 'D';
                  diasCalenda[contador].cntTras = contaDes;
                  contador++;
               }
               contador = 0;
               duraDias = 0;
            }
         }
      }

      /* Genera e imprime el calendario para el mes y anno solicitado. */
      calBuque.imprimeCalendario(mes, anno, diasCalenda, cntCargas, cntTrasla, cntDescar);

      printf("\n\nMostrar otro mes (S/N)?");
      fflush(stdin);
      resp = toupper(getchar());
   }while(resp == 'S');
}

/* Procedimiento para inicializar la flota de buques. */
void flota::iniciaFlota() {
   nomBuq nomIni = "                   ";

   for(int i = 0; i < numBuques; i++) {
      vectorBuques[i].asignaBuque(X, nomIni, 0, 0, 0, 0);

      /* Inicializa el vector de operaciones del buque. */
      for(int j = 0; j < maxOperaciones; j++) {
         vectorBuques[i].oprdelBuque[j].asignaOperacion(vacio, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      }

      vectorBuques[i].cntOper = 0;   /* Inicializa el contador de operaciones del Buque. */
   }

   /* carga inicial de buques para las pruebas. */
   strcpy(nomIni, "CARGUERO DEL NORTE ");
   vectorBuques[0].asignaBuque(A, nomIni, 1, 1, 2022, 1);
   /* Se registra una 1ra. Carga. */
   vectorBuques[0].oprdelBuque[0].asignaOperacion(fuel, 1, 0, 1, 0, 0, 1, 1, 2022, 0);
   vectorBuques[0].cntOper++;
   /* Se registra un 1er. traslado. */
   vectorBuques[0].oprdelBuque[1].asignaOperacion(fuel, 1, 3, 0, 4, 0, 2, 1, 2022, 0);
   vectorBuques[0].cntOper++;
   /* se registra una 1ra. Descarga. */
   vectorBuques[0].oprdelBuque[2].asignaOperacion(vacio, 3, 0, 0, 0, 1, 6, 1, 2022, 0);
   vectorBuques[0].cntOper++;
   /* Se registra una 2da. Carga. */
   vectorBuques[0].oprdelBuque[3].asignaOperacion(gasoil, 3, 0, 3, 0, 0, 8, 1, 2022, 0);
   vectorBuques[0].cntOper++;
   /* Se registra un 2do. traslado. */
   vectorBuques[0].oprdelBuque[4].asignaOperacion(gasoil, 3, 1, 0, 4, 0, 11, 1, 2022, 0);
   vectorBuques[0].cntOper++;
   /* se registra una 2da. Descarga. */
   vectorBuques[0].oprdelBuque[5].asignaOperacion(gasoil, 1, 0, 0, 0, 0, 15, 1, 2022, 0);
   vectorBuques[0].cntOper++;

   strcpy(nomIni, "BEATRIZ UNO        ");
   vectorBuques[1].asignaBuque(B, nomIni, 10, 5, 2022, 1);
   vectorBuques[1].oprdelBuque[0].asignaOperacion(gasolina, 2, 3, 0, 5, 0, 10, 5, 2022, 1);
   vectorBuques[1].cntOper++;

   strcpy(nomIni, "SOUTH OIL TANKER   ");
   vectorBuques[2].asignaBuque(C, nomIni, 2, 11, 2022, 1);
   vectorBuques[2].oprdelBuque[0].asignaOperacion(gasolina, 1, 0, 1, 0, 0, 26, 12, 2022, 0);
   vectorBuques[2].cntOper++;
   vectorBuques[2].oprdelBuque[1].asignaOperacion(gasolina, 1, 2, 0, 1, 0, 27, 12, 2022, 0);
   vectorBuques[2].cntOper++;
}

/* Procedimiento de tratamiento de la opcion "Estado Buque". */
void flota::estadoBuques(Puertos & listaPuertos) {
   char       idBq = ' ';
   nomBuq     nombre = "                   ";
   int        dia;
   int        mes;
   int        ano;
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
      if(vectorBuques[i].id != X) {
         /* Toma el ID del Buque. */
         switch(vectorBuques[i].id) {
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
         strncpy(nombre, vectorBuques[i].nomB, 19);

         ultOper = 0;
         ultOper = vectorBuques[i].cntOper-1;

         /* Toma la fecha fin de la Operacion. */
         dia = vectorBuques[i].oprdelBuque[ultOper].diaF;
         mes = vectorBuques[i].oprdelBuque[ultOper].mesF;
         ano = vectorBuques[i].oprdelBuque[ultOper].anoF;

         /* Toma la Carga del Buque durante la Operacion. */
         cargadBuque = vectorBuques[i].oprdelBuque[ultOper].carga;

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
         puertoAct = vectorBuques[i].oprdelBuque[ultOper].puertoI-1;
         strcpy(nomPrtAct, "                   ");
         strncpy(nomPrtAct, listaPuertos.lista[puertoAct].nomP, 19);

         /* Imprime registro con el estado del Buque. */
         printf("%2c %19s %16s %02d/%02d/%4d %s\n", idBq, nombre, nomPrtAct, dia, mes, ano, nombreCarga);
      }
   }

   fflush(stdin);
   getchar();
}
