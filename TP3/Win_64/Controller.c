#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "../../UTN/utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *texto;

    if((texto = fopen(path, "r")) != NULL)
    {
        parser_EmployeeFromText(texto, pArrayListEmployee);
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *binario;

    if((binario = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(binario, pArrayListEmployee);
    }

    else if((binario = fopen(path, "wb"))!= NULL)
    {
        printf("\nSe ha creado un nuevo archivo.");

    }

    return 1;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    char idSrt[150], nombreSrt[150], horasTrabajaSrt[150], sueldoSrt[150];
    Employee *empleadoNuevo = employee_new();

    getStringNumber("\nIngrese id: ", idSrt);
    getValidStringRango("\nIngrese nombre: ","Error, reingrese", nombreSrt,149);
    getStringNumber("\nIngrese las horas trabajadas: ",horasTrabajaSrt);
    getStringNumber("\nIngrese sueldo: ", sueldoSrt);



    empleadoNuevo = employee_newParametros(idSrt,nombreSrt, horasTrabajaSrt, sueldoSrt);
    ll_add(pArrayListEmployee, empleadoNuevo);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    Employee *this;


    int idEmpleado, horasTrabajadas, sueldo;
    int nuevasHorasTrabajadas, nuevoSueldo;

    char nombreAux[51], nombre[51];

    int modificar = 0;
    int opcionMenu= 0;
    char confirma = 0;
    char continuarSubMenuModificar = 's';
    int i;

    printf("\tMODIFICAR EMPLEADO\n");

    idEmpleado = getIntOnly("Ingrese ID: ");
    for(i=0; i<ll_len(pArrayListEmployee) ; i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {

            modificar = 1;
            break;
        }

    }

    if(modificar == 1)
    {
        do
        {
            system("cls");
            printf("\t MENU MODIFICAR\n\n");
            printf("\n  Id  -  Nombre  -   Horas  - Sueldo ");
            printf("\n%4d%10s%10d    %8d\n\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);

            printf("1. Modificar nombre\n");
            printf("2. Modificar horas trabajadas\n");
            printf("3. Modificar sueldo\n");
            printf("4. Regresar al menu anterior\n\n");

            opcionMenu = getIntOnly("Ingrese una opcion: \n");

            switch(opcionMenu)
            {
            case 1:
                employee_getNombre(this, nombre);
                getValidStringRango("\nIngrese nombre: ","\nError. Solo se admiten letras",nombreAux,50);
                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n)","\nReingrese", 's','n');

                if(confirma == 's')
                {
                    employee_setNombre(this,nombreAux);
                    printf("\nEl nombre ha sido modificado");
                }
                else
                {
                    printf("\nLa modificacion ha sido cancelada");
                }

                system("pause");

                break;

            case 2:
                employee_getHorasTrabajadas(this, &horasTrabajadas);
                nuevasHorasTrabajadas =getValidInt("\nIngrese horas trabajadas: ", "\nError. Solo se permiten numeros");
                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n) ","\nReingrese", 's','n');

                if(confirma == 's')
                {
                    employee_setHorasTrabajadas(this,nuevasHorasTrabajadas);
                    printf("\nLas horas trabajadas han sido modificado");
                }
                else
                {
                    printf("\nLa modificacion ha sido cancelada");
                }

                system("pause");

                break;

            case 3:
                nuevoSueldo =getValidInt("\nIngrese el nuevo sueldo: ", "\nError. Solo se permiten numeros");
                employee_getSueldo(this,&sueldo);
                confirma = getValidChar("\nRealmente quiere modificarlo?: (s/n) ","\nReingrese", 's','n');

                if(confirma == 's')
                {
                    employee_setSueldo(this,nuevoSueldo);
                    printf("\nEl sueldo ha sido modificado");
                }
                else
                {
                    printf("\nLa modificacion ha sido cancelada");
                }

                system("pause");

                break;

            case 4:
                continuarSubMenuModificar = 'n';
                break;

            }



        }
        while(continuarSubMenuModificar == 's');
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    Employee *this;
    int todoOk=0;
    int idEliminar;
    char confirma = 0;
    int i;

    printf("ELIMINAR EMPLEADO");
    idEliminar = getValidInt("\nIngrese ID: ","El ID debe ser solo en numeros");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        if(this->id == idEliminar)
        {
            printf("\nId  - Nombre  -  Horas  -  Sueldo  ");
            printf("\n%4d %10s %10d %6d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
            confirma = getValidChar("\nRealmente quiere eliminarlo?: (s/n) ","\nReingrese", 's','n');




            if(confirma == 's')
            {
                ll_remove(pArrayListEmployee,i);
                printf("\nEl empleado ha sido dado de baja\n");
                system("pause");
            }
            else
            {
                printf("\nEl empleado no ha sido dado de baja\n");
                system("pause");
            }

            todoOk =1;

            if(todoOk == 0)
            {
                printf("\nNo existen empleados con el ID a eliminar");
                system("pause");
            }

        }

    }

    return todoOk;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    system("cls");
    Employee *existe;

    int i;

    printf("Lista de empleados\n\n");
    printf("N      |Nombre           |Horas|Sueldo\n");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        existe = ll_get(pArrayListEmployee, i);
        employee_printData(existe);
    }

        printf("\n");


    return 1;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char seguir= 's';
    int opcion = 0;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            system("cls");
            printf("\tORDENAMIENTO EMPLEADOS\n\n");
            printf("1. Id\n");
            printf("2. Nombre\n");
            printf("3. Horas trabajadas\n");
            printf("4. Sueldo\n");
            printf("5. Salir\n\n");

            opcion = getValidInt("Ingrese una opcion: \n","Reingrese: \n");
            switch(opcion)
            {
            case 1:
                ll_sort(pArrayListEmployee,employeeSortById,1);
                printf("\nEmpleados ordenados por ID\n");
                system("pause");
                retorno = 1;

                break;

            case 2:
                ll_sort(pArrayListEmployee, employeeSortByNombre,1);
                printf("\nEmpleados ordenados por nombre\n");
                system("pause");
                retorno = 1;
                break;

            case 3:
                ll_sort(pArrayListEmployee, employeeSortByHorasTrabajadas,1);
                printf("\nEmpleados ordenados por horas trabajadas\n");
                system("pause");

                retorno = 1;
                break;

            case 4:
                ll_sort(pArrayListEmployee, employeeSortBySueldo,1);
                printf("\nEmpleados ordenados por sueldo\n");
                system("pause");

                retorno = 1;
                break;

            case 5:
                seguir = 'n';
                break;
            }

        }
        while(seguir == 's');

    }


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *texto;
    Employee * aGuardar;

    int i, cantidad;

    texto = fopen(path, "w");
    cantidad = ll_len(pArrayListEmployee);

    if(texto != NULL && pArrayListEmployee != NULL)
    {
        rewind(texto);
        fprintf(texto, "id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<cantidad; i++)
        {
            aGuardar = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(texto, "%d, %s, %d, %d\n", aGuardar->id, aGuardar->nombre, aGuardar->horasTrabajadas, aGuardar->sueldo);
        }
        printf("\nLos datos se han guardado\n");
    }
    fclose(texto);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE*binario;
    Employee *aGuardar;

    int i, cantidad;


    binario = fopen(path, "wb");
    cantidad = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && binario != NULL)
    {
        for (i=0; i<cantidad; i++)
        {
            aGuardar = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(aGuardar, sizeof(Employee),1, binario);
        }
    }

    fclose(binario);


    return 1;
}

