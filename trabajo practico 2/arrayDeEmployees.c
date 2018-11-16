#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<../UTN/utn.h>
#include "arrayDeEmployees.h"
#define FALSE 0
#define TRUE 1



// SE GENERA UN CONTADOR DE ID.






/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

// SE INICIALIZA EN TODOS LOS INDICES DEL ARRAY ISEMPTY EN 1 (VACIOS)
//2.1

int inicializarEmpleados(eEmpleado *listaEmpleados, int tam)
{
    int i, retorno = -1;
    if (listaEmpleados != NULL && tam != 0)
    {
        retorno = 0;
        for (i=0; i<tam; i++)
        {
            listaEmpleados[i].isEmpty = 1;
        }
    }
    return retorno;
}

// 2.2 ADD EMPLOYEES

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
* \return return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/


int addEmployees(eEmpleado *lista, int tam, int id, char nombre[], char apellido[], float salario, int sector)
{
    int index;
    int retorna = -1;
    system("cls");
    index = buscarLibreParaEmpleados(lista, tam);
    eEmpleado nuevoEmpleado;

// SI HAY ALGUN INDICE VACIO, SE PIDEN LOS DATOS PARA CARGARLO.
    if (index != -1 )
    {
        strcpy(nuevoEmpleado.nombre,nombre);
        strcpy(nuevoEmpleado.apellido,apellido);
        nuevoEmpleado.salario = salario;
        nuevoEmpleado.sector = sector;
        nuevoEmpleado.id = id;
        nuevoEmpleado.isEmpty = 0;
        lista[index]=nuevoEmpleado;
        retorna = 0;
    }

    return retorna;

}


 int altaEmpleado(eEmpleado* lista, int tam)
{
    char nombre [31], apellido [31];
    float salario;
    int id;
    int sector;
    int retorna;

    system("cls");
//  SE PIDEN LOS VALORES PARA COMPLETAR LOS INDICES DEL ARRAY Y SE GUARDAN EN VARIABLES
//  AXULIARES.

    getValidString("Ingrese nombre: ","Solo se pueden ingresar letras", nombre);
    getValidString("Ingrese apellido: ", "Solo se pueden ingresar letras", apellido);
    salario = getFloatOnly("Ingrese salario: ");
    sector = getValidInt("Ingrese sector: ", "Solo puede ingresar numeros");


//    printf("Ingrese nombre: ");
//    fflush(stdin);
//    fgets(nombre, 31-2, stdin);
//
//    printf("Ingrese apellido: ");
//    fflush(stdin);
//    fgets(apellido, 31-2, stdin);
//
//    printf("Ingrese salario: ");
//    scanf("%f",&salario);
//
//    printf("Ingrese sector: ");
//    scanf("%d",&sector);

    id= generarNextId();


// VARIABLE RETORNA CARGA LA FUNCION ADDEMPLOYEES.


    retorna= addEmployees(lista,tam,id,nombre,apellido,salario,sector);

    return retorna;

}



/** \brief  Indica el primer indice vacio, pasandole un array y su tamaño.
 *
 * \param   Lista de empleados
 * \param   Tamaño int
 * \return  Retorna indice vacio.
 *
 */


 // SE BUSCA EL PRIMER LUGAR VACIO, SE ROMPE PARA QUE EL FOR NO SIGA BUSCANDO

int buscarLibreParaEmpleados(eEmpleado *listaEmpleados, int tam)
{
    int i;
    int indiceLibre = -1;

    for (i=0; i< tam; i++)
    {
        if(listaEmpleados[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}








// 2.3 ENCONTRAR EMPLEADOS POR ID
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */


int buscarEmpleadoPorId (eEmpleado *listaEmpleados, int tam, int id)
{
    int i;
    int idEncontrado = -1;

    for(i=0; i< tam; i++)
    {
        if( listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].id == idEncontrado)
        {
            idEncontrado = i;
            break;
        }
    }
    return idEncontrado;
}










// SE COMPARA EL ID PARA SABER SI EXISTE. ADEMAS SE FIJA SI EN INDICE ESTA VACIO.


int findEmployeeById(eEmpleado* lista, int tam,int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice= i;
            break;
        }
    }
    return indice;
}


// 2.4

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */


// SE INGRESA UN ID A ELIMINAR, SE LO COMPARA PARA VER SI COINCIDE CON ALGUNO.
// ADEMAS COMPRUEBA QUE EL INDICE NO ESTE VACIO.
int removeEmployee(eEmpleado* lista, int tam, int id)
{
    int i;
    printf("\nIngrese Id a eliminar: ");
    scanf("%d", & id);

    int flag= -1;
    for (i=0; i<tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            flag = 0;
            printf("\nEl usuario ha sido eliminado con exito");

            break;
        }

    }
    return flag;
}



// 2.5 SORT EMPLOYEES

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(eEmpleado* lista, int tam, int orden)
{
    int i, j;
    eEmpleado listaAux;

    for(i=0; i<tam; i++)
    {
        for (j=0; j< tam ; j++)
        {
            if(lista[i].isEmpty != 1 && lista[i].apellido > lista[i].apellido)
            {
                listaAux = lista[i];
                lista[i]= lista[j];
                lista[j] = listaAux;
            }
        }

    }
    return 0;

}


//2.6 PRINT EMPLOYEES


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */


 // SE COMPRUEBA QUE EL INDICE TENGA VALORES Y EN ESE CASO SE LOS MUSTRA POR PANTALLA.

int printEmployees(eEmpleado* lista, int tam)
{
    int i;
    printf("\n Nombre  -  Apellido  -  Salario  -  Sector  -  Id  \n");
    for (i=0; i<tam; i++)
    {
        if (lista[i].isEmpty == 0)
        {
           mostrarUnEmpleado(lista[i]);
           printf("\n\n");
        }
    }
    return 0;
}

/** \brief  Muestra un empleado
 *
 * \param   array de empleados
 * \return  Retorna 0 si es ok.
 *
 */

// SE MUESTRA UN SOLO EMPLEADO

int mostrarUnEmpleado(eEmpleado unoSolo)
{
    printf("%c\t %c\t %d\t %d\t %d\t", unoSolo.nombre, unoSolo.apellido, unoSolo.salario, unoSolo.sector, unoSolo.id);
    return 0;
}

