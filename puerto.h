/* =========================== TAD PUERTO ============================== */
#pragma once

/* ======================= CONSTANTES Y TIPOS =========================== */
/* Tipo de puerto. */
typedef enum tipoPuerto {yacimiento, refineria, deposito, sinAsignacion};

/* Tipo basico para el nombre de puerto. */
const int longNpuerto = 20;   /* Longitud de nombre del Puerto. */
typedef char nomPrt[longNpuerto];
/* ======================= CONSTANTES Y TIPOS =========================== */

/* ====================== ELEMENTO PUERTO ======================= */
typedef struct puerto {
   int          id;     /* Identificacion del puerto: 1..20. */
   nomPrt       nomP;   /* Nombre del puerto. */
   tipoPuerto   tipo;   /* Tipo de puerto. */
};
/* ====================== ELEMENTO PUERTO ======================= */

/* =========================== LISTA DE PUERTOS ========================= */
/* Comentarios: - Si un Puerto tiene Id con caracter '0' indica que dicho puerto
                  no existe en el sistema y puede ser creado.                    */

/* Numero de puertos disponibles en el sistema. */
const int numPuertos = 10;
typedef puerto puertos[numPuertos];
/* =========================== LISTA DE PUERTOS ========================= */

/* =============== DECLARACION DE PROCEDIMIENTOS Y FUNCIONES =============== */
/* ------------------------------------------------------ *
 * Realiza el alta de un Puerto en el sistema de gestion. *
 * Devuelve un elemento de tipo Puerto.                   *
 *                                                        *
 * Parametros: - ID del Puerto     (de entrada)           *
 *             - Nombre del Puerto (de entrada)           *
 *             - Tipo de Puerto    (de entrada)           *
 *             - Puerto            (de salida)            *
 * ------------------------------------------------------ */
void asignaPuerto(int inId, nomPrt inNom, tipoPuerto inTipo, puerto & inPuerto);

/* --------------------------------------------------- *
 * Procedimiento para inicializar la lista de puertos. *
 *                                                     *
 * Parametros: - Lista de puertos (salida)             *
 * --------------------------------------------------- */
void iniciaListaPuertos(puertos & lista);

/* ---------------------------------------------------------- *
 * Procedimiento de tratamiento de la opcion "Editar Puerto". *
 * Interactua con el usuario del sistema para tomar los datos *
 * basicos y regstrarlos en el elemento Puerto indicado por   *
 * el usuario.                                                *
 *                                                            *
 * Parametros: - Lista de puertos (entrada/salida)            *
 * ---------------------------------------------------------- */
void editaPuerto(puertos & lista);
/* =============== DECLARACION DE PROCEDIMIENTOS Y FUNCIONES =============== */
