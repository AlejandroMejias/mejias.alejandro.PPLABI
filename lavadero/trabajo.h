#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
typedef struct
{
    int id;
    char patente[8];
    int idServicio;
    int disponible;
    eFecha fecha;
}eTrabajo;

/** \brief Se encarga de dar de alta un trabajo
 *
 * \param Array de estructuras trabajo
 * \param Tamaño del array trabajo
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras servicio
 * \param Tamaño del array servicio
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo dar de alta el servicio
 */
int altaTrabajo(eTrabajo trabajo[],int tam_trabajo,eAuto autos[],int tam_auto,eServicio servicio[],int tam_servicio);

/** \brief
 *
 * \param Array de estructuras trabajo
 * \param Tamaño del array trabajo
 * \param Array de estructuras servicio
 * \param Tamaño del array servicio
 * \param Array de estructuras fechas
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar el servicio
 *
 */
int mostrarTrabajos(eTrabajo trabajo[],int tam_trabajo ,eServicio servicio[],int tam_servicio,eFecha fecha[]);

/** \brief Se encarga de inicializar las posiciones de trabajo
 *
 * \param Array de estructuras trabajo
 * \param Tamaño del array trabajo
 *
 */
void inicializarTrabajo(eTrabajo trabajo[], int tam_trabajo);

/** \brief Se encarga de buscar un servicio existente
 *
 * \param Tamaño del array trabajo
 * \param Array de estructuras servicio
 * \param ID del servicio a buscar
 * \param Cadena donde se copiara el nombre del servicio
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo encontrar el servicio
 */
int buscarServicio(eServicio servicio[],int tam_servicio,int idServicio, char aux[]);
#endif /* TRABAJO_H_INCLUDED*/
