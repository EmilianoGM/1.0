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

void mostrar_ePelicula(ePelicula pelicula)
{
    printf("%20s | %4d | %20s | %20s | %4d", pelicula.titulo, pelicula.anio, pelicula.nacionalidad,
    pelicula.director, pelicula.identificador);
}

void agregarValoresDePrueba(ePelicula listadoPeliculas[], eDirector listadoDirectores[])
{
    char nombresDirector[3][TAM_NOMBRE_DIRECTOR] = {"Juan Perez", "Ana Lopez", "Pedro Medina"};
    eFecha fechas[3];
    int anioFecha[3] = {1960, 1987, 1975};
    int mesFecha[3] = {2, 6, 12};
    int diaFecha[3] = {24, 30, 10};
    char paisDirector[3][TAM_PAIS_DIRECTOR] = {"Argentina", "Uruguay", "Brazil"};
    char tituloPelicula[3][TAM_TITULO_PELICULA] = {"Depredador", "Legado Bourne", "Warrior"};
    int anioPelicula[3] = {2007, 2010, 2011};
    char nacionalidadPelicula[3][TAM_NACIONALIDAD_PELICULA] = {"Alemania", "Francia", "Chile"};
    int idPelicula[3] = {1, 2, 3};
    int indice;
    for(indice = 0; indice < 3; indice++)
    {
        fechas[indice].anio = anioFecha[indice];
        fechas[indice].mes = mesFecha[indice];
        fechas[indice].dia = diaFecha[indice];
    }
    for(indice = 0; indice < 3; indice++)
    {
        strcpy(listadoDirectores[indice].nombre, nombresDirector[indice]);
        listadoDirectores[indice].nacimiento = fechas[indice];
        strcpy(listadoDirectores[indice].paisDeOrigen, paisDirector[indice]);
        listadoDirectores[indice].estado = OCUPADO;

        strcpy(listadoPeliculas[indice].titulo, tituloPelicula[indice]);
        strcpy(listadoPeliculas[indice].director, nombresDirector[indice]);
        listadoPeliculas[indice].anio = anioPelicula[indice];
        strcpy(listadoPeliculas[indice].nacionalidad, nacionalidadPelicula[indice]);
        listadoPeliculas[indice].identificador = idPelicula[indice];
        listadoPeliculas[indice].estado = OCUPADO;
    }
}

int iniciar_ePelicula(ePelicula listado[], int cantidad, int ilogico)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        for(indice = 0; indice < cantidad; indice ++)
        {
            listado[indice].estado = ilogico;
        }
        retorno = 0;
    }
    return retorno;
}

int alta_ePelicula(ePelicula listado[], int cantidad, eDirector listadoDirectores[], int cantidadDirectores)
{
    int indice;
    int indiceDirector;
    char nombreAuxiliar[TAM_NOMBRE_DIRECTOR];
    if(listado != NULL && cantidad > 0 && listadoDirectores != NULL && cantidadDirectores > 0)
    {
        indice = buscarLibre_ePelicula(listado, cantidad, LIBRE);
        if(indice > -1)
        {
            pedirArrayAlfanumericaConEspacio(listado[indice].titulo, TAM_TITULO_PELICULA, "Introduzca el titulo de la pelicula:\n",
            "Error titulo invalido. Introduzca el titulo nuevamente:\n");
            pedirArrayLetrasConEspacio(nombreAuxiliar, TAM_NOMBRE_DIRECTOR, "Introduzca el nombre del director:\n",
            "Error nombre invalido. Introduzca el nombre nuevamente:\n");
            capitalizarArrayLetras(nombreAuxiliar);
            indiceDirector = buscarNombre_eDirector(listadoDirectores, cantidadDirectores, nombreAuxiliar);
            if(indiceDirector > -1)
            {
                printf("\n");
                strcpy(listado[indice].director, listadoDirectores[indiceDirector].nombre);
                listado[indice].anio = pedirEntero("Introduzca anio: \n", "Error anio invalido. Introduzca el anio nuevamente:\n",
                1900, ANIO_ACTUAL);
                pedirArrayLetrasConEspacio(listado[indice].nacionalidad, TAM_NACIONALIDAD_PELICULA, "Introduzca el pais:\n",
                "Error pais invalido. Introduzca el pais nuevamente:\n");
                listado[indice].identificador = generarId_ePelicula(listado, cantidad);
                listado[indice].estado = OCUPADO;
                printf("\nPelicula agregada.\n");
            }else
            {
                printf("\nEse director aun no ha sido registrado.\n");
            }
        } else
        {
            printf("Lista de peliculas llena.");
        }
        return 0;
    }
    return -1;
}

