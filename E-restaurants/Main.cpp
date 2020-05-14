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


		ofstream file("datos.txt");
		Restaurante r1;Menu m1;Trabajador t1;Producto p1; p1.id = 0; p1.nombre = "Filete";p1.descripcion = "Carne de muy alta calidad de los baserris de Erandio"; p1.precio = 8.45;
		Restaurante r2;Menu m2;Trabajador t2;Producto p2; p2.id = 1; p2.nombre = "Merluza";p2.descripcion = "Recien pescado en el mar cantabrico"; p2.precio = 6.72;
		Restaurante r3;Menu m3;Trabajador t3;Producto p3; p3.id = 2; p3.nombre = "Lentejas";p3.descripcion = "Lentejas de calidad extremadamente alta"; p3.precio = 4.50;
		Restaurante r4;Menu m4;Trabajador t4;Producto p4; p4.id = 3; p4.nombre = "Alubias";p4.descripcion = "Alubias de Tolosa"; p4.precio = 5.30;
		Restaurante r5;Menu m5;Trabajador t5;Producto p5; p5.id = 4; p5.nombre = "Pan";p5.descripcion = "Chapata recien hornada"; p5.precio = 1.50;
		Restaurante r6;Menu m6;Trabajador t6;Producto p6; p6.id = 5; p6.nombre = "Agua";p6.descripcion = "Agua de manantial"; p6.precio = 1.20;
					   Menu m7;				 Producto p7; p7.id = 6; p7.nombre = "Vino";p7.descripcion = "Vino rioja cosecha 2012"; p7.precio = 3.50;
					   Menu m8;				 Producto p8; p8.id = 7; p8.nombre = "Pollo";p8.descripcion = "Pollo de calidad increible"; p8.precio = 6.45;
					   Menu m9;				 Producto p9; p9.id = 8; p9.nombre = "Ensalada";p9.descripcion = "Ensalada de verano deliciosa"; p9.precio = 3.20;
					   Menu m10;			 Producto p10; p10.id = 9; p10.nombre = "Tarta de queso";p10.descripcion = "Tarta de queso de la casa"; p10.precio = 4.62;
					   	   	   	   	   	   	 Producto p11; p11.id = 10; p11.nombre = "Esparragos";p11.descripcion = "Esparragos de otro nivel"; p11.precio = 3.50;
					   	   	   	   	   	   	 Producto p12; p12.id = 11; p12.nombre = "Helado ";p12.descripcion = "Helado de tarrina de distintos sabores"; p12.precio = 3.50;

		t1.id = 0;t1.dni="78512067W";t1.nombre = "Joseba Agirre";t1.sueldo=950;//Sueldo mensual
		t2.id = 1;t2.dni="62107549V";t2.nombre = "Leire Perez";t2.sueldo=1050;
		t3.id = 2;t3.dni="03749821Y";t3.nombre = "Andoni Ikasti";t3.sueldo=900;
		t4.id = 3;t4.dni="63012430P";t4.nombre = "Mikel Rebic";t4.sueldo=700;
		t5.id = 4;t5.dni="31024578U";t5.nombre = "Ane Solobaren";t5.sueldo=1250;
		t6.id = 5;t6.dni="47581264A";t6.nombre = "Koldo Argitaletxe";t6.sueldo=980;

		Producto* productosMenu1 = new Producto[3];
		productosMenu1[0] = p1;
		productosMenu1[1] = p7;
		productosMenu1[2] = p1;
		Producto* productosMenu2 = new Producto[3];
		productosMenu2[0] = p12;
		productosMenu2[1] = p6;
		productosMenu2[2] = p10;
		Producto* productosMenu3 = new Producto[3];
		productosMenu3[0] = p2;
		productosMenu3[1] = p9;
		productosMenu3[2] = p7;
		Producto* productosMenu4 = new Producto[3];
		productosMenu4[0] = p11;
		productosMenu4[1] = p4;
		productosMenu4[2] = p6;
		Producto* productosMenu5 = new Producto[3];
		productosMenu5[0] = p3;
		productosMenu5[1] = p4;
		productosMenu5[2] = p1;
		Producto* productosMenu6 = new Producto[3];
		productosMenu6[0] = p10;
		productosMenu6[1] = p4;
		productosMenu6[2] = p6;
		Producto* productosMenu7 = new Producto[3];
		productosMenu7[0] = p4;
		productosMenu7[1] = p4;
		productosMenu7[2] = p8;
		Producto* productosMenu8 = new Producto[3];
		productosMenu8[0] = p9;
		productosMenu8[1] = p4;
		productosMenu8[2] = p5;
		Producto* productosMenu9 = new Producto[3];
		productosMenu9[0] = p5;
		productosMenu9[1] = p4;
		productosMenu9[2] = p12;
		Producto* productosMenu10 = new Producto[3];
		productosMenu10[0] = p8;
		productosMenu10[1] = p4;
		productosMenu10[2] = p11;

		Trabajador* trabajadorRestaurante1 = new Trabajador[3];
		trabajadorRestaurante1[0] = t1;
		trabajadorRestaurante1[1] = t2;
		trabajadorRestaurante1[2] = t3;
		Trabajador* trabajadorRestaurante2 = new Trabajador[3];
		trabajadorRestaurante2[0] = t4;
		trabajadorRestaurante2[1] = t5;
		trabajadorRestaurante2[2] = t6;
		Trabajador* trabajadorRestaurante3 = new Trabajador[3];
		trabajadorRestaurante3[0] = t1;
		trabajadorRestaurante3[1] = t3;
		trabajadorRestaurante3[2] = t5;
		Trabajador* trabajadorRestaurante4 = new Trabajador[3];
		trabajadorRestaurante4[0] = t2;
		trabajadorRestaurante4[1] = t4;
		trabajadorRestaurante4[2] = t6;
		Trabajador* trabajadorRestaurante5 = new Trabajador[3];
		trabajadorRestaurante5[0] = t1;
		trabajadorRestaurante5[1] = t6;
		trabajadorRestaurante5[2] = t5;
		Trabajador* trabajadorRestaurante6 = new Trabajador[3];
		trabajadorRestaurante6[0] = t2;
		trabajadorRestaurante6[1] = t3;
		trabajadorRestaurante6[2] = t4;

		m1.numMenu = 1;m1.productos=productosMenu1;m1.precio= 17.50;
		m2.numMenu = 2;m2.productos=productosMenu2;m2.precio= 15.00;
		m3.numMenu = 3;m3.productos=productosMenu3;m3.precio= 14.25;
		m4.numMenu = 4;m4.productos=productosMenu4;m4.precio= 13.99;
		m5.numMenu = 5;m5.productos=productosMenu5;m5.precio= 18.50;
		m6.numMenu = 6;m6.productos=productosMenu6;m6.precio= 12.20;
		m7.numMenu = 7;m7.productos=productosMenu7;m7.precio= 10.99;
		m8.numMenu = 8;m8.productos=productosMenu8;m8.precio= 13.50;
		m9.numMenu = 9;m9.productos=productosMenu9;m9.precio= 14.40;
		m10.numMenu = 10;m10.productos=productosMenu10;m10.precio= 16.00;

		Menu* menuRestaurante1 = new Menu[3];
		menuRestaurante1[0] = m1;
		menuRestaurante1[1] = m2;
		menuRestaurante1[2] = m3;
		Menu* menuRestaurante2 = new Menu[3];
		menuRestaurante2[0] = m4;
		menuRestaurante2[1] = m5;
		menuRestaurante2[2] = m6;
		Menu* menuRestaurante3 = new Menu[3];
		menuRestaurante3[0] = m7;
		menuRestaurante3[1] = m8;
		menuRestaurante3[2] = m9;
		Menu* menuRestaurante4 = new Menu[3];
		menuRestaurante4[0] = m10;
		menuRestaurante4[1] = m1;
		menuRestaurante4[2] = m2;
		Menu* menuRestaurante5 = new Menu[3];
		menuRestaurante5[0] = m3;
		menuRestaurante5[1] = m4;
		menuRestaurante5[2] = m5;
		Menu* menuRestaurante6 = new Menu[3];
		menuRestaurante6[0] = m6;
		menuRestaurante6[1] = m7;
		menuRestaurante6[2] = m8;

		r1.id = 0; r1.nombre = "Taberna de Santi";r1.tipoComida = "Casera"; r1.direccion = "Cristobal Colon kalea 1"; r1.menus = menuRestaurante1;r1.telefono=687941203;r1.numMesas=15;r1.trabajadores=trabajadorRestaurante1;
		r2.id = 1; r2.nombre = "Etxepareren jatetxea";r2.tipoComida = "Completa"; r2.direccion = "Alboko etorbidea 11"; r2.menus = menuRestaurante2;r2.telefono=674803021;r2.numMesas=10;r2.trabajadores=trabajadorRestaurante2;
		r3.id = 2; r3.nombre = "El txoko";r3.tipoComida = "Asador"; r3.direccion = "San jose 2"; r3.menus = menuRestaurante3;r3.telefono=94578213;r3.numMesas=9;r3.trabajadores=trabajadorRestaurante3;
		r4.id = 3; r4.nombre = "La mona vestida de seda";r4.tipoComida = "Vegetariana"; r4.direccion = "Aitor aretxabala 9"; r4.menus = menuRestaurante4;r4.telefono=932546781;r4.numMesas=12;r4.trabajadores=trabajadorRestaurante4;
		r5.id = 4; r5.nombre = "El sexto sentido";r5.tipoComida = "Francesa"; r5.direccion = "deusto kalea 3"; r5.menus = menuRestaurante5;r5.telefono=947812658;r5.numMesas=11;r5.trabajadores=trabajadorRestaurante5;
		r6.id = 5; r6.nombre = "Milaka";r6.tipoComida = "Italiana"; r6.direccion = "Gure etorbidea 8"; r6.menus = menuRestaurante6;r6.telefono=62574890;r6.numMesas=9;r6.trabajadores=trabajadorRestaurante6;
		//Introducir en el fichero txt los distintos restaurantes

		//parte de crear el administrador y login del administrador
		int opcion,salir,opcionAdmin,opcionUsuario,op;
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
		case 1:{
			cout << "1. Registrar administrador" << endl;
			cout << "2. Iniciar como administrador" << endl;
			cout << "3. Volver" << endl;
			cin >> op;
		switch(op){
		case 1:{
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

								//menu del admin
								cout<<"---MODO ADMINISTRADOR---"<<endl;
								cout<<"1. Ver todos los restaurantes"<<endl;
								cout<<"2. Buscar restaurante por id"<<endl;
								cout<<"3. Modificar restaurantes"<<endl;
								cout<<"4. Anyadir restaurante"<<endl;
								cout<<"5. Eliminar restaurante"<<endl;
								cout<<"6. Cerrar sesion"<<endl;
								cin>>opcionAdmin;
								switch(opcionAdmin){
								case 1:{
									cout<<"VER TODOS LOS RESTAURANTES"<<endl;
									r1.imprimir();
									r2.imprimir();
									r3.imprimir();
									r4.imprimir();
									r5.imprimir();
									r6.imprimir();
								} break;
								case 2:{
									cout<<"BUSCAR RESTAURANTES";
									string nombre;
									int idTrabajador,idProducto,idRestaurante,numMenu,numMesas;
									string dni,nombreTrabajador,nombreProducto,nombreRestaurante,descripcionMenu,tipoComida,descripcionRestaurante;
									Menu* menuRestaurante = menuRestaurante[3];
									Producto* productoMenu = productoMenu[3];
									Trabajador* trabajadorRestaurante = trabajadorRestaurante[3];
									cout<<"Introduzca el nombre de un restaurante:";
									cin>>nombre;
									if(r1.getNombre() == nombre){

									}else if (r2.getNombre() == nombre){
										r2.imprimir();
									}else if(r3.getNombre() == nombre){
										r3.imprimir();
									}else if (r4.getNombre() == nombre){
										r4.imprimir();
									}else if(r5.getNombre() == nombre){
										r5.imprimir();
									}else if (r6.getNombre() == nombre){
										r6.imprimir();
									}else{
										cout<<"No existe ningun restaurante con ese nombre";
									}

								}break;
								case 3:{
									cout<<"MODIFICAR RESTAURANTES";
									string nombre;
									cout<<"Introduzca el nombre de un restaurante:";
									cin>>nombre;
									if(r1.getNombre() == nombre){

										r1.imprimir();
									}else if (r2.getNombre() == nombre){
										r2.imprimir();
									}else if(r3.getNombre() == nombre){
										r3.imprimir();
									}else if (r4.getNombre() == nombre){
										r4.imprimir();
									}else if(r5.getNombre() == nombre){
										r5.imprimir();
									}else if (r6.getNombre() == nombre){
										r6.imprimir();
									}else{
										cout<<"No existe ningun restaurante con ese nombre";
									}
								}break;
								case 4:{
									system("cls");
									cout<<"anyadir"<<endl;
									system("cls");
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
			cout<<"Introducir el usuario: ";
			cin>>usuario;
			cout<<"Introducir contrasenya: ";
			cin>>contrasenya;
			if(usuario == USUARIO && contrasenya == CONTRA){
				cout<<"---MODO USUARIO---"<<endl;

			}else{
				cout<<"Contrasenya y/o usuario incorrectos"<<endl;
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

