#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mision.h"


void cargarMision(char archivo[])
{
    char op;
    stMision huston;
    printf("Desea cargar una mision?");
    fflush(stdin);
    scanf("%c",&op);

    while(op=='s')
    {
        printf("Ingrese el ID de la mision: ");
        scanf("%i",&huston.id);

        printf("\nIngrese el ID de la nave: ");
        scanf("%i",&huston.idNave);

        printf("\nIngrese el estado de la mision: ");
        printf("\n 1 Listo");
        printf("\n 2 En vuelo");
        printf("\n 3 Retornada");
        printf("\n 4 Cancelada");
        printf("\n 5 Fallida\n");

        scanf("%i",&huston.estado);

        printf("\n Ingrese el destino de la mision:\n");
        fflush(stdin);
        gets(huston.destino);

        printf("\n Ingrese el cargamento de la mision:\n");
        fflush(stdin);
        gets(huston.cargamento);

//        printf("\n Ingrese los tripulantes de la mision:\n");
//        while (decision='s')
//        {
//          scanf("%i",&huston.tripulantes[i]);
//        }


        printf("\n Ingrese un breve detalle de la mision\n");
        fflush(stdin);
        gets(huston.detalle);

        printf("desea cargar otro mas? ");
        fflush(stdin);
        scanf("%c",&op);

        system("cls");

         cargarMisiones(archivo,huston);
    }


}

void cargarMisiones(char archivo[],stMision cargando)
{
    FILE *archi;
    archi=fopen(archivo,"ab");

    char op='s';

    if (archi!=NULL)
    {

        fwrite(&cargando,sizeof (stMision),1,archi);
    }
    fclose(archi);
}
void leerArchivo (char archivo[])
{
    stMision aux;

    FILE *archi;

    archi=fopen(archivo,"rb");

    if (archi != NULL)
    {

        printf("el contenido del archivo es: \n\n");
        while (fread(&aux,sizeof(stMision),1,archi)>0)
        {
            printf("----------------------------------\n");
            printf("MISION ID: %i \n",aux.id);
            printf("ID NAVE  : %i \n",aux.idNave);
            switch (aux.estado)
            {
                case 1:
                    printf("ESTADO MISION: Listo\n" );
                    break;
                case 2:
                    printf("ESTADO MISION: En vuelo\n" );
                    break;
                case 3:
                    printf("ESTADO MISION: Retornada\n" );
                    break;
                case 4:
                    printf("ESTADO MISION: Cancelada\n" );
                    break;
                case 5:
                    printf("ESTADO MISION: Fallida\n" );
                    break;
            }
            printf("DESTINO:      %s \n",aux.destino);
            printf("CARGAMENTO:   %s \n",aux.cargamento);
//            printf("Tripulantes:        %i \n",aux.tripulantes);
            printf("Detalle:      %s\n",aux.detalle);
            printf("----------------------------------\n");
        }
    }
    fclose(archi);
}

void bajaMision (char archivo[])
{
    stMision a;
    int idBaja=0;
    FILE * archi;
    archi=fopen(archivo,"rb");

    leerArchivo(archivo);

    printf("ingrese el id de la mision a dar de baja: ");
    scanf("%i",&idBaja);

    while(fread(&a,sizeof (stMision),1,archi)>0)
    {
        if (idBaja== a.id)
        {
             a.estado=4;
            fwrite(&a,sizeof (stMision),1,archi);
            fclose(archivo);
        }

        }
        if(idBaja != a.id)
            printf("error!");
    }

