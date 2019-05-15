#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "utn.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int limite = 2;
    int indiceActual;
    int auxInt;
    //float auxFloat;
    char auxName[50];
    //char auxName2[50];

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();

    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        for(int i=0;i<limite;i++)
        {
            pArrayEmpleado[i] =  Emp_new();
            utn_getName("\nIngrese el nombre: ", "Error", 0, 50, 5, auxName);
            if(!Emp_setId(pArrayEmpleado[i],14)
                && !Emp_setEstado(pArrayEmpleado[i], 1)
                && !Emp_setNombre(pArrayEmpleado[i], auxName)
                && !Emp_setPeso(pArrayEmpleado[i], 65))
            {
                Emp_getNombre(pArrayEmpleado[i], auxName);
                printf("\nNombre: %s", auxName);
                printf("Ingreso OK");
            }
        }
        //auxInt = Emp_compararPorNombre(pArrayEmpleado[0], pArrayEmpleado[1]);
        //printf("Comparacion: %d", auxInt);
    }


    return 0;
}
