#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct
{
    int idServicio;
    char descripcion[21];
    float precio;
}eServicio;

void serviciosPorDefecto(eServicio servicio[], int tam_servicio);
int mostrarServicio(eServicio servicio[], int tam_servicio);
#endif /* SERVICIO_H_INCLUDED */
