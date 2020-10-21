#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auxiliares.h"
#include "auto.h"

char menu()
{
    char opcion;

    printf("        ****       Lavadero        *****");
    printf("\n------------------------------------------\n\n");
    printf("A)Alta auto\nB)Modificar auto\nC)Baja auto\nD)Listar autos\nE)Listar marcas\nF)Listar colores\nG)Listar servicios\nH)Alta trabajo\nI)listar trabajos\nJ)Menu informes\nX)Salir del sistema\n\n");
    printf("Ingrese su accion a ejecutar: ");

    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);

    return opcion;
}
char validarCaracter(char caracter)
{

    while(caracter < 97 || caracter > 122 )
    {
        printf("\nERROR! Ingresa una opcion correcta: ");
        fflush(stdin);
        caracter = tolower(getchar());
    }
    return caracter;
}
void toMayuscula(char cadena [])
{
    int i;
    char aux;
    for(i = 0; i < strlen(cadena); i++)
    {
        aux = cadena[i];
        aux = toupper(aux);
        cadena[i] = aux;
    }
}
int capturarCadena(char cadena[])
{
    int retorno = -1;
    int tam;
    int i;
    int aux;


    printf("Ingrese la patente de su auto. Ejem XR5JYU6: ");
    fflush(stdin);
    gets(cadena);
    toMayuscula(cadena);
    tam = strlen(cadena);

    for(i = 0; cadena[i] != '\0' && tam == 7; i++)
    {
        aux = cadena[i];
        if((aux >= 48 && aux <= 57) || (aux >= 65 && aux <= 90))
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}
int capturarColor(int* color)
{
    int auxColor;
    int retorno = -1;

    if(color != NULL)
    {
        printf("\nIngrese el id del color: ");
        fflush(stdin);
        scanf("%d",&auxColor);

        if(auxColor > 4999  && auxColor < 5005)
        {
            *color = auxColor;
            retorno = 0;
        }
    }
    return retorno;
}
int capturarMarca(int* marca)
{
    int auxMarca;
    int retorno = -1;

    if(marca != NULL)
    {
        printf("\nIngrese el id de la marca: ");
        fflush(stdin);
        scanf("%d",&auxMarca);

        if(auxMarca > 999 && auxMarca < 1005)
        {
            *marca = auxMarca;
            retorno = 0;
        }
    }
    return retorno;
}
int capturarModelo(int* modelo)
{
    int auxModelo;
    int retorno = -1;

    if(modelo != NULL)
    {
        system("cls");
        printf("\nIngrese el a%co de fabricacion de su vehiculo. Ejem: 2005: ",164);
        fflush(stdin);
        scanf("%d",&auxModelo);

        if(auxModelo > 1950 && auxModelo < 2021)
        {
            *modelo = auxModelo;
            retorno = 0;
        }
    }
    return retorno;
}

int capturarServicio(int* servicio)
{
    int auxServicio;
    int retorno = -1;

    if(servicio != NULL)
    {
        printf("\nSeleccione el servicio a prestar: ");
        fflush(stdin);
        scanf("%d",&auxServicio);

        if(auxServicio > 19999 && auxServicio < 20005)
        {
            *servicio = auxServicio;
            retorno = 0;
        }
    }
    return retorno;
}
int capturarCliente(int* cliente)
{
    int auxCliente;
    int retorno = -1;

    if(cliente != NULL)
    {
        printf("\nSeleccione el ID del cliente a asignar: ");
        fflush(stdin);
        scanf("%d",&auxCliente);

        if(auxCliente > 0 && auxCliente < 11)
        {
            *cliente = auxCliente;
            retorno = 0;
        }
    }
    return retorno;
}

char menuInformes()
{
    char opcion;

    printf("        ****       Lavadero        *****");
    printf("\n------------------------------------------\n\n");
    printf("K)Listar autos por color\nL)Listar autos por marca\nM)Listar autos o el auto mas viejo\nN)Separar autos por marca\nO)Contar marcas y color\nP)Mostrar la marca mas elegida\nX)Salir del sistema\n\n");
    printf("Ingrese su accion a ejecutar: ");
    fflush(stdin);
    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);

    return opcion;
}
