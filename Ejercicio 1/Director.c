#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "Fecha.h"
#include "Director.h"

void mostrar_eDirector(eDirector director)
{
    printf("%20s | %8s", director.nombre, " ");
    mostrar_eFecha(director.nacimiento);
    printf(" | %20s", director.paisDeOrigen);
}

int iniciar_eDirector(eDirector listado[], int cantidad, int ilogico)
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

int alta_eDirector(eDirector listado[], int cantidad)
{
    int indice;
    int j;
    int bandera = 0;
    char nombreAuxiliar[TAM_NOMBRE_DIRECTOR];
    if(listado != NULL && cantidad > 0)
    {
        indice = buscarLibre_eDirector(listado, cantidad, LIBRE);
        if(indice > -1)
        {
            pedirArrayLetrasConEspacio(nombreAuxiliar, TAM_NOMBRE_DIRECTOR, "Introduzca el nombre del director:\n",
            "Error nombre invalido. Introduzca el nombre nuevamente:\n");
            capitalizarArrayLetras(nombreAuxiliar);
            for(j = 0; j < cantidad; j++)
            {
                if(strcmp(listado[j].nombre, nombreAuxiliar) == 0)
                {
                    printf("\nEse director ya a sido registrado.\n");
                    bandera = 1;
                }
            }
            if(bandera == 0)
            {
                strcpy(listado[indice].nombre, nombreAuxiliar);
                listado[indice].nacimiento = pedir_eFecha();
                printf("\n");
                pedirArrayLetrasConEspacio(listado[indice].paisDeOrigen, TAM_PAIS_DIRECTOR, "Introduzca el pais de origen:\n",
                "Error pais invalido. Introduzca el pais nuevamente:\n");
                listado[indice].estado = OCUPADO;
                printf("\nDirector agregado.\n");
            }
        } else
        {
            printf("Lista de directores llena.");
        }
        return 0;
    }
    return -1;
}

int baja_eDirector(eDirector listado[], int cantidad, int indice)
{
    char respuesta;
    if(listado != NULL && cantidad > 0)
    {
        printf("%20s | %19s | %20s\n", "Nombre", "Fecha de nacimiento", "Pais de origen");
        mostrar_eDirector(listado[indice]);
        respuesta = pedirRespuestaSN("\nDar de baja director? Introduzca s(para SI) o n(para NO): ");
        printf("\n");
        if(respuesta == 's')
        {
            listado[indice].estado = LIBRE;
            printf("Director eliminado.\n");
        } else
        {
            printf("Director no eliminado.\n");
        }
        return 0;
    }
    return -1;
}

int buscarLibre_eDirector(eDirector listado[], int cantidad, int ilogico)
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

int mostrarListado_eDirector(eDirector listado[], int cantidad)
{
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        printf("%20s | %19s | %20s\n", "Nombre", "Fecha de nacimiento", "Pais de origen");
        for(indice = 0; indice < cantidad; indice++)
        {
            if(listado[indice].estado == OCUPADO)
            {
                mostrar_eDirector(listado[indice]);
                printf("\n");
            }
        }
        return 0;
    }
    return -1;
}

int contarAltas_eDirector(eDirector listado[], int cantidad)
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

int buscarNombre_eDirector(eDirector listado[], int cantidad, char nombreDirector[])
{
    int retorno = -1;
    int indice;
    if(listado != NULL && cantidad > 0)
    {
        retorno = -2;
        for(indice = 0; indice < cantidad; indice ++)
        {
            if(strcmp(listado[indice].nombre, nombreDirector) == 0 && listado[indice].estado == OCUPADO)
            {
                retorno = indice;
                break;
            }
        }
    }
    return retorno;
}
