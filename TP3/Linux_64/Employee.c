#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"
#include <string.h>

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    Employee* retorno = NULL;
    Employee* pAuxEmpleado;
    if(id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
    {
        pAuxEmpleado = employee_new();
        if(pAuxEmpleado != NULL)
        {
            if( !employee_setIdAsString(pAuxEmpleado, id) && !employee_setNombre(pAuxEmpleado, nombre) &&
                !employee_setHorasTrabajadasAsString(pAuxEmpleado, horasTrabajadas) && !employee_setSueldoAsString(pAuxEmpleado, sueldo))
            {
                retorno = pAuxEmpleado;
            }else
            {
                employee_delete(pAuxEmpleado);
            }
        }
    }
    return retorno;
}

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int employee_setIdAsString(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(isValidNumber(id))
        {
            retorno = employee_setId(this, atoi(id));
        }

    }
    return retorno;
}

int employee_getIdAsString(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        employee_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasAsString(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        if(isValidNumber(horasTrabajadas))
        {
            retorno = employee_setHorasTrabajadas(this, atoi(horasTrabajadas));
        }
    }
    return retorno;
}

int employee_getHorasTrabajadasAsString(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferHorasTrabajadas;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferHorasTrabajadas = this->horasTrabajadas;
        sprintf(resultado, "%d", bufferHorasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoAsString(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        if(isValidNumber(sueldo))
        {
            retorno = employee_setSueldo(this, atoi(sueldo));
        }
    }
    return retorno;
}

int employee_getSueldoAsString(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferSueldo;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferSueldo = this->sueldo;
        sprintf(resultado, "%d", bufferSueldo);
        retorno = 0;
    }
    return retorno;
}

int employee_compararPorNombre(Employee* this1, Employee* this2)
{
    int retorno = -2;
    if(this1 != NULL && this2 != NULL)
    {
        retorno = strncmp(this1->nombre, this2->nombre, sizeof(this1->nombre));
    }
    return retorno;
}
