#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Biblioteca.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Archivo data.csv abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int cantidadDeDatosLeidos;
    char id[15];
    char nombre[128];
    char horasTrabajadas[15];
    char sueldo[15];
    if (pFile==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    if(pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(cantidadDeDatosLeidos == 4 && isdigit(id[0]) != 0)
            {
                pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
                if(pEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                }
            }

        }
        return 0;
    }
    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* Archivo data.bin abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee auxEmployee;
    Employee* pEmployee = NULL;
    if (pFile==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    while(!feof(pFile))
    {
        fread(&auxEmployee,sizeof(Employee),1,pFile);
        if(feof(pFile))
        {
            fclose(pFile);
            return 0;
        }
        pEmployee = employee_new();
        if(pEmployee != NULL)
        {
            *pEmployee = auxEmployee;
            ll_add(pArrayListEmployee, pEmployee);
        }
    }
    fclose(pFile);
    return 1;
}
