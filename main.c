#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
int main()
{
    char Nombre[] = "archivo.bin";
    int opc;


    do
    {
        printf("1. Dar de alta a un nuevo Astronauta \n");
        printf("2. Ver los astronautas \n");
        printf("3. Mostrar la informacion de un astronauta en especial \n");
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
            system("cls");
            break;
        }
    }while(opc != 0);

    return 0;
}
