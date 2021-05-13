#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"



int main(void)
{
	setbuf(stdout,NULL);
	eTrabajo miTrabajo[20];
	eServicio listaServicio[S]= {{1,"Limpieza",250},{2,"Parche",300},{3,"Centrado",400},{4,"Cadena",350}};
	//*void HardcodeoServicio(eServicio listaServicio[]);
	int idAux;
	char marcaAux[90];
	int rodadoAux;
	int idServicioAux;
	int indexAux;
	char continuar='s';
	int flagAlta=0;

	InicializarTrabajos (miTrabajo,20);

	do
		{
			switch(Menu())
			{
			case 1:

				if ( PedirDatos(miTrabajo,20,&idAux,marcaAux,&rodadoAux, &idServicioAux, &indexAux, listaServicio)==0 && LeerDatos (miTrabajo,20,idAux,marcaAux,rodadoAux,idServicioAux,indexAux) == 0)
					{
						printf("El alta fue realizada \n");
						flagAlta=1;


					}
					else
					{
						printf("Error. El alta no pudo ser realizada \n");
					}
					break;
			case 2:
				if (flagAlta!=1)
				{
					printf("Error, primero debe realizar un Alta \n");
				}
				else
				{
					ModificarTrabajo(miTrabajo,20,listaServicio,4);
				}
				break;
			case 3:
				break;

			case 4:

				break;
			case 5:
					printf("Esta seguro que desea salir?: s/n \n");
					fflush(stdin);
					scanf("%c", &continuar);
					break;

			}
		}while(stricmp(continuar,"s"));





	return EXIT_SUCCESS;
}
