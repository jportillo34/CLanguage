/* =========================== TAD BUQUE ============================== */
#pragma once

/* ======================= CONSTANTES Y TIPOS =========================== */
/* Id del Buque. */
typedef enum idBuque {A, B, C, D, E, X};

/* Tipo de carga. */
typedef enum tipoCarga {crudo, fuel, gasoil, gasolina, vacio};

/* Nombre de la Carga del Buque. */
typedef char nomCarga[9];

/* Tipo basico para el nombre de buque: 1..20 caracteres. */
const int longNbuque = 20;   /* Longitud de nombre del Buque. */
typedef char nomBuq[longNbuque];
/* ======================= CONSTANTES Y TIPOS =========================== */


/* ====================== ELEMENTO OPERACION ======================= */
typedef struct operacion {
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
};
/* ====================== ELEMENTO OPERACION ======================= */


/* =========================== LISTA DE OPERACIONES ========================= */
/* Numero maximo de operaciones por Buque. */
const int maxOperaciones = 5;
typedef operacion operaciones[maxOperaciones];
/* =========================== LISTA DE OPERACIONES ========================= */


/* ====================== ELEMENTO BUQUE ======================= */
/* ---------------------------------------------------------------------------------------------------------------- *
 * Comentarios: - Este programa no funciona en tiempo real para la operacion del Buque.                             *
 *                El estado de un Buque (si esta en puerto o en traslado; si ha llegado al puerto destino;          *
 *                si esta cargado o vacio, todo esto se establece cuando el usuario elige la opcion "Operar buque". *
 * ---------------------------------------------------------------------------------------------------------------- */
typedef struct buque {
   //void cargarBuque();
   //void trasladarBuque();
   //void descargarBuque();

   idBuque      id;            /* Identificacion del buque: A, B, C, D, E. */
   nomBuq       nomB;          /* Nombre del buque. */
   int          fId;           /* Dia de inicio en el sistema. */
   int          fIm;           /* Mes de inicio en el sistema. */
   int          fIa;           /* Anno de inicio en el sistema. */
   int          pIid;          /* ID del Puerto donde se ubica inicialmente el Buque o como Puerto inicio de Oper.  */
   int          cntOper;       /* Contador de operaciones del Buque. */
   operaciones  oprdelBuque;   /* Lista de operaciones del Buque. Historico de operaciones. */
};
/* ====================== ELEMENTO BUQUE ======================= */


/* =========================== LISTA DE BUQUES ========================= */
/* ------------------------------------------------------------------------------------------------------------------ *
 * Comentarios: - Si un Buque tiene Id con valor X indica que dicho buque no existe en el sistema y puede ser creado. *
 * ------------------------------------------------------------------------------------------------------------------ */
/* Numero de buques disponibles en el sistema. */
const int numBuques = 5;
typedef buque buques[numBuques];
/* =========================== LISTA DE BUQUES ========================= */


/* ====================== ELEMENTO BUQUE ======================= */
typedef struct flota {
   buques vectorBuques;
};
/* ====================== ELEMENTO BUQUE ======================= */


/* =============== DECLARACION DE PROCEDIMIENTOS Y FUNCIONES =============== */
/* ---------------------------------------------------------- *
 * Realiza el alta de una Operacion para un Buque especifico. *
 * Incrementa el contador de operaciones para el Buque.       *
 *                                                            *
 * Parametros: - ID del Buque         (de entrada)            *
 *             - Carga                (de entrada)            *
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
 *             - Buque                (de salida)             *
 * ---------------------------------------------------------- */
void asignaOperacion(int inId, tipoCarga inCrg, int inPi, int inPd, int inDc, int inDt, int inDd, int inDi, int inMi, int inAi, int inDf, int inMf, int inAf, buque & inBuque);

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
void asignaBuque(idBuque inId, nomBuq inNom, int inDi, int inMi, int inAi, int inPi, buque & inBuque);

/* --------------------------------------------------- *
 * Procedimiento para inicializar la flota de buques.  *
 *                                                     *
 * Parametros: - Lista de buques (salida)              *
 * --------------------------------------------------- */
void iniciaFlota(buques & lista);

/* --------------------------------------------------------- *
 * Procedimiento de tratamiento de la opcion "Editar Buque". *
 *                                                           *
 * Parametros: - Lista de buques (salida)                    *
 * --------------------------------------------------------- */
void editaBuque(puertos listPuertos, buques & lista);

/* --------------------------------------------------------- *
 * Procedimiento de tratamiento de la opcion "Operar Buque". *
 *                                                           *
 * Parametros: - Lista de buques (salida)                    *
 * --------------------------------------------------------- */
void operaBuque(buques & lista);

/* --------------------------------------------------------- *
 * Procedimiento de tratamiento de la opcion "Estado Buque". *
 *                                                           *
 * Parametros: - Lista de buques (salida)                    *
 * --------------------------------------------------------- */
void estadobuques(puertos listaPuertos, buques & lista);
/* =============== DECLARACION DE PROCEDIMIENTOS Y FUNCIONES =============== */

/* =========================== TAD BUQUE ============================== */
