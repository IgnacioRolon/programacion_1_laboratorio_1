#include "Empleado.h"
#include <string.h>
#include <stdio.h>

int emp_initArray(Empleado array[], int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        array[i].isEmpty = 1;
    }
    return 0;
}

int emp_lugarLibreArray(Empleado array[], int limite, int* indice)
{
    int i;
    int retorno = -1;
    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty)
        {
            *indice = i;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int emp_altaArray(Empleado array[], int limite, int id)
{
    char buffer[limite];
    int index;
    emp_lugarLibreArray(array, limite, &index);
    printf("\n Ingrese el nombre el empleado: ");
    fgets(buffer,limite, stdin);
    array[index].idEmpleado = id;
    strncpy(array[index].nombre, buffer, limite);
    array[index].isEmpty = 0;
    return 0;
}
