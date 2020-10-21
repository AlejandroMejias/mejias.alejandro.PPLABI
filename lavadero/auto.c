#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "auto.h"
#include "marca.h"
#include "color.h"
#include "auxiliares.h"
#include "cliente.h"

int inicializarAuto(eAuto autos[], int tam_auto)
{
    int i;

    if(autos != NULL && tam_auto > 0)
    {
        for(i = 0; i < tam_auto; i++)
        {
            autos[i].disponible = 1;
        }
    }
    return 0;
}
int autosPorDefecto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color,eCliente clientes[], int tam_cliente)
{
    int i;
    char patente[][8] =
    {
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
            autos[i].idAuto = 100 + i;
            strcpy(autos[i].patente,patente[i]);
            autos[i].idMarca = marca[i].id;
            autos[i].idColor = color[i].id;
            autos[i].modelo = modelo[i];
            autos[i].idCliente = clientes[i].id;
            autos[i].disponible = 0;
        }
    }
    return 0;
}
int buscarColor(eColor color[], int tam_color, char auxColor[],int id)
{
    int i;

    if(color != NULL && tam_color > 0)
    {
        for(i = 0; i < tam_color; i++)
        {
            if(id == color[i].id)
            {
                strcpy(auxColor,color[i].nombre);
            }
        }
    }

    return 0;
}
int buscarMarca(eMarca marca[], int tam_marca, char auxMarca[],int id)
{
    int i;
    int retorno = -1;

    if(marca != NULL && tam_marca > 0)
    {
        for(i = 0; i < tam_marca; i++)
        {
            if(id == marca[i].id)
            {
                strcpy(auxMarca,marca[i].descripcion);
                retorno = 0;
            }
        }
    }

    if(retorno == -1)
    {
        printf("No existe un color con ese id, por favor intente nuevamente");
    }
    return retorno;
}
int mostrarAutos(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color, eCliente clientes[],int tam_cliente)
{
    int i;
    int j;
    int retorno = -1;
    char auxColor[21];
    char auxMarca[21];
    char auxCliente[21];
    int idAux;
    eAuto auxAuto;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        printf("        ****       Listado de autos        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID      PATENTE       Marca         Color     Modelo    NOMBRE CLIENTE \n\n");

        for(i = 0; i < tam_auto - 1; i++)
        {
            for(j = i + 1; j < tam_auto; j++)
            {
                if((strcmp(marca[i].descripcion,marca[j].descripcion) > 0 && strcmp(autos[i].patente,autos[j].patente) < 0) || (strcmp(marca[i].descripcion,marca[j].descripcion) < 0 && strcmp(autos[i].patente,autos[j].patente) < 0))
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
            }
        }

        for(i = 0; i < tam_auto; i++)
        {

            if(autos[i].disponible == 0)
            {
                idAux = autos[i].idColor;
                buscarColor(color,tam_color,auxColor,idAux);
                idAux = autos[i].idMarca;
                buscarMarca(marca,tam_marca,auxMarca,idAux);
                idAux = autos[i].idCliente;
                buscarCliente(clientes,tam_cliente,auxCliente,idAux);
                printf("%d   %8s  %12s %12s      %d   %12s  \n",autos[i].idAuto,autos[i].patente,auxMarca,auxColor,autos[i].modelo,auxCliente);
                retorno = 0;
            }
        }
    }

    if(retorno == -1)
    {
        printf("\n\nNo hay autos para mostrar");
    }
    printf("\n\n");
    return retorno;
}
int buscarLibre(eAuto autos[], int tam_auto)
{
    int i;
    int indice;

    if(autos != NULL && tam_auto)
    {
        for(i = 0; i < tam_auto; i++)
        {
            if(autos[i].disponible == 1)
            {
                indice = i;
                break;
            }
            else
            {
                indice = -1;
            }
        }
    }
    return indice;
}
int altaAutos(eAuto autos[],int tam_auto,char patente[],int color,int marca,int modelo,int idAuto,int idCliente)
{
    int retorno = -1;
    int i;

    for(i = 0; i < tam_auto; i++)
    {
        if(autos[i].disponible == 1)
        {
            autos[i].idAuto = idAuto + 1;
            strcpy(autos[i].patente,patente);
            autos[i].idMarca = marca;
            autos[i].idColor = color;
            autos[i].modelo = modelo;
            autos[i].idCliente = idCliente;
            autos[i].disponible = 0;
            retorno = 0;
            break;
        }
    }
    system("cls");
    return retorno;
}

