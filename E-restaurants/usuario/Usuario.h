/*
 * Usuario.h
 *
 *  Created on: 24 mar. 2020
 *      Author: Mikel
 */

#ifndef USUARIO_USUARIO_H_
#define USUARIO_USUARIO_H_

typedef struct {
	char nom[10];
	char correo[20];
	char contra[15];
	int numTarjeta;
	float saldo;
}Usuario;

Usuario nuevoCliente() // no sé si está bien!!


#endif /* USUARIO_USUARIO_H_ */
