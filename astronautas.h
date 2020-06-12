#ifndef ASTRONAUTAS_H_INCLUDED
#define ASTRONAUTAS_H_INCLUDED
typedef struct {
    int ID;
    char Nombre[20];
    char Apellido[20];
    char Apodo[20];
    int Edad;
    char Nacionalidad[20];
    char Especialidad[20];
    int Experiencia;
    int misionesR;
    int HorasA;
    int Estado;
} StAstronauta;

void altaDeAstronauta(char Nombre[]);
StAstronauta nuevoAstronauta();
StAstronauta especialidad(StAstronauta nuevo);
void listaDeAtronautas(char Nombre[]);
void mostrarAstronauta(StAstronauta a);
void mostrarUnAstronauta(char Nombre[]);
void listaDeAtronautas2 (StAstronauta a);

#endif // ASTRONAUTAS_H_INCLUDED
