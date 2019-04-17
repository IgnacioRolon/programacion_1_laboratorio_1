#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char auxName[500] = "test";
    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    return 0;
}
