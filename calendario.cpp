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
#include "calendario.h"

bool esBiciesto(int anno)
{
   if(anno%400 == 0) { return true; }
   if(anno%100 == 0) { return false; }
   return(anno%4 == 0);
}

/* Dada una fecha (dd-mm-aaaa), aplica un incremento (en dias). */
void calendario::incrementaFecha(int &dia, int &mes, int &anno, int incremento) {
   for(int i = 0; i < incremento; i++) {
      dia++;

      if (dia > diasMes[mes-1] || (mes == 2 && dia == 29 && !esBiciesto(anno))) {
         dia = 1;
         mes++;

         if (mes == 13) {
            mes = 1;
            anno++;
         }
      }
   }
}

/* Cuenta los annos biciestos antes de una fecha dada. */
int cuentaBiciestos(fecha fec)
{
	int annos = fec.a;


  /* Comprueba si el anno en curso debe contarse dentro de los annos biciestos. */
	if (fec.m <= 2) {
		annos--;
	}

  /* Comprueba si es multiplo de 4 y multiplo de 400 pero no multiplo de 100. */
	return annos / 4 - annos / 100 + annos / 400;
}

/* Retorna la diferencia (en dias) entre dos fechas dadas. */
int calendario::diferenciaFechas(fecha fec1, fecha fec2)
{
  int dif2 = 0;

	/* Cuenta hasta primera fecha (en dias). */
	int dif1 = fec1.a * 365 + fec1.d;


	/* Primera fecha (en dias) + los dias por mes hasta el mes solicitado. */
	for (int i = 0; i < fec1.m-1; i++) {
		dif1 = dif1 + diasMes[i];
	}

  /* Suma un dia por cada anno biciesto. */
	dif1 = dif1 + cuentaBiciestos(fec1);

	/* Cuenta hasta segunda fecha (en dias). */
	dif2 = fec2.a * 365 + fec2.d;

	/* Segunda fecha (en dias) + los dias por mes hasta el mes solicitado. */
	for (int i = 0; i < fec2.m-1; i++) {
		dif2 = dif2 + diasMes[i];
	}

	dif2 = dif2 + cuentaBiciestos(fec2);

	return dif2 - dif1;
}

/* imprime el nombre del mes solicitado. */
void impriMesAnno(int numMes, int numAnno) {
   if(numMes == 1) {
      printf("ENERO                  %4d\n", numAnno);
   }

   if(numMes == 2) {
      printf("FEBRERO                %4d\n", numAnno);
   }

   if(numMes == 3) {
      printf("MARZO                  %4d\n", numAnno);
   }

   if(numMes == 4) {
      printf("ABRIL                  %4d\n", numAnno);
   }

   if(numMes == 5) {
      printf("MAYO                   %4d\n", numAnno);
   }

   if(numMes == 6) {
      printf("JUNIO                  %4d\n", numAnno);
   }

   if(numMes == 7) {
      printf("JULIO                  %4d\n", numAnno);
   }

   if(numMes == 8) {
      printf("AGOSTO                 %4d\n", numAnno);
   }

   if(numMes == 9) {
      printf("SEPTIEMBRE             %4d\n", numAnno);
   }

   if(numMes == 10) {
      printf("OCTUBRE                %4d\n", numAnno);
   }

   if(numMes == 11) {
      printf("NOVIEMBRE              %4d\n", numAnno);
   }

   if(numMes == 12) {
      printf("DICIEMBRE              %4d\n", numAnno);
   }
}

typedef int factores[15];

/* Determina el dia de la semana para una fecha especifica. */
int diaSemana(int dia, int mes, int anno) {
	factores fac = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

	anno = anno - (mes < 3);

	return (anno + anno/4 - anno/100 + anno/400 + fac[mes-1] + dia) % 7;
}

