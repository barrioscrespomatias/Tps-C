#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <../UTN/utn.h>
#include "arrayDeEmployees.h"
#define CANT_EMPLEADOS 100




int main()
{

    char seguir= 's';
    int opcion= 0;
    int opcionMenuInformes = 0;
    char seguirMenuInformes = 's';



    eEmpleado personas[CANT_EMPLEADOS];
    inicializarEmpleados(personas, CANT_EMPLEADOS);
    hardcodearEmpleados(personas);

    float w = sumarSalarios(personas,CANT_EMPLEADOS);
    float r = promedioSalarios(personas,CANT_EMPLEADOS,w);

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
            altaEmpleado(personas,CANT_EMPLEADOS);
            break;
        case 2:
            modificarEmpleado(personas,CANT_EMPLEADOS);
            break;
        case 3:
            removeEmployee(personas,CANT_EMPLEADOS);
            break;
        case 4:

            do
            {
                system("cls");
                printf("   MENU INFORMES\n\n");
                printf("1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
                printf("2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
                printf("3- Salir\n\n");

                opcionMenuInformes = getValidInt("Ingrese una opcion: ","Error. Solo puede ingresar numeros");
                switch(opcionMenuInformes)
                {
                case 1:
                    ordenarEmpleados(personas,CANT_EMPLEADOS,1);
                    printEmployees(personas,CANT_EMPLEADOS);
                    system("pause");
                    break;
                case 2:
                    cantidadEmpleadosMayorPromedio(personas,CANT_EMPLEADOS,r);
                    system("pause");
                    break;
                case 3:
                    seguirMenuInformes = 'n';
                    break;
                }
            }while(seguirMenuInformes == 's');

                break;
            case 5:
                seguir = 'n';
                break;
            }

        }
        while(seguir == 's');

        return 0;
    }


