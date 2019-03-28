#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int firstNumber(float *numberOne);
int secondNumber(float *numberTwo);
int addNumbers(float addFirstNumber, float addSecondNumber, int confirmInputs);
int substractNumbers(float subFirstNumber, float subSecondNumber, int confirmInputs);
int multiplyNumbers(float multiFirstNumber, float multiSecondNumber, int confirmInputs);
int factorizeNumbers(float factorFirstNumber, int confirmInputs);
int divideNumbers(float divideFirstNumber, float divideSecondNumber, int confirmInputs);

int main()
{
    char seguir='s';
    int opcion=0;
    float numberOne;
    float numberTwo;
    int confirmInputOne = -1;
    int confirmInputTwo = -1;
    int confirmedInputs = -1;

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
                confirmInputOne = firstNumber(&numberOne);
                break;
            case 2:
                confirmInputTwo = secondNumber(&numberTwo);
                break;
            case 3:
                addNumbers(numberOne, numberTwo, confirmedInputs);
                break;
            case 4:
                substractNumbers(numberOne, numberTwo, confirmedInputs);
                break;
            case 5:
                divideNumbers(numberOne, numberTwo, confirmedInputs);
                break;
            case 6:
                multiplyNumbers(numberOne, numberTwo, confirmedInputs);
                break;
            case 7:
                factorizeNumbers(numberOne, confirmInputOne);
                break;
            case 8:
                addNumbers(numberOne, numberTwo, confirmedInputs);
                substractNumbers(numberOne, numberTwo, confirmedInputs);
                divideNumbers(numberOne, numberTwo, confirmedInputs);
                multiplyNumbers(numberOne, numberTwo, confirmedInputs);
                factorizeNumbers(numberOne, confirmInputOne);
                break;
            case 9:

                seguir = 'n';
                break;
        }
        if(confirmInputOne == 0 && confirmInputTwo == 0)
        {
            confirmedInputs = 0;
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


int addNumbers(float addFirstNumber, float addSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }else
    {
        mathResult = addFirstNumber + addSecondNumber;
        printf("\nLa suma es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int substractNumbers(float subFirstNumber, float subSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }else
    {
        mathResult = subFirstNumber - subSecondNumber;
        printf("\nLa resta es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int multiplyNumbers(float multiFirstNumber, float multiSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");

    }else
    {
        mathResult = multiFirstNumber * multiSecondNumber;
        printf("\nEl producto es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int factorizeNumbers(float factorFirstNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult = factorFirstNumber;
    int i;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado el primer operando.");
    }else
    {
        for(i = factorFirstNumber - 1;i>0;i--)
        {
            mathResult = mathResult * i;
        }
        printf("\nLa factorizacion es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int divideNumbers(float divideFirstNumber, float divideSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");

    }else
    {
        if(divideSecondNumber == 0)
        {
            printf("ERROR: La division no puede ser por cero.");
        }else
        {
            mathResult = divideFirstNumber / divideSecondNumber;
            printf("\nLa division es: %f", mathResult);
            returnValue = 0;
        }
    }
    return returnValue;
}
