#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Estructura.h"

eEmpleado* eEmpleado_nuevo(void)
{
    eEmpleado* pNuevo = (eEmpleado *)malloc(sizeof(eEmpleado));
    return pNuevo;
}

eEmpleado* eEmpleado_nuevoParametrizado(char* idStr, char* nombreStr, char* direccionStr, char* horasTrabajadasStr, char* sueldoStr)
{
    eEmpleado* peEmpleado = NULL;
    int id;
    int horasTrabajadas;
    int sueldo;
    if(idStr != NULL && nombreStr != NULL && direccionStr!= NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        peEmpleado = eEmpleado_nuevo();
        if(peEmpleado != NULL)
        {
            id = atoi(idStr);
            horasTrabajadas = atoi(horasTrabajadasStr);
            sueldo = atoi(sueldoStr);
            eEmpleado_setId(peEmpleado, id);
            eEmpleado_setNombre(peEmpleado, nombreStr);
            eEmpleado_setDireccion(peEmpleado, direccionStr);
            eEmpleado_setHorasTrabajadas(peEmpleado, horasTrabajadas);
            eEmpleado_setSueldo(peEmpleado, sueldo);
        }

    }
    return peEmpleado;
}

void eEmpleado_eliminar(eEmpleado* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int eEmpleado_setId(eEmpleado* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 0;
    }
    return 1;
}


int eEmpleado_getId(eEmpleado* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 0;
    }
    return 1;
}


int eEmpleado_setNombre(eEmpleado* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        return 0;
    }
    return 1;
}


int eEmpleado_getNombre(eEmpleado* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        return 0;
    }
    return 1;
}

int eEmpleado_getDireccion(eEmpleado* this, char* direccion)
{
    if(this != NULL && direccion != NULL)
    {
        strcpy(direccion, this->direccion);
        return 0;
    }
    return 1;
}

int eEmpleado_setDireccion(eEmpleado* this, char* direccion)
{
    if(this != NULL && direccion != NULL)
    {
        strcpy(this->direccion, direccion);
        return 0;
    }
    return 1;
}

int eEmpleado_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas)
{
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 0;
    }
    return 1;
}

int eEmpleado_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    return 1;
}

int eEmpleado_setSueldo(eEmpleado* this,int sueldo)
{
    if(this != NULL)
    {
        this->sueldo = sueldo;
        return 0;
    }
    return 1;
}

int eEmpleado_getSueldo(eEmpleado* this,int* sueldo)
{
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        return 0;
    }
    return 1;
}

int eEmpleado_print(eEmpleado* this)
{
    if(this != NULL)
    {
        printf("%5d | %15s | %30s | %20d\n", this->id, this->nombre, this->direccion, this->horasTrabajadas);
        return 0;
    }
    return 1;
}

int eEmpleado_compararNombre(void* this, void* thisDos)
{
    int retorno;
    eEmpleado* peEmpleado = NULL;
    eEmpleado* peEmpleadoDos = NULL;
    if(this != NULL && thisDos != NULL)
    {
        peEmpleado = (eEmpleado*)this;
        peEmpleadoDos = (eEmpleado*)thisDos;
        retorno = strcmp(peEmpleado->nombre, peEmpleadoDos->nombre);
    }
    return retorno;
}

int eEmpleado_calcularSueldo(void* this)
{
    eEmpleado* peEmpleado = NULL;
    int retorno = -1;
    int horasTrabajadas;
    int cantidad = 0;
    int cantidadDos = 0;
    int cantidadTres = 0;
    int sueldo;
    if(this != NULL)
    {
        peEmpleado = (eEmpleado *)this;
        eEmpleado_getHorasTrabajadas(peEmpleado, &horasTrabajadas);
        if(horasTrabajadas <= 120)
        {
            cantidad = horasTrabajadas * 180;
        }
        if(horasTrabajadas <= 160)
        {
            cantidad = 120 * 180;
            cantidadDos = (horasTrabajadas - 120) * 240;
        }
        if(horasTrabajadas <= 240)
        {
            cantidad = 120 * 180;
            cantidadDos = 40 * 240;
            cantidadTres = (horasTrabajadas - 160) * 350;
        }
        sueldo = cantidad + cantidadDos + cantidadTres;
        peEmpleado->sueldo = sueldo;
    }
    return retorno;
}
