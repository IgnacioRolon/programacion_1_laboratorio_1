#ifndef EMPLEADO_H
#define EMPLEADO_H
typedef struct
{
    int id;
    char nombre[50];
    float peso;
    int estado;
}Empleado;
#endif

Empleado* Emp_new(void);
int Emp_delete(Empleado* this);

int Emp_setId(Empleado* this, int id);
int Emp_getId(Empleado* this, int* resultado);
int Emp_setPeso(Empleado* this, float peso);
int Emp_getPeso(Empleado* this, float* resultado);
int Emp_setNombre(Empleado* this, char* nombre);
int Emp_getNombre(Empleado* this, char* resultado);
int Emp_setEstado(Empleado* this, int estado);
int Emp_getEstado(Empleado* this, int* resultado);
int Emp_compararPorNombre(Empleado* this1, Empleado* this2);




