#include <stdio.h>
#include <stdlib.h>

int sumar(int a,int b);
int restar (int a, int b);
int dividir(int a , int b);
int multiplicar(int a, int b);
int factorA (int a);
int factorB(int b);

int main()
{
    int opcion;
    int numeroUno=0;
    int numeroDos=0;
    int suma;
    int resta;
    int division;
    int multiplicacion;
    int factorialA;
    int factorialB;



   do
   {
        system("cls");
        printf("\n\n MENU \n\n");
        printf("1. Ingresar primer operando (A=%d)\n",numeroUno);
        printf("2. Ingresar segundo operando (B=%d)\n",numeroDos);
        printf("3. Calcular todas las operaciones \n");
        printf("4. Informar resultado \n");
        printf("5. Salir \n\n\n");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opcion);


       switch(opcion)
       {

           case 1:
            {
                printf("Ingrese el primer operando: ");
                scanf("%d",&numeroUno);
                break;
            }

            case 2:
            {
                printf("Ingrese el segundo operando: ");
                scanf("%d",&numeroDos);
                break;
            }

            case 3:
            {
                suma=sumar(numeroUno,numeroDos);
                resta= restar(numeroUno,numeroDos);
                division= dividir(numeroUno,numeroDos);
                multiplicacion= multiplicar(numeroUno,numeroDos);
                factorialA= factorA(numeroUno);
                factorialB=factorB(numeroDos);
                break;
            }

            case 4:
            {
                printf(" \n\n La suma es: %d\n\n",suma);
                printf(" La resta es: %d\n\n",resta);
                printf(" La division es: %d\n\n",division);
                printf(" La multiplicacion es: %d\n\n",multiplicacion);
                printf(" El factorial del primer numero es: %d\n\n",factorialA);
                printf(" El factorial del segundo numero es: %d\n\n",factorialB);
                system("pause");
                break;
            }

            case 5:
            {
                printf("\n\n Hasta luego!\n\n");
                break;
            }

            default:
            {
                printf("\n\n Error, ingrese una opcion correcta\n");
                system("pause");
                break;
            }

       }





       }

    while(opcion!=5);
    {

    }

    return 0;


   }

int sumar(int a, int b)
{
    int suma;
    suma= a + b;
    return suma;
}

int restar (int a,int b)
{
    int resta;
    resta = a - b;
    return resta;
}

int dividir(int a , int b)
{
    int resultado;
    if(b==0)
    {

        resultado= printf("No se puede dividir");
        system("pause");
    }

   else
    {
        resultado= a/b;
    }

    return resultado;
}



int multiplicar (int a, int b)
{
    int resultado;
    resultado= a*b;
    return resultado;
}

int factorA (int a)
{
    if (a==1)
    {
        return 1;
    }
    else
    {
        return a* factorA(a-1);
    }
}



int factorB (int b)
{
    if (b==1)
    {
        return 1;
    }
    else
    {
        return b* factorB(b-1);
    }
}








