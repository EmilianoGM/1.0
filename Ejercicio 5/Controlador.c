#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "Estructura.h"
#include "Menu.h"
#include "LinkedList.h"
#include "Controlador.h"

int controlador_cargarTxt(char* path, LinkedList* pListaLinkeada)
{
    FILE* pArchivo = NULL;
    if(path != NULL && pListaLinkeada != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            parser_txt(pArchivo, pListaLinkeada);
            fclose(pArchivo);
            printf("Archivo de texto cargado exitosamente.\n");
            return 0;
        }
    }
    return 1;
}

int controlador_cargarBinario(char* path, LinkedList* pListaLinkeada)
{
    FILE* pArchivo = NULL;
    if(path != NULL && pListaLinkeada != NULL)
    {
        if((pArchivo = fopen(path, "rb")) == NULL)
        {
            printf("El archivo binario no ha sido creado todavia\n");
        } else
        {
            parser_binario(pArchivo, pListaLinkeada);
            fclose(pArchivo);
            printf("Archivo binario cargado exitosamente.\n");
            return 0;
        }
    }
    return 1;
}

int parser_txt(FILE* pArchivo, LinkedList* pListaLinkeada)
{
    Generica* pGenerica = NULL;
    int cantidadDeDatosLeidos;
    char id[15];
    char nombre[128];
    char entero[15];
    char flotante[15];
    if (pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    if(pListaLinkeada != NULL)
    {
        while(!feof(pArchivo))
        {
            cantidadDeDatosLeidos = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, entero, flotante);
            if(cantidadDeDatosLeidos == 4 && isdigit(id[0]) != 0)
            {
                pGenerica = Generica_nuevoParametrizado(id, nombre, entero, flotante);
                if(pGenerica != NULL)
                {
                    ll_add(pListaLinkeada, pGenerica);
                }
            }

        }
        return 0;
    }
    return 1;
}

int parser_binario(FILE* pArchivo, LinkedList* pListaLinkeada)
{
    Generica auxGenerica;
    Generica* pGenerica = NULL;
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    while(!feof(pArchivo))
    {
        fread(&auxGenerica, sizeof(Generica), 1, pArchivo);
        if(feof(pArchivo))
        {
            fclose(pArchivo);
            return 0;
        }
        pGenerica = Generica_nuevo();
        if(pGenerica != NULL)
        {
            *pGenerica = auxGenerica;
            ll_add(pListaLinkeada, pGenerica);
        }
    }
    fclose(pArchivo);
    return 1;
}

int controlador_altaGenerica(LinkedList* pListaLinkeada)
{
    Generica* pGenerica = NULL;
    char id[15];
    char nombre[128];
    char entero[15];
    char flotante[15];
    char respuesta;
    int nuevoId;
    if(pListaLinkeada != NULL)
    {
        /**< ESTABLECE EL ID */
        nuevoId = controlador_nuevoId(pListaLinkeada);
        itoa(nuevoId, id, 10);
        /**< INGRESA DATOS */
        pedirString_caracteresAlfabeticosEspaciados(nombre, 128, "\nIntroduzca nombre: ", "\nError, nombre invalido. Introduzca nombre nuevamente: ");
        pedirString_NumeroEnteroPositivo(entero, 15, "\nIntroduzca entero: ", "\nError, entero invalido. Introduzca entero nuevamente: ");
        pedirString_NumeroFlotantePositivo(flotante, 15, "\nIntroduzca flotante: ", "\nError, flotante invalido. Introduzca flotante nuevamente: ");
        /**< CREA dato */
        pGenerica = Generica_nuevoParametrizado(id, nombre, entero, flotante);
        if(pGenerica != NULL)
        {
            printf("\n");
            Generica_print(pGenerica);
            respuesta = pedirRespuestaSN("\n\nDesea agregar dato?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                ll_add(pListaLinkeada, pGenerica);
                printf("dato agregado\n");
            } else
            {
                Generica_eliminar(pGenerica);
                printf("dato no agregado\n");
            }
            return 0;
        }
    }
    return 1;
}

