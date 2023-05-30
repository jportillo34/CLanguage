
#pragma once

/* ==================================== TAD puerto ==================================== */
/* Tipo de puerto. */
typedef enum tipoPuerto {yacimiento, refineria, deposito, sinAsignacion};

/* Tipo basico para el nombre de puerto. */
const int longNpuerto = 20;   /* Longitud de nombre del Puerto. */
typedef char nomPrt[longNpuerto];

typedef struct puerto {
/* ---------------------------------------------------------- *
 * Realiza el registro de un Puerto en el sistema de gestion. *
 *                                                            *
 * Parametros: - Carga                (de entrada)            *
 *             - Puerto inicio        (de entrada)            *
 *             - Puerto destino       (de entrada)            *
 * ---------------------------------------------------------- */
   void asignaPuerto(int inId, nomPrt inNom, tipoPuerto inTipo);

   int          id;     /* Identificacion del puerto: 1..20. */
   nomPrt       nomP;   /* Nombre del puerto. */
   tipoPuerto   tipo;   /* Tipo de puerto. */
};
/* ==================================== TAD puerto ==================================== */


/* =================================== TAD Puertos =================================== */
/* Comentarios: - Este TAD consume el TAD Puerto.
                - Si un Puerto tiene Id con caracter '0' indica que dicho puerto
                  no existe en el sistema y puede ser creado.                    */

/* Numero de puertos disponibles en el sistema. */
const int numPuertos = 10;
typedef puerto puertos[numPuertos];

typedef struct Puertos {
   void iniciaListaPuertos();  /* Procedimiento para inicializar la lista de puertos. */
   void editaPuerto();         /* Procedimiento de tratamiento de la opcion "Editar Puerto". */

   puertos   lista;            /* Lista de puertos disponibles para las operaciones. */
};
/* =================================== TAD Puertos =================================== */
