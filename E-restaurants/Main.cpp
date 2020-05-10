/*
 * Main.cpp
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

//CONSOLA

#include <iostream>
#include <string.h>
#include "Restaurante.h"
#include <cstdlib>

#include "Menu.h"
#define ADMIN "admin"
#define PASSWORD "admin"
#define USUARIO "usuario"
#define CONTRA "usuario"
using namespace std;


int main(void)
{

		int opcion,salir,opcionAdmin,opcionUsuario;
		string usuario;
		string contrasenya;
		cout<<"-----BIENVENIDO A E-RESTAURANTS-----"<<endl;
		cout<<"1.Entrar como administrador"<<endl;
		cout<<"2.Entrar como usuario"<<endl;
		cout<<"3.Salir"<<endl;
		cin>>opcion;

		switch(opcion){
		case 1:
			cout<<"Introducir el usuario: ";
			cin>>usuario;
			cout<<"Introducir contrasenya: ";
			cin>>contrasenya;
			if(usuario == ADMIN && contrasenya == PASSWORD){
				cout<<"---MODO ADMINISTRADOR---"<<endl;
				cout<<"1. Ver todos los restaurantes"<<endl;
				cout<<"2. Modificar restaurantes"<<endl;
				cout<<"3. Anyadir restaurante"<<endl;
				cout<<"4.Eliminar restaurante"<<endl;
				cin>>opcionAdmin;
				switch(opcionAdmin){
				case 1:
					system("cls");
					cout<<"opcion 1";
					system("pause");
					system("cls");
					break;
				}
			}else{
				cout<<"Contrasenya y/o usuario incorrectos"<<endl;
				return main();
			}

		break;
		case 2:
			cout<<"Introducir el usuario: ";
			cin>>usuario;
			cout<<"Introducir contrasenya: ";
			cin>>contrasenya;
			if(usuario == USUARIO && contrasenya == CONTRA){
				cout<<"---MODO USUARIO---"<<endl;

			}else{
				cout<<"Contrasenya y/o usuario incorrectos"<<endl;
			}

		break;
		case 3:
			cout<< "Estas seguro?"<<endl;
			cout<<"1.SI"<<endl;
			cout<<"2.NO"<<endl;
			cin>>salir;
			if(salir ==1){
				return 0;
			}else{
				return main();
			}
		break;
		default:
			cout<<"Introduzca un valor correcto por favor"<<endl;
			return main();
}
}

