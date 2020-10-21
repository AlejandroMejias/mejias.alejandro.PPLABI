#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_SERVICIO 4
#define TAM_MARCA 5
#define TAM_COLOR 5
#define TAM_AUTO 10
#define TAM_CLIENTE 10
#define TAM_TRABAJO 100

/*Bibliotecas*/
#include "auto.h"
#include "auxiliares.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "trabajo.h"
#include "fecha.h"
#include "cliente.h"

int main()
{

    char opcion;
    int respuesta;
    int banderaAltas = 1;
    int banderaTrabajos = 1;
    char patente[8];
    int idColor;
    int idMarca;
    int modelo;
    int cliente;
    int idAuto = 99;

    eAuto Auto[TAM_AUTO];
    eMarca Marca[TAM_MARCA];
    eColor Color[TAM_COLOR];
    eServicio Servicio[TAM_SERVICIO];
    eTrabajo Trabajo[TAM_TRABAJO];
    eFecha Fecha[TAM_TRABAJO];
    eCliente Cliente[TAM_CLIENTE];

    inicializarAuto(Auto,TAM_AUTO);
    inicializarTrabajo(Trabajo,TAM_TRABAJO);
    marcasPorDefecto(Marca,TAM_MARCA);
    coloresPorDefecto(Color,TAM_COLOR);
    serviciosPorDefecto(Servicio,TAM_SERVICIO);
    clientesPorDefecto(Cliente,TAM_CLIENTE);



    if(autosPorDefecto(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR,Cliente,TAM_CLIENTE) == 0)
    {
        idAuto = 104;
    }

    do
    {
        opcion = menu();

        switch(opcion)
        {
            case 'a':
                system("cls");
                printf("        ****       Alta de auto        *****");
                printf("\n-----------------------------------------------\n\n");
                respuesta = capturarCadena(patente);
                while(respuesta == -1)
                {
                    printf("\n\nERROR! Ingrese un formato de patente correcto.Ejem, XR5JYU6:\n\n");
                    system("pause");
                    system("cls");
                    respuesta = capturarCadena(patente);
                }
                mostrarColores(Color,TAM_COLOR);
                respuesta = capturarColor(&idColor);
                while(respuesta == -1)
                {
                    printf("\n\nERROR! Ingrese nuevamente un id existente...\n\n");
                    system("pause");
                    mostrarColores(Color,TAM_COLOR);
                    respuesta = capturarColor(&idColor);
                }
                mostrarMarca(Marca,TAM_MARCA);
                respuesta = capturarMarca(&idMarca);
                while(respuesta == -1)
                {
                    printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
                    system("pause");
                    mostrarMarca(Marca,TAM_MARCA);
                    respuesta = capturarMarca(&idMarca);
                }

                respuesta = capturarModelo(&modelo);
                while(respuesta == -1)
                {
                    printf("\nERROR! El a%co no puede ser mayor a 2020...\n\n",164);
                    system("pause");
                    respuesta = capturarModelo(&modelo);
                }
                mostrarCliente(Cliente,TAM_CLIENTE);
                respuesta = capturarCliente(&cliente);
                while(respuesta == -1)
                {
                    printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
                    system("pause");
                    mostrarCliente(Cliente,TAM_CLIENTE);
                    respuesta = capturarCliente(&cliente);
                }
                respuesta = altaAutos(Auto,TAM_AUTO,patente,idColor,idMarca,modelo,idAuto,cliente);
                idAuto++;

                if(respuesta == 0)
                {
                    printf("\nAlta exitosa...");
                    banderaAltas = 0;
                }
                else
                {
                    printf("\nHubo un problema con el alta del auto");
                }
                break;
            case 'b':
                if(banderaAltas == 0)
                {
                    system("cls");
                    respuesta = modificarAuto(Auto,TAM_AUTO,Color,TAM_COLOR);
                    if(respuesta == 0)
                    {
                        printf("\n\nModificacion exitosa...");
                    }
                    else
                    {
                        printf("\n\nNo fue posible efectuar la modificacion, verifique los datos ingresados...\n\n");
                    }
                }
                else
                {
                    printf("\n\nNo puedes ingresar a esta opcion sin haber ingresado al menos un auto");
                }

                break;
            case 'c':
                if(banderaAltas == 0)
                {
                    system("cls");
                    respuesta = eliminarAuto(Auto,TAM_AUTO);
                    if(respuesta == 0)
                    {
                        printf("\n\nBaja exitosa...");
                    }
                    else
                    {
                        printf("\n\nNo se completo la baja del auto");
                    }
                }
                else
                {
                    printf("\n\nNo puedes ingresar a esta opcion sin haber ingresado al menos un auto");
                }

                break;
            case 'd':
                if(banderaAltas == 0)
                {
                    system("cls");
                    mostrarAutos(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR,Cliente,TAM_CLIENTE);
                }
                else
                {
                    printf("\n\nNo puedes ingresar a esta opcion sin haber ingresado al menos un auto");
                }

                break;
            case 'e':
                mostrarMarca(Marca,TAM_MARCA);
                break;
            case 'f':
                mostrarColores(Color,TAM_COLOR);
                break;
            case 'g':
                system("cls");
                mostrarServicio(Servicio,TAM_SERVICIO);
                break;
            case 'h':
                system("cls");
                respuesta = altaTrabajo(Trabajo,TAM_TRABAJO,Auto,TAM_AUTO,Servicio,TAM_SERVICIO);
                if(respuesta == 0)
                {
                    printf("\n\nAlta de trabajo exitosa");
                    banderaTrabajos = 0;
                }
                else
                {
                    printf("\n\nNo fue posible completar el alta de trabajo!");
                }
                break;
            case 'i':
                if(banderaTrabajos == 0)
                {
                    mostrarTrabajos(Trabajo,TAM_TRABAJO,Servicio,TAM_SERVICIO,Fecha);
                }
                else
                {
                    printf("\n\nNo puedes mostrar los trabajos sin antes ingresar al menos un trabajo");
                }
                break;
            case 'j':
                if(banderaAltas == 0)
                {
                    system("cls");
                    opcion = menuInformes();

                    switch(opcion)
                    {
                    case 'k':
                        system("cls");
                        autosPorColor(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'l':
                        system("cls");
                        autosPorMarca(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'm':
                        system("cls");
                        autosViejos(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'n':
                        system("cls");
                        separarPorMarca(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'o':
                        system("cls");
                        contar_MarcaColor(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'p':
                        system("cls");
                        marcasMasElegidas(Auto,TAM_AUTO,Marca,TAM_MARCA,Color,TAM_COLOR);
                        break;
                    case 'x':
                        system("cls");
                        printf("\nSaliendo del sistema...");
                        break;
                    default:
                        system("cls");
                        printf("\nOpcion invalida.Sera devuelto al menu principal\n\n");
                    }
                }
                else
                {
                    printf("\n\nNo puedes ingresar a esta opcion sin haber ingresado al menos un auto");
                }
                break;
            case 'x':
                system("cls");
                printf("\nSaliendo del sistema...");
                break;
            default:
                system("cls");
                printf("\nOpcion invalida.Se mostrara el menu nuevamente\n\n");
        }
        fflush(stdin);
        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(opcion != 'x');

    return 0;
}
