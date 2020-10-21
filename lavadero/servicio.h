#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[21];
    float precio;
}eServicio;

/** \brief Inicializa servicios por defecto
 *
 * \param Array de estructuras servicio
 * \param Tamaño del array servicio
 *
 */
void serviciosPorDefecto(eServicio servicio[], int tam_servicio);

/** \brief Se encarga de mostrar los servicio
 *
 * \param Array de estructuras servicio
 * \param Tamaño del array servicio
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar los servicios
 */
int mostrarServicio(eServicio servicio[], int tam_servicio);
#endif /* SERVICIO_H_INCLUDED */