int baja_ePelicula(ePelicula listado[], int cantidad, int indice)
{
    char respuesta;
    if(listado != NULL && cantidad > 0)
    {
        printf("%20s | %4s | %20s | %20s | %4s\n", "Titulo", "Anio", "Nacionalidad", "Director", "ID");
        mostrar_ePelicula(listado[indice]);
        respuesta = pedirRespuestaSN("\nDar de baja pelicula? Introduzca s(para SI) o n(para NO): ");
        printf("\n");
        if(respuesta == 's')
        {
            listado[indice].estado = LIBRE;
            printf("Pelicula eliminada.\n");
        } else
        {
            printf("Pelicula no eliminada.\n");
        }
        return 0;
    }
    return -1;
}

int modificar_ePelicula(ePelicula listado[], int cantidad, eDirector listadoDirectores[], int cantidadDirectores, int opcion, int indice)
{
    int indiceNombreDirector;
    char nombreAuxiliar[TAM_NOMBRE_DIRECTOR];
    if(listado != NULL && cantidad > 0)
    {
        switch(opcion)
        {
            case 1:
                pedirArrayAlfanumericaConEspacio(listado[indice].titulo, TAM_TITULO_PELICULA,
                "Introduzca el titulo de la pelicula:\n", "Error titulo invalido. Introduzca el titulo nuevamente:\n");
                break;
            case 2:
                listado[indice].anio = pedirEntero("Introduzca anio: \n",
                "Error anio invalido. Introduzca el anio nuevamente:\n", 1900, ANIO_ACTUAL);
                break;
            case 3:
                pedirArrayLetrasConEspacio(listado[indice].nacionalidad, TAM_NACIONALIDAD_PELICULA,
                "Introduzca el pais:\n", "Error pais invalido. Introduzca el pais nuevamente:\n");
                break;
            case 4:
                pedirArrayLetrasConEspacio(nombreAuxiliar, TAM_NOMBRE_DIRECTOR, "Introduzca el nombre del director:\n",
                "Error nombre invalido. Introduzca el nombre nuevamente:\n");
                capitalizarArrayLetras(nombreAuxiliar);
                indiceNombreDirector = buscarNombre_eDirector(listadoDirectores, cantidadDirectores, nombreAuxiliar);
                if(indiceNombreDirector > -1)
                {
                    strcpy(listado[indice].director, listadoDirectores[indiceNombreDirector].nombre);
                    printf("Director cambiado.\n");
                } else
                {
                    printf("\nEse director aun no ha sido registrado.\n");
                }
                break;
        }
        return 0;
    }
    return -1;
}

int mostrarListado_ePelicula(ePelicula listado[], int cantidad)
{
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        printf("%20s | %4s | %20s | %20s | %4s\n", "Titulo", "Anio", "Nacionalidad", "Director", "ID");
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == OCUPADO)
            {
                mostrar_ePelicula(listado[indice]);
                printf("\n");
            }
        }
        return 0;
    }
    return -1;
}

int buscarLibre_ePelicula(ePelicula listado[], int cantidad, int ilogico)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = -2;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == ilogico)
            {
                retorno = indice;
                break;
            }
        }
    }
    return retorno;
}

int generarId_ePelicula(ePelicula listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    int cantidadDeAltas;
    if(listado != NULL && cantidad > 0)
    {
        cantidadDeAltas = contarAltas_ePelicula(listado, cantidad);
        retorno = 1;
        if(cantidadDeAltas > 0)
        {
            int listadoDeIds[cantidadDeAltas];
            generarListaOrdenadaDeIds_ePelicula(listado, cantidad, listadoDeIds, cantidadDeAltas);
            if(listadoDeIds[0] != 1)
            {
                retorno = 1;
            } else
            {
                if(cantidadDeAltas == 1)
                {
                    retorno = 2;
                }else
                {
                    for(indice = 1; indice < (cantidadDeAltas - 1); indice++)
                    {
                        if((listadoDeIds[indice + 1] - listadoDeIds[indice]) != 1)
                        {
                            retorno = listadoDeIds[indice] + 1;
                            break;
                        }
                    }
                    if((listadoDeIds[cantidadDeAltas - 1] - listadoDeIds[cantidadDeAltas - 2]) == 1)
                    {
                        retorno = listadoDeIds[cantidadDeAltas - 1] + 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int generarListaOrdenadaDeIds_ePelicula(ePelicula listado[], int cantidad, int listaDeIds[], int cantidadDeIds)
{
    int retorno = -1;
    int indice;
    int indiceDos = 0;
    if(listado != NULL && cantidad > 0 && listaDeIds != NULL && cantidadDeIds > 0)
    {
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == OCUPADO)
            {
                listaDeIds[indiceDos] = listado[indice].identificador;
                indiceDos++;
            }
        }
        ordenarArrayNumerica(listaDeIds, cantidadDeIds);
        retorno = 0;
    }
    return retorno;
}

int contarAltas_ePelicula(ePelicula listado[], int cantidad)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = 0;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].estado == OCUPADO)
            {
                retorno++;
            }
        }
    }
    return retorno;
}

int buscarPorId_ePelicula(ePelicula listado[], int cantidad, int id)
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = -2;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(listado[indice].identificador == id && listado[indice].estado == OCUPADO)
            {
                retorno = indice;
                break;
            }
        }
    }
    return retorno;
}
