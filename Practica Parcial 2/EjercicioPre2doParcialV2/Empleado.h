#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Employee;

Employee* employee_new();
Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas, char* sueldo);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* resultado);
int employee_setIdAsString(Employee* this, char* id);
int employee_getIdAsString(Employee* this, char* resultado);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* resultado);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* resultado);
int employee_setHorasTrabajadasAsString(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadasAsString(Employee* this, char* resultado);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* resultado);
int employee_setSueldoAsString(Employee* this, char* sueldo);
int employee_getSueldoAsString(Employee* this, char* resultado);

int employee_compararPorNombre(void* this1, void* this2);
int em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
