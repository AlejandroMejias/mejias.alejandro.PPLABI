#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "auto.h"
#include "servicio.h"
#include "fecha.h"
#include "trabajo.h"
#include "auxiliares.h"
#include "trabajo.h"

void inicializarTrabajo(eTrabajo trabajo[], int tam_trabajo)
{
    int i;

    for(i = 0; i < tam_trabajo; i++)
    {
        trabajo[i].disponible = 1;
    }
}
int altaTrabajo(eTrabajo trabajo[],int tam_trabajo,eAuto autos[],int tam_auto,eServicio servicio[],int tam_servicio)
{
    int retorno = -1;
    char patente[8];
    int idServicio;
    int respuesta;
    int i;
    int dia;
    int mes;
    int anio;
    char seguir = 's';

    if(trabajo != NULL && autos != NULL && servicio != NULL && tam_trabajo > 0 && tam_servicio > 0)
    {
        do
        {
            imprimirPatentes(autos,tam_auto);
            respuesta = capturarCadena(patente);
            while(respuesta == -1)
            {
                printf("\n\nERROR! Ingrese un formato de patente correcto.Ejem, XR5JYU6:\n\n");
                system("pause");
                system("cls");
                imprimirPatentes(autos,tam_auto);
                respuesta = capturarCadena(patente);
            }

            respuesta = buscarPatente(autos,tam_auto,patente);

            if(respuesta > -1)
            {
                system("cls");
                mostrarServicio(servicio,tam_servicio);
                printf("\nSe registrara un servicio al auto con patente %s\n\n",patente);
                respuesta = capturarServicio(&idServicio);
                while(respuesta == -1)
                {
                    printf("\n\nERROR! Ingrese nuevamente un id existente...\n\n");
                    system("pause");
                    system("cls");
                    mostrarServicio(servicio,tam_servicio);
                    respuesta = capturarServicio(&idServicio);
                }
                system("cls");
                printf("\nIngrese la fecha en que se hara el servicio.Ejem, 03/04/2020:  ");
                fflush(stdin);
                scanf("%d/%d/%d",&dia,&mes,&anio);

                /*Valido fecha*/
                while(dia > 31 || mes > 12 || anio != 2020 || dia < 1 || mes < 1)
                {
                    printf("\nERROR!Ingrese una fecha correcta para el servicio del vehiculo.Ejem, 03/04/2020:  ");
                    fflush(stdin);
                    scanf("%d/%d/%d",&dia,&mes,&anio);
                }

                for(i = 0; i < tam_trabajo; i++)
                {
                    if(trabajo[i].disponible == 1)
                    {
                        trabajo[i].id = 1 + i;
                        strcpy(trabajo[i].patente,patente);
                        trabajo[i].idServicio = idServicio;
                        trabajo[i].fecha.dia = dia;
                        trabajo[i].fecha.mes = mes;
                        trabajo[i].fecha.anio = anio;
                        trabajo[i].disponible = 0;
                        retorno = 0;
                        break;
                    }
                }

                system("cls");
                printf("\nNecesitar dar de alta a otro trabajo? S(Si) / N(No)\n");
                printf("\nIngrese su accion a ejecutar: ");
                fflush(stdin);
                seguir = tolower(getchar());
                seguir = validarCaracter(seguir);
            }
            system("cls");
        }
        while(seguir == 's');
    }
    return retorno;
}
int buscarServicio(eServicio servicio[],int tam_servicio,int idServicio, char aux[])
{
    int i;
    int retorno = -1;
    if(servicio != NULL && tam_servicio > 0 && idServicio > 0)
    {
        for(i = 0; i < tam_servicio; i++)
        {
            if(servicio[i].id == idServicio)
            {
                strcpy(aux,servicio[i].descripcion);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int mostrarTrabajos(eTrabajo trabajo[],int tam_trabajo,eServicio servicio[],int tam_servicio,eFecha fecha[])
{
    int i;
    int retorno = -1;
    char aux[21];
    int idServicio;

    if(trabajo != NULL && servicio != NULL && fecha != NULL && tam_trabajo > 0 && tam_servicio > 0)
    {
        system("cls");
        printf("      ****       Listado de trabajos        *****");
        printf("\n    ----------------------------------------------\n\n");
        printf("ID     Patente        Servicio      Fecha \n\n");
        for(i = 0; i < tam_trabajo; i++)
        {
            if(trabajo[i].disponible == 0)
            {
                idServicio = trabajo[i].idServicio;
                buscarServicio(servicio,tam_servicio,idServicio,aux);
                printf("%d     %8s   %12s     %d/%d/%d\n",trabajo[i].id,trabajo[i].patente,aux,trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);
            }
        }
    }
    return retorno;
}
