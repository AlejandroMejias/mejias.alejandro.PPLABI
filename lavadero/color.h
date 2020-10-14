#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int idColor;
    char nombre[21];


}eColor;
void coloresPorDefecto(eColor color[], int tam_color);
int mostrarColores(eColor color[], int tam_color);
#endif /* COLOR_H_INCLUDED */
