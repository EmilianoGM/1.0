#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "Fecha.h"
#include "Director.h"
#include "Pelicula.h"
#include "Menu.h"

/**< 1.0 */

void mostrarMenuPrincipal(void)
{
    printf("Menu de opciones:\n");
    printf("1) Altas peliculas\n");
    printf("2) Modificar datos de una pelicula\n");
    printf("3) Baja de pelicula\n");
    printf("4) Nuevo director\n");
    printf("5) Eliminar director\n");
    printf("6) Listar\n");
    printf("7) Salir\n");
}

void mostrarMenuModificar(void)
{
    printf("1) Titulo\n");
    printf("2) Anio\n");
    printf("3) Nacionalidad\n");
    printf("4) Director");
}

void mostrarMenuListar(void)
{
    printf("1) Peliculas\n");
    printf("2) Directores\n");
    printf("3) Peliculas con su director\n");
    printf("4) Directores alfabeticamente(A-Z)\n");
    printf("5) Peliculas por anio(menor-mayor)\n");
}

int menuPrincipal(void)
{
    int opcion;
    printf("BIENVENIDO\n");
    printf("\n");
    mostrarMenuPrincipal();
    opcion = pedirEntero("\nIntroduzca una opcion: ", "\nOpcion invalida, introduzca una opcion: ", 1, 7);
    return opcion;
}

void menuBajaPelicula(ePelicula listadoPeliculas[], int cantidadPeliculas)
{
    int id;
    int indice;
    id = pedirEntero("\nIntroduzca la id a buscar: ", "\nError id invalida. Introduzca la id a buscar: ", 1, 1000);
    indice = buscarPorId_ePelicula(listadoPeliculas, cantidadPeliculas, id);
    if(indice > -1)
    {
        baja_ePelicula(listadoPeliculas, cantidadPeliculas, indice);
    }else
    {
        printf("\nId inexistente.\n");
    }
}

void menuModificarPelicula(ePelicula listadoPeliculas[], int cantidadPeliculas)
{
    int opcion;
    int id;
    int indice;
    id = pedirEntero("\nIntroduzca la id a buscar: ", "\nError id invalida. Introduzca la id a buscar: ", 1, 1000);
    indice = buscarPorId_ePelicula(listadoPeliculas, cantidadPeliculas, id);
    if(indice > -1)
    {
        printf("\n");
        mostrarMenuModificar();
        opcion = pedirEntero("\nIntroduzca una opcion: ", "\nOpcion invalida, introduzca una opcion: ", 1, 4);
        modificar_ePelicula(listadoPeliculas, cantidadPeliculas, opcion, indice);
        printf("\n");
    }else
    {
        printf("\nId inexistente.\n");
    }
}

void menuBajaDirector(eDirector listadoDirectores[], int cantidadDirectores)
{
    char nombreAuxiliar[TAM_NOMBRE_DIRECTOR];
    int indice;
    pedirArrayLetrasConEspacio(nombreAuxiliar, TAM_NOMBRE_DIRECTOR, "Introduzca el nombre del director:\n",
    "Error nombre invalido. Introduzca el nombre nuevamente:\n");
    capitalizarArrayLetras(nombreAuxiliar);
    indice = buscarNombre_eDirector(listadoDirectores, cantidadDirectores, nombreAuxiliar);
    if(indice > -1)
    {
        baja_eDirector(listadoDirectores, cantidadDirectores, indice);
    }else
    {
        printf("\nDirector no encontrado.\n");
    }
}

void menuListar(ePelicula listadoPeliculas[], int cantidadPeliculas, eDirector listadoDirectores[], int cantidadDirectores)
{
    int opcion;
    mostrarMenuListar();
    opcion = pedirEntero("\nIntroduzca una opcion: ", "\nOpcion invalida, introduzca una opcion: ", 1, 5);
    printf("\n");
    switch(opcion)
    {
        case 1:
            if(contarAltas_ePelicula(listadoPeliculas, cantidadPeliculas) > 0)
            {
                mostrarListado_ePelicula(listadoPeliculas, cantidadPeliculas);
            }else
            {
                printf("\nNo se ha ingresado una pelicula todavia.\n");
            }
            break;
        case 2:
            if(contarAltas_eDirector(listadoDirectores, cantidadDirectores) > 0)
            {
                mostrarListado_eDirector(listadoDirectores, cantidadDirectores);
            } else
            {
                printf("\nNo se ha ingresado un director todavia\n");
            }
            break;
        case 3:
            if(contarAltas_ePelicula(listadoPeliculas, cantidadPeliculas) > 0)
            {
                mostrarListadoConDirector_ePelicula(listadoPeliculas, cantidadPeliculas, listadoDirectores, cantidadDirectores);
            }else
            {
                printf("\nNo se ha ingresado una pelicula todavia.\n");
            }
            break;
        case 4:
            if(contarAltas_eDirector(listadoDirectores, cantidadDirectores) > 0)
            {
                ordenarPorNombre_eDirector(listadoDirectores, cantidadDirectores, 0);
                mostrarListado_eDirector(listadoDirectores, cantidadDirectores);
            } else
            {
                printf("\nNo se ha ingresado un director todavia\n");
            }
            break;
        case 5:
            if(contarAltas_ePelicula(listadoPeliculas, cantidadPeliculas) > 0)
            {
                ordernarPorAnio_ePelicula(listadoPeliculas, cantidadPeliculas, 0);
                mostrarListado_ePelicula(listadoPeliculas, cantidadPeliculas);
            }else
            {
                printf("\nNo se ha ingresado una pelicula todavia.\n");
            }
            break;
    }
}
