#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            parser_EmployeeFromText(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
            printf("Archivo de texto cargado exitosamente.\n");
            return 0;
        }
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        if((pArchivo=fopen(path, "rb")) == NULL)
        {
            printf("El archivo binario no ha sido creado todavia\n");
        } else
        {
            parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
            printf("Archivo binario cargado exitosamente.\n");
            return 0;
        }
    }
    return 1;
}


/** \brief Alta de empleados.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada a la cual se agrega el empleado.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    Employee* auxEmployee = NULL;
    char id[15];
    char nombre[128];
    char horasTrabajadas[15];
    char sueldo[15];
    char respuesta;
    int lastId;
    if(pArrayListEmployee != NULL)
    {
        printf("ALTA EMPLEADO\n");
        /**< ESTABLECE EL ID */
        if((ll_len(pArrayListEmployee)) == 0)
        {
            itoa(1, id, 10);
        } else
        {
            auxEmployee = (Employee *)ll_get(pArrayListEmployee, (ll_len(pArrayListEmployee)) - 1);
            employee_getId(auxEmployee, &lastId);
            itoa(lastId + 1, id, 10);
        }
        /**< INGRESA DATOS */
        pedirStringSoloLetras(nombre, 128, "\nIntroduzca nombre: ", "\nError, nombre invalido. Introduzca nombre nuevamente: ");
        pedirStringDeNumerosPositivo(horasTrabajadas, 15, "\nIntroduzca horas trabajadas: ", "\nError, cantidad de horas invalida. Introduzca horas nuevamente: ");
        pedirStringDeNumerosPositivo(sueldo, 15, "\nIntroduzca sueldo: ", "\nError, sueldo invalido. Introduzca sueldo nuevamente: ");
        /**< CREA EMPLEADO */
        pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        if(pEmployee != NULL)
        {
            printf("\n");
            employee_print(pEmployee);
            respuesta = pedirRespuestaSN("\n\nDesea agregar empleado?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                ll_add(pArrayListEmployee, pEmployee);
                printf("Empleado agregado\n");
            } else
            {
                employee_delete(pEmployee);
                printf("Empleado no agregado\n");
            }
            return 0;
        }
    }
    return 1;
}


/** \brief Modificar datos de empleado. Pide un id al usuario para buscar el empleado a modificar.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtiene el empleado.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    Employee* pEmployee = NULL;
    int opcion;
    int indice;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(pArrayListEmployee != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        indice = controller_findId(pArrayListEmployee, id_aBuscar);
        if(indice > -1)
        {
            printf("\nId encontrado\n");
            printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
            employee_print(pEmployee);
            printf("\n");
            opcion = menuEditEmployee();
            switch(opcion)
            {
                case 1:
                    pedirStringSoloLetras(nombre, 128, "\nIntroduzca el nuevo nombre: ", "\nError, nombre invalido. Introduzca el nuevo nombre: ");
                    employee_setNombre(pEmployee, nombre);
                    printf("\nNombre modificado.\n");
                    employee_print(pEmployee);
                    break;
                case 2:
                    pedirEntero(&horasTrabajadas, "\nIntroduzca la nueva cantidad de horas trabajadas", "\nError cantidad invalida. Introduzca la cantidad nuevamente: ", 0, 400);
                    employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
                    printf("\nCantidad de horas modificada.\n");
                    employee_print(pEmployee);
                    break;
                case 3:
                    pedirEntero(&sueldo, "\nIntroduzca el nuevo sueldo: ", "\nError, sueldo invalido. Introduzca el sueldo nuevamente: ", 1000, 5000000);
                    employee_setSueldo(pEmployee, sueldo);
                    printf("\nSueldo modificado.\n");
                    employee_print(pEmployee);
                    break;
                case 4:
                    printf("\nEmpleado no modificado.\n");
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


/** \brief Baja de empleado. Pide un id al usuario para buscar el empleado a eliminar.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtiene el empleado.
 * \return Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    Employee* pEmployee  = NULL;
    char respuesta;
    int indice;
    if(pArrayListEmployee != NULL)
    {
        pedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        indice = controller_findId(pArrayListEmployee, id_aBuscar);
        if(indice > -1)
        {
            printf("\nId encontrado\n");
            printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
            employee_print(pEmployee);
            respuesta = pedirRespuestaSN("\nDesea eliminar empleado?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee, indice);
                employee_delete(pEmployee);
                printf("\nEmpleado eliminado.\n");
            } else
            {
                printf("\nEmpleado no eliminado.\n");
            }
        } else
        {
            printf("\nId no encontrado.\n");
        }
        return 0;
    }
    return 1;
}

/** \brief Busca el id de un empleado en el LinkedList y devuelve el indice de su posicion.
 *
 * \param pArrayListEmployee LinkedList*  Lista linkeada donde se obtiene el empleado.
 * \param id_aBuscar int Id a buscar.
 * \return int Devuelve -1 (ERROR) si el puntero de la lista es NULL o el id no existe y el indice (OK) si lo encuentra.
 *
 */
