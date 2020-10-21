#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "cliente.h"
typedef struct
{
    int idAuto;
    char patente[8];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
    int disponible;

}eAuto;
/** \brief Se encarga de inicializar las posiciones de la estructura
 *
 * \param Array de estructuras auto
 * \param Tamaño del array
 * \return 0
 *
 */
int inicializarAuto(eAuto autos[], int tam_auto);

/** \brief Se encarga de cargar por defecto en  5 posiciones del Array de estructuras auto
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param Array de estructuras cliente
 * \param Tamaño del array cliente
 * \return 0
 *
 */
int autosPorDefecto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color,eCliente clientes[], int tam_cliente);

/** \brief Mostrar listado de autos
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param Array de estructuras cliente
 * \param Tamaño del array cliente
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar los autos
 *
 */
int mostrarAutos(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color, eCliente clientes[],int tam_cliente);

/** \brief Se encarga de dar el alta de un auto
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Patente a cargar
 * \param Color a cargar
 * \param Marca a cargar
 * \param Modelo a cargar
 * \param ID del auto a cargar
 * \param ID del cliente a cargar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo dar el de los autos
 *
 */
int altaAutos(eAuto autos[],int tam_auto,char patente[],int color,int marca,int modelo,int idAuto,int idCliente);

/** \brief Se encarga de dar de baja un auto
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo eliminar el auto
 *
 */
int eliminarAuto(eAuto autos[], int tam_auto);

/** \brief Se encarga de modificar un auto
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo modificar el auto
 *
 */
int modificarAuto(eAuto autos[],int tam_auto,eColor color[],int tam_color);

/** \brief Se encarga de listar las patentes cargadas en el sistema
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 *
 */
void imprimirPatentes(eAuto autos[],int tam_auto);

/** \brief Se encarga de buscar una patente en el sistema
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Patente a cargar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo encontrar la patente
 *
 */
int buscarPatente(eAuto autos[], int tam_auto, char patente[]);

/** \brief Se encarga de buscar un color
 *
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param Auxiliar tipo cadena donde se almacenara el color encontrado
 * \param ID del color a buscar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo encontrar el color
 *
 */
int buscarColor(eColor color[], int tam_color, char auxColor[],int id);

/** \brief
 *
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Auxiliar tipo cadena donde se almacenara el marca encontrado
 * \param ID del marca a buscar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo encontrar la marca
 *
 */
int buscarMarca(eMarca marca[], int tam_marca, char auxMarca[],int id);

/** \brief Buscar una posicion libre
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \return Devuelve el indice, donde:
 * Indice o posicion disponible
 * -1 = No hay posiciones disponibles
 *
 */
int buscarLibre(eAuto autos[], int tam_auto);

/** \brief Imprime autos por color
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar los colores
 *
 */
int autosPorColor(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);

/** \brief Imprime autos por marca
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar las marcas
 *
 */
int autosPorMarca(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);

/** \brief Muestra autos por color o por marca
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param ID del color o de la marca
 *  0 = Todo Ok
 * -1 = No pudo mostrar el auto
 *
 */
int mostrarAuto(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color,int id);

/** \brief Se encarga de mostrar el o los autos mas viejos
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param ID del color o de la marca
 *
 */
void autosViejos(eAuto autos[],int tam_auto,eMarca marca[],int tam_marca,eColor color[],int tam_color);

/** \brief Separa los autos por marca
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \param ID del color o de la marca
 *
 */
void separarPorMarca(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[],int tam_color);

/** \brief Se encarga de contar marca y colores pedidos al usuarios
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 *
 */
void contar_MarcaColor(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[], int tam_color);

/** \brief Se encarga de mostrar las o la marca mas elegida
 *
 * \param Array de estructuras auto
 * \param Tamaño del array auto
 * \param Array de estructuras marca
 * \param Tamaño del array marca
 * \param Array de estructuras color
 * \param Tamaño del array color
 *
 */
void marcasMasElegidas(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[], int tam_color);

#endif /* AUTO_H_INCLUDED */
