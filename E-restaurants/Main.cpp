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
#define USUARIO "usuario"
#define CONTRA "usuario"
using namespace std;

int main(void)
{

		int opcion,salir,opcionAdmin,opcionUsuario,op;

		//parte de crear el administrador y login del administrador
		string nombreAdmin;
		string contraAdmin;
		string linea;
		string no;
		string co;
		int con = 0;
		string parte;


		string usuario;
		string contrasenya;
		Restaurante restaurante;
		cout<<"-----BIENVENIDO A E-RESTAURANTS-----"<<endl;
		cout<<"1.Entrar como administrador"<<endl;
		cout<<"2.Entrar como usuario"<<endl;
		cout<<"3.Salir"<<endl;
		cin>>opcion;

		switch(opcion){
		case 1:
			cout << "1. Registrar administrador" << endl;
			cout << "2. Iniciar como administrador" << endl;
			cout << "3. Salir" << endl;
			cin >> op;

			if(op == 1){//Registramos admin
				cout << "Ingresa el nombre del admin\n";
				cin >> nombreAdmin;
				cout << endl;

				cout << "Ingresa la contraseña del admin\n";
				cin >> contraAdmin;
				cout << endl;


				ofstream ofs("administradores.txt");

				ofs << nombreAdmin << "," << contraAdmin;

				ofs.close();

				cout << "Administrador creado correctamente" << endl;
			}

			if(op == 2){//Accedemos a admin
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

					//menu del admin
					cout<<"---MODO ADMINISTRADOR---"<<endl;
					cout<<"1. Ver todos los restaurantes"<<endl;
					cout<<"2. Modificar restaurantes"<<endl;
					cout<<"3. Anyadir restaurante"<<endl;
					cout<<"4.Eliminar restaurante"<<endl;
					cin>>opcionAdmin;
					switch(opcionAdmin){
						case 1:
						cout<<"VER TODOS LOS RESTAURANTES"<<endl;
//						ifstream archivo("restaurantes.txt");
//						string lineaArchivo;
//						if(archivo.fail()){
//							cout<<"El archivo no se pudo leer"<<endl;
//						}
//						while(getline(archivo, lineaArchivo)){
//							cout<<lineaArchivo<<endl;
//						}

						break;
						case 2:
						cout<<"modificar"<<endl;
						break;
						case 3:
						cout<< "anyadir"<<endl;
						break;
						case 4:
						cout<<"eliminar"<<endl;
						break;
						default:
						cout<<"introduzca un valor correcto"<<endl;
						break;
					}


					}else{
						cout << "El nombre o la contra introduccidos son incorrectos" << endl;
					}

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

