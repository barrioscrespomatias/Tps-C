#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<../UTN/utn.h>
#include "arrayDeEmployees.h"
#define FALSE 0
#define TRUE 1
#define ELIMINAR 2
#define CANTIDAD_SECTORES 5










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
        if( listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].id == id)
        {
            idEncontrado = i;
            break;
        }
    }
    return idEncontrado;
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


int addEmployees(eEmpleado *listaEmpleados, int tamEmpleados, int auxId, char auxNombre[], char auxApellido[], float auxSalario, int auxSector)
{
    int todoOk = -1;
    int index;

    eEmpleado auxiliarEmpleado;

    index = buscarLibreParaEmpleados(listaEmpleados,tamEmpleados);

    if(index == -1)
    {
        printf("\nNo hay mas espacio");

    }
    else
    {
        todoOk = 0;
        auxiliarEmpleado.id = auxId;
        strcpy(auxiliarEmpleado.nombre, auxNombre);
        strcpy(auxiliarEmpleado.apellido, auxApellido);
        auxiliarEmpleado.salario = auxSalario;
        auxiliarEmpleado.sector = auxSector;
        auxiliarEmpleado.isEmpty = FALSE;
        listaEmpleados[index] = auxiliarEmpleado;
    }

    return todoOk;

}

/** \brief Pide datos para cargar en la estructura de empleado.
 *
 * \param
 * \param
 * \return funcion add employees
 *
 */



