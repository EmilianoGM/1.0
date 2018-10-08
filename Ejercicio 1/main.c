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

int main()
{
    eDirector listaDirectores[MAX_DIRECTORES];
    ePelicula listaPeliculas[MAX_PELICULAS];
    iniciar_eDirector(listaDirectores, MAX_DIRECTORES, LIBRE);
    iniciar_ePelicula(listaPeliculas, MAX_PELICULAS, LIBRE);
    agregarValoresDePrueba(listaPeliculas, listaDirectores);
    int opcion;
    do
    {
        opcion = menuPrincipal();
        system("pause");
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("Alta de pelicula\n");
                if(contarAltas_eDirector(listaDirectores, MAX_DIRECTORES) > 0)
                {
                    printf("\n");
                    alta_ePelicula(listaPeliculas, MAX_PELICULAS, listaDirectores, MAX_DIRECTORES);
                }else
                {
                    printf("\nNo se ha ingresado ningun director todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Modificar pelicula\n");
                if(contarAltas_ePelicula(listaPeliculas, MAX_PELICULAS) > 0)
                {
                    menuModificarPelicula(listaPeliculas, MAX_PELICULAS, listaDirectores, MAX_DIRECTORES);
                }else
                {
                    printf("\nNo se ha ingresado una pelicula todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Baja de pelicula\n");
                if(contarAltas_ePelicula(listaPeliculas, MAX_PELICULAS) > 0)
                {
                    menuBajaPelicula(listaPeliculas, MAX_PELICULAS);
                }else
                {
                    printf("\nNo se ha ingresado una pelicula todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                printf("Alta de director\n");
                printf("\n");
                alta_eDirector(listaDirectores, MAX_DIRECTORES);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("Baja de director\n");
                if(contarAltas_eDirector(listaDirectores, MAX_DIRECTORES) > 0)
                {
                    menuBajaDirector(listaDirectores, MAX_DIRECTORES, listaPeliculas, MAX_PELICULAS);
                } else
                {
                    printf("\nNo se ha ingresado ningun director todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                printf("Listar\n");
                if(contarAltas_eDirector(listaDirectores, MAX_DIRECTORES) > 0)
                {
                    menuListar(listaPeliculas, MAX_PELICULAS, listaDirectores, MAX_DIRECTORES);
                }else
                {
                    printf("\nNo se agrego ningun director todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                break;
        }
    }while(opcion != 7);

    printf("Gracias por usar la aplicacion\n");
    return 0;
}
