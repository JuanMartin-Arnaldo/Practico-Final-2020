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

//CARGA DE ASTRONAUTA
void altaDeAstronauta(char Nombre[]);
StAstronauta nuevoAstronauta();
StAstronauta especialidad(StAstronauta nuevo);

//LISTA DE ASTRONAUTAS
void listaDeAstronautas(char Nombre[]);
void mostrarAstronauta(StAstronauta a);
void listaDeAstronautas2 (char Nombre[]);

//BUSQUEDA
int buscarArchivoEspecifico(char Nombre[]);

//LISTA SIMPLIFICADA DE ASTRONAUTAS
void mostrarUnAstronauta(char Nombre[]);

//MODIFICACIONES
void bajaDeAstronauta(char nombre[]);
void modificaciones(char Nombre[]);
void modificarHVA(char Nombre[]);
void modificarMER(char Nombre[]);

//VERIFICACIONES
StAstronauta verificEDAD(StAstronauta a);

#endif // ASTRONAUTAS_H_INCLUDED
