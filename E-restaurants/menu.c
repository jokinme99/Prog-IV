/*
 * menu.c
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */

#include "menu.h"
#include "producto.h"

void imprimirMenus(Menu m1){
	printf("Numero de menu = :%i \n Productos = %s \n Precio = %f \n", m1.numMenu, m1.productos->nombre, m1.precio );
}
