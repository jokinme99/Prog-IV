/*
 * menu.h
 *
 *  Created on: 29 mar. 2020
 *      Author: jokin
 */
#include <stdio.h>
#include "producto.h"
#ifndef MENU_MENU_H_
#define MENU_MENU_H_

typedef struct{
	int numMenu;
	Producto* productos;
	float precio;
}Menu;

void imprimirMenus(Menu m1);


#endif /* MENU_MENU_H_ */