int controlador_modificarGenerica(LinkedList* pListaLinkeada)
{
    Generica* pGenerica = NULL;
    int id_aBuscar;
    int opcion;
    int indice;
    char nombre[128];
    int entero;
    float flotante;
    if(pListaLinkeada != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        indice = controlador_buscarId(pListaLinkeada, id_aBuscar);
        if(indice > -1)
        {
            pGenerica = ll_get(pListaLinkeada, indice);
            printf("\nId encontrado\n");
            printf("%5s | %15s | %10s | %10s\n", "Id", "Nombre", "entero", "flotante");
            Generica_print(pGenerica);
            printf("\n");
            opcion = menuModificar();
            switch(opcion)
            {
                case 1:
                    pedirString_caracteresAlfabeticosEspaciados(nombre, 128, "\nIntroduzca el nuevo nombre: ", "\nError, nombre invalido. Introduzca el nuevo nombre: ");
                    Generica_setNombre(pGenerica, nombre);
                    printf("\nNombre modificado.\n");
                    Generica_print(pGenerica);
                    break;
                case 2:
                    pedirEntero(&entero, "\nIntroduzca el nuevo entero", "\nError entero invalido. Introduzca el entero nuevamente: ", 1, 100000);
                    Generica_setEntero(pGenerica, entero);
                    printf("\nCantidad de horas modificada.\n");
                    Generica_print(pGenerica);
                    break;
                case 3:
                    pedirFlotante(&flotante, "\nIntroduzca el nuevo flotante: ", "\nError, flotante invalido. Introduzca el flotante nuevamente: ", 1, 100000);
                    Generica_setFlotante(pGenerica, flotante);
                    printf("\nflotante modificado.\n");
                    Generica_print(pGenerica);
                    break;
                case 4:
                    printf("\ndato no modificado.\n");
                    break;
            }
        } else
        {
            printf("\nId no encontrado.\n");
        }
        return 0;
    }
    return 1;
}

int controlador_bajaGenerica(LinkedList* pListaLinkeada)
{
    int id_aBuscar;
    Generica* pGenerica  = NULL;
    char respuesta;
    int indice;
    if(pListaLinkeada != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        indice = controlador_buscarId(pListaLinkeada, id_aBuscar);
        if(indice > -1)
        {
            pGenerica = ll_get(pListaLinkeada, indice);
            printf("\nId encontrado\n");
            printf("%5s | %15s | %10s | %12s\n", "Id", "Nombre", "entero", "flotante");
            Generica_print(pGenerica);
            respuesta = pedirRespuestaSN("\nDesea eliminar dato?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                ll_remove(pListaLinkeada, indice);
                Generica_eliminar(pGenerica);
                printf("\nDato eliminado.\n");
            } else
            {
                printf("\nDato no eliminado.\n");
            }
        } else
        {
            printf("\nId no encontrado.\n");
        }
        return 0;
    }
    return 1;
}

int controlador_nuevoId(LinkedList* pListaLinkeada)
{
    Generica* pGenerica = NULL;
    int id = -1;
    int ultimoId;
    if(pListaLinkeada != NULL)
    {
        if((ll_len(pListaLinkeada)) == 0)
        {
            id = 1;
        } else
        {
            pGenerica = (Generica *)ll_get(pListaLinkeada, (ll_len(pListaLinkeada)) - 1);
            Generica_getId(pGenerica, &ultimoId);
            id = ultimoId + 1;
        }
    }
    return id;
}

int controlador_buscarId(LinkedList* pListaLinkeada, int id_aBuscar)
{
    Generica* pGenerica = NULL;
    int indice = -1;
    int id;
    if(pListaLinkeada != NULL && id_aBuscar > 0)
    {
        for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
        {
            pGenerica = (Generica *)ll_get(pListaLinkeada, indice);
            Generica_getId(pGenerica, &id);
            if(id == id_aBuscar)
            {
                break;
            }
        }
    }
    return indice;
}


int controlador_printLinkedListGenerica(LinkedList* pListaLinkeada)
{
    Generica* pGenerica = NULL;
    int indice;
    if(pListaLinkeada != NULL)
    {
        printf("%5s | %15s | %10s | %13s\n", "Id", "Nombre", "entero", "flotante");
        for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
        {
                pGenerica = (Generica *)ll_get(pListaLinkeada, indice);
                Generica_print(pGenerica);
        }
        return 0;
    }
    return 1;
}

