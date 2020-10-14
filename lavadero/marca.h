#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int idMarca;
    char descripcion[21];
}eMarca;

void marcasPorDefecto(eMarca marca[], int tam_marca);
int mostrarMarca(eMarca marca[],int tam_marca);

#endif /* MARCA_H_INCLUDED */
