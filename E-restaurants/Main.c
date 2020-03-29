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

	    do
	    {
	        printf("Bienvenido a e-restaurant, como desea acceder:\n\n");
	        printf("1. Usuario\n");
	        printf("2. Administrador\n");
	        printf("3. Salir\n");
	        scanf("%d",&eleccion);

	        switch(eleccion)
	        {
	            case 1:	void usuario();
	                break;
	            case 2: void administrador();
	                break;
	            case 3: printf("Adios, pase un buen dia!\n");
	                exit(0);
	                break;
	            default: printf("Elección incorrecta!\n");
	                break;
	        }

	    } while (eleccion != 3||2||1);


void usuario()
{

}

void administrador()
{
	printf("Introduzca el usuario:");
	scanf("%s",&usuarioAdmin);
	if(&usuarioAdmin == "admin")
	{

		printf("Introduzca la contraseña:");
		scanf("%s",&contraseñaAdmin);

		if(&contraseñaAdmin == "admin")
		{
			printf("Cuenta correcta, adelante");
			menu2();
		}

	}else
	{
	printf("Cuenta incorrecta, intentelo de nuevo");
	void administrador;
	}

}

void menu2(){

	int eleccion;

	do
	{
		printf("Que desea visualizar:\n");
		printf("1.Restaurantes");
		printf("2.Menus");
		printf("3.Producto");

		switch (eleccion) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default: printf("Elección incorrecta\n");
				menu2();
		}
	} while (eleccion != 3||2||1);


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
}





