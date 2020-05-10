/*
 * producto.h
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */

#ifndef PRODUCTO_PRODUCTO_H_
#define PRODUCTO_PRODUCTO_H_

typedef struct{
	int id;
	char* nombre;
	char* descripcion;
	float precio;

}Producto;

void imprimirProductos(Producto p);


#endif /* PRODUCTO_PRODUCTO_H_ */
