#include <stdio.h>
#include <stdlib.h>
#include "entregas.h"
#include "utn.h"
#include <string.h>


/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Entrega* posición de memoria de entrega.
 *
 */


Entrega* entrega_new(void)
{
    return (Entrega*) malloc(sizeof(Entrega));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* tipo
 * \param3 char* cantidad
 * \param4 char* importe
 * \return retorno Entrega*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


Entrega* entrega_newParametros(char* id, char* tipo, char* cantidad, char* importe)
{
    Entrega* retorno = NULL;
    Entrega* pAuxEmpleado;
    if(id != NULL && tipo != NULL && cantidad != NULL && importe != NULL)
    {
        pAuxEmpleado = entrega_new();
        if(pAuxEmpleado != NULL)
        {
            if( !entrega_setIdAsString(pAuxEmpleado, id) && !entrega_setTipo(pAuxEmpleado, tipo) &&
                !entrega_setCantidadAsString(pAuxEmpleado, cantidad) && !entrega_setImporteAsString(pAuxEmpleado, importe))
            {
                retorno = pAuxEmpleado;
            }else
            {
                entrega_delete(pAuxEmpleado);
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param1 this Entrega* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


int entrega_delete(Entrega* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int entrega_setId(Entrega* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int entrega_getId(Entrega* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


int entrega_setIdAsString(Entrega* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(isValidNumber(id))
        {
            retorno = entrega_setId(this, atoi(id));
        }

    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int entrega_getIdAsString(Entrega* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        entrega_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el tipo de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 tipo char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int entrega_setTipo(Entrega* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && isValidName(tipo))
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el tipo de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int entrega_getTipo(Entrega* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 cantidad int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int entrega_setCantidad(Entrega* this, int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int entrega_getCantidad(Entrega* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 cantidad char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int entrega_setCantidadAsString(Entrega* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        if(isValidNumber(cantidad))
        {
            retorno = entrega_setCantidad(this, atoi(cantidad));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int entrega_getCantidadAsString(Entrega* this, char* resultado)
{
    int retorno = -1;
    int bufferCantidad;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferCantidad = this->cantidad;
        sprintf(resultado, "%d", bufferCantidad);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el importe de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 importe int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int entrega_setImporte(Entrega* this, float importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el importe de un empleado.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int entrega_getImporte(Entrega* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el importe de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 importe char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int entrega_setImporteAsString(Entrega* this, char* importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        if(isValidFloatNumber(importe))
        {
            retorno = entrega_setImporte(this, atof(importe));
        }
    }
    return retorno;
}

/** \brief Define el importe de un empleado como string.
 *
 * \param1 this Entrega* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int entrega_getImporteAsString(Entrega* this, char* resultado)
{
    int retorno = -1;
    int bufferImporte;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferImporte = this->importe;
        sprintf(resultado, "%d", bufferImporte);
        retorno = 0;
    }
    return retorno;
}

int entrega_filtrarGold(void* this)
{
    int retorno = -1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "GOLD");
    if(!comparison)
        retorno = 1;

    return retorno;
}

int entrega_filtrarPlus(void* this)
{
    int retorno = -1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "PLUS");
    if(!comparison)
        retorno = 1;

    return retorno;
}

int entrega_filtrarRegular(void* this)
{
    int retorno = -1;
    Entrega* auxEntrega = (Entrega*)this;
    int comparison = strcmp(auxEntrega->tipo, "REGULAR");
    if(!comparison)
        retorno = 1;

    return retorno;
}

