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


int initEmployees(eEmpleado* lista, int tam);
int obtenerEspacioLibre(eEmpleado* lista, int tam);

int addEmployees(eEmpleado* lista, int tam, int id, char nombre[], char apellido[], float salario, int sector);
int altaEmpleado(eEmpleado* lista, int tam);
int findEmployeeById(eEmpleado* lista, int tam,int id);
int removeEmployee(eEmpleado* lista, int tam, int id);
int sortEmployees(eEmpleado* lista, int len, int orden);
int mostrarUnEmpleado(eEmpleado unoSolo);
int printEmployees(eEmpleado* lista, int tam);









#endif // ARRAYDEEMPLOYEE_H_INCLUDED

