#include <stdio.h>
#include <stdlib.h>
#include "Estructura.h"
#include "Menu.h"
#include "LinkedList.h"
#include "Controlador.h"

int main()
{
    int opcion;
    LinkedList* lista = ll_newLinkedList();
    int archivoDataCargado = 0;
    do
    {
        printf("BIENVENIDO\n");
        printf("\n");
        opcion = menuPrincipal();
        system("cls");
        switch(opcion)
        {
            case 1:
                if(archivoDataCargado == 0)
                {
                    controlador_cargarTxt("ejemplo.csv", lista);
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
                    if((controlador_cargarBinario("ejemplo.bin", lista)) == 0)
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
                    printf("ALTA\n");
                    controlador_altaGenerica(lista);
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
                    printf("MODIFICAR\n");
                    controlador_modificarGenerica(lista);
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
                    printf("BAJA\n");
                    controlador_bajaGenerica(lista);
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
                    printf("LISTAR\n\n");
                    controlador_printLinkedListGenerica(lista);
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
                    printf("ORDENAR\n"),
                    controlador_ordenarGenerica(lista);
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
                    printf("FILTRAR\n");
                    controlador_filtrarGenerica(lista);
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
                    printf("INFORMES\n");
                    controlador_informes(lista);
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
                    controlador_guardarTxt("ejemplo.csv", lista);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 11:
                if(archivoDataCargado == 1)
                {
                    controlador_guardarBinario("ejemplo.bin", lista);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 12:
                break;
        }
    }while(opcion != 12);

    printf("Gracias por usar la aplicacion\n");
    return 0;
}
