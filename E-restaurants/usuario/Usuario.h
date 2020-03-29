/*
 * Usuario.h
 *
 *  Created on: 24 mar. 2020
 *      Author: Mikel
 */

#ifndef USUARIO_USUARIO_H_
#define USUARIO_USUARIO_H_

typedef struct
{
	char correo[30];
	char contraseña[30];
	char usuario[30];
	int admin;

}cuenta;

typedef struct {
	char nom[10];
	char correo[20];
	int numTarjeta;
	float saldo;
}Usuario;

Usuario nuevoCliente() // no sé si está bien!! esto para que????


#endif /* USUARIO_USUARIO_H_ */
