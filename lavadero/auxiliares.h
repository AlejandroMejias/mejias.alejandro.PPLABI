#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

/** \brief Se encarga de mostrar el menu de opciones
 *
 * \return Caracter introducido por el usuario
 *
 */

char menu();

/** \brief Se encarga de validar un caracter
 *
 * \param Caracter a validar
 * \return Caracter validado
 *
 */
char validarCaracter(char caracter);

/** \brief Se encarga de convertir a mayusculas una cadena
 *
 * \param Cadena a transformar
 *
 */
void toMayuscula(char cadena []);

/** \brief Se encarga de capturar y validar una cadena
 *
 * \param Cadena a capturar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar la cadena
 */
int capturarCadena(char cadena[]);

/** \brief Se encarga de capturar y validar un color
 *
 * \param Direccion de memoria donde se almacenara el color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar el color
 */
int capturarColor(int* color);

/** \brief Se encarga de capturar y validar una marca
 *
 * \param Direccion de memoria donde se almacenara la marca
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar la marca
 */
int capturarMarca(int* marca);

/** \brief Se encarga de capturar y validar un modelo
 *
 * \param Direccion de memoria donde se almacenara el modelo
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar el modelo
 */
int capturarModelo(int* modelo);

/** \brief Se encarga de capturar y validar un servicvio
 *
 * \param Direccion de memoria donde se almacenara el servicio
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar el servicio
 */
int capturarServicio(int* servicio);

/** \brief Se encarga de capturar y validar un cliente
 *
 * \param Direccion de memoria donde se almacenara el cliente
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar el cliente
 */
int capturarCliente(int* cliente);
/** \brief Se encarga de mostrar el menu de informes con sus opciones
 *
 * \return Caracter introducido por el usuario
 *
 */
char menuInformes();

#endif /* AUXILIARES_H_INCLUDED */
