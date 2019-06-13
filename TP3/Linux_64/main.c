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
        utn_getUnsignedInt("\n1) Cargar desde el archivo en modo texto\n2) Cargar desde el archivo en modo binario\n3) Agregar Empleado\n4) Listar Empleados\n5) Modificar Empleado\n6) Eliminar Empleado\n7) Ordenar empleados por nombre\n8) Guardar el archivo en modo binario\n9) Guardar el archivo en modo texto\n10) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &option);
        __fpurge(stdin);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_ListEmployee(listaEmpleados);
                break;
            case 5:
                controller_editEmployee(listaEmpleados);
                break;
            case 6:
                controller_removeEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsBinary("data.bin", listaEmpleados);
                break;
            case 9:
                controller_saveAsText("data.csv", listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
