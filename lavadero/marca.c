#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "marca.h"


void marcasPorDefecto(eMarca marca[], int tam_marca)
{
    int i;
    int idMarca[] = {1000,1001,1002,1003,1004};
    char descripcion[][21] ={
        {"Renault"},
        {"Fiat"},
        {"Ford"},
        {"Chevrolet"},
        {"Peugeot"}
    };


    for(i = 0; i < tam_marca; i++)
    {
        marca[i].id = idMarca[i];
        strcpy(marca[i].descripcion,descripcion[i]);
    }

}

int mostrarMarca(eMarca marca[],int tam_marca)
{
    int i;
    int retorno = -1;

    system("cls");
    if(marca != NULL && tam_marca > 0)
    {
        printf("        ****       Listado de marcas        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID          DESCRIPCION\n\n");
         for(i = 0; i < tam_marca; i++)
        {
            printf("%d     %12s\n",marca[i].id,marca[i].descripcion);
        }
        retorno = 0;
    }

    if(retorno == -1)
    {
        printf("\nHubo un error al listar las marcas");
    }
    return retorno;
}
