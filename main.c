#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
#include "string.h"
int main()
{
    char Nombre[] = "archivo.bin";
    int opc;
    do
    {
        printf("1. Dar de alta a un nuevo Astronauta \n");
        printf("2. Ver los astronautas \n");
        printf("3. Mostrar la informacion de un astronauta en especial \n");
        printf("4. Dar de baja a un Astronauta \n");
        printf("5. Menu de modificaciones \n");
        printf("0. Salir... \n");
        printf("Ingrese la opcion que quiera: ");
        scanf("%i",&opc);

        switch(opc)
        {
        case 1 :
            system("cls");
            altaDeAstronauta(Nombre);
            system("cls");
            break;
        case 2 :
            system("cls");
            listaDeAtronautas(Nombre);
            break;
        case 3 :
            system("cls");
            mostrarUnAstronauta(Nombre);
            break;
        case 4 :
            system("cls");
            bajaDeAstronauta(Nombre);
            break;
        case 5 :
            system("cls");
            modificaciones(Nombre);
            break;
        case 0 :
            system("cls");
            printf("\n El archivo se cerro correctamente... \n");
            break;
        default :
            system("cls");
            printf("Opcion Incorrecta, Ingrese la opcion nuevamente: ");
            scanf("%i",&opc);
            break;
        }
    }while(opc != 0);

    return 0;
}