int controller_findId(LinkedList* pArrayListEmployee, int id_aBuscar)
{
    Employee* pEmployee = NULL;
    int indice = -1;
    int id;
    if(pArrayListEmployee != NULL && id_aBuscar > 0)
    {
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
            employee_getId(pEmployee, &id);
            if(id == id_aBuscar)
            {
                break;
            }
        }
    }
    return indice;
}

/** \brief Listar empleados. Imprime todos los empleados en la lista linkeada a la pantalla.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int indice;
    if(pArrayListEmployee != NULL)
    {
        printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
                pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
                employee_print(pEmployee);
        }
        return 0;
    }
    return 1;
}


/** \brief Ordenar empleados. Clona la lista linkeada, la ordena segun el criterio, la muestra en pantalla y se elimina sin modificar la original.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    LinkedList* pAuxListEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        pAuxListEmployee = ll_clone(pArrayListEmployee);
        opcion = menuSortEmployee();
        switch(opcion)
        {
            case 1:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareId, 0);
                printf("\nLista de empleados ordenada por Id(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 2:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareNombre, 1);
                printf("\nLista de empleados ordenada por nombre(A-Z).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 3:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareNombre, 0);
                printf("\nLista de empleados ordenada por nombre(Z-A).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 4:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareHorasTrabajadas, 1);
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(menor a mayor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 5:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareHorasTrabajadas, 0);
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 6:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareSueldo, 1);
                printf("\nLista de empleados ordenada por sueldo(menor a mayor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 7:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_compareSueldo, 0);
                printf("\nLista de empleados ordenada por sueldo(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 8:
                printf("\nLista no ordenada.\n");
                break;
        }
        ll_deleteLinkedList(pAuxListEmployee);
        return 0;
    }
    return 1;
}

int controller_filterEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    LinkedList* pAuxListEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        opcion = menuFilterEmployee();
        switch(opcion)
        {
            case 1:
                pAuxListEmployee = ll_filter(pArrayListEmployee, employe_filterNombre);
                if(pAuxListEmployee != NULL)
                {
                    printf("Lista de Empleados filtrada por nombre\n");
                    controller_ListEmployee(pAuxListEmployee);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 2:
                pAuxListEmployee = ll_filter(pArrayListEmployee, employee_filterHorasTrabajadas);
                if(pAuxListEmployee != NULL)
                {
                    printf("Lista de Empleados filtrada por cantidad de horas trabajadas\n");
                    controller_ListEmployee(pAuxListEmployee);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 3:
                pAuxListEmployee = ll_filter(pArrayListEmployee, employee_filterSueldo);
                if(pAuxListEmployee != NULL)
                {
                    printf("Lista de Empleados filtrada por sueldo\n");
                    controller_ListEmployee(pAuxListEmployee);
                }else
                {
                    printf("LISTA NULA\n");
                }
                break;
            case 4:
                printf("\nLista no filtrada\n");
                break;
        }
        ll_deleteLinkedList(pAuxListEmployee);
        return 0;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    Employee* auxEmployee = NULL;
    int indice;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");
            for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
            {
                auxEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
                fprintf(pArchivo, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado.\n");
        return 0;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    Employee* auxEmployee = NULL;
    int indice;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "wb");
        if(pArchivo != NULL)
        {
            for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
            {
                auxEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
                fwrite(auxEmployee, sizeof(Employee), 1, pArchivo);
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado.\n");
        return 0;
    }
    return 1;
}

