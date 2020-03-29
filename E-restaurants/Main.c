/*
 * Prueba.c
 *
 *  Created on: 22 mar. 2020
 *      Author: Mikel
 */

#include <stdio.h>
//#include "Usuario.h"

int main() {

	int menu, lugar, cancelarReserva;

		printf("Elige una de estas opciones: \n");
		printf("1. Reservar mesa \n");
		printf("2. Mesas disponibles \n");
		printf("3. Eliminar reserva \n");
		printf("4. Administracion \n");
		scanf("%i", &menu);


		if (menu == 1) {
			printf("Elige donde quieres hacer la reserva: \n");
			printf("1. Bilbao \n");
			printf("2. Burgos \n");
			printf("3. Madrid \n");
			printf("4. Barcelona \n");
			scanf("%i", &lugar);
		}

		if (menu == 2) {
			printf("El numero de mesas disponibles es: ");
			//scanf("&i", );

		}

		if (menu == 3) {
			printf("Desea eliminar una reserva? \n");
			printf("1. Si \n");
			printf("2. No \n");
			scanf("&i", &cancelarReserva);
			if(cancelarReserva == 1){
				printf("Reserva cancelada");
			}
			if(cancelarReserva == 2){
				printf("Reserva NO cancelada");
			}

		}

		if (menu == 4) {
			printf("Introduzca la contraseña del administrador \n");
		}

		if (menu >= 5) {
			printf ("El numero introducido no corresponde a ninguna categoria \n");
		}
		//prueba


	return 0;

}


