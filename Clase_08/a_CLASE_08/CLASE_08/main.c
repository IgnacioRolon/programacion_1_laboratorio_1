#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define MAXNAMELENGTH 25
#define QTY_EMPLEADOS 100

int showArray(char arrayString[][50], int qtyValues);
int initializeArray(char arrayString[][50], int qtyValues);
int findEmptyArray(char arrayString[][50], int qtyValues);
int findStringinArray(char arrayString[][50], int qtyValues, char* nombre);

int main()
{
    char bufferStr[1];
    char arrayNombres[QTY_EMPLEADOS][MAXNAMELENGTH];
    char arrayName[50];
    int respuesta;
    int emptyIndex;

    //testeo
    strncpy(arrayNombres[0],"Juan",MAXNAMELENGTH);
    strncpy(arrayNombres[1],"Veronica",MAXNAMELENGTH);
    strncpy(arrayNombres[2],"Carolina",MAXNAMELENGTH);
    //testeo
    initializeArray(arrayNombres, QTY_EMPLEADOS);
    int i;

    while(respuesta != 5)
    {
        printf("\n1- Ingresar nombre no repetido\n");
        printf("2- Listar nombres\n");
        printf("3- Ordenar nombres\n");
        printf("4- Borrar nombre\n");
        printf("5- Salir\n");
        scanf("%d", &respuesta);
        __fpurge(stdin);
        switch(respuesta)
        {
            case 1:
            getName("Ingrese un nombre: ", "Error", 2, MAXNAMELENGTH, 3, arrayName);
            while(findStringinArray(arrayNombres, QTY_EMPLEADOS, arrayName) >= 0)
            {
                printf("\nEl nombre está repetido.");
                getName(" Ingreselo nuevamente: ", "Error", 2, MAXNAMELENGTH, 3, arrayName);
            }
            emptyIndex = findEmptyArray(arrayNombres, QTY_EMPLEADOS);
            strncpy(arrayNombres[emptyIndex], arrayName, MAXNAMELENGTH);
            printf("%s", arrayNombres[emptyIndex]);
            break;

            case 2:
            i = 0;
            while(strncmp(arrayNombres[i], "\0", MAXNAMELENGTH) != 0)
            {
                printf("%s\n",arrayNombres[i]);
                i++;
            }
            break;

            case 3:


            break;

            case 4:
            getName("Ingrese el nombre a borrar: ", "Error", 2, MAXNAMELENGTH, 3, arrayName);
            emptyIndex = findStringinArray(arrayNombres, QTY_EMPLEADOS, arrayName);
            if(emptyIndex >= 0)
            {
                strncpy(arrayNombres[emptyIndex], "\0", MAXNAMELENGTH);
            }
            break;
        }
    }

}


int showArray(char arrayString[][50], int qtyValues)
{
    int i;
    for(i = 0; i <= qtyValues; i++)
    {
        printf("%s\n", arrayString[i]);
    }
    return 0;
}

int initializeArray(char arrayString[][50], int qtyValues)
{
    int i;
    for(i = 0; i < qtyValues; i++)
    {
        strncpy(arrayString[i], "\0", 50);
    }
    return 0;
}

int findEmptyArray(char arrayString[][50], int qtyValues)
{
    int i;
    int retorno = -1;
    for(i = 0; i < qtyValues; i++)
    {
        if(strcmp(arrayString[i], "\0") == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int findStringinArray(char arrayString[][50], int qtyValues, char *nombre)
{
    int i;
    int retorno = -1;
    for(i = 0; i < qtyValues; i++)
    {
        if(strcmp(arrayString[i], nombre) == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
