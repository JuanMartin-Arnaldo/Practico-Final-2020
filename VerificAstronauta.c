#include <stdio.h>
#include <stdlib.h>
#include "astronautas.h"
#include "string.h"

//TODAS LAS VERIFICACIONES...

StAstronauta verificEDAD(StAstronauta a)
{
    if(a.Edad < 18)
        {

            printf("La edad no es suficiente para ser un astronauta, Ingrese una edad correspondiente(+18): ");
            scanf("%i",&a.Edad);

        }
    return a;
}

/* StAstronauta verificID(StAstronauta a)
{
    FILE * archi = fopen(Nombre, "rb" );
    if(a.ID )
} */
