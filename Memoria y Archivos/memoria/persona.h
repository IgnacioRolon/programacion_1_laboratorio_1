#ifndef PERSONA_H
#define PERSONA_H
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
}Persona;
#endif

Persona* Pers_new(void);
int Pers_delete(Persona* this);

int Pers_setId(Persona* this, int id);
int Pers_getId(Persona* this, int* resultado);
int Pers_setNombre(Persona* this, char* nombre);
int Pers_getNombre(Persona* this, char* resultado);
int Pers_setApellido(Persona* this, char* nombre);
int Pers_getApellido(Persona* this, char* resultado);
int Pers_setEstado(Persona* this, int estado);
int Pers_getEstado(Persona* this, int* resultado);
int Pers_compararPorNombre(Persona* this1, Persona* this2);
int Pers_setIdAsString(Persona* this, char* id);
int Pers_getIdAsString(Persona* this, char* resultado);
int Pers_setEstadoAsString(Persona* this, char* estado);
int Pers_getEstadoAsString(Persona* this, char* resultado);
Persona* Pers_newStr(char* id, char* nombre, char* apellido, char* estado);


