#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int confirmInputOne = 0;
int confirmInputTwo = 0;

int firstNumber(float *numberOne);
int secondNumber(float *numberTwo);
int addNumbers(float addFirstNumber, float addSecondNumber);
int substractNumbers(float subFirstNumber, float subSecondNumber);
int multiplyNumbers(float multiFirstNumber, float multiSecondNumber);
int factorizeNumbers(float factorFirstNumber);

int main()
{
    char seguir='s';
    int opcion=0;
    float numberOne;
    float numberTwo;

    while(seguir=='s')
    {
        printf("\n \n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                firstNumber(&numberOne);
                confirmInputOne = 1;
                break;
            case 2:
                secondNumber(&numberTwo);
                confirmInputTwo = 1;
                break;
            case 3:
                addNumbers(numberOne, numberTwo);
                break;
            case 4:
                substractNumbers(numberOne, numberTwo);
                break;
            case 5:

                break;
            case 6:
                multiplyNumbers(numberOne, numberTwo);
                break;
            case 7:
                factorizeNumbers(numberOne);
                break;
            case 8:

                break;
            case 9:

                seguir = 'n';
                break;
        }
    }
    return 0;
}

int firstNumber(float *numberOne)
{
    float localNumberOne;
    printf("\nIngrese el primer numero \n");
    scanf("%f", &localNumberOne);
    *numberOne = localNumberOne;
    return 0;
}

int secondNumber(float *numberTwo)
{
    float localNumberTwo;
    printf("\nIngrese el segundo numero \n");
    scanf("%f", &localNumberTwo);
    *numberTwo = localNumberTwo;
    return 0;
}

int addNumbers(float addFirstNumber, float addSecondNumber)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputOne == 1 || confirmInputTwo == 1)
    {
        mathResult = addFirstNumber + addSecondNumber;
        printf("\nLa suma es: %f", mathResult);
        returnValue = 0;
    }else
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }
    return returnValue;
}

int substractNumbers(float subFirstNumber, float subSecondNumber)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputOne == 1 || confirmInputTwo == 1)
    {
        mathResult = subFirstNumber - subSecondNumber;
        printf("\nLa resta es: %f", mathResult);
        returnValue = 0;
    }else
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }
    return returnValue;
}

int multiplyNumbers(float multiFirstNumber, float multiSecondNumber)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputOne == 1 || confirmInputTwo == 1)
    {
        mathResult = multiFirstNumber * multiSecondNumber;
        printf("\nEl producto es: %f", mathResult);
        returnValue = 0;
    }else
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }
    return returnValue;
}

int factorizeNumbers(float factorFirstNumber)
{
    int returnValue = -1;
    float mathResult = 0;
    int i;
    if (confirmInputOne == 1)
    {
        for(i = factorFirstNumber - 1;i>0;i--)
        {
            mathResult = mathResult + factorFirstNumber * i;
        }
        printf("\nLa factorizacion es: %f", mathResult);
        returnValue = 0;
    }else
    {
        printf("ERROR: No se ha ingresado el primer operando.");
    }
    return returnValue;
}
