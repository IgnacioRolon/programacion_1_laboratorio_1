#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"
#include <string.h>

Persona* Pers_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Pers_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Pers_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Pers_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int Pers_setIdAsString(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(isValidNumber(id))
        {
            retorno = Pers_setId(this, atoi(id));
        }

    }
    return retorno;
}

//transformar String

int Pers_getIdAsString(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        Pers_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

int Pers_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Pers_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Pers_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Pers_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Pers_setEstadoAsString(Persona* this, char* estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        if(strcmp(estado, "true"))
        {
            strcpy(estado, "1");
        }
        if(strcmp(estado, "false"))
        {
            strcpy(estado, "0");
        }
        if(isValidNumber(estado))
        {
            retorno = Pers_setEstado(this, atoi(estado));
        }

    }
    return retorno;
}

int Pers_getEstadoAsString(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferEstado;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferEstado = this->estado;
        sprintf(resultado, "%d", bufferEstado);
        retorno = 0;
    }
    return retorno;
}


//hacer getter

int Pers_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && isValidName(apellido))
    {
        strncpy(this->apellido, apellido, sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int Pers_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->apellido, sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int Pers_compararPorNombre(Persona* this1, Persona* this2)
{
    int retorno = -2;
    if(this1 != NULL && this2 != NULL)
    {
        retorno = strncmp(this1->nombre, this2->nombre, sizeof(this1->nombre));
    }
    return retorno;
}

Persona* Pers_newStr(char* id, char* nombre, char* apellido, char* estado)
{
    Persona* retorno = NULL;
    Persona* pAuxEmpleado;
    if(id != NULL && nombre != NULL && apellido != NULL && estado != NULL)
    {
        pAuxEmpleado = Pers_new();
        if(pAuxEmpleado != NULL)
        {
            if( !Pers_setIdAsString(pAuxEmpleado, id) && !Pers_setNombre(pAuxEmpleado, nombre) &&
                !Pers_setApellido(pAuxEmpleado, apellido) && !Pers_setEstadoAsString(pAuxEmpleado, estado))
            {
                retorno = pAuxEmpleado;
            }else
            {
                Pers_delete(pAuxEmpleado);
            }
        }
    }
    return retorno;
}

int Pers_dump(Persona* this, FILE *pFile)
{
    int retorno = -1;
    if(this != NULL && pFile != NULL)
    {
        fprintf(pFile, "id,first_name,last_name,is_empty\n");

    }
}
