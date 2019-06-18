#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"

int reduceTest(void* pEmployee);
int mapTest(void* pEmployee);

int main()
{
    LinkedList* linkedTest = ll_newLinkedList();
    LinkedList* linkedCopy = ll_newLinkedList();
    controller_loadFromText("data.csv", linkedTest);
    linkedCopy = ll_filter(linkedTest, reduceTest);
    ll_reduce(linkedTest, reduceTest);
    ll_map(linkedTest, mapTest);
    controller_ListEmployee(linkedTest);
}

int reduceTest(void* pEmployee)
{
    Employee* localEmp = (Employee*)pEmployee;
    if(localEmp->sueldo >= 50000)
    {
        return 0;
    }else
    {
        return 1;
    }
}

int mapTest(void* pEmployee)
{
    Employee* localEmp = (Employee*)pEmployee;
    localEmp->sueldo += 333;
}
