#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return retorno int. 0 si salio todo bien, -1 si no se pudo completar la operacion.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int flag=0;
    char bufferId[50];
    char bufferName[128];
    char bufferHoras[50];
    char bufferSueldo[50];

    Employee* pEmployee;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras, bufferSueldo);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pEmployee = employee_newParametros(bufferId, bufferName, bufferHoras, bufferSueldo);
        if(pEmployee != NULL)
        {
            ll_add(pArrayListEmployee, pEmployee);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
