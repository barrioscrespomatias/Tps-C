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
    Employee *pNuevoEmployee;

    char idSrtAux[50], nombreAuxSrt[50], horasTrabajadasSrtAux[50], sueldoSrtAux[50];
    int leidos;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);

    while(!feof(pFile))
    {
        leidos =fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);

        if(leidos == 4)
        {
            pNuevoEmployee = employee_newParametros(idSrtAux,nombreAuxSrt,horasTrabajadasSrtAux,sueldoSrtAux);
            ll_add(pArrayListEmployee,pNuevoEmployee);
        }

        else if(leidos != 4)
        {
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
    Employee *archivo_Binario;
    int cantidad;

    while(!feof(pFile))
    {
        archivo_Binario = employee_new();
        cantidad = fread(archivo_Binario, sizeof(Employee),1,pFile);
        if(cantidad == 1 && archivo_Binario != NULL)
        {
            ll_add(pArrayListEmployee,archivo_Binario);
        }
    }

    fclose(pFile);

    return 1;
}