/* Determina el numero de dias para un mes y anno especificos. */
int diasxMes(int mes, int anno) {
	if(mes == 1) {
		return 31;
	}

	if(mes == 2)
	{
		/* Determina si el anno solicitado es bisiesto. */
		if(anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0)) {
			return 29;
		}else{
			return 28;
		}
	}

	if(mes == 3) {
		return 31;
	}

	if(mes == 4) {
		return 30;
	}

	if(mes == 5) {
		return 31;
	}

	if(mes == 6) {
		return 30;
	}

	if(mes == 7) {
		return 31;
	}

	if(mes == 8) {
		return 31;
	}

	if(mes == 9) {
		return 30;
	}

	if(mes == 10) {
		return 31;
	}

	if(mes == 11) {
		return 30;
	}

	if(mes == 12) {
		return 31;
	}

  return 0;
}


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
void calendario::imprimeCalendario(int mes, int anno, vectorDias pdiasCalendas, int tiempoC, int tiempoT, int tiempoD) {
   int cntDia = 1;   /* Contador de dias. */
   int diaS;         /* Dia de la semana. */
   int numDias;      /* Numero de dias en el mes. */
   int tiempoL = 0;  /* Total (en dias) de parada o dias libres. */


   /* Genera el calendario en el rango 1601 <= anno <= 3000
      y
      1 <= mes <= 12.                                       */
   if(anno >= 1601 && anno <= 3000 && mes >= 1 && mes <= 12) {
      /* Obtiene el dia de la semana correspondiente al 1ro del mes:
          0 dom, 1 lun, 2 mar, 3 mie, 4 jue, 5 vie, 6 sab.            */
       diaS = diaSemana(1, mes, anno);

       /* Obtiene el numero de dias para el mes y anno solicitado. */
       numDias = diasxMes(mes, anno);

       /* Calcula el tiempo de parada. */
       tiempoL = numDias - (tiempoC + tiempoT + tiempoD);

       /* Imprime la cabecera del calendario. */
       printf("\n");
       impriMesAnno(mes, anno);
       printf("===========================\n");
       printf("LU  MA  MI  JU  VI | SA  DO\n");
       printf("===========================\n");

       /* Es primer dia del mes domingo? */
       if(!diaS) {
          diaS = 7;
       }

       /* Rellena con caracter "." hasta el dia de inicio del mes. */
       for(int i = 1; i < diaS; i++) {
          if(i == 5) {
             printf(" . | ");
          }else {
             printf(" .  ");
          }
       }

       /* Imprime los dias del mes. */
       while(cntDia <= numDias) {
          if(diaS == 7) {
             diaS = 0;
             //printf("%2d\n", cntDia);
             if(pdiasCalendas[cntDia].tipoPeracion == 'T') {
                printf("T%d\n", pdiasCalendas[cntDia].cntTras);
             }else if(pdiasCalendas[cntDia].tipoPeracion == 'C') {
                printf("C%d\n", pdiasCalendas[cntDia].cntTras);
             }else if(pdiasCalendas[cntDia].tipoPeracion == 'D') {
                printf("D%d\n", pdiasCalendas[cntDia].cntTras);
             }else {
                printf("%2d\n", pdiasCalendas[cntDia].nroDia);
             }
          }else {
             if(!((diaS) % 5)) {
                //printf("%2d | ", cntDia);
                if(pdiasCalendas[cntDia].tipoPeracion == 'T') {
                   printf("T%d | ", pdiasCalendas[cntDia].cntTras);
                }else if(pdiasCalendas[cntDia].tipoPeracion == 'C') {
                   printf("C%d | ", pdiasCalendas[cntDia].cntTras);
                }else if(pdiasCalendas[cntDia].tipoPeracion == 'D') {
                   printf("D%d | ", pdiasCalendas[cntDia].cntTras);
                }else {
                   printf("%2d | ", pdiasCalendas[cntDia].nroDia);
                }
             }else {
                //printf("%2d  ", cntDia);
                if(pdiasCalendas[cntDia].tipoPeracion == 'T') {
                   printf("T%d  ", pdiasCalendas[cntDia].cntTras);
                }else if(pdiasCalendas[cntDia].tipoPeracion == 'C') {
                   printf("C%d  ", pdiasCalendas[cntDia].cntTras);
                }else if(pdiasCalendas[cntDia].tipoPeracion == 'D') {
                   printf("D%d  ", pdiasCalendas[cntDia].cntTras);
                }else {
                   printf("%2d  ", pdiasCalendas[cntDia].nroDia);
                }
             }
          }

          cntDia++;

          diaS = ( diaS + 1 ) % 7;

          if(!diaS && cntDia <= numDias) {
             //printf("%2d\n", cntDia);
             if(pdiasCalendas[cntDia].tipoPeracion == 'T') {
                printf("T%d\n", pdiasCalendas[cntDia].cntTras);
             }else if(pdiasCalendas[cntDia].tipoPeracion == 'C') {
                printf("C%d\n", pdiasCalendas[cntDia].cntTras);
             }else if(pdiasCalendas[cntDia].tipoPeracion == 'D') {
                printf("D%d\n", pdiasCalendas[cntDia].cntTras);
             }else {
                printf("%2d\n", pdiasCalendas[cntDia].nroDia);
             }
             cntDia++;
             diaS = 1;
          }else if(cntDia > numDias) {
            /* Rellena con caracter "." hasta completar el formato del calendario. */
            while(diaS) {
                if(!((diaS) % 5)) {
                   printf(" . | ");
                }else {
                   printf(" .  ");
                }

                diaS = (diaS + 1) % 7;
            }

            printf(" .\n");
         }
       }

      printf("\nTiempo de cargas(C#): %2d dias", tiempoC);
      printf("\nTiempo de traslados(T#): %2d dias", tiempoT);

      for(int i = 0; i < dsM; i++) {
         /* Unicamente muestra un solo registro de Traslado. Para ello utiliza el hito. */
         if(pdiasCalendas[i].tipoPeracion == 'T' && pdiasCalendas[i].hito) {
            //printf("\nTraslado T%d: desde %5s a %5s con %9s", pdiasCalendas[i].cntTras, pdiasCalendas[i].prtIni, pdiasCalendas[i].prtDst, pdiasCalendas[i].nCarga);
            printf("\nTraslado T%d: desde ", pdiasCalendas[i].cntTras);
            for(int z = 0; z < 18; z++) {
               printf("%c", pdiasCalendas[i].prtIni[z]);
            }
            printf(" a ");
            for(int z = 0; z < 18; z++) {
               printf("%c", pdiasCalendas[i].prtDst[z]);
            }
            printf(" con ");
            for(int z = 0; z < 9; z++) {
               printf("%c", pdiasCalendas[i].nCarga[z]);
            }
         }
      }

      printf("\nTiempo de descargas(D#): %2d dias", tiempoD);
      printf("\nTiempo de parada: %2d dias", tiempoL);
   }
}
