#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "Empleado.h"

#define LEN_LISTA    100
#define LIMITE 50






int buscarLibre(char lista[][20],
                int len,
                int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len ; i++)
    {
        if(lista[i][0]=='\0')
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;

}


int buscarNombre(char* pNombre,
                 char lista[][20],
                 int len,
                 int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(strcmp(pNombre,lista[i])==0)
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;


}

int main()
{

    int opcion;
    char nombres[LEN_LISTA][20];
    int i,posLibre, posAeliminar;
    char buffer[20];

    int idEmp = 0;
    int freeIndex;

    Empleado empleados[LIMITE];

    emp_initArray(empleados, LIMITE);

    for(i=0; i<LEN_LISTA;i++)
        nombres[i][0]='\0';

    while(1)
    {
        utn_getNumber(&opcion,
                      "\n1)ingresar\n2)listar\n4)eliminar\n",
                      "NO!",
                      1,10,2);

        printf("elegiste:%d\n",opcion);
        switch(opcion)
        {
            case 1:
            {

                emp_altaArray(empleados, LIMITE, idEmp);
                idEmp++;
                /*
                printf("agregar nombre\n");

                if(buscarLibre(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("1.se encontro lugar en %d\n",posLibre);

                    //utn_getString(buffer,"Ingrese:","No!",0,20,1);
                    fgets(buffer,20,stdin);

                    printf("se ingreso:%s\n",buffer);

                    printf("2. se encontro lugar en %d\n",posLibre);
                    //nombres[posLibre] = buffer;
                    strncpy(nombres[posLibre],buffer,20);


                    for(i=0;i<10; i++)
                        printf("-%d: %s\n",i,nombres[i]);

                }
                */
                break;
            }
            case 2:
            {
                //Forma primitiva. No funcionaria en proyecto final.
                printf("\n");
                emp_lugarLibreArray(empleados,LIMITE,&freeIndex);
                for(i=0;i<freeIndex;i++)
                {
                    printf("ID: %d - Nombre: %s", empleados[i].idEmpleado, empleados[i].nombre);
                }
                break;
            }
            case 4:
            {
                // PIDO NOMBRE
                //utn_getString(buffer,...)
                fgets(buffer,20,stdin);buffer[strlen(buffer)-1]='\0';

                // en buffer esta el nombre
                buscarNombre(buffer,
                            nombres,
                            LEN_LISTA,
                            &posAeliminar);

                // borro
                nombres[posAeliminar][0]='\0';

                break;
            }
        }

    }


    return 0;
}