void imprimirPatentes(eAuto autos[],int tam_auto)
{
    int i;

    if(autos != NULL && tam_auto > 0)
    {
        printf("        Patentes registradas en sistema \n");
        printf("      ---------------------------------------\n\n");
        for(i = 0; i < tam_auto; i++)
        {
            if(autos[i].disponible == 0)
            {
                printf("%8s\n",autos[i].patente);
            }
        }
        printf("\n");
    }
}
int buscarPatente(eAuto autos[], int tam_auto, char patente[])
{
    int i;
    int indice = -1;

    if(autos != NULL && tam_auto > 0)
    {
        for(i = 0; i < tam_auto; i++)
        {
            if(strcmp(autos[i].patente,patente) == 0 )
            {
                indice = i;
                break;
            }
        }
    }
    if(indice == -1)
    {
        printf("\n\nNo tenemos registrado la patente %s en el sistema...\n\n",patente);
    }
    return indice;
}
int modificarAuto(eAuto autos[],int tam_auto,eColor color[],int tam_color)
{
    int indice;
    char patente[8];
    char auxColor[21];
    int idColor;
    int auxModelo;
    int respuesta;
    int opcion;
    int retorno = -1;

    if(autos != NULL && color != NULL && tam_auto > 0 && tam_color > 0)
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
        indice = buscarPatente(autos,tam_auto,patente);

        if(indice >= 0)
        {
            system("cls");
            printf("        Modificar auto \n");
            printf("      ---------------------\n\n");
            printf("A)Modificar color\nB)Modificar modelo\n\n");
            printf("Ingrese su accion a ejecutar: ");
            opcion = tolower(getchar());
            opcion = validarCaracter(opcion);

            switch(opcion)
            {
            case 'a':
                system("cls");
                mostrarColores(color,tam_color);
                buscarColor(color,tam_color,auxColor,autos[indice].idColor);
                printf("\n\nEl color actual es: %s\n",auxColor);
                respuesta = capturarColor(&idColor);

                /*Valido ID del color*/
                while(respuesta == -1)
                {
                    system("cls");
                    printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
                    system("pause");
                    mostrarColores(color,tam_color);
                    buscarColor(color,tam_color,auxColor,autos[indice].idColor);
                    printf("\n\nEl color actual es: %s\n",auxColor);
                    respuesta = capturarColor(&idColor);
                }
                autos[indice].idColor = idColor;
                retorno = 0;
                break;
            case 'b':
                printf("\nEl a%co actual es: %d\n\n",162,autos[indice].modelo);
                respuesta = capturarModelo(&auxModelo);
                while(respuesta == -1)
                {
                    printf("\nERROR! El a%co no puede ser mayor a 2020...\n\n",164);
                    system("pause");
                    respuesta = capturarModelo(&auxModelo);
                }
                autos[indice].modelo = auxModelo;
                retorno = 0;
                break;
            default:
                retorno = -1;
            }
        }
    }
    system("cls");
    return retorno;
}
int eliminarAuto(eAuto autos[], int tam_auto)
{
    int indice;
    char patente[8];
    char respuesta;
    int retorno = -1;

    if(autos != NULL && tam_auto > 0)
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
        indice = buscarPatente(autos,tam_auto,patente);

        if(strcmp(autos[indice].patente,patente) == 0)
        {
            printf("\nSe eliminara el auto con patente -->  %s.\n\nEstas seguro que deseas eliminarlo? S(si) / N(no)",patente);
            printf("\nIngrese su accion a ejecutar: ");
            fflush(stdin);
            scanf("%c",&respuesta);
            respuesta = validarCaracter(respuesta);
            if(respuesta == 's')
            {
                autos[indice].disponible = 1;
                retorno = 0;
            }
        }
    }
    system("cls");
    return retorno;
}
int mostrarAuto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color,int id)
{
    int i;
    int retorno = -1;
    char auxColor[21];
    char auxMarca[21];
    int idAux;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        printf("        ****       Listado de autos        *****");
        printf("\n-------------------------------------------------\n\n");
        printf("ID      PATENTE       Marca         Color     Modelo\n\n");

        for(i = 0; i < tam_auto; i++)
        {

            if(autos[i].idColor == id || autos[i].idMarca == id)
            {
                idAux = autos[i].idColor;
                buscarColor(color,tam_color,auxColor,idAux);
                idAux = autos[i].idMarca;
                buscarMarca(marca,tam_marca,auxMarca,idAux);
                printf("%d   %8s  %12s %12s      %d\n",autos[i].idAuto,autos[i].patente,auxMarca,auxColor,autos[i].modelo);
                retorno = 0;
            }
        }
    }
    return retorno;
}
int autosPorMarca(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color)
{
    int retorno = -1;
    int idMarca;
    int respuesta;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_color > 0 && tam_marca > 0)
    {
        mostrarMarca(marca,tam_marca);
        respuesta = capturarMarca(&idMarca);
        while(respuesta == -1)
        {
            printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
            system("pause");
            mostrarMarca(marca,tam_marca);
            respuesta = capturarMarca(&idMarca);
        }
        system("cls");
        mostrarAuto(autos,tam_auto,marca,tam_marca,color,tam_color,idMarca);
        retorno = 0;

    }
    return retorno;
}
int autosPorColor(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color)
{
    int retorno = -1;
    int idColor;
    int respuesta;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_color > 0 && tam_marca > 0)
    {
        mostrarColores(color,tam_color);
        respuesta = capturarColor(&idColor);

        while(respuesta == -1)
        {
            system("cls");
            printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
            system("pause");
            mostrarColores(color,tam_color);
            respuesta = capturarColor(&idColor);
        }
        system("cls");
        mostrarAuto(autos,tam_auto,marca,tam_marca,color,tam_color,idColor);
        retorno = 0;
    }
    return retorno;
}
void autosViejos(eAuto autos[],int tam_auto, eMarca marca[],int tam_marca, eColor color[], int tam_color)
{
    int i;
    int minimo;
    int idAux;
    char auxColor[21];
    char auxMarca[21];

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color > 0)
    {
        printf("        ****       Autos mas viejos        *****");
        printf("\n     ------------------------------------------\n\n");
        printf("ID      PATENTE       Marca         Color     Modelo\n\n");

        minimo = autos[0].modelo;
        for(i = 0; i < tam_auto; i++)
        {
            if(autos[i].modelo <= minimo && autos[i].disponible == 0)
            {
                minimo = autos[i].modelo;
            }
        }
        for(i = 0; i < tam_auto; i++)
        {
            if(autos[i].modelo == minimo && autos[i].disponible == 0 )
            {
                idAux = autos[i].idColor;
                buscarColor(color,tam_color,auxColor,idAux);
                idAux = autos[i].idMarca;
                buscarMarca(marca,tam_marca,auxMarca,idAux);
                printf("%d   %8s  %12s %12s      %d\n",autos[i].idAuto,autos[i].patente,auxMarca,auxColor,autos[i].modelo);
            }
        }
    }
}
void separarPorMarca(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[],int tam_color)
{
    int i;
    int j;
    int idAux;
    int aux;
    char auxColor[21];

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color)
    {
        for(i = 0; i < tam_marca; i++)
        {
            aux = marca[i].id;
            printf("%12s           |\n",marca[i].descripcion);
            printf("-----------------------\n");
            printf("ID      PATENTE         Color     Modelo\n\n");
            for(j = 0; j < tam_auto; j++)
            {
                if(aux == autos[j].idMarca && autos[j].disponible == 0)
                {
                    idAux = autos[j].idColor;
                    buscarColor(color,tam_color,auxColor,idAux);
                    printf("%d   %8s  %12s      %d\n",autos[j].idAuto,autos[j].patente,auxColor,autos[j].modelo);
                }
            }
            printf("\n");
            printf("-----------------------------------------------\n");
        }
    }
}
void contar_MarcaColor(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[], int tam_color)
{
    int i;
    int contadorMarca = 0;
    int contadorColor = 0;
    int idMarca;
    int idColor;
    int respuesta;
    char auxColor[21];
    char auxMarca[21];

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color)
    {
        mostrarMarca(marca,tam_marca);
        respuesta = capturarMarca(&idMarca);
        while(respuesta == -1)
        {
            printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
            system("pause");
            mostrarMarca(marca,tam_marca);
            respuesta = capturarMarca(&idMarca);
        }
        mostrarColores(color,tam_color);
        respuesta = capturarColor(&idColor);

        while(respuesta == -1)
        {
            system("cls");
            printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
            system("pause");
            mostrarColores(color,tam_color);
            respuesta = capturarColor(&idColor);
        }
        buscarMarca(marca,tam_marca,auxMarca,idMarca);
        buscarColor(color,tam_color,auxColor,idColor);

        for(i = 0; i < tam_auto; i++)
        {
            if(idColor == autos[i].idColor)
            {
                contadorColor++;
            }
            if(idMarca == autos[i].idMarca)
            {
                contadorMarca++;
            }
        }
        system("cls");
        printf("\n  Cantidad de autos color %s ---> %d\n",auxColor,contadorColor);
        printf("\n  Cantidad de autos marca %s ---> %d\n",auxMarca,contadorMarca);
    }
}
void marcasMasElegidas(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[], int tam_color)
{
    int i;
    int j;
    int contador[tam_marca];
    int maximo;
    int flag = 0;

    if(autos != NULL && marca != NULL && color != NULL && tam_auto > 0 && tam_marca > 0 && tam_color)
    {
        for(i = 0; i < tam_marca; i++)
        {
            contador[i] = 0;
        }
        for(i = 0; i < tam_marca; i++)
        {
            for(j = 0; j < tam_auto; j++)
            {
                if(autos[j].disponible == 0 && autos[j].idMarca == marca[i].id)
                {
                    contador[i]++;
                }
            }

        }

        for(i = 0; i < tam_marca; i++)
        {
            if(contador[i] > maximo || flag == 0)
            {
                maximo = contador[i];
                flag = 1;
            }
        }
        printf("\nLa marca con mas cantidad es:\n");

        for(i = 0; i < tam_auto; i++)
        {
            if(contador[i] == maximo)
            {
                printf("\n%s",marca[i].descripcion);
            }
        }
    }

}
