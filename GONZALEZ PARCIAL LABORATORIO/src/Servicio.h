

#ifndef SERVICIO_H_
#define SERVICIO_H_

#define S 4

 typedef struct
   {

	 int id;

	 char descripcion[25];

	 float precio;

   }eServicio;



 void HardcodeoServicio(eServicio listaServicio[]);
 int MostrarListaServicios(eServicio servicios[], int tam);
 void MostrarServicio (eServicio servicio);
 int servicioPorId(int id, eServicio servicios[], int tam,char nombreDelservicio[]);


#endif /* SERVICIO_H_ */
