#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"

int main()
{
    Persona *pArrayPersona[2000];
    int ultimoElementoArrayPersona = 0;
    //int limite = 2;
    int indiceActual;
    int i = 0;
    int flag=0;
    char bufferId[50];
    char bufferName[50];
    char bufferApellido[50];
    char bufferEstado[50];

    FILE *pFile = NULL;
    pFile = fopen("data.csv", "r");

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Pers_new();

    if(pFile != NULL && pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferApellido, bufferEstado);
            if(flag == 0)
            {
                flag++;
                continue;
            }
            if(pArrayPersona[i] = Pers_new() != NULL)
            {
                Pers_setFromFile(pArrayPersona[i], bufferId, bufferName, bufferApellido, bufferEstado);
            }
            i++;
        }
        Pers_getApellido(pArrayPersona[50], bufferApellido);
        printf("Apellido: %s", bufferApellido);
    }

/*
    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Pers_new();

    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        for(int i=0;i<limite;i++)
        {
            pArrayPersona[i] =  Pers_new();
            utn_getName("\nIngrese el nombre: ", "Error", 0, 50, 5, auxName);
            utn_getName("\nIngrese el apellido: ", "Error", 0, 50, 5, auxName2);
            __fpurge(stdin);
            if(!Pers_setId(pArrayPersona[i],14)
                && !Pers_setEstado(pArrayPersona[i], 1)
                && !Pers_setNombre(pArrayPersona[i], auxName)
                && !Pers_setApellido(pArrayPersona[i], auxName2))
            {
                Pers_getNombre(pArrayPersona[i], auxName);
                Pers_getApellido(pArrayPersona[i], auxName2);
                printf("\nNombre: %s", auxName);
                printf("\nApellido: %s\n", auxName2);
                printf("Ingreso OK\n");
            }
        }
        //auxInt = Pers_compararPorNombre(pArrayPersona[0], pArrayPersona[1]);
        //printf("Comparacion: %d", auxInt);
    }

*/
    return 0;
}
