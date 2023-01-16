/************************************
* NOMBRE: #Jose Rafael#
* PRIMER APELLIDO: #Portillo#
* SEGUNDO APELLIDO: #Lugo#
* DNI: #Y7489057H#
* EMAIL: #jportillo89@alumno.uned.es#
*************************************/
#pragma once

/* Elemento fecha. */
typedef struct fecha {
	int d;
  int m;
  int a;
};

const int diasMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef int vtrDias[12];

/* ====================== TAD DIA ======================= */
/* Nombre de un Puerto. */
const int longNomP = 20;
typedef char puertoNom[longNomP];

/* Nombre de una Carga. */
const int longCarga = 9;
typedef char cargaNom[longCarga];

/* Representa un dia cualquiera dentro del Calendario del Buque. */
typedef struct regDia {
   int       nroDia;         /* Numero de dia en el mes. */
   int       cntTras;        /* Conteo de Operaciones (CX, TX, DX). */
   char      tipoPeracion;   /* Tipo de Operacion del dia: CX, TX o DX. */
   puertoNom prtIni;         /* Nombre del Puerto de Inicio de un Traslado. */
   puertoNom prtDst;         /* Nombre del Puerto destino de un Traslado. */
   cargaNom  nCarga;         /* Tipo de Carga. */
   int       hito;           /* Senala el inicio de una Operacion. */
};
/* ====================== TAD DIA ======================= */



/* ====================== TAD CALENDARIO ======================= */
/* Vector de los dias del mes a imprimir. */
const int dsM = 32;
typedef regDia vectorDias[dsM];

typedef struct calendario {
   int diasxMes(int mes, int anno);
/* --------------------------------------------------------------------------------- *
 * Genera e imprime el calendario mensual de un Buque para un mes y anno especifico. *
 *                                                                                   *
 * Parametros: - mes                             (de entrada)                        *
 *             - anno                            (de entrada)                        *
 *             - dias del mes                    (de entrada)                        *
 *             - duracion de la Carga en dias    (de entrada)                        *
 *             - duracion de traslado en dias    (de entrada)                        *
 *             - duracion de descargas en dias   (de entrada)                        *
 * ----------------------------------------------------------------------------------*/
   void imprimeCalendario(int pmes, int panno, vectorDias pdiasCalendas, int tiempoC, int tiempoT, int tiempoD);
   void incrementaFecha(int &dia, int &mes, int &anno, int incremento);   /* Dada una fecha (dd-mm-aaaa), aplica un incremento (en dias). */
   int diferenciaFechas(fecha fec1, fecha fec2);

   int mes;
   int anno;
};
/* ====================== TAD CALENDARIO ======================= */
