#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
#include "string.h"

//FUNCION PARA EL ALTA DE UN NUEVO ASTRONAUTA
void altaDeAstronauta(char Nombre[])
{
    char control = 's';
    StAstronauta a;
    FILE * archi = fopen(Nombre, "ab");
    if(archi != NULL)
        {
        while(control == 's')
            {
                a = nuevoAstronauta(Nombre);
                fwrite(&a, sizeof(StAstronauta), 1, archi);

                printf("Si desea continuar presione S, de lo contrario N: ");
                fflush(stdin);
                scanf("%c",&control);
                system("cls");
            }
        fclose(archi);
        }else
        {
            printf("El archivo no abrio correctamente");
        }
}
//FUNCION COMPLEMENTARIA A LA F. DEL ALTA
StAstronauta nuevoAstronauta(char Nombre[])
{
    StAstronauta nuevo;
    int aux;
    int flag = 0;

    printf("Ingrese su numero de ID: ");
    scanf("%i",&aux);
    flag = verificID(Nombre, aux);

    if(flag == 1)
        {
            printf("Ese ID ya se encuentra en uso. Ingrese otro: ");
            scanf("%i",&nuevo.ID);
        }else
        {
            nuevo.ID = aux;
        }

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
    nuevo = verificEDAD(nuevo);

    printf("Ingrese su Nacionalidad: ");
    fflush(stdin);
    gets(&nuevo.Nacionalidad);

    nuevo = especialidad(nuevo); //SE LE HIZO UNA FUNCION ESPECIAL PARA UNA MEJOR LEGIBILIDAD

    printf("Ingrese su cantidad de horas de vuelo acumuladas: ");
    scanf("%i",&nuevo.Experiencia);

    printf("Ingrese sus misiones realizadas: ");
    scanf("%i",&nuevo.misionesR);

    printf("Ingrese sus horas acumuladas: ");
    scanf("%i",&nuevo.HorasA);

    nuevo.Estado = 1 ;

    return nuevo;
}
//FUNCION COMPLEMENTARIA A LA F. NUEVOASTRAONAUTA
 StAstronauta especialidad(StAstronauta nuevo)
{
    int opc;
    printf("1. Piloto \n");
    printf("2. Astrofisico \n");
    printf("3. Ingeniero especial \n");
    printf("4. Biologo \n");
    printf("5. Otra \n");
    printf("Ingrese su especialidad: ");
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
        printf("Ingrese el nombre de su especialidad: ");
        fflush(stdin);
        scanf("%s",&nuevo.Especialidad);
        break;
    default :
        printf("Error");
    }
    return nuevo;
}

//FUNCION PARA MOSTRAR A TODOS LOS ASTRONAUTAS
void listaDeAtronautas(char Nombre[])
{
    StAstronauta a;
    int cant = 0;
    FILE * archi = fopen(Nombre, "rb");
    if(archi != NULL)
        {
            printf("---------------------------------------- \n");
            while(fread(&a, sizeof(StAstronauta), 1, archi) > 0)
                {
                    mostrarAstronauta(a);
                }
            fclose(archi);
        }else
        {
            printf("Error!");
        }
}

//FUNCION PARA MOSTRAR UN ASTRONAUTA DE MANERA COMPLETA
void mostrarAstronauta(StAstronauta a)
{
    printf("..............ID del Astronauta es: %i \n", a.ID);
    printf("..........Nombre del Astronauta es: %s \n", a.Nombre);
    printf("........Apellido del Atronauta  es: %s \n", a.Apellido);
    printf("...........Apodo del Astronauta es: %s \n", a.Apodo);
    printf(".........La edad del Astronauta es: %i \n", a.Edad);
    printf(".La nacionalidad del Astronauta es: %s \n", a.Nacionalidad);
    printf(".La especialidad del Astronauta es: %s \n", a.Especialidad);
    printf(".Las horas de vuelo acumuladas son: %i \n", a.Experiencia);
    printf(".......Las misiones realizadas son: %i \n", a.misionesR);
    printf("Las horas acumuladas en la EEI son: %i \n", a.HorasA);
    if(a.Estado == 1)
        {
            printf(".......El estado del Astronauta es: ACTIVO \n");
        }else
        {
            printf(".......El estado del Astronauta es: RETIRADO \n");
        }
    printf("---------------------------------------- \n");
}

//FUNCION PARA MOSTRAR EL ASTRONAUTA QUE EL CLIENTE QUIERA
void mostrarUnAstronauta(char Nombre[])
{

    StAstronauta a;
    listaDeAstronautas2(Nombre);
    int opc;
    printf("Ingrese el ID del Astronauta que desea ver: ");
    scanf("%d",&opc);
    system("cls");

    FILE * archi = fopen(Nombre, "rb" );
    if(archi != NULL)
        {
            while(fread(&a, sizeof(StAstronauta), 1, archi) > 0)
                {
                    if(opc == a.ID)
                        {
                            printf("---------------------------------------- \n");
                            mostrarAstronauta(a);
                        }
                }
            fclose(archi);
        }else
        {
            printf("Error!!");
        }
}

