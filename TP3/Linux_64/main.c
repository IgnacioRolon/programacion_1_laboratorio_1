#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    //Employee* pEmpleado;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getUnsignedInt("\n1) Cargar desde el archivo en modo texto\n2) Agregar Empleado\n3) Listar Empleados\n10) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &option);
        __fpurge(stdin);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_addEmployee(listaEmpleados);
                break;
            case 3:
                controller_ListEmployee(listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
