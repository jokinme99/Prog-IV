/*
 * Main.cpp
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

//CONSOLA

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Restaurante.h"
#include <cstdlib>
#include <fstream>
#include "Producto.h"
#include "Menu.h"
#include <stdio.h>

#define USUARIO "usuario"
#define CONTRA "usuario"
using namespace std;
void admin(){
	cout<<"---MODO ADMINISTRADOR---"<<endl;
	cout<<"1. Ver todos los restaurantes"<<endl;
	cout<<"2. Modificar restaurantes"<<endl;
	cout<<"3. Buscar restaurantes"<<endl;
	cout<<"4. Anyadir restaurante"<<endl;
	cout<<"5. Eliminar restaurante"<<endl;
	cout<<"6. Cerrar sesion"<<endl;
}
int main(void)
{

		//parte de crear el administrador y login del administrador
		int opcion,salir,opcionAdmin,opcionUsuario,op;
		string nombreAdmin;
		string contraAdmin;
		string linea;
		string no;
		string co;
		int con = 0;
		string parte;

		//parte de crear el usuario y login del usuario
		string nombreUsuario;
		string contraUsuario;
		int opUsu;

		string usuario;
		string contrasenya;
		Restaurante restaurante;
		cout<<"-----BIENVENIDO A E-RESTAURANTS-----"<<endl;
		cout<<"1.Entrar como administrador"<<endl;
		cout<<"2.Entrar como usuario"<<endl;
		cout<<"3.Salir"<<endl;
		cin>>opcion;

		switch(opcion){
		case 1:{
			cout << "1. Registrar administrador" << endl;
			cout << "2. Iniciar como administrador" << endl;
			cout << "3. Volver" << endl;
			cin >> op;
		switch(op){
		case 1:{
			cout << "Ingresa el nombre del admin: ";
							cin >> nombreAdmin;
							cout << endl;

							cout << "Ingresa la contraseña del admin: ";
							cin >> contraAdmin;
							cout << endl;


							ofstream ofs("administradores.txt");

							ofs << nombreAdmin << "," << contraAdmin;

							ofs.close();

							cout << "Administrador creado correctamente" << endl;
		} break;
		case 2:{ //Accedemos a admin
			cout << "Ingresa el nombre del admin\n";
							cin >> nombreAdmin;
							cout << endl;

							cout << "Ingresa la contraseña del admin\n";
							cin >> contraAdmin;
							cout << endl;

							ifstream ifs("administradores.txt");

							while(!ifs.eof()){
							ifs >> linea;



							char separador = ',';
							for(size_t p=0, q=0; p!=linea.npos;p=q){
								parte= linea.substr(p+(p!=0), (q=linea.find(separador,p+1))-p-(p!=0));
									if(con == 0){
										no = parte;
										//cout << "El nombre es: " << no << endl;
									}else if(con == 1){
										co = parte;
										//cout << "La contra es: " << co << endl;
									}else{
										cout << "error";
									}
									con++;
							}

							ifs.close();

							}
							if(nombreAdmin == no && contraAdmin == co){
								cout << "Nombre y contra introduccidos correctamente" << endl;
								cout << endl;
								/*cout << "nombre introduccido: " << nombreAdmin << endl; // esta linea y las 3 siguientes es para ver si funciona bien, quitar para la entrega final!
								cout << "nombre del txt: " << no << endl;
								cout << "contra introduccido: " << contraAdmin << endl;
								cout << "contra del txt: " << co << endl;*/

								admin();
								cin>>opcionAdmin;

								switch(opcionAdmin){
								case 1:{
									cout<<"VER TODOS LOS RESTAURANTES"<<endl;

								} break;
								case 2:{

								}break;
								case 3:{
									cout<<"BUSCAR RESTAURANTE";//Todo:HACER FUNCIONAL

								}break;
								case 4:{
								}break;
								case 5:{
									system("cls");
									cout<<"eliminar"<<endl;
									system("cls");
								}break;
								case 6:{
									cout<<"Cerrando sesion"<<endl;
									return main();
								}break;
								default:{
									cout<<"introduzca un valor correcto"<<endl;
								}break;
								}

								//Contrasenya/usuario incorrecta
								}else{
									cout << "El nombre o la contra introduccidos son incorrectos" << endl;
								}
		}break;
		case 3:{
			return main();
		}break;
		default:{
			cout<<"Introduzca un valor correcto";
		}break;
		}

		}break;
		case 2:{
			cout<<"1. Registrar usuario"<<endl;
			cout<<"2. Iniciar sesion como usuario"<<endl;
			cin>>opUsu;


			switch(opUsu){
				case 1:{
					cout << "Ingresa el nombre del usuario: ";
					cin >> nombreUsuario;
					cout << endl;

					cout << "Ingresa la contraseña del usuario: ";
					cin >> contraUsuario;
					cout << endl;


					ofstream ofs("usuarios.txt", ios::app);

					ofs << nombreUsuario << " " << contraUsuario << endl;

					ofs.close();

					cout << "Usuario creado correctamente" << endl;
				} break;
				case 2:{ //Accedemos al usuario

					ifstream ifs;
					ifs.open("usuarios.txt", ios::in);
					string nom, con, nomAu, conAu;
					bool en = false;
					cout << "Ingrese el nombre del usuario: " << endl;
					cin >> nomAu;
					cout << "Ingrese la contra del usuario: "<<endl;
					cin >> conAu;
					ifs >> nom;
						while (!ifs.eof() && !en) {
							ifs>>con;
							if(nom == nomAu && con == conAu){
							cout<<"Usuario y contraseña correctos. Bienvenido " << nomAu <<endl;
							/*cout<<"Nombre introducido: " <<nomAu<<endl; estas cuatro lineas son para compobar datos
							cout<<"nombre del txt: " << nom<<endl; //nombre encontrado en el txt
							cout<<"Contra introducida: "<<conAu<<endl;
							cout<<"contra del txt: " <<con<<endl;  //contra encontrada en el txt*/
							en = true;

							//parte del usuario
							cout<<"---MODO USUARIO---"<<endl;

						}

						if(nom == nomAu && con != conAu || nom != nomAu && con == conAu) {
							cout<<"El usuario y/o la contraseña son incorrectos"<<endl;
						}
						ifs>>nom;
					}
					ifs.close();

					if(!en){
						cout<<"usuario NO encontrado"<<endl;
					}
				}
			}
					}break;
		case 3:{
			cout<< "Estas seguro?"<<endl;
			cout<<"1.SI"<<endl;
			cout<<"2.NO"<<endl;
			cin>>salir;
			if(salir ==1){
				return 0;
			}else{
				return main();
			}
		}break;
		default:{
			cout<<"Introduzca un valor correcto por favor"<<endl;
			return main();
		}break;
}
}

