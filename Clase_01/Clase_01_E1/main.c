#include <stdio.h>
#include <stdlib.h>

//calcular promedio en una funcion

#define CANTIDAD 3

// int sumarNumeros();
int calcularPromedio();

int main()
{

    calcularPromedio();
    return 0;

}

int calcularPromedio()
{
    int i;
    float promedio;
    int ingreso;

    promedio = 0;

    for(i = 0;i < CANTIDAD;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &ingreso);
        promedio += ingreso;
    }

    promedio = promedio / CANTIDAD;
    printf("El promedio es: %f", promedio);
    return 0;
}
/*

int sumarNumeros()
{
    int valorA;
    int valorB;
    int resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &valorA);


    printf("Ingrese el segundo numero: ");
    scanf("%d", &valorB);

    printf("\n");
    resultado = valorA + valorB;
    return resultado;
}

*/
