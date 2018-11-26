#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Estructura.h"

Generica* Generica_nuevo(void)
{
    Generica* pNuevo = (Generica *)malloc(sizeof(Generica));
    return pNuevo;
}

Generica* Generica_nuevoParametrizado(char* idStr, char* nombreStr, char* enteroStr, char* flotanteStr)
{
    Generica* pGenerica = NULL;
    int id;
    int entero;
    float flotante;
    if(idStr != NULL && nombreStr != NULL && enteroStr != NULL && flotanteStr != NULL)
    {
        pGenerica = Generica_nuevo();
        if(pGenerica != NULL)
        {
            id = atoi(idStr);
            entero = atoi(enteroStr);
            flotante = atof(flotanteStr);
            Generica_setId(pGenerica, id);
            Generica_setNombre(pGenerica, nombreStr);
            Generica_setEntero(pGenerica, entero);
            Generica_setFlotante(pGenerica, flotante);
        }

    }
    return pGenerica;
}

void Generica_eliminar(Generica* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief  Establece el id.
 *
 * \param this Generica*
 * \param id int
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int Generica_setId(Generica* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 0;
    }
    return 1;
}


int Generica_getId(Generica* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 0;
    }
    return 1;
}


int Generica_setNombre(Generica* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        return 0;
    }
    return 1;
}


int Generica_getNombre(Generica* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        return 0;
    }
    return 1;
}


int Generica_setEntero(Generica* this,int entero)
{
    if(this != NULL)
    {
        this->entero = entero;
        return 0;
    }
    return 1;
}


int Generica_getEntero(Generica* this,int* entero)
{
    if(this != NULL && entero != NULL)
    {
        *entero = this->entero;
        return 0;
    }
    return 1;
}


int Generica_setFlotante(Generica* this, float flotante)
{
    if(this != NULL)
    {
        this->flotante = flotante;
        return 0;
    }
    return 1;
}


int Generica_getFlotante(Generica* this,float* flotante)
{
    if(this != NULL && flotante != NULL)
    {
        *flotante = this->flotante;
        return 0;
    }
    return 1;
}


int Generica_print(Generica* this)
{
    if(this != NULL)
    {
        printf("%5d | %15s | %10d | %8.2f\n", this->id, this->nombre, this->entero, this->flotante);
        return 0;
    }
    return 1;
}


int Generica_compararId(void* this, void* thisDos)
{
    int retorno;
    Generica* pGenerica = NULL;
    Generica* pGenericaDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pGenerica = (Generica*)this;
        pGenericaDos = (Generica*)thisDos;
        if(pGenerica->id > pGenericaDos->id)
        {
            retorno = 1;
        } else if(pGenerica->id < pGenericaDos->id)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}


int Generica_compararNombre(void* this, void* thisDos)
{
    int retorno;
    Generica* pGenerica = NULL;
    Generica* pGenericaDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pGenerica = (Generica*)this;
        pGenericaDos = (Generica*)thisDos;
        retorno = strcmp(pGenerica->nombre, pGenericaDos->nombre);
    }
    return retorno;

}


int Generica_compararEntero(void* this, void* thisDos)
{
    int retorno;
    Generica* pGenerica = NULL;
    Generica* pGenericaDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pGenerica = (Generica*)this;
        pGenericaDos = (Generica*)thisDos;
        if(pGenerica->entero > pGenericaDos->entero)
        {
            retorno = 1;
        } else if(pGenerica->entero < pGenericaDos->entero)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

int Generica_compararFlotante(void* this, void* thisDos)
{
    int retorno;
    Generica* pGenerica = NULL;
    Generica* pGenericaDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        pGenerica = (Generica*)this;
        pGenericaDos = (Generica*)thisDos;
        if(pGenerica->flotante > pGenericaDos->flotante)
        {
            retorno = 1;
        } else if(pGenerica->flotante < pGenericaDos->flotante)
        {
            retorno = -1;
        } else
        {
            retorno = 0;
        }

    }
    return retorno;
}

int Generica_filtrarNombre(void* this)
{
    int retorno = -1;
    Generica* pGenerica = NULL;
    if(this != NULL)
    {
        pGenerica = (Generica *)this;
        if(pGenerica->nombre[0] == 'C')
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int Generica_filtrarFlotante(void* this)
{
    int retorno = -1;
    Generica* pGenerica = NULL;
    if(this != NULL)
    {
        pGenerica = (Generica *)this;
        if(pGenerica->flotante >= 100)
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int Generica_filtrarEntero(void* this)
{
    int retorno = -1;
    Generica* pGenerica = NULL;
    if(this != NULL)
    {
        pGenerica = (Generica *)this;
        if(pGenerica->entero >= 500)
        {
            retorno = 1;
        }else
        {
            retorno = 0;
        }
    }
    return retorno;
}