int altaEmpleado(eEmpleado* listaEmpleados, int tamEmpleados)
{
    int todoOK, auxId, auxSector;
    char auxNombre[51], auxApellido[51];
    float auxSalario;



    system("cls");
    printf("\nAlta de empleados\n");

    getValidString("Ingrese nombre: ","Error. Solo puede ingresar letras",auxNombre);
    getValidString("Ingrese apellido: ","Error. Solo puede ingresar letras",auxApellido);
    auxSalario = getFloatOnly("Ingrese sueldo: ");
    auxSector = getValidInt("Ingrese sector: ", "Error. Solo puede ingresar numeros");
    auxId = getUltimoId();

    todoOK = addEmployees(listaEmpleados,tamEmpleados,auxId, auxNombre,auxApellido,auxSalario,auxSector);

    system("pause");


    return todoOK;
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

int borrarEmpleado(eEmpleado* listaEmpleados, int tamEmpleados, int id)
{
    int indice, retorno = -1;
    indice = buscarEmpleadoPorId(listaEmpleados, tamEmpleados, id);
    if (indice != -1)
    {
        listaEmpleados[indice].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int removeEmployee(eEmpleado* listaEmpleados, int tamEmpleados)
{
    int indice, id;
    char opcion;

    id = getValidInt("Ingrese el Id a eliminar: ", "Error. Solo puede ingresar numeros enteros");

    indice = buscarEmpleadoPorId(listaEmpleados,tamEmpleados,id);

    if(indice == -1)
    {
        printf("\nEl codigo no se relaciona con ningun empleado.\n\n");
        system("pause");
    }

    else
    {
        printf("\nEmpleados encontrados: \n\n");
        printf("Id   |Nombre    |Apellido  |Salario   |Sector    \n");
        mostrarUnEmpleado(listaEmpleados[indice]);

        opcion = getValidChar("Realmente quiere borrar el empleado?: (s/) ","Error. Solo ingrese 's' o 'n'",'s','n');

        if(opcion == 's')
        {
            borrarEmpleado(listaEmpleados,tamEmpleados,id);
            printf("\nSe ha eliminado al empleado\n");
            system("pause");

        }
        else
        {
            printf("\nNo se ha borrado el empleado\n");
            system("pause");
        }

    }

    return 0;

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


int ordenarEmpleados(eEmpleado* listaEmpleados, int tamEmpleados, int order)
{
    eEmpleado auxiliar;
    int retorno = -1;

    int i, j;
    if(order == 1)
    {
        for(i=0; i<tamEmpleados-1; i++)
        {
            for(j= i+1; j<tamEmpleados; j++)
            {
                retorno = 0;
                if(strcmp(listaEmpleados[i].apellido,listaEmpleados[j].apellido)>0)
                {
                    auxiliar = listaEmpleados[i];
                    listaEmpleados[i]=listaEmpleados[j];
                    listaEmpleados[j]=auxiliar;
                }

                if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido)==0 && listaEmpleados[i].sector>listaEmpleados[j].sector)
                {
                    auxiliar = listaEmpleados[i];
                    listaEmpleados[i]=listaEmpleados[j];
                    listaEmpleados[j]=auxiliar;
                }
            }
        }

    }
    return retorno;
}


//2.6 PRINT EMPLOYEES


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return 0 si es ok
 *
 */


// SE COMPRUEBA QUE EL INDICE TENGA VALORES Y EN ESE CASO SE LOS MUSTRA POR PANTALLA.

int printEmployees(eEmpleado* lista, int tam)
{
    int i;
    printf("\nNombre    -  Apellido-  Salario -  Sector  -  Id      \n");
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
    printf("%-13s %-10s %-12.2f %-10d %-10d\t", unoSolo.nombre, unoSolo.apellido, unoSolo.salario, unoSolo.sector, unoSolo.id);
    return 0;
}

/** \brief Modifica los distintos campos que puede tener un empleado
 *
 * \param lista empleados
 * \param cantidad empleados
 * \return retorna 0 si es ok.
 *
 */

// MODIFICAR LOS DISTINTOS CAMPOS DE UN EMPLEADO
int modificarEmpleado(eEmpleado* listaEmpleados, int tamEmpleados)
{
    int esta, codigoEmpleado, auxSector, opcionMenuModificar;
    char opcion;
    char auxApellido[51], auxNombre[51], seguirModificarEmpleados = 's';
    float auxSalario;


    printf("Ingrese el codigo del empleado a modificar: \n");
    scanf("%d", & codigoEmpleado);

    esta = buscarEmpleadoPorId(listaEmpleados,tamEmpleados, codigoEmpleado);
    system("cls");

    if(esta == -1)
    {
        printf("\nEl codigo no se relaciona con ningun empleado.\n\n");
        system("pause");
    }

    else
    {

        printf("Empleado encontrado! Que desea modificar ? \n\n1.Apellido:\t[%s].\n2.Nombre:  \t[%s].\n3.Salario: \t[%.2f].\n4.Sector:  \t[%d].\n5.Salir\n\n",listaEmpleados[esta].apellido, listaEmpleados[esta].nombre, listaEmpleados[esta].salario, listaEmpleados[esta].sector);
        fflush(stdin);

        opcionMenuModificar = getValidInt("Ingrese una opcion: ","Solo puede ingresar numeros enteros");

        switch (opcionMenuModificar)// SUBMENU MODIFICAR EMPLEADOS
        {
        case 1:
            fflush(stdin);
            opcion= getValidChar("Realmente desea modificar su apellido?:(s/n) ","Error. Ingrese s/n",'s','n');

            if(opcion == 's')
            {
                getValidString("Ingrese el nuevo apellido: ", "Error. Solo se pueden ingresar letras.", auxApellido);

                strcpy(listaEmpleados[esta].apellido, auxApellido);
                printf("Apellido cambiado con exito!\n\n");
                system("pause");
            }

            else
            {
                printf("El apellido NO se ha modificado\n\n");
                system("pause");
            }


            break;
        case 2:

            fflush(stdin);
            opcion= getValidChar("Realmente desea modificar su nombre?:(s/n) ","Error. Ingrese s/n",'s','n');

            if(opcion == 's')
            {
                getValidString("Ingrese el nuevo nombre: ", "Error. Solo se pueden ingresar letras.", auxNombre);

                strcpy(listaEmpleados[esta].nombre, auxNombre);
                printf("Nombre cambiado con exito!\n\n");
                system("pause");
            }

            else
            {
                printf("El nombre NO se ha modificado\n\n");
                system("pause");
            }

            break;
        case 3:
            fflush(stdin);
            opcion= getValidChar("Realmente desea modificar salario?: (s/n) ","Error. Ingrese s/n",'s','n');

            if(opcion == 's')
            {
                auxSalario = getFloatOnly("Ingrese nuevo salario: ");
                listaEmpleados[esta].salario = auxSalario;
                printf("Salario cambiado con exito!\n\n");
                system("pause");
            }

            else
            {
                printf("El salario NO se ha modificado\n\n");
                system("pause");
            }

            break;
        case 4:
            fflush(stdin);
            opcion= getValidChar("Realmente desea modificar su sector?:(s/n) ","Error. Ingrese s/n",'s','n');

            if(opcion == 's')
            {
                auxSector = getValidInt("Ingrese el nuevo sector","Error. Solo puede ingresar numeros");
                listaEmpleados[esta].sector = auxSector;
                printf("Sector cambiado con exito!\n\n");
                system("pause");
            }

            else
            {
                printf("El sector NO se ha modificado\n\n");
                system("pause");
            }

            break;
        case 5:
            seguirModificarEmpleados = 'n';

        }while(seguirModificarEmpleados == 's');

    }
    return 0;

}


/** \brief Realiza suma de todos los salarios
 *
 * \param lista empleados
 * \param cantidad empleados
 * \return suma TOTAL de salarios
 *
 */

float sumarSalarios(eEmpleado* listaEmpleados, int tamEmpleados)
{
    int i;
    float suma=0;

    for(i=0; i<tamEmpleados; i ++)
    {
        if(listaEmpleados[i].isEmpty == FALSE)
        {
            suma = suma + listaEmpleados[i].salario;

        }
    }

    return suma;
}


/** \brief Realiza un promedio, teniendo en cuenta todos los salarios y la cantidad de empleados
 *
 * \param lista empleados
 * \param cantidad empleados
 * \param funcion sumar salarios
 * \return promedio total
 *
 */

float promedioSalarios(eEmpleado* listaEmpleados, int tamEmpleados, float sumarSalarios)
{
    int i;
    int contador=0;
    float promedio;

    for(i=0; i<tamEmpleados; i ++)
    {
        if(listaEmpleados[i].isEmpty == FALSE)
        {
            contador ++;
        }
    }

    promedio = sumarSalarios/contador;

    return promedio;
}


/** \brief Calcula la cantidad de empleados que tienen un sueldo mayor al promedio.
 *
 * \param lista empleados
 * \param cantidad empleados
 * \param funcion promedio salarios
 * \return cantidad de empleados que superan el sueldo promedio.
 *
 */



int cantidadEmpleadosMayorPromedio(eEmpleado* listaEmpleados, int tamEmpleados, float promedioSalarios)
{
    int i;
    int cantidadEmpleados = 0;

    for(i=0; i<tamEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].salario> promedioSalarios)
        {
            cantidadEmpleados++;
        }
    }

    printf("La cantidad de empleados que superan el sueldo promedio: %d\n\n",cantidadEmpleados);


    return cantidadEmpleados;
}


