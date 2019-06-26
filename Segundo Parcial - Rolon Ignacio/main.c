#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
#include "utn.h"

int main()
{
    LinkedList* registro = ll_newLinkedList();

    if(!controller_loadFromText("data.csv", registro))
    {
        controller_saveAsText("informes.txt", registro);
    }
    return 0;
}
