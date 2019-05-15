#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "utn.h"
#include <string.h>

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;
    if(this != NULL && peso >= 20)
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Emp_setEstado(Empleado* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_compararPorNombre(Empleado* this1, Empleado* this2)
{
    int retorno = -2;
    if(this1 != NULL && this2 != NULL)
    {
        retorno = strncmp(this1->nombre, this2->nombre, sizeof(this1->nombre));
    }
    return retorno;
}




