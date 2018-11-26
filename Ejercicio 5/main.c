#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Estructura.h"
#include "LinkedList.h"
#include "Controlador.h"

int main()
{
    int opcion;
    LinkedList* lista = ll_newLinkedList();
    controlador_cargarEmpleados("empleados.csv", lista);
    do
    {
        printf("BIENVENIDO\n");
        printf("\n");
        printf("1) Listar\n");
        printf("2) Generar sueldo.csv\n");
        printf("3) Salir\n");
        pedirEntero(&opcion, "Introduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion: " ,1, 3);
        system("cls");
        switch(opcion)
        {
            case 1:
                controlador_ordenareEmpleado(lista);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                controlador_generarSueldo(lista);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                break;
        }
    }while(opcion != 3);

    printf("Gracias por usar la aplicacion\n");
    return 0;
}
