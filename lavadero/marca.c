#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "marca.h"


void marcasPorDefecto(eMarca marca[], int tam_marca)
{
    int i;
    int idMarca[] = {1000,10001,10002,10003};
    char descripcion[][21] ={
        {"Renault"},
        {"Fiat"},
        {"Ford"},
        {"Chevrolet"},
        {"Peugeot"}
    };


    for(i = 0; i < tam_marca; i++)
    {
        marca[i].idMarca = idMarca[i];
        strcpy(marca[i].descripcion,descripcion[i]);
    }

}

int mostrarMarca(eMarca marca[],int tam_marca)
{
     system("cls");
    int i;
    int retorno = -1;

    printf("        ****       Listado de marcas        *****");
    printf("\n-------------------------------------------------\n\n");
    printf("ID          DESCRIPCION\n\n");

    if(marca != NULL && tam_marca > 0)
    {
        printf("        ****       Listado de marcas        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID          DESCRIPCION\n\n");
        retorno = 0;
         for(i = 0; i < tam_marca; i++)
        {
            printf("%d     %12s\n",marca[i].idMarca,marca[i].descripcion);
        }
    }

    if(retorno == -1)
    {
        printf("\nHubo un error al listar las marcas");
    }

    printf("\n\n");
    system("pause");
    return retorno;
}
