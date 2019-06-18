#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(void* pElement);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados = ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(!controller_loadFromText("data.csv",listaEmpleados))
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);
        controller_ListEmployee(listaEmpleados);

        // Generar archivo de salida
        if(!controller_saveAsText("sueldos.csv", listaEmpleados))
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");

        ll_reduce(listaEmpleados, generarArchivoSueldos);

        if(!controller_saveAsText("sueldosMayoresA25.csv", listaEmpleados))
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}

int generarArchivoSueldos(void* pElement)
{
    Employee* localEmp = (Employee*)pElement;
    if(localEmp->sueldo < 25000)
    {
        return 1;
    }else{
        return 0;
    }
}
