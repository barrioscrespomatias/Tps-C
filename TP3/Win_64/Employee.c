#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee *employee_new()
{
    Employee *this;
    this = malloc(sizeof(Employee));

    if(this == NULL)
    {
        printf("\nNo hay mas lugar para cargar empleados");
    }

    else
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}
////////////////////////////////////////////////////////////// SETTERS
int employee_setId(Employee* this, int idEmployee)
{
    int todoOk= 0;

    if(this!= NULL && idEmployee>0)
    {
        this -> id = idEmployee;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee * this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && strlen(nombre)>0)
    {
        strcpy(this-> nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}


int employee_setSueldo(Employee * this, int sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo>0)
    {
        this -> sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int todoOk = 0;

    if(this!= NULL && horasTrabajadas>0)
    {
        this -> horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}
////////////////////////////////////////////////////////////GETTERS

int employee_getId(Employee *this, int *id)
{
    int todoOk = 0;

    if(this!= NULL && id> 0)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee*this, int *horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas>0)
    {
        *horasTrabajadas = this-> horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this, int *sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo>0)
    {
        *sueldo = this-> sueldo;
        todoOk = 1;
    }

    return todoOk;
}



Employee* employee_newParametros(char* idStr, char * nombreStr, char * horasTrabajadasStr, char *salario)
{



    int idAux, horasTrabajadasAux;
    float salarioAux;
    int sePudoCargar = 1;

    Employee* this;

    this = employee_new();

    idAux = atoi(idStr);
    if(employee_setId(this, idAux)!= 1)
    {
        sePudoCargar = 0;

    }

    horasTrabajadasAux = atoi(horasTrabajadasStr);
    if(employee_setHorasTrabajadas(this, horasTrabajadasAux)!= 1)
    {
        sePudoCargar = 0;

    }

    if(employee_setNombre(this, nombreStr)!= 1)
    {
        sePudoCargar = 0;

    }

    salarioAux = atoi(salario);

    if(employee_setSueldo(this, salarioAux)!= 1)
    {
        sePudoCargar = 0;

    }

    if(sePudoCargar == 0)
    printf("\nError al cargar los datos\n");


    return this;
}



int employeeSortByNombre (void *empleadoA, void* empleadoB)
{
    int retorno = 0;

    if(strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre)>0)
    {
        retorno = 1;
    }

    return retorno;
}

int employeeSortById(void * empleadoA, void * empleadoB)
{
    int retorno = 0;

    if(((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id)
    {
        retorno = 1;
    }


    return retorno;
}



int employeeSortByHorasTrabajadas(void * empleadoA, void *empleadoB)
{
    int retorno = 0;

    if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)
    {
        retorno = 1;
    }

    return retorno;
}

int employeeSortBySueldo(void * empleadoA, void *empleadoB)
{
    int retorno = 0;

    if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)
    {
        retorno = 1;
    }

    return retorno;
}


void employee_printData(Employee* this)
{
    int id, sueldo, horasTrabajadas;
    char nombre[31];

    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);

    printf("%-5d%-20s%-7d%-6d\n", id, nombre, horasTrabajadas, sueldo);
}



