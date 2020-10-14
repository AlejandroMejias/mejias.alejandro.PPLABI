#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicio.h"

void serviciosPorDefecto(eServicio servicio[], int tam_servicio)
{
    int i;
    int idServicio[] = {20000,20001,20002,20003,20004};
    char descripcion[][21] =
    {
        {"Lavado"},
        {"Pulido"},
        {"Encerado"},
        {"Completo"}
    };
    float precio[] = {250.00,300.00,400.00,600.00};

    for(i = 0; i < tam_servicio; i++)
    {
        servicio[i].idServicio = idServicio[i];
        strcpy(servicio[i].descripcion,descripcion[i]);
        servicio[i].precio = precio[i];
    }
}

int mostrarServicio(eServicio servicio[], int tam_servicio)
{
    system("cls");
    int i;
    int retorno = -1;

    printf("        ****       Listado de servicios        *****");
    printf("\n-------------------------------------------------\n\n");
    printf("ID          Descripcion     Precio \n\n");
    if(servicio != NULL && tam_servicio > 0)
    {
        retorno = 0;
        for(i = 0; i < tam_servicio; i++)
        {
            printf("%d  %12s          %.2f\n",servicio[i].idServicio,servicio[i].descripcion,servicio[i].precio);
        }
    }
    printf("\n\n");
    system("pause");
    return retorno;
}
