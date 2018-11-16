#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayDeEmployees.h"
#define CANT_EMPLEADOS 10



int main()
{

    eEmpleado personas[CANT_EMPLEADOS];
    char seguir= 's';
    int opcion= 0;
    int r;

    r = inicializarEmpleados(personas, CANT_EMPLEADOS);

    do
    {
        system("cls");
        printf("   MENU\n\n");
        printf("1- Altas\n");
        printf("2- Modificar\n");
        printf("3- Bajas\n");
        printf("4- Informar\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            r = altaEmpleado(personas,CANT_EMPLEADOS);
            break;
        case 2:

            break;
        case 3:
            break;
        case 4:
            printEmployees(personas, CANT_EMPLEADOS);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');

    return 0;
}


