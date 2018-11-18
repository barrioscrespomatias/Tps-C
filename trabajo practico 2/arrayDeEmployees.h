#ifndef ARRAYDEEMPLOYEE_H_INCLUDED
#define ARRAYDEEMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
} eEmpleado;



// ID UTILIZADO PARA CUALQUIER ESTRUCTURA
static int generarNextId()
{
    static int id = -1;

    id ++;

    return id;
}

int inicializarEmpleados(eEmpleado *listaEmpleados, int tam);
int obtenerEspacioLibre(eEmpleado* lista, int tam);

int addEmployees(eEmpleado *listaEmpleados, int tamEmpleados, int auxId, char auxNombre[], char auxApellido[], float auxSalario, int auxSector);
int altaEmpleado(eEmpleado* listaEmpleados, int tamEmpleados);
int buscarEmpleadoPorId (eEmpleado *listaEmpleados, int tam, int id);
int modificarEmpleado(eEmpleado* listaEmpleados, int tamEmpleados);
int removeEmployee(eEmpleado* listaEmpleados, int tamEmpleados);
int sortEmployees(eEmpleado* lista, int len, int orden);
int mostrarUnEmpleado(eEmpleado unoSolo);
int printEmployees(eEmpleado* lista, int tam);
void hardcodearEmpleados(eEmpleado x[]);
int ordenarEmpleados(eEmpleado* listaEmpleados, int tamEmpleados, int order);
float sumarSalarios(eEmpleado* listaEmpleados, int tamEmpleados);
float promedioSalarios(eEmpleado* listaEmpleados, int tamEmpleados, float sumarSalarios);
int cantidadEmpleadosMayorPromedio(eEmpleado* listaEmpleados, int tamEmpleados, float promedioSalarios);













#endif // ARRAYDEEMPLOYEE_H_INCLUDED

