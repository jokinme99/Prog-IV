/*
 * Usuario.c
 *
 *  Created on: 25 mar. 2020
 *      Author: Mikel
 */

#include "Usuario.h"
#include <stdio.h>


void registro()
{
	FILE * fichero;

			fichero = fopen("cuenta.txt","a");


			char correo[30];
			char usuario[30];
			char contraseņa[];
			int admin;

			if(fichero == NULL){
				printf("No se ha podido abrir.\n");				//si esta vacio no se abre
				exit(1);
			}

			printf("Introduce el correo: ");
			fflush(stdout);
			scanf("%s", &correo);

			printf("Introduce el nombre de usuario: ");			//pedimos los datos de la cuenta, por defecto no admin
			fflush(stdout);
			scanf("%s", &usuario);

			printf("Introduce la contraseņa: ");
			fflush(stdout);
			scanf("%s", &contraseņa);

			&admin = 0;

			printf("Nuevo usuario aņadido. \n");

			fprintf(fichero, "\n %s %s %s %i\n", correo, usuario, contraseņa, admin);				//Escribimos los datos dentro del fichero


			fclose(fichero);
}


cuenta*cuentaC;
cuenta* login()
{
	FILE * fichero;
		int contadorCantCuenta=0;
		char correo[30];
		char usuario[30];
		char contraseņa[30];
		int admin;
		int contadores=contadorCuenta()+1;
		cuentaC =(cuenta*)malloc(sizeof(cuenta)*contadores);

		fichero = fopen("usuario.txt", "rb");
		if(fichero == NULL){

		}

		do{
			fscanf(fichero, "%s %s %s %i", &correo, &usuario, &contraseņa, &admin);    		 	//Abrimos el fichero y leemos el contenido
			if(contadores!=0){

				strncpy(cuentaC[contadorCantCuenta].correo, correo,30);
				strncpy(cuentaC[contadorCantCuenta].usuario, usuario,30);
				strncpy(cuentaC[contadorCantCuenta].contraseņa, contraseņa,30);
				cuentaC[contadorCantCuenta].admin=admin;
				contadorCantCuenta++;
				contadores--;
			}
		}while (feof(fichero) == 0);

			fclose(fichero);
			printf ("\n Lectura de cuentas correcta \n");
			return cuentaC;

}






