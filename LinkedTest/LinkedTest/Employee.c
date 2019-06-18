#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"
#include <string.h>


/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Employee* posición de memoria de employee.
 *
 */


Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* nombre
 * \param3 char* horasTrabajadas
 * \param4 char* sueldo
 * \return retorno Employee*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


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

/** \brief Elimina un empleado.
 *
 * \param1 this Employee* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


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

/** \brief Define el ID de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

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

/** \brief Obtiene el ID de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

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

/** \brief Define el ID de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


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

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

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

/** \brief Define el nombre de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 nombre char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

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

/** \brief Obtiene el nombre de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

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

/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 horasTrabajadas int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

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

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

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

/** \brief Define las horas trabajadas de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 horasTrabajadas char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

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

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

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

/** \brief Define el sueldo de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 sueldo int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

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

/** \brief Obtiene el sueldo de un empleado.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

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

/** \brief Define el sueldo de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 sueldo char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

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

/** \brief Define el sueldo de un empleado como string.
 *
 * \param1 this Employee* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

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

/** \brief Devuelve el resultado de una comparación entre 2 nombres de empleado.
 *
 * \param1 this1 void* Primer empleado.
 * \param2 this2 void* Segundo empleado
 * \return retorno int. 0 si los nombres son iguales
 *                      1 si el primero es mayor
 *                      -1 si el segundo es mayor.
 *
 */

int employee_compararPorNombre(void* this1, void* this2)
{
    int retorno = 0;
    int compareResult;
    char name1[4096];
    char name2[4096];
    employee_getNombre((Employee*)this1, name1);
    employee_getNombre((Employee*)this2, name2);
    if(this1 != NULL && this2 != NULL)
    {
        compareResult = strcmp(name1, name2);
    }
    if(compareResult > 0)
    {
        retorno = 1;
    }else if(compareResult <0)
    {
        retorno = -1;
    }
    return retorno;
}
