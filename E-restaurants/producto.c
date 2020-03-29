/*
 * producto.c
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */
#include <stdio.h>
#include "producto.h"

void imprimirProductos(Producto p1){
	printf("Id = :%i \n Nombre = %s \n Descripcion = %s \n Precio = %f \n", p1.id, p1.nombre, p1.descripcion, p1.precio);
}
