#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_SERVICIO 4
#define TAM_MARCA 5
#define TAM_COLOR 5
#define TAM_AUTO 10

/*Bibliotecas*/
#include "auto.h"
#include "auxiliares.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
int main()
{

    char opcion;
    eAuto Auto[TAM_AUTO];
    eMarca Marca[TAM_MARCA];
    eColor Color[TAM_COLOR];
    eServicio Servicio[TAM_SERVICIO];

    marcasPorDefecto(Marca,TAM_MARCA);
    coloresPorDefecto(Color,TAM_COLOR);
    serviciosPorDefecto(Servicio,TAM_SERVICIO);
    inicializarAuto(Auto,TAM_AUTO);
    autosPorDefecto(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);


    do
    {
        opcion = menu();
    /*
        AUTO:::
        � id
        � patente
        � idMarca Validar
        idColor Validar
        modelo(a�o de fabricaci�n)

    */

        switch(opcion)
        {
            case 'a':
                /*altaAuto(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);*/
                break;
            case 'd':
                mostrarAutos(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                break;
            case 'e':
                mostrarMarca(Marca,TAM_MARCA);
                break;
            case 'f':
                system("cls");
                mostrarColores(Color,TAM_COLOR);
                printf("\n\n");
                system("pause");
                break;
            case 'g':
                mostrarServicio(Servicio,TAM_SERVICIO);
                break;
        }
        fflush(stdin);
        system("cls");
    }while(opcion != 'x');

    return 0;
}
/*

    Fecha:
� dia
� mes
� a�o

Marca:
� id (comienza en 1000)
� descripci�n (m�x 20 caracteres)
Color:
� id (comienza en 5000)
� nombreColor(m�x 20 caracteres)

Auto:
� id
� patente
� idMarca Validar
� idColor Validar
� modelo(a�o de fabricaci�n)

Servicio:
� id(comienza en 20000)
� descripci�n (m�xim
o 25 caracteres)
� precio

Trabajo:
� id (autoincremental)
� patente (debe existir) Validar
� idServicio (debe existir) Validar
� fecha ( Validar d�a, mes y a�o )

DATOS PREVIOS:

Los arrays de marca, color y lavado deber�n ser hardcodeados.
Marcas (Renault, Fiat, Ford, Chevrolet, Peugeot)
Colores (Negro, Blanco, Gris, Rojo, Azul)
Lavados (Lavado: $250, Pulido: $300, Encerado: $400, Completo: $600)



*/