//FUNCION PARA MOSTRAR LOS ASTRONAUTAS (NOMBRE E ID)
void listaDeAstronautas2 (char Nombre[])
{
    StAstronauta a;
    FILE * archi = fopen(Nombre, "rb");
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

//FUNCION PARA DAR DE BAJA A UN ASTRONAUTA
void bajaDeAstronauta(char Nombre[])
{
    StAstronauta a;
    listaDeAstronautas2(Nombre);

    int flag = 0;
    int opc;
    printf("Ingrese el ID del astronauta que quiere dar de baja: ");
    scanf("%i",&opc);

    FILE * archi = fopen(Nombre, "r+b");
    if(archi != NULL)
        {
            while(flag == 0 && fread(&a, sizeof(StAstronauta), 1, archi) > 0 )
                {
                    if(opc == a.ID)
                        {
                            a.Estado = 0;
                            fseek(archi, (-1)*sizeof(StAstronauta), SEEK_CUR);
                            fwrite(&a, sizeof(StAstronauta), 1, archi);

                            flag = 1;
                        }
                }

            fclose(archi);
        }else
                {
                    printf("ERROR!!");
                }
}

//FUNCION MENU DE MODIFICACIONES
void modificaciones(char Nombre[])
{
    int opc ;
    do{
        printf("1. Modificar horas horas de vuelo acumuladas \n");
        printf("2. Modificar misiones especiales realizadas \n");
        printf("3. Modificar Horas acumuladas en la estacion espacial \n");
        printf("0. Salir \n");
        printf("\n Ingrese la opcion que desea modificar: ");
        scanf("%i",&opc);


        switch(opc)
        {
        case 1 :
            system("cls");
            modificarHVA(Nombre);
            break;
        case 2 :
            system("cls");
            modificarMER(Nombre);
            break;
        case 3 :
            system("cls");
            modificarHEEI(Nombre);
            break;
        case 0 :
            system("cls");
            printf("\n El archivo se cerro correctamente... \n");
        default :
            printf("Opcion Incorrecta!, Ingrese nuevamente la opcion: ");
            scanf("%i",&opc);
            break;
        }
    }while(opc == 0);
}

//FUNCION PARA BUSCAR UN ARCHIVO ESPECIFICO
int buscarArchivoEspecifico(char Nombre[])
{
    StAstronauta a;
    int opc, pos, cont = 0;

    listaDeAstronautas2(Nombre);

    printf("Ingrese el ID del astronauta que desea buscar: ");
    scanf("%i",&opc);

    FILE * archi = fopen(Nombre, "rb" );
    if(archi != NULL)
        {
            while(fread(&a, sizeof(StAstronauta), 1, archi))
                {
                    if(opc == a.ID)
                        {
                            pos = cont;
                        }
                    cont++;
                }
            fclose(archi);
        }else
        {
            printf("Error! \n");
        }
    return pos;
}

//MODIFICAR HORAS DE VUELO ACUMULADAS
void modificarHVA(char Nombre[])
{
    StAstronauta a;
    int pos, aux;
    pos = buscarArchivoEspecifico(Nombre);

    FILE * archi = fopen(Nombre, "r+b");
    if(archi != NULL)
        {
            printf("Ingrese la nueva cantidad de horas de vuelo acumuladas: ");
            scanf("%i",&aux);

            fseek(archi, (pos - 1) * sizeof(StAstronauta), SEEK_SET);
            fread(&a, sizeof(StAstronauta), 1, archi);

            a.Experiencia = aux;
            fseek(archi, (-1) * sizeof(StAstronauta), SEEK_CUR);
            fwrite(&a, sizeof(StAstronauta), 1, archi);
            fseek(archi, 0, SEEK_END);

            fclose(archi);

        }else
        {
            printf("Error! \n");
        }

}

//MODIFICAR MISIONES REALIZADAS
void modificarMER(char Nombre[])
{
    StAstronauta a;
    int pos, aux;
    pos = buscarArchivoEspecifico(Nombre);

    FILE * archi = fopen(Nombre, "r+b");
    if(archi != NULL)
        {
            printf("Ingrese la nueva cantidad de misiones realizadas: ");
            scanf("%i",&aux);

            fseek(archi, (pos - 1) * sizeof(StAstronauta), SEEK_SET);
            fread(&a, sizeof(StAstronauta), 1, archi);

            a.misionesR = aux;
            fseek(archi, (-1) * sizeof(StAstronauta), SEEK_CUR);
            fwrite(&a, sizeof(StAstronauta), 1, archi);
            fseek(archi, 0, SEEK_END);

            fclose(archi);

        }else
        {
            printf("Error! \n");
        }

}

//MODIFICAR LA CANTIDAD DE HORAS EN LA EEI
void modificarHEEI(char Nombre[])
{
    StAstronauta a;
    int pos, aux;
    pos = buscarArchivoEspecifico(Nombre);

    FILE * archi = fopen(Nombre, "r+b");
    if(archi != NULL)
        {
            printf("Ingrese la nueva cantidad de horas de vuelo acumuladas en EEI: ");
            scanf("%i",&aux);

            fseek(archi, (pos - 1) * sizeof(StAstronauta), SEEK_SET);
            fread(&a, sizeof(StAstronauta), 1, archi);

            a.HorasA = aux;
            fseek(archi, (-1) * sizeof(StAstronauta), SEEK_CUR);
            fwrite(&a, sizeof(StAstronauta), 1, archi);
            fseek(archi, 0, SEEK_END);

            fclose(archi);

        }else
        {
            printf("Error! \n");
        }

}
