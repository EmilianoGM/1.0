#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Fecha.h"

/**< 1.0 */

eFecha pedir_eFecha(void)
 {
     eFecha auxiliar;
     auxiliar.anio = pedirEntero("\nIntroduzca anio (aaaa): ", "\nError, anio invalido. Introduzca anio: ", 1900, ANIO_ACTUAL);
     auxiliar.mes = pedirEntero("\nIntroduzca mes (mm): ", "\nError, mes invalido. Introduzca mes: ", 1, 12);
     switch(auxiliar.mes)
     {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            auxiliar.dia = pedirEntero("\nIntroduzca dia (dd): ", "\nError, dia invalido. Introduzca dia: ", 1, 30);
            break;
        case 2:
            auxiliar.dia = pedirEntero("\nIntroduzca dia (dd): ", "\nError, dia invalido. Introduzca dia: ", 1, 29);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            auxiliar.dia = pedirEntero("\nIntroduzca dia (dd): ", "\nError, dia invalido. Introduzca dia: ", 1, 31);
            break;
     }
     return auxiliar;
 }

 void mostrar_eFecha(eFecha fecha)
 {
     printf("%2d-%2d -%4d", fecha.dia, fecha.mes, fecha.anio);
 }
