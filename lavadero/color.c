#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "color.h"


void coloresPorDefecto(eColor color[], int tam_color)
{
    int i;
    int idColor[] = {5000,5001,5002,5003,5004};
    char nombre[][21] =
    {
        {"Negro"},
        {"Blanco"},
        {"Gris"},
        {"Rojo"},
        {"Azul"}
    };

    if(color != NULL && tam_color > 0)
    {
        for(i = 0; i < tam_color; i++)
        {
            color[i].id = idColor[i];
            strcpy(color[i].nombre , nombre[i]);
        }
    }
}
int mostrarColores(eColor color[], int tam_color)
{
    int i;
    int retorno = -1;

    system("cls");
    if(color != NULL && tam_color > 0)
    {
        printf("        ****       Listado de colores        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID            NOMBRE\n\n");
        retorno = 0;
         for(i = 0; i < tam_color; i++)
        {
            printf("%d   %12s\n",color[i].id,color[i].nombre);
        }
    }

    if(retorno == -1)
    {
        printf("\nHubo un error al listar los colores");
    }
    return retorno;
}