int controlador_ordenarGenerica(LinkedList* pListaLinkeada)
{
    int opcion;
    LinkedList* pAuxListaLinkeada = NULL;
    if(pListaLinkeada != NULL)
    {
        pAuxListaLinkeada = ll_clone(pListaLinkeada);
        opcion = menuOrdenar();
        switch(opcion)
        {
            case 1:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararId, 0);
                printf("\nLista de datos ordenada por Id(mayor a menor).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 2:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararNombre, 1);
                printf("\nLista de datos ordenada por nombre(A-Z).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 3:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararNombre, 0);
                printf("\nLista de datos ordenada por nombre(Z-A).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 4:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararEntero, 1);
                printf("\nLista de datos ordenada por entero(menor a mayor).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 5:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararEntero, 0);
                printf("\nLista de datos ordenada por entero(mayor a menor).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 6:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararFlotante, 1);
                printf("\nLista de datos ordenada por flotante(menor a mayor).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 7:
                printf("Ordenando...\n");
                ll_sort(pAuxListaLinkeada, Generica_compararFlotante, 0);
                printf("\nLista de datos ordenada por flotante(mayor a menor).\n\n");
                controlador_printLinkedListGenerica(pAuxListaLinkeada);
                break;
            case 8:
                printf("\nLista no ordenada.\n");
                break;
        }
        ll_deleteLinkedList(pAuxListaLinkeada);
        return 0;
    }
    return 1;
}

int controlador_filtrarGenerica(LinkedList* pListaLinkeada)
{
    int opcion;
    LinkedList* pAuxListaLinkeada = NULL;
    if(pListaLinkeada != NULL)
    {
        opcion = menuFiltrar();
        switch(opcion)
        {
            case 1:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, Generica_filtrarNombre);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por nombre\n");
                    controlador_printLinkedListGenerica(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 2:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, Generica_filtrarEntero);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por cantidad de horas trabajadas\n");
                    controlador_printLinkedListGenerica(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 3:
                pAuxListaLinkeada = ll_filter(pListaLinkeada, Generica_filtrarFlotante);
                if(pAuxListaLinkeada != NULL)
                {
                    printf("Lista de datos filtrada por flotante\n");
                    controlador_printLinkedListGenerica(pAuxListaLinkeada);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 4:
                printf("\nLista no filtrada\n");
                break;
        }
        ll_deleteLinkedList(pAuxListaLinkeada);
        return 0;
    }
    return 1;
}

int controlador_informes(LinkedList* pListaLinkeada)
{
    int opcion;
    //int indice;
    LinkedList* pAuxListaLinkeada = NULL;
    if(pListaLinkeada != NULL)
    {
        opcion = menuInformes();
        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;

        }
        controlador_printLinkedListGenerica(pAuxListaLinkeada);
        ll_deleteLinkedList(pAuxListaLinkeada);
        return 0;
    }
    return 1;
}

int controlador_guardarTxt(char* path , LinkedList* pListaLinkeada)
{
    FILE* pArchivo = NULL;
    Generica* auxGenerica = NULL;
    int indice;
    if(path != NULL && pListaLinkeada != NULL)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo, "%s,%s,%s,%s\n", "id", "nombre", "entero", "flotante");
            for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
            {
                auxGenerica = (Generica *)ll_get(pListaLinkeada, indice);
                fprintf(pArchivo, "%d,%s,%d,%f\n", auxGenerica->id, auxGenerica->nombre, auxGenerica->entero, auxGenerica->flotante);
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado.\n");
        return 0;
    }
    return 1;
}

int controlador_guardarBinario(char* path , LinkedList* pListaLinkeada)
{
    FILE* pArchivo = NULL;
    Generica* auxGenerica = NULL;
    int indice;
    if(path != NULL && pListaLinkeada != NULL)
    {
        pArchivo = fopen(path, "wb");
        if(pArchivo != NULL)
        {
            for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
            {
                auxGenerica = (Generica *)ll_get(pListaLinkeada, indice);
                fwrite(auxGenerica, sizeof(Generica), 1, pArchivo);
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado.\n");
        return 0;
    }
    return 1;
}
