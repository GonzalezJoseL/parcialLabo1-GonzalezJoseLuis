#include "Servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


void HardcodeoServicio(eServicio listaServicio[])
{
    int auxId[S]={1,2,3,4};
    char auxDescripcion[S][25]={"Limpieza","Parche","Centrado","Cadena"};
    float auxPrecio[S]={250,300,400,350};

    int i;

    for (i=0;i<S;i++)
    {
        	listaServicio[i].id=auxId[i];
            strcpy(listaServicio[i].descripcion,auxDescripcion[i]);
            listaServicio[i].precio=auxPrecio[i];
   }

}

int MostrarListaServicios(eServicio servicios[], int tam)
{
    int retorno=-1;
    int i;

    if(servicios!=NULL && tam>0)
    {
        printf("\t> LISTA DE SERVICIOS: \n");
        for(i=0;i<tam;i++)
        {
            MostrarServicio(servicios[i]);
            retorno=0;
        }
    }

    return retorno;
}

void MostrarServicio (eServicio servicio)
{



    printf( "ID del servicio: %d\n"
            "Descripcion: %s\n"
            "Precio: %.2f\n", servicio.id
                            , servicio.descripcion
                            , servicio.precio);


 }

int servicioPorId(int id, eServicio servicios[], int tam,char nombreDelservicio[])
{
	int retorno=-1;
	int i;

	for (i=0;i<tam;i++)
	{
		if ( servicios[i].id == id)
		{
			strcpy(nombreDelservicio,servicios[i].descripcion);
			retorno=0;
		}
	}

	return retorno;
}
