/*
 * restaurante.c
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */
#include <stdio.h>
#include "restaurante.h"
#include "menu.h"

void imprimirRestaurantes(Restaurante r1){
	printf("Id = :%i \n Nombre = %s \n Direccion = %s \n Descripcion = %s \n Telefono = %i \n Mesas disponibles:&i \n Numero menu = %i \n", r1.id, r1.nombre, r1.direccion, r1.tipoComida, r1.telefono,r1.numMesas, r1.menus->numMenu);
}

