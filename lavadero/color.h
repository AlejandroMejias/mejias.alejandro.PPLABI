#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[21];


}eColor;

/** \brief Inicializa colores por defecto
 *
 * \param Array de estructuras color
 * \param Tamaño del array color
 *
 */
void coloresPorDefecto(eColor color[], int tam_color);

/** \brief Se encarga de mostrar los colores
 *
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar los colores
 */
int mostrarColores(eColor color[], int tam_color);

#endif /* COLOR_H_INCLUDED */
