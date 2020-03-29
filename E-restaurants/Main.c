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

	int eleccion;
	char usuarioAdmin[30];
	char contraseñaAdmin[30];

	do {
		printf("Bienvenido a e-restaurant, como desea acceder:\n\n");
		printf("1. Usuario\n");
		printf("2. Administrador\n");
		printf("3. Salir\n");
		scanf("%d", &eleccion);

		switch (eleccion) {
		case 1:
			void usuario();
			break;
		case 2:
			void administrador();
			break;
		case 3:
			printf("Adios, pase un buen dia!\n");
			exit(0);
			break;
		default:
			printf("Elección incorrecta!\n");
			break;
		}

	} while (eleccion != 3 || 2 || 1);

	char usuario[30];
	char contraseña[30];

	void usuario() {
		printf("Introduzca el usuario:");
		scanf("%s", &usuario);
		menu3();//mejoraremos el login comprobando el usuario y contraseña con los existentes en un archivo
	}

	void administrador() {
		printf("Introduzca el usuario:");
		scanf("%s", &usuarioAdmin);
		if (&usuarioAdmin == "admin") {

			printf("Introduzca la contraseña:");
			scanf("%s", &contraseñaAdmin);

			if (&contraseñaAdmin == "admin") {
				printf("Cuenta correcta, adelante");
				menu2();
			}

		} else {
			printf("Cuenta incorrecta, intentelo de nuevo");
			void administrador;
		}

	}

	void menu2() {

		int eleccion;
		int eleccion2;
		int eleccion3;
		char restaurante[30];
		char direccion[30];
		char tipoComida[30];
		int telefono[30];
		Menu memus[30];
		int numMesas[30];
		int menu[30];
		char nombrePro[30];
		char descripcion[30];
		float precio[30];


		do {
			printf("Que desea visualizar:\n");
			printf("1.Restaurantes");
			printf("2.Menus");
			printf("3.Producto");

			switch (eleccion) {	// la creacion, eliminacion y edicion de los restaurantes, menus y productos se implementaran en c++
			case 1:
				printf("Que desea hacer:\n");
				printf("1.Crear Restaurante");
				printf("2.Editar Restaurante");
				printf("3.Eliminar Restaurante");

				switch (eleccion2) {
				case 1:do{


					printf(
							"Introduce en nombre del restaurante que quiera crear")
					scanf("%s", &restaurante);
					printf("Introduce direccion:");
					scanf("%s", &direccion);
					printf("Introduce el tipo de comida:");
					scanf("%s", &tipoComida);
					printf("Introduce el numero de telefono:");
					scanf("%s", &telefono);
					printf("Introduce los menus que deseas añadir");
					//scanf("%s", &menus);
					printf("Introduce el numero de mesas");
					scanf("%s", &numMesas);
					menu2();
					break;
				case 2:
					printf("Introduce el restaurante que quiera editar");
					scanf("%s", &restaurante);
					menu2();
					break;
				case 3:
					printf("Escriba el restaurante que desea eliminar: ");
					scanf("%s", &restaurante);
					menu2();
					break;
				} while (eleccion2 != 3 || 2 || 1);
				}
				while (eleccion2 != 3 || 2 || 1);

				break;
			case 2:
				printf("Escriba menu: ");
				scanf("%s", &restaurante);
				imprimirRestaurantes(&restaurante);
				imprimirMenus(&menu);
				break;
			case 3:
				do {
				printf("Que desea hacer:\n");
				printf("1.Crear un producto");
				printf("2.Editar un producto");
				printf("3.Eliminar un producto");

				switch (eleccion3) {
				case 1:
					printf(
							"Introduce en nombre del producto que quiera crear")
					scanf("%s", &nombrePro);
					printf("Introduce una descripcion:");
					scanf("%s", &descripcion);
					printf("Introduce el precio:");
					scanf("%s", &precio);
					menu2();
					break;
				case 2:
					printf("Introduce producto que quiera editar");
					scanf("%s", &nombrePro);
					menu2();
					break;
				case 3:
					printf("Escriba el producto que desea eliminar: ");
					scanf("%s", &nombrePro);
					menu2();
					break;
				} while (eleccion2 != 3 || 2 || 1);
				}
				while (eleccion3 != 3 || 2 || 1);

				break;
			default:
				printf("Elección incorrecta\n");
				menu2();
			}
		} while (eleccion != 3 || 2 || 1);

	}




	void menu3(){

		int eleccion;
		float saldo;
		char restaurante[30];
		int menu[30];

		do {
				printf("Que desea hacer:\n");
				printf("1.Hacer una reserva");
				printf("2.Ver mi perfil");
				printf("3.Añadir saldo");
				switch (eleccion){		//la funcionalidad se añadira en c++
				case 1:
					printf("seleccione el restaurante donde quiera hacer la reserva");
					scanf("%s", &restaurante);
					printf("seleccione el menu");
					scanf("%s", &menu);
					menu3();
					break;
				case 2:
					printf("Estos son los datos de su perfil");
					break;
				case 3:
					printf("escriba una cantidad a añadir");
					scanf("%s", &saldo);
					printf("el saldo ha sido añadido");
					menu3();
					break;
				}

		} while (eleccion != 3 || 2 || 1);
	}

//Restaurantes: Ver todos los restaurantes, ver restaurantes con mesas disponibles & restaurantes con un tipo de comida
//Menus: Ver los menus de los restaurantes, menus con un precio mayor/menor que x & menus con x productos
//Producto: Productos con un precio mayor/menor que x

	/*int menu1; //,opciones, categoria,tipo;
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
	 }}
	 else if(usuario1 == "usuario2"){
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

	 return 0;*/


