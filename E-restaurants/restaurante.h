/*
 * restaurante.h
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */

#include <stdio.h>
#include "menu.h"
#include "producto.h"
#ifndef RESTAURANTE_RESTAURANTE_H_
#define RESTAURANTE_RESTAURANTE_H_


typedef struct{
	int id;
	char* nombre;
	char* direccion;
	char* tipoComida;
	int telefono;
	Menu* menus;
	int numMesas;//Mesas disponibles
}Restaurante;

void imprimirRestaurantes(Restaurante r);


#endif /* RESTAURANTE_RESTAURANTE_H_ */
