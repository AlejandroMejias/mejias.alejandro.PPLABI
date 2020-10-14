#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auto.h"
#include "marca.h"
#include "color.h"

void inicializarAuto(eAuto autos[], int tam_auto)
{
    int i;

    if(autos != NULL && tam_auto > 0)
    {
        for(i = 0; i < tam_auto; i++)
        {
            autos[i].disponible = 1;
        }
    }
}
void autosPorDefecto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color)
{
    int i;
    int idAuto[] = {100,101,102,103,104};
    char patente[][10] ={
        {"XR5JYU6"},
        {"ML39Y61"},
        {"JP2R5B8"},
        {"EE0LOL2"},
        {"QE79YP4"},
    };
    int modelo[] = {2002,2010,1999,2017,2008};

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        for(i = 0; i < 5; i++)
        {
            autos[i].idAuto = idAuto[i];
            strcpy(autos[i].patente,patente[i]);
            strcpy(autos[i].idMarca.descripcion,marca[i].descripcion);
            strcpy(autos[i].idColor.nombre,color[i].nombre);
            autos[i].modelo = modelo[i];
            autos[i].disponible = 0;
        }
    }
}

int mostrarAutos(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color)
{
    int i;
    int retorno = -1;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        printf("        ****       Listado de autos        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID      PATENTE       Marca          Color     Modelo\n\n");
        retorno = 0;
         /*
    int idAuto;
    char patente[21];
    int marca;
    int idColor;
    int modelo;
    int disponible;
    */

        for(i = 0; i < tam_auto; i++)
        {
            if(autos[i].disponible == 0)
            {
               printf("%d  %10s  %12s %12s      %d\n",autos[i].idAuto,autos[i].patente,autos[i].idMarca.descripcion,autos[i].idColor.nombre,autos[i].modelo);
            }
        }
    }
    printf("\n\n");
    system("pause");
    return retorno;
}

int altaAuto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color)
{
    system("cls");
    int i;
    int respuesta;
    int retorno = -1;
    char patente[10];
    /*
    char marca[21];
    char color[21];
    int modelo;
    int aux;*/


    /*
        • id
        • patente
        • idMarca Validar
        • idColor Validar
        • modelo(año de fabricación)

    */

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        printf("        ****       Alta de auto        *****");
        printf("\n-----------------------------------------------\n\n");
        printf("Ingrese la patente de su auto: ");
        fflush(stdin);
        gets(patente);
        strcpy(patente,strupr(patente));

    }

    return retorno;
}
