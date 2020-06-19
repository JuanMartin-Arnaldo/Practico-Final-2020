#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
#include "string.h"

//TODAS LAS VERIFICACIONES...


StAstronauta verificEDAD(StAstronauta a)
{
    if(a.Edad < 18)
        {
            do{

                printf("La edad no es suficiente para ser un astronauta, Ingrese una edad correspondiente(+18): ");
                scanf("%i",&a.Edad);

            }while(a.Edad < 18);
        }
    return a;
}

int verificID(char Nombre[], int aux)
{
    int flag = 0;

    StAstronauta a;
    FILE * archi = fopen(Nombre, "rb" );

    if(archi != NULL)
        {
            while(fread(&a, sizeof(StAstronauta), 1, archi))
                {
                    if(aux == a.ID)
                    {
                        flag = 1;
                    }
                }
            }else
            {
                printf("Error! \n");
            }
    return flag;
}
