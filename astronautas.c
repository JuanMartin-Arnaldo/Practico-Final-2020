#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
#include "string.h"
void altaDeAstronauta(char Nombre[])
{
    char control = 's';
    StAstronauta a;
    FILE * archi = fopen(Nombre, "wb");
    if(archi != NULL)
        {
        while(control == 's')
            {
                a = nuevoAstronauta();
                fwrite(&a, sizeof(StAstronauta), 1, archi);

                printf("Si desea continuar presione S, de lo contrario N: ");
                fflush(stdin);
                scanf("%c",&control);
            }
        fclose(archi);
        }else
        {
            printf("El archivo no abrio correctamente");
        }
}

StAstronauta nuevoAstronauta()
{
    StAstronauta nuevo;

    printf("Ingrese su numero de ID: ");
    scanf("%i",&nuevo.ID);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(&nuevo.Nombre);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(&nuevo.Apellido);

    printf("Ingrese su apodo: ");
    fflush(stdin);
    gets(&nuevo.Apodo);

    printf("Ingrese su edad: ");
    scanf("%i",&nuevo.Edad);

    printf("Ingrese su Nacionalidad: ");
    fflush(stdin);
    gets(&nuevo.Nacionalidad);

    nuevo = especialidad(nuevo);

    printf("Ingrese su cantidad de horas de vuelo acumuladas: ");
    scanf("%i",&nuevo.Experiencia);

    printf("Ingrese sus misiones realizadas: ");
    scanf("%i",&nuevo.misionesR);

    printf("Ingrese sus horas acumuladas: ");
    scanf("%i",&nuevo.HorasA);

    nuevo.Estado = 1 ;

    return nuevo;
}

StAstronauta especialidad(StAstronauta nuevo)
{
    //piloto, astrofísico, ingeniero espacial, biólogo, etc
    int opc;
    printf("\n");
    printf("1. Piloto \n");
    printf("2. Astrofisico \n");
    printf("3. Ingeniero especial \n");
    printf("4. Biologo \n");
    printf("5. Otra \n");
    printf("Ingrese su especialidad: \n");
    scanf("%i",&opc);

    switch(opc)
    {
    case 1 :
        strcpy(nuevo.Especialidad, "Piloto");
        break;
    case 2 :
        strcpy(nuevo.Especialidad, "Astrofisico");
        break;
    case 3 :
        strcpy(nuevo.Especialidad, "Ingeniero especial");
        break;
    case 4 :
        strcpy(nuevo.Especialidad, "Biologo");
        break;
    case 5 :
        printf("Ingrese su especialidad: ");
        fflush(stdin);
        scanf("%s",&nuevo.Especialidad);
    default :
        printf("Error");
    }
    return nuevo;
}

void listaDeAtronautas(char Nombre[])
{
    StAstronauta a;
    int cant = 0;
    FILE * archi = fopen(Nombre, "rb");
    if(archi != NULL)
        {
            printf("------------------------------- \n");
            while(fread(&a, sizeof(StAstronauta), 1, archi) > 0)
                {
                    mostrarAstronauta(a);
                }
            cant = fclose(archi);
        }else
        {
            printf("Error!");
        }
    printf("\n El archivo cerro con: %d datos \n",cant);
}

void mostrarAstronauta(StAstronauta a)
{
    printf("ID del Astronauta: %i \n", a.ID);
    printf("Nombre del Astronauta: %s \n", a.Nombre);
    printf("Apellido del Atronauta: %s \n", a.Apellido);
    printf("Apodo del Astronauta: %s \n", a.Apodo);
    printf("La edad del Astronauta: %i \n", a.Edad);
    printf("La nacionalidad del Astronauta: %s \n", a.Nacionalidad);
    printf("La especialidad del Astronauta es: %s \n", a.Especialidad);
    printf("Las horas de vuelo acumuladas del Astronauta son: %i \n", a.Experiencia);
    printf("Las misiones especiales realizadas por el Astronauta son: %i \n", a.misionesR);
    printf("Las horas acumuladas en la Estacion Espacial Internacional del Astronauta son: %i \n", a.HorasA);
    if(a.Estado == 1)
        {
            printf("El estado del Astronauta es ACTIVO \n");
        }else
        {
            printf("El estado del Astronauta es RETIRADO \n");
        }
    printf("------------------------------- \n");
}

void mostrarUnAstronauta(char Nombre[])
{

    StAstronauta a;
    listaDeAtronautas2(a);

    int opc;
    printf("Ingrese el ID del Astronauta que desea ver: ");
    scanf("%d",&opc);
    system("cls");

    fopen(Nombre, "rb" );
    if(archi != NULL)
        {
            while(fread(&a, sizeof(StAstronauta), 1, archi) > 0)
                {
                    if(opc == a.ID)
                        {
                            mostrarAstronauta(a);
                        }
                }
            fclose(archi);
        }else
        {
            printf("Error!!");
        }
}

//Esta segunda lista solo te muestra el nombre y el ID de los astronautas
void listaDeAtronautas2 (char Nombre[]);
{
    StAstronauta a;
    FILE *archi = fopen(Nombre, "rb");
    if(archi != NULL)
        {
            printf("---- Lista de Astronautas ----\n");
            while(fread(&a, sizeof(StAstronauta), 1, archi) > 0)
                {
                    printf("Nombre: %s , ID: %d \n",a.Nombre, a.ID);
                }
            fclose(archi);
        }
}

void bajaDeAstronauta(char nombre[])
{

}

