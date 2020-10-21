#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
}eMarca;
/** \brief Inicializa marcas por defecto
 *
 * \param Array de estructuras marcas
 * \param Tamaño del array marcas
 *
 */
void marcasPorDefecto(eMarca marca[], int tam_marca);

/** \brief Se encarga de mostrar los marcas
 *
 * \param Array de estructuras marcas
 * \param Tamaño del array marcas
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar las marcas
 */
int mostrarMarca(eMarca marca[],int tam_marca);

#endif /* MARCA_H_INCLUDED */
