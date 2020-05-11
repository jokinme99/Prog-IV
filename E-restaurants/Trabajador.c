/*
 * Trabajador.c
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */
#include "Trabajador.h"
#include <stdio.h>
void imprimirTrabajadores(Trabajador t1){
	printf("Id trabajador = %i \n ,DNI = %s \n ,Nombre = %s \n ,Sueldo= %f", t1.id, t1.dni, t1.nombre, t1.sueldo);
}



