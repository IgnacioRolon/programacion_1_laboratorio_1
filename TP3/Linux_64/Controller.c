#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


int controller_arrayMaxID(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int length;
    int currentID;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);
        for(i=0;i<length;i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            employee_getId(pAux, &currentID);
            if(currentID > maxID)
            {
                maxID = currentID;
            }
        }
    }
    maxID += 1;
    return maxID;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                printf("Carga exitosa.");
                retorno = 0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pAux  = employee_new();
    char bufferChar[128];
    int bufferInt;
    int id;
    if(pArrayListEmployee != NULL && pAux != NULL)
    {
        id = controller_arrayMaxID(pArrayListEmployee);
        if(id != -1)
        {
            employee_setId(pAux, id);
            if(!utn_getName("\nIngrese el nombre: ", "\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128, 2, bufferChar))
            {
                employee_setNombre(pAux, bufferChar);
            }
            if(!utn_getUnsignedInt("\nIngrese las horas trabajadas: ", "\nError: Horas invalidas. Ingreselo nuevamente: ", 0, 3, 0, 24, 2, &bufferInt))
            {
                employee_setHorasTrabajadas(pAux, bufferInt);
            }
            if(!utn_getUnsignedInt("\nIngrese el sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: ", 0, 100, 0, 1000000, 2, &bufferInt))
            {
                employee_setSueldo(pAux, bufferInt);
            }
            ll_add(pArrayListEmployee, pAux);
            printf("\nEmpleado ingresado correctamente\n");
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int auxID, auxSueldo, auxHoras;
    char bufferChar[128];
    int length;
    int i;
    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);
        for(i=0;i<length;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado, &auxID);
            employee_getSueldo(pEmpleado, &auxSueldo);
            employee_getHorasTrabajadas(pEmpleado, &auxHoras);
            employee_getNombre(pEmpleado, bufferChar);
            printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: $%d\n", auxID, bufferChar, auxHoras, auxSueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}
