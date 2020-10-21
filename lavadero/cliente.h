#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[21];
    char sexo;
}eCliente;
/** \brief Inicializa clientes por defecto
 *
 * \param   Array de estructuras cliente
 * \param   Tamaño del array
 *
 */
void clientesPorDefecto(eCliente clientes[],int tam_cliente);

/** \brief Se encarga de mostrar los clientes
 *
 * \param Array de estructuras color
 * \param Tamaño del array color
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo mostrar los clientes
 */
int mostrarCliente(eCliente clientes[],int tam_cliente);

/** \brief Se encarga de capturar y validar un ID cliente
 *
 * \param Direccion de memoria donde se almacenara el cliente
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo capturar el cliente
 */
int capturarCliente(int* cliente);

/** \brief Se encarga de buscar un cliente
 *
 * \param Array de estructuras cliente
 * \param Tamaño del array cliente
 * \param Auxiliar tipo cadena donde se almacenara el cliente encontrado
 * \param ID del cliente a buscar
 * \return Devuelve dos valores posibles
 *  0 = Todo Ok
 * -1 = No pudo encontrar el cliente
 *
 */
int buscarCliente(eCliente clientes[],int tam_cliente, char auxCliente[],int id);

#endif /* CLIENTE_H_INCLUDED */
