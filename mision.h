#ifndef MISION_H_INCLUDED
#define MISION_H_INCLUDED
typedef struct
{
    int id;
    int idNave;
    int estado;
    char destino[30];
    char cargamento[30];
    int tripulantes[10];
    char detalle[100];
}stMision;

void cargarMision(char archivo[]);
void cargarMisiones(char archivo[],stMision cargando);
void leerArchivo (char archivo[]);
void bajaMision (char archivo[]);




#endif // MISION_H_INCLUDED
