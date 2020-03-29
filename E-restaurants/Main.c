/*
 * Prueba.c
 *
 *  Created on: 22 mar. 2020
 *      Author: Mikel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurante.h"
#include "menu.h"
#include "producto.h"
#include "usuario.h"


int main() {

//Restaurantes: Ver todos los restaurantes, ver restaurantes con mesas disponibles & restaurantes con un tipo de comida
//Menus: Ver los menus de los restaurantes, menus con un precio mayor/menor que x & menus con x productos
//Producto: Productos con un precio mayor/menor que x

	int menu1; //,opciones, categoria,tipo;
	char* usuario1;
	char* contrasenya1;
	char* contrasenyaAdmin;

	printf("Por favor elija una opción\n");
	printf("1. Usuario\n");
	printf("2. Administrador\n");
	printf("3. Salir\n");
	scanf("%i", &menu1);


	if (menu1 == 1){
		printf("Inicio sesión de usuario\n");//Registro de usuarios
		printf("Introducir usuario: ");
		scanf("%s", usuario1);
		if(usuario1 == "usuario1"){
			printf("Introduzca su contrasenya:");
			scanf("%s", &contrasenya1);
			if(contrasenya1 != "clave1"){
				printf("contrasenya incorrecta");
			}else{
				printf("------ Bienvenido/a a E-restaurants ------");
				//Aquí se mete los restaurantes, reservas, menus, productos...
			}
		}else if(usuario1 == "usuario2"){
			printf("Introduzca su contrasenya: ");
						scanf("%s", &contrasenya1);
						if(contrasenya1 != "clave2"){
							printf("contrasenya incorrecta");
						}else{
							printf("------ Bienvenido/a a E-restaurants ------");
							//Aquí se mete los restaurantes, reservas, menus, productos...
						}
		}
		else{
			printf("Usuario incorrecto!!");
		}
	}
	if (menu1 == 2){
		printf("Inicio sesión de administrador\n");
		printf("Introducir contrasenya:");
		scanf("%s", &contrasenyaAdmin);
		if(contrasenyaAdmin == "claveAdmin"){
			printf("------ Bienvenido/a a E-restaurants ------");
			//Aqui se mete la administracion
		}else{
			printf("contrasenya incorrecta");

		}
	}
	if (menu1== 3){
		printf("Vuelva cuanto antes\n");
	}
	else{
		printf("Por favor elija una opción correcta\n");
	}

	return 0;
}