void hardcodearEmpleados(eEmpleado x[])
{
    eEmpleado y[]=
    {
        {1,"Pep","Guardiola",50000,1,0},
        {2, "Jose","Mourinhio",30000,2,0},
        {3, "Arsene","Wenger", 18000,3,0},
        {4, "Massimo","Allegri",20000,4,0},
        {5, "Carlo","Ancelotti",29000,5,0},
        {6, "Ernesto","Valverde", 31000,1,0},
        {7, "Marcelo","Gallardo",15000,2,0},
        {8, "Guillermo","Schelotto",14000,3,0},
        {9, "Luis","Enrique", 25000,4,0},
        {10, "Mauricio","Pochettino",33000,5,0},
        {11, "Antonio","Conte",27000,1,0},
        {12, "Didier","Deschamps", 24000,2,0},
        {13, "Unai","Emery",15000,3,0},
        {14, "Jorge","Sampaoli",28000,4,0},
        {15, "Vicente","DelBosque", 35000,5,0},
        {16, "Ariel","Holan",12000,1,0},
        {17, "Rafa","Benitez",21000,2,0},
        {16, "Marcelo","Bielsa",19000,3,0},
        {17, "Jurgen","Klopp",38000,4,0},

    };

    for(int i=0; i<17; i++)
    {
        x[i] = y[i];
    }

}



