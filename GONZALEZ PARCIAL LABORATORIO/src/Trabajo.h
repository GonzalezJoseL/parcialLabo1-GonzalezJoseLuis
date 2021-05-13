

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "Servicio.h"

#define VACIO 0
#define OCUPADO 1

#define S 4


typedef struct
    {
        int dia;
        int mes;
        int anio;
    }eFecha;


    typedef struct
    {
        int id;
        char marcaBicicleta[45];
        int rodadoBicicleta;
        int idServicio;
        eFecha fecha;
        int isEmpty;
    }eTrabajo;


    int Asignarid();
    int Menu ();
    int InicializarTrabajos (eTrabajo lista[],int tam);
    int BuscarLibre (eTrabajo lista[],int tam);
    int BuscarTrabajoPorID(eTrabajo lista[], int tam,int id);
    int PedirDatos (eTrabajo lista[], int tam, int* id, char marcaBici[], int* rodadoBici, int* idServicio,int* index, eServicio listaS[]);
    int LeerDatos (eTrabajo lista[], int tam, int id, char marcaBici[],int rodadoBici, int idServicio, int index);
    void MostrarTrabajo (eTrabajo Lista, eServicio listaS[], int tamS);
    int MostrarTrabajos (eTrabajo Lista[],int tam, eServicio listaS[], int tamS);
    int ModificarTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS);
    int MenuModificaciones ();

#endif /* TRABAJO_H_ */
