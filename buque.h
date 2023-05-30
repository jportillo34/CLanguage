
#pragma once

/* ============================= TAD OPERACION ============================= */
/* Tipo de carga. */
typedef enum tipoCarga {crudo, fuel, gasoil, gasolina, vacio};

/* Nombre de la Carga del Buque. */
typedef char nomCarga[9];

/*
 * Comentario: La identificacion del tipo de la Operacion (Carga, Traslado o Descarga) se realiza
 *             comprobando cual campo (duraC, duraT, duraD) es diferente de cero.
 */
typedef struct operacion {
/* ---------------------------------------------------------- *
 * Realiza el alta de una Operacion para un Buque especifico. *
 * Incrementa el contador de operaciones para el Buque.       *
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
 *             - Dia fin de Oper.     (de entrada)            *
 *             - Mes fin de Oper.     (de entrada)            *
 *             - Anno fin de Oper.    (de entrada)            *
 *             - Status de Oper.      (de entrada)            *
 * ---------------------------------------------------------- */
   void asignaOperacion(tipoCarga inCrg, int inPi, int inPd, int inDc, int inDt, int inDd, int inDi, int inMi, int inAi, int inStatus);

   tipoCarga    carga;    /* Tipo de Carga en la operacion. */
   int          puertoI;  /* Puerto de inicio de la operacion. */
   int          puertoD;  /* Puerto destino de la operacion. */
   int          duraC;    /* Duracion (en dias) de la operacion Cargar. */
   int          duraT;    /* Duracion (en dias) de la operacion Trasladar. */
   int          duraD;    /* Duracion (en dias) de la operacion Descargar. */

   /* Fecha inicio de operacion. */
   int          diaI;     /* Dia inicio. */
   int          mesI;     /* Mes inicio. */
   int          anoI;     /* Anno inicio. */

   /* Fecha fin de la operacion. */
   int          diaF;     /* Dia fin. */
   int          mesF;     /* Mes fin. */
   int          anoF;     /* anno fin. */

   int          status;   /* de la Operacion, 1-->en curso, 0-->finalizada. */
};
/* ============================= TAD OPERACION ============================= */



/* =================================== TAD BUQUE =================================== */
/* Comentarios:   - Consume el TAD Operacion.
                  - Este programa no funciona en tiempo real para la operacion del Buque.
                  El estado de un Buque (si esta en puerto o en traslado; si ha llegado al puerto destino;
                  si esta cargado o vacio, todo esto se establece cuando el usuario elige la opcion "Operar buque". */
/* Numero maximo de operaciones por Buque. */
const int maxOperaciones = 8;
typedef operacion operaciones[maxOperaciones];

/* Id del Buque. */
typedef enum idBuque {A, B, C, D, E, X};

/* Tipo basico para el nombre de buque: 1..20 caracteres. */
const int longNbuque = 20;   /* Longitud de nombre del Buque. */
typedef char nomBuq[longNbuque];

typedef struct buque {
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
   void asignaBuque(idBuque inId, nomBuq inNom, int inDi, int inMi, int inAi, int inPi);

   idBuque      id;            /* Identificacion del buque: A, B, C, D, E. */
   nomBuq       nomB;          /* Nombre del buque. */
   int          fId;           /* Dia de inicio en el sistema. */
   int          fIm;           /* Mes de inicio en el sistema. */
   int          fIa;           /* Anno de inicio en el sistema. */
   int          pIid;          /* ID del Puerto donde se ubica inicialmente el Buque o como Puerto inicio de Oper.  */
   int          cntOper;       /* Contador de operaciones del Buque. */
   operaciones  oprdelBuque;   /* Lista de operaciones del Buque. Historico de operaciones. */
};
/* =================================== TAD BUQUE =================================== */


/* =================================== TAD FLOTA =================================== */
/* Comentarios: - Consume el TAD Buque.
                - Si un Buque tiene Id con valor X indica que dicho buque no existe en el sistema y puede ser creado. */
/* Numero de buques disponibles en el sistema. */
const int numBuques = 5;
typedef buque buques[numBuques];

typedef struct flota {
   void iniciaFlota();                          /* Procedimiento para inicializar la flota de buques. */
   void editaBuque(Puertos & listaPuertos);     /* Procedimiento de tratamiento de la opcion "Editar Buque". */
/* ------------------------------------------------------------------------------------------------ *
 * Procedimiento de tratamiento de la opcion "Operar Buque".                                        *
 *                                                                                                  *
 * Comentarios:                                                                                     *
 * 1.- La Carga, Traslado o Descarga crean un registro nuevo dentro del vector Operacion del Buque. *
 *                                                                                                  *
 * 2.- Busca en el vector de operaciones del Buque para conocer la situacion del Buque:             *
 *                                                                                                  *
 *     - Si duraC <> 0 y status = 1, la Operacion carga esta en curso                               *
 *     - Si duraC <> 0 y status = 0, la Operacion carga se ha completado                            *
 *     - Si duraT <> 0 y status = 1, la Operacion trasladado esta en curso                          *
 *     - Si duraT <> 0 y status = 0, la Operacion trasladado se ha completado                       *
 *     - Si duraD <> 0 y status = 1, la Operacion descarga esta en curso                            *
 *     - Si duraD <> 0 y status = 0, la Operacion descarga se ha completado                         *
 * ------------------------------------------------------------------------------------------------ */
   void operaBuque(Puertos & listaPuertos);
   void estadoBuques(Puertos & listaPuertos);   /* Procedimiento de tratamiento de la opcion "Estado Buque". */
   void resumenBuque(Puertos & listaPuertos);   /* Procedimiento de tratamiento de la opcion "Resumen mensual Buque". */

   buques vectorBuques;
};
/* =================================== TAD FLOTA =================================== */
