#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int archivoDataCargado = 0;
    do
    {
        printf("BIENVENIDO\n");
        opcion = menuPrincipal();
        system("cls");
        switch(opcion)
        {
            case 1:
                if(archivoDataCargado == 0)
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    archivoDataCargado = 1;
                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                if(archivoDataCargado == 0)
                {
                    if((controller_loadFromBinary("data.bin", listaEmpleados)) == 0)
                    {
                        archivoDataCargado = 1;
                    }
                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                if(archivoDataCargado == 1)
                {
                    controller_addEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                if(archivoDataCargado == 1)
                {
                    printf("MODIFICAR EMPLEADO\n");
                    controller_editEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                if(archivoDataCargado == 1)
                {
                    printf("BAJA EMPLEADO\n");
                    controller_removeEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                if(archivoDataCargado == 1)
                {
                    printf("LISTAR EMPLEADOS\n\n");
                    controller_ListEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                if(archivoDataCargado == 1)
                {
                    printf("ORDENAR EMPLEADOS\n");
                    controller_sortEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 8:
                if(archivoDataCargado == 1)
                {
                    printf("FILTRAR EMPLEADOS\n");
                    controller_filterEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 9:
                if(archivoDataCargado == 1)
                {
                    controller_saveAsText("data.csv", listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 10:
                if(archivoDataCargado == 1)
                {
                    controller_saveAsBinary("data.bin", listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 11:
                break;
        }
    }while(opcion != 11);

    printf("Gracias por usar la aplicacion\n");

    return 0;
}
