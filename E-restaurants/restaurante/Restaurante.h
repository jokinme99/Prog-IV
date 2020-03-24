/*
 * Restaurante.h
 *
 *  Created on: 24 mar. 2020
 *      Author: Mikel
 */

#ifndef RESTAURANTE_RESTAURANTE_H_
#define RESTAURANTE_RESTAURANTE_H_

typedef struct{
	int idRestaurante;
	char nomRestaurante[15];
	char dirRestaurante[15];
	int telefono;
	int mesasDisponibles;
	char descripcion[20];
}Restaurante;

#endif /* RESTAURANTE_RESTAURANTE_H_ */
