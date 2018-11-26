#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "Estructura.h"
#include "LinkedList.h"
#include "Controlador.h"

int controlador_cargarEmpleados(char* path, LinkedList* pListaLinkeada)
{
    FILE* pArchivo = NULL;
    if(path != NULL && pListaLinkeada != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            parser_txtSinSueldo(pArchivo, pListaLinkeada);
            fclose(pArchivo);
            return 0;
        }
    }
    return 1;
}

int parser_txtSinSueldo(FILE* pArchivo, LinkedList* pListaLinkeada)
{
    eEmpleado* peEmpleado = NULL;
    int cantidadDeDatosLeidos;
    char id[15];
    char nombre[128];
    char direccion[128];
    char horasTrabajadas[5];
    char sueldo[15] = "0";
    if (pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    if(pListaLinkeada != NULL)
    {
        while(!feof(pArchivo))
        {
            cantidadDeDatosLeidos = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, direccion, horasTrabajadas);
            if(cantidadDeDatosLeidos == 4 && isdigit(id[0]) != 0)
            {
                peEmpleado = eEmpleado_nuevoParametrizado(id, nombre, direccion, horasTrabajadas, sueldo);
                if(peEmpleado != NULL)
                {
                    ll_add(pListaLinkeada, peEmpleado);
                }
            }
        }
        return 0;
    }
    return 1;
}

int controlador_printLinkedListeEmpleado(LinkedList* pListaLinkeada)
{
    eEmpleado* peEmpleado = NULL;
    int indice;
    if(pListaLinkeada != NULL)
    {
        printf("%5s | %15s | %30s | %20s\n", "Id", "Nombre", "Direccion", "Horas Trabajadas");
        for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
        {
                peEmpleado = (eEmpleado *)ll_get(pListaLinkeada, indice);
                eEmpleado_print(peEmpleado);
        }
        return 0;
    }
    return 1;
}

int controlador_ordenareEmpleado(LinkedList* pListaLinkeada)
{
    LinkedList* pAuxListaLinkeada = NULL;
    if(pListaLinkeada != NULL)
    {
        pAuxListaLinkeada = ll_clone(pListaLinkeada);
        ll_sort(pAuxListaLinkeada, eEmpleado_compararNombre, 1);
        printf("\nLista de datos ordenada por nombre(A-Z).\n\n");
        controlador_printLinkedListeEmpleado(pAuxListaLinkeada);
        ll_deleteLinkedList(pAuxListaLinkeada);
        return 0;
    }
    return 1;
}

int controlador_generarSueldo(LinkedList* pListaLinkeada)
{
    float promedio;
    if(pListaLinkeada != NULL)
    {
        ll_map(pListaLinkeada, eEmpleado_calcularSueldo);
        promedio = controlador_promedioSueldo(pListaLinkeada);
        controlador_guardarTxtSueldos("sueldos.csv", pListaLinkeada, promedio);
        return 0;
    }
    return 1;
}

float controlador_promedioSueldo(LinkedList* pListaLinkeada)
{
    eEmpleado* peEmpleado = NULL;
    int sueldo;
    float retorno = -1;
    int indice;
    int contador;
    int suma = 0;
    float promedio;
    if(pListaLinkeada != NULL)
    {
        contador = ll_len(pListaLinkeada);
        if(contador > 0)
        {
            for(indice = 0; indice < contador; indice++)
            {
                peEmpleado = (eEmpleado*)ll_get(pListaLinkeada, indice);
                eEmpleado_getSueldo(peEmpleado, &sueldo);
                suma = suma + sueldo;
            }
            promedio = suma / contador;
            retorno = promedio;
        }
    }
    return retorno;
}

int controlador_guardarTxtSueldos(char* path , LinkedList* pListaLinkeada, float promedio)
{
    FILE* pArchivo = NULL;
    eEmpleado* auxeEmpleado = NULL;
    int indice;
    if(path != NULL && pListaLinkeada != NULL)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo, "%s,%s,%s,%s,%s\n", "Id", "Nombre", "Direccion", "HorasTrabajadas", "Sueldo");
            for(indice = 0; indice < ll_len(pListaLinkeada); indice++)
            {
                auxeEmpleado = (eEmpleado *)ll_get(pListaLinkeada, indice);
                if(auxeEmpleado->sueldo > promedio)
                {
                    fprintf(pArchivo, "%d,%s,%s,%d,%d\n", auxeEmpleado->id, auxeEmpleado->nombre, auxeEmpleado->direccion, auxeEmpleado->horasTrabajadas, auxeEmpleado->sueldo);
                }
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado.\n");
        return 0;
    }
    return 1;
}
