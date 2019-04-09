#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAXSIZE 256
/*
    strncpy(nombre, nombre2,sizeof(nombre));
    printf("\n%s", nombre);
    fgets(nombre, sizeof(nombre), stdin);
    printf("\n%s", nombre);
*/

int main()
{
    char buffer[MAXSIZE];
    char name[MAXSIZE];
    printf("Ingrese su nombre: ");
    fgets(buffer, sizeof(buffer), stdin);
    if(isStrOnlyChar(buffer))
    {
        strncpy(name, buffer, sizeof(name));
        printf("\nSu nombre es: %s", name);
    }else
    {
        printf("\nSu nombre no es valido.");
    }

}

