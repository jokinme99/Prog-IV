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
#define USER1 "usuario1"
#define USER2 "usuario2"
#define CLAVE1 "clave1"
#define CLAVE2 "clave2"
#define CLAVEADMIN "claveadmin"

int main() {
//Restaurantes: Ver todos los restaurantes, ver restaurantes con mesas disponibles & restaurantes con un tipo de comida
//Menus: Ver los menus de los restaurantes, menus con un precio mayor/menor que x & menus con x productos
//Producto: Productos con un precio mayor/menor que x

	int menu1; //,opciones, categoria,tipo;
	char* usuario1, contrasenya1,contrasenyaAdmin;;

	printf("Por favor elija una opción");
	printf("1. Usuario");
	printf("2. Administrador");
	printf("3. Salir");
	scanf("%i", &menu1);


	if (menu1 == 1){
		printf("Inicio sesión de usuario\n");//Registro de usuarios
		printf("Introducir usuario:");
		scanf("%s" &usuario1);
		if(usuario1 == USER1){
			printf("Introduzca su contrasenya:");
			scanf("%s", &contrasenya1);
			if(contrasenya1 != CLAVE1){
				printf("contrasenya incorrecta");
			}else{
				printf("------ Bienvenido/a a E-restaurants ------");
				//Aquí se mete los restaurantes, reservas, menus, productos...
			}
		}if(usuario1 == USER2){
			printf("Introduzca su contrasenya:");
						scanf("%s", &contrasenya1);
						if(contrasenya1 != CLAVE2){
							printf("contrasenya incorrecta");
						}else{
							printf("------ Bienvenido/a a E-restaurants ------");
							//Aquí se mete los restaurantes, reservas, menus, productos...
						}
		}
		if(usuario1 != USER1 || usuario1 != USER2){
			printf("Usuario incorrecto!!");
		}
	}
	if (menu1 == 2){
		printf("Inicio sesión de administrador\n");
		printf("Introducir contrasenya:");
		scanf("%s", &contrasenyaAdmin);
		if(contrasenyaAdmin == CLAVEADMIN){
			printf("------ Bienvenido/a a E-restaurants ------");
			//Aqui se mete la administracion
		}else{
			printf("contrasenya incorrecta");
		}
	}
	if (menu1== 3){
		break;
	}
	else{
		printf("Por favor elija una opción correcta");
	}


	return 0;
}




