#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int menuPrincipal(void)
{
    int opcion;
    printf("1)  Cargar los datos desde el archivo (modo texto)\n");
    printf("2)  Cargar los datos desde el archivo(modo binario)\n");
    printf("3)  Alta\n");
    printf("4)  Modificar\n");
    printf("5)  Baja\n");
    printf("6)  Listar\n");
    printf("7)  Ordenar\n");
    printf("8)  Filtrar\n");
    printf("9)  Informes\n");
    printf("10)  Guardar los dato en el archivo(modo texto)\n");
    printf("11) Guardar los datos en el archivo (modo binario)\n");
    printf("12) Salir\n");
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion incorrecta. Introduzca una opcion valida: ", 1, 12);
    return opcion;
}

int menuModificar(void)
{
    int opcion;
    printf("1) Modificar char\n");
    printf("2) Modificar int\n");
    printf("3) Modificar float\n");
    printf("4) Salir\n");
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 4);
    return opcion;
}

int menuOrdenar(void)
{
    int opcion;
    printf("1) Ordenar por Id(mayor a menor)\n");
    printf("2) Ordenar por char(A-Z)\n");
    printf("3) Ordenar por char(Z-A)\n");
    printf("4) Ordenar por int(menor a mayor)\n");
    printf("5) Ordenar por int(mayor a menor)\n");
    printf("6) Ordenar por float(menor a mayor)\n");
    printf("7) Ordenar por float(mayor a menor)\n");
    printf("8) Salir\n");
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 8);
    return opcion;
}

int menuFiltrar(void)
{
    int opcion;
    printf("1) Filtrar por char\n");
    printf("2) Filtrar por int\n");
    printf("3) Filtrar por float\n");
    printf("4) Salir\n");
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 4);
    return opcion;
}

int menuInformes(void)
{
    int opcion;
    printf("1) Min\n");
    printf("2) Max\n");
    printf("3) Promedio\n");
    printf("4) Salir\n");
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 4);
    return opcion;
}
