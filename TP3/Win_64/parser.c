#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pNuevoEmployee =employee_new();

    char idSrtAux[50], nombreAuxSrt[50], horasTrabajadasSrtAux[50], sueldoSrtAux[50];
    int leidos;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);
//    printf("1");
//    system("pause");

    while(!feof(pFile))
    {
//        printf("2");
//        system("pause");
        leidos =fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);

        if(leidos == 4)
        {
            pNuevoEmployee = employee_newParametros(idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);
            ll_add(pArrayListEmployee,pNuevoEmployee);
            //printf("\n %d %s %d %.2f", pNuevoEmployee->id, pNuevoEmployee->nombre, pNuevoEmployee->horasTrabajadas, pNuevoEmployee->sueldo);
        }

        else if(leidos != 4)
        {
//            printf("3");
//            system("pause");
            if(!feof(pFile))
            {
              printf("Hubo un error\n");
            }
            else
            {
              printf("Se ha leido el archivo\n");
            }
        }
    }

    printf("\nSe han cargado todos los empleados\n");
    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *nuevoEmployeeAux = employee_new();
    int cargaEmpleados;
    int retorno =0;

    while(!feof(pFile))
    {
        cargaEmpleados = fread(nuevoEmployeeAux, sizeof(Employee),1,pFile);
        if(cargaEmpleados == 1)
        {
            ll_add(pArrayListEmployee,nuevoEmployeeAux);
            printf("%d %s %d %.2f",nuevoEmployeeAux->id, nuevoEmployeeAux->nombre, nuevoEmployeeAux->horasTrabajadas, nuevoEmployeeAux->sueldo);
            retorno = 1;
        }

    }

    return retorno;
}
