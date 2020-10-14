#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"
typedef struct
{
    int idAuto;
    char patente[21];
    eMarca idMarca;
    eColor idColor;
    int modelo;
    int disponible;

}eAuto;
void inicializarAuto(eAuto autos[], int tam_auto);
void autosPorDefecto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);
int mostrarAutos(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);
int altaAuto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);
#endif /* AUTO_H_INCLUDED */
