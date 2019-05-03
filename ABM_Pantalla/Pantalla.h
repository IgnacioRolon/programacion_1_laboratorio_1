#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    char nombre[50];
    char direccion[250];
    float precio;
    int tipo;
    int isEmpty; ///1vacio - 0ocupado
    int idPantalla; ///clave unica de identidad univoca
}Pantalla;

int pan_initPantalla(Pantalla* pPantalla,int len);

int pan_addPan(Pantalla* pPantalla,int len,int pIndex,char* msgE,int tries);
int pan_alter(Pantalla* pPantalla, int len,char* msgE,int tries);
int pan_removePantalla(Pantalla* pPantalla, int len,char* msgE,int tries);

int pan_orderByPrice(Pantalla* pPantalla, int len);
int pan_orderByID(Pantalla* pPantalla, int len);

int pan_printPantalla(Pantalla* pPantalla,int len);

int pan_findPanById(Pantalla* pPantalla, int len, int idE);
int pan_findFree(Pantalla* pPantalla, int len);

int pan_getID (Pantalla* pPantalla,int len,char* msgE,int tries);

int getByID(Pantalla visor[],int ID, int length, Pantalla *resultado);
#endif // PANTALLA_H_INCLUDED
