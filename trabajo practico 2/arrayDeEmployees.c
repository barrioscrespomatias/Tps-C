#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayDeEmployees.h"



// SE GENERA UN CONTADOR DE ID.

static int generarNextId()
{
    static int id = -1;

    id ++;

    return id;
}




/** \brief  Indica que todas las posiciones del array estan vacias, poniendo la
            bandera "isEmpty" en "verdadero = 1".
 * \param   Lista de empleados.
 * \param   Tamaño del array.
 * \return  Retorna (-1) si hay error. (0) si es OK.
 *
 */

// SE INICIALIZA EN TODOS LOS INDICES DEL ARRAY ISEMPTY EN 1 (VACIOS)

int initEmployees(eEmpleado* lista, int tam)
{
    int i;
    int flag = -1;

    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
        flag = 0;
    }
    return flag;
}




/** \brief  Indica el primer indice vacio, pasandole un array y su tamaño.
 *
 * \param   Lista de empleados
 * \param   Tamaño int
 * \return  Retorna indice vacio.
 *
 */


 // SE BUSCA EL PRIMER LUGAR VACIO, SE ROMPE PARA QUE EL FOR NO SIGA BUSCANDO

int obtenerEspacioLibre(eEmpleado* lista, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            index= i;
            break;

        }
    }
    return index;
}



/** \brief  Pide los datos de un nuevo empleado y los guarda en variables a mostrar.

 *
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return
 *
 */



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

    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(nombre, 31-2, stdin);

    printf("Ingrese apellido: ");
    fflush(stdin);
    fgets(apellido, 31-2, stdin);

    printf("Ingrese salario: ");
    scanf("%f",&salario);

    printf("Ingrese sector: ");
    scanf("%d",&sector);

    id= generarNextId();


// VARIABLE RETORNA CARGA LA FUNCION ADDEMPLOYEES.


    retorna= addEmployees(lista,tam,id,nombre,apellido,salario,sector);

    return retorna;

}

/** \brief  Agrega en un array de empleados existente los valores recibidos como
            parametro en la primera posicion libre.
 *
 * \param   Lista de empleados.
 * \param   Tamaño int.
 * \param   id int
 * \param   Nombre [] Char
 * \param   Apellido [] Char
 * \param   Salario Float
 * \param   Sector int
 * \return  Retorna si es OK.

*/



int addEmployees(eEmpleado *lista, int tam, int id, char nombre[], char apellido[], float salario, int sector)
{
    int index;
    int retorna = -1;
    system("cls");
    index = obtenerEspacioLibre(lista, tam);
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




/** \brief  Busca un empleado por Id.
 *
 * \param   lista de empleados
 * \param   tamaño del array
 * \param   id del empleado
 * \return  Indice donde se encuentra cargado el empleado.
 *
 */

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





/** \brief  Elimina unempleado del array
 *
 * \param   Array de empleados
 * \param   tamaño del array
 * \param   id del empleado
 * \return  Retorna 0 si es OK.
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
            flag 0;
            break;
        }

    }
    return flag;
}




/** \brief  Ordena lista de empleados
 *
 * \param   array de empleados
 * \param    tamaño del array
 * \param   criterio de orden
 * \return
 *
 */

//
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


/** \brief  Imprime array de empleados por pantalla
 *
 * \param   Lista de empleados
 * \param   tamaño del array
 * \return
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

