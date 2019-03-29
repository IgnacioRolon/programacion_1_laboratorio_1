#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char number;
    getChar("Ingrese una letra: ", "Error\n", 'a', 'f', 2, &number);
    printf("Letra: %c", number);
    return 0;
}

