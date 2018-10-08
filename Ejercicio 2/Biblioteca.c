#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

/**< 1.0 */

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(array, 13, stdin);
        if(array[(strlen(array) - 1)] != '\n')
        {
            error = 1;
        } else
        {
            /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
            if(comprobarArrayNumericaEntero(array, (strlen(array) - 1)) == 0)
            {
                error = 1;
            }else
            {
                array[(strlen(array) - 1)] = '\0';
                numero = atoi(array);
                if(numero > maximo || numero < minimo)
                {
                    error = 1;
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    } while(error == 1);

    return numero;
}

float pedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo)
{
    char array[45];
    float numero;
    int error;
    int numeroDePuntos;
    int indice;
    printf("%s", mensaje);
    do
    {
        error = 0;
        numeroDePuntos = 0;
        fflush(stdin);
        fgets(array, 45, stdin);
        if((array[(strlen(array) - 1)]) != '\n')
        {
            error = 1;
        }else
        {
            if(array[0] != '-' && isdigit(array[0]) == 0)
            {
                error = 1;
            }else
            {
                for(indice = 1; indice < (strlen(array) - 1); indice++)
                {
                    if(isdigit(array[indice]) == 0 && array[indice] != '.')
                    {
                        error = 1;
                        break;
                    }
                    if(array[indice] == '.' && numeroDePuntos < 2)
                    {
                        numeroDePuntos++;
                    }
                }
                if(numeroDePuntos == 2 && error == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atof(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    }
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    }while(error == 1);

    return numero;
}

int pedirArrayLetrasConEspacio(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    if(arrayLetras != NULL && tamanio > 0)
    {
        int error;
        int indice;
        char arrayAuxiliar[tamanio + 1];
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                if(isalpha(arrayAuxiliar[0]) == 0 || isalpha(arrayAuxiliar[strlen(arrayAuxiliar) - 2]) == 0)
                {
                    error = 1;
                } else
                {
                    for(indice = 1; indice < (strlen(arrayAuxiliar) - 2); indice++)
                    {
                        if(isalpha(arrayAuxiliar[indice]) == 0 && arrayAuxiliar[indice] != ' ')
                        {
                            error = 1;
                        }
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return -1;
}

int pedirArrayAlfanumericaConEspacio(char arrayAlfanumerica[], int tamanio, char mensaje[], char mensajeError[])
{
    if(arrayAlfanumerica != NULL && tamanio > 0)
    {
        int error;
        int indice;
        char arrayAuxiliar[tamanio + 1];
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                if(isalnum(arrayAuxiliar[0]) == 0 || isalnum(arrayAuxiliar[strlen(arrayAuxiliar) - 2]) == 0)
                {
                    error = 1;
                } else
                {
                    for(indice = 1; indice < (strlen(arrayAuxiliar) - 2); indice++)
                    {
                        if(isalnum(arrayAuxiliar[indice]) == 0 && arrayAuxiliar[indice] != ' ')
                        {
                            error = 1;
                        }
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
        strncpy(arrayAlfanumerica, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return -1;
}

char pedirRespuestaSN(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    do
    {
        fflush(stdin);
        respuesta = getchar();
        respuesta = tolower(respuesta);
        if(respuesta != 's' && respuesta != 'n')
        {
            printf("\nRespuesta invalida. Ingrese s(para si) o n (para no): ");
        }
    } while(respuesta != 's' && respuesta != 'n');
    return respuesta;
}

int comprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio)
{
    int retorno = 1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int capitalizarArrayLetras(char arrayLetras[])
{
    int indice;
    if(arrayLetras != NULL)
    {
        strlwr(arrayLetras);
        arrayLetras[0] = toupper(arrayLetras[0]);
        for(indice = strlen(arrayLetras); indice > 1; indice--)
        {
            if(arrayLetras[indice - 1] == ' ')
            {
                arrayLetras[indice] = toupper(arrayLetras[indice]);
            }
        }
        return 0;
    }
    return -1;
}

void ordenarArrayNumerica(int arrayNumerica[],int tamanio)
{
    int indice;
    int j;
    int auxiliar;
    for(indice = 1; indice < tamanio; indice++)
    {
        auxiliar = arrayNumerica[indice];
        j = indice - 1;
        while(j>=0 && auxiliar < arrayNumerica[j])
        {
            arrayNumerica[j+1] = arrayNumerica[j];
            j--;
        }
        arrayNumerica[j+1] = auxiliar;
    }
}
