/*
 * Trabajador.h
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

typedef struct{
	int id;
	char* nombre;
	float sueldo;
	char* dni;
}Trabajador;

void imprimir(Trabajador t);


#endif /* TRABAJADOR_H_ */
