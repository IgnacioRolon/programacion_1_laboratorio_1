#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//calcular promedio en una funcion

#define CANTIDAD 3

// int sumarNumeros();
int calcularPromedio();
int funcionPromedio(int valorAcumulado, int cantidad, float *promedio);
int calcularMaximoMinimo(int valorIngresado, int *maximo, int *minimo);

int main()
{
    calcularPromedio();
    return 0;
}

int calcularPromedio()
{
    int i;
    float promedio;
    int acumulador = 0;
    int ingreso;
    int maximo = INT_MIN;
    int minimo = INT_MAX;

    for(i = 0;i < CANTIDAD;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &ingreso);
        acumulador += ingreso;
        if(calcularMaximoMinimo(ingreso, &maximo, &minimo))
        {
            printf("Error");
            break;
        }
    }
    //promedio = (float)acumulador / CANTIDAD;
    if(funcionPromedio(acumulador, CANTIDAD, &promedio) == 0)
    {
        printf("\nEl promedio es: %.2f", promedio);
    }
    else{
        printf("\n");
        printf("\nError");
    }
    printf("\nEl maximo es: %d", maximo);
    printf("\nEl minimo es: %d", minimo);
    printf("\n");
    return 0;
}

int funcionPromedio(int valorAcumulado, int cantidad, float *promedio)
{
    int retorno = -1;
    if(cantidad > 0 && promedio != NULL)
    {
        *promedio = (float)valorAcumulado / cantidad;
        retorno = 0;
    }
    return retorno;

}

int calcularMaximoMinimo(int valorIngresado, int *maximo, int *minimo)
{
    int retorno = -1;
    if(*maximo != NULL && *minimo != NULL)
    {
        if(valorIngresado>*maximo)
        {
            *maximo = valorIngresado;
        }
        if(valorIngresado<*minimo)
        {
            *minimo = valorIngresado;
        }
        retorno = 0;
    }

    return retorno;
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
