#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

int pedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    if(pEntero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                array[(strlen(array) - 1)] = '\0';
                /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
               if(comprobarString_numeroEntero(array, strlen(array)) == 0)
                {
                    error = 1;
                }else
                {
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pEntero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return 1;
}

int pedirFlotante(float* pNumero, char mensaje[], char mensajeError[], float minimo, float maximo)
{
    char array[13];
    float numero;
    int error;
    if(pNumero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                array[(strlen(array) - 1)] = '\0';
                /**Devuelve 1 si ES FLOTANTE y 0 si NO ES */
               if(comprobarString_numeroFlotante(array, strlen(array)) == 0)
                {
                    error = 1;
                }else
                {
                    numero = atof(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pNumero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return 1;
}


int pedirString_NumeroEnteroPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if(arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE FORME UN NUMERO ENTERO POSITIVO*/
                if(comprobarString_numeroEnteroPositivo(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);
        strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar) + 1);
        return 0;
    }
    return 1;
}

int pedirString_NumeroFlotantePositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if(arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE FORME UN NUMERO FLOTANTE POSITIVO*/
                if(comprobarString_numeroFlotantePositivo(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);
        strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar) + 1);
        return 0;
    }
    return 1;
}

int pedirString_caracteresAlfabeticos(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                printf("\nLINEA 1\n");
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE ESTE FORMADO POR LETRAS*/
                if(comprobarString_caracteresAlfabeticos(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    printf("\nLINEA 2\n");
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return 1;
}

int pedirString_caracteresAlfabeticosEspaciados(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            /**< EVALUA QUE EL LARGO DEL STRING INTRODUCIDO SEA CORRECTO*/
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                /**< COMPRUEBA QUE ESTE FORMADO POR LETRAS Y ESPACIO*/
                if(comprobarString_caracteresAlfabeticosEspaciados(arrayAuxiliar, strlen(arrayAuxiliar)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return 1;
}

int comprobarString_numeroEnteroPositivo(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0; indice < tamanio; indice++)
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

int comprobarString_numeroEntero(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
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

int comprobarString_numeroFlotante(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int cantidadPuntos = 0;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(cadenaNumerica[indice] == '.')
            {
                cantidadPuntos++;
                if(cantidadPuntos > 1)
                {
                    retorno = 0;
                    break;
                }
            }else
            {
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int comprobarString_numeroFlotantePositivo(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int cantidadPuntos = 0;
    int indice;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0 ; indice < tamanio; indice++)
        {
            if(cadenaNumerica[indice] == '.')
            {
                cantidadPuntos++;
                if(cantidadPuntos > 1)
                {
                    retorno = 0;
                    break;
                }
            }else
            {
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int comprobarString_caracteresAlfabeticos(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isalpha(stringLetras[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int comprobarString_caracteresAlfabeticosEspaciados(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        for(indice = 0; indice < tamanio; indice++)
        {
            if(isalpha(stringLetras[indice]) == 0 && stringLetras[indice] != ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
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
