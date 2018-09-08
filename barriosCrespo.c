#include <stdio.h>
#include <stdlib.h>


/** \brief Suma dos enteros
 *
 * \param primer numero
 * \param segundo numero
 * \return resultado
 *
 */

int sumar(int a, int b)
{
    int suma;
    suma= a + b;
    return suma;
}

/** \brief resta dos enteros
 *
 * \param primer numero
 * \param segundo numero
 * \return resultado
 *
 */

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
        resultado= printf("No se puede dividir\n");
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



