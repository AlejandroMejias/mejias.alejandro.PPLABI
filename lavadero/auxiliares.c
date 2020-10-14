#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "auxiliares.h"

char menu()
{
    char opcion;

    printf("        ****       Lavadero        *****");
    printf("\n------------------------------------------\n\n");
    printf("A)Alta auto\nB)Modificar auto\nC)Baja auto\nD)Listar autos\nE)Listar marcas\nF)Listar colores\nG)Listar servicios\nH)Alta trabajo\nI)listar trabajos\nX)Salir del sistema\n\n");
    printf("Ingrese su accion a ejecutar: ");

    opcion = tolower(getchar());
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
