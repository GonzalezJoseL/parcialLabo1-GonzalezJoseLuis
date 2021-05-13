#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Trabajo.h"
#include "Servicio.h"
#include "utn.h"

int idAutoincremental=19999;

int Asignarid()

{
	return idAutoincremental+=1;
}

int Menu ()
{
	int opcion;



	printf("------------MENU------------ \n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. SALIR\n");

	printf("Por favor ingresar una opcion\n");
	scanf("%d",&opcion);

	return opcion;
}

int InicializarTrabajos (eTrabajo lista[],int tam)
{
	int i;
	int error=-1;

	if (lista != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			lista[i].isEmpty=VACIO;
		}
		error=0;
	}


	return error;
}
int BuscarLibre (eTrabajo lista[],int tam)
{

	int i;
	int index=-1;

		if (lista != NULL && tam > 0)

		{
			for (i=0;i<tam;i++)
			{
				if(lista[i].isEmpty==VACIO)
				{
					index=i;
					break;
				}
			}

		}


		return index;

}

int BuscarTrabajoPorID(eTrabajo lista[], int tam,int id)
{
	int indice=-1;
	int i;
	if (lista != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			if (lista[i].id==id)
			{
				indice=i;
				break;
			}
		}

	}
	return indice;
}

int PedirDatos (eTrabajo lista[], int tam, int* id, char marcaBici[], int* rodadoBici, int* idServicio,int* index, eServicio listaS[])

{

	int retorno=-1;

	if (lista != NULL && tam >0 && marcaBici != NULL && idServicio != NULL && rodadoBici != NULL && idServicio != NULL  )

		{

			*index=BuscarLibre(lista,tam);

				{
					if (*index==-1)
					{
						printf("No se encontro un lugar vacio. La lista de trabajos esta llena \n");
					}
					else
					{
						*id=Asignarid();

						fflush(stdin);
						utn_getNombre(marcaBici,"Por favor ingresar una marca de bici \n",40);

						utn_getInt(rodadoBici,"Por favor ingresar un rodado de bici \n",999);
						MostrarListaServicios(listaS,S);
						utn_getInt(idServicio,"Por favor ingresar un ID de Servicio \n",999);



						retorno=0;

					}
				}

		}

	return retorno;
}

int LeerDatos (eTrabajo lista[], int tam, int id, char marcaBici[],int rodadoBici, int idServicio, int index)

{
	int error=-1;

	if (lista != NULL && tam >0 && marcaBici != NULL )

	{



		lista[index].id=id;
		strcpy(lista[index].marcaBicicleta,marcaBici);
		lista[index].rodadoBicicleta=rodadoBici;
		lista[index].idServicio=idServicio;
		lista[index].isEmpty=OCUPADO;

		error=0;


	}
	return error;
}

void MostrarTrabajo (eTrabajo Lista, eServicio listaS[], int tamS)
{
	char nombre[90];

	servicioPorId(Lista.id,listaS,tamS,nombre);


	printf("ID: %d		MARCA: %s		RODADO: %d		SERVICIO: %s\n",Lista.id,Lista.marcaBicicleta,Lista.rodadoBicicleta,nombre);

}

int MostrarTrabajos (eTrabajo Lista[],int tam, eServicio listaS[], int tamS)
{
	int i;
	int retorno=0;
	for (i=0;i<tam;i++)
	{
		if (Lista[i].isEmpty==OCUPADO)
		{
				MostrarTrabajo(Lista[i],listaS,tamS);
		}
	}
	return retorno;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS)
{
	int retorno=-1;
	int id;
	int indiceEmpleado;
	int opcion;
	char salida;
	if (lista != NULL && tam >0)
	{
		MostrarTrabajos(lista,tam,listaS,tamS);
		utn_getInt(&id,"Por favor ingresar el ID del usuario a modificar",30000);
		indiceEmpleado=BuscarTrabajoPorID(lista,tam,id);

		if (indiceEmpleado==-1)
		{
			printf("El id no le corresponde a ningun empleado \n");
		}
		else
		{

			MostrarTrabajo(lista[indiceEmpleado],listaS,tamS);
			do
			{



				switch(MenuModificaciones())
				{

				case 1:
					printf("La marca es %s",lista[indiceEmpleado].marcaBicicleta);
					//utn_getNombre(&lista[indiceEmpleado].marcaBicicleta,"Por favor ingresar nuevo MARCA", 30);
					printf("Por favor ingresar nueva MARCA");
					scanf("%s",lista[indiceEmpleado].marcaBicicleta);
					break;
				case 2:
					printf("El SERVICIO es %d",lista[indiceEmpleado].idServicio);
					utn_getInt(&lista[indiceEmpleado].idServicio,"Por favor ingresar nuevo nombre", 30);
					break;
				case 3:
					printf("Esta seguro que desea salir? presione S para salir\n");
					scanf("%c",&salida);
					break;

				default:
					printf("Por favor ingresar una opcion valida");
					break;
				}
			}while(salida!='s');
			retorno=0;
		}
	}
	return retorno;
}

int MenuModificaciones ()
{
	int opcion;

	system("clear");

	printf("Que desea modificar?");
	printf("1. Marca\n");
	printf("2. Servicio\n");
	printf("3. SALIR\n");


	scanf("%d",&opcion);

	return opcion;
}

/*
int BajaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS)
{
	int retorno=-1;
	int indiceEmpleado;
	char confirmacion;
	int id;
	if (lista != NULL && tam > 0)
	{
		MostrarTrabajos(lista,tam,listaS,tamS);
		utn_getInt(&id,"Por favor ingresar el ID del usuario a dar BAJA",1001);
		indiceEmpleado=BuscarTrabajoPorID(lista,tam,id);

		if (indiceEmpleado<0)
		{
			printf("El id no le corresponde a ningun empleado \n");
		}
		else
		{

			MostrarEmpleado(lista[indiceEmpleado],listaS,tamS);


			printf("Esta seguro que desea realizar la BAJA? s/n \n:");
			scanf("%c",&confirmacion);

			if (confirmacion != 's' && confirmacion != 'n')
			{
				printf("Por favor ingresar la letra s para confirmar la baja O la letra n para no realizar la baja \n");
				scanf("%c",&confirmacion);
			}
			else
			{
				if (confirmacion=='s')
				{
					listaEmpleados[indiceEmpleado].isEmpty=VACIO;
					retorno=0;
					printf("El empleado se dio de baja con exito \n");
				}
				else
				{
					printf("El empleado NO se dio de baja \n");
				}
			}
		}



	}
	return retorno;
}


int MenuModificaciones ()
{
	int opcion;

	system("clear");

	printf("Que desea modificar?");
	printf("1. Marca\n");
	printf("2. Servicio\n");
	printf("3. SALIR\n");


	scanf("%d",&opcion);

	return opcion;
}
*/
