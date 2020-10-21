#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cliente.h"
void clientesPorDefecto(eCliente clientes[],int tam_cliente)
{
    int i;

    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[][21] ={
        {"Ana"},
        {"Paula"},
        {"Jose"},
        {"Luis"},
        {"Natalia"},
        {"Fernando"},
        {"Jesus"},
        {"Maria"},
        {"Lautaro"},
        {"Lucia"},
    };
    char sexo[10] = {'f','f','m','m','f','m','m','f','m','f'};


    for(i = 0; i < tam_cliente; i++)
    {
        clientes[i].id = id[i];
        strcpy(clientes[i].nombre,nombre[i]);
        clientes[i].sexo = sexo[i];
    }
}
int mostrarCliente(eCliente clientes[],int tam_cliente)
{
    int i;
    int retorno = -1;

    system("cls");
    printf("      ****       Listado de Clientes        *****");
    printf("\n    ----------------------------------------------\n\n");
    printf("ID          Nombre\n\n");
    if(clientes != NULL && tam_cliente > 0)
    {
        for(i = 0; i < tam_cliente; i++)
        {
            printf("%d  %12s\n",clientes[i].id,clientes[i].nombre);
        }
        retorno = 0;
    }
    return retorno;
}
int buscarCliente(eCliente clientes[],int tam_cliente, char auxCliente[],int id)
{
    int i;
    int retorno = -1;

    if(clientes != NULL && tam_cliente > 0)
    {
        for(i = 0; i < tam_cliente; i++)
        {
            if(id == clientes[i].id)
            {
                strcpy(auxCliente,clientes[i].nombre);
                retorno = 0;
            }
        }
    }

    if(retorno == -1)
    {
        printf("No existe un cliente con ese id, por favor intente nuevamente");
    }
    return retorno;
}
