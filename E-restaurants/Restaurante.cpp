/*
 * GestionRestaurantes.cpp
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

#include "Restaurante.h"

#include <iostream>
#include <string.h>

#include "Menu.h"
using namespace std;

int Restaurante::id=0;
//id de restaurantes
Restaurante::Restaurante(char* nombre, char* direccion, char* tipoComida, int telefono, Menu* menus, int numMesas,Trabajador* trabajadores){
	this->nombre = new char[strlen(nombre) +1];
	strcpy(this->nombre, nombre);
	this->direccion = new char[strlen(direccion) +1];
	strcpy(this->direccion, direccion);
	this->tipoComida = new char[strlen(tipoComida) +1];
	strcpy(this->tipoComida, tipoComida);
	this->telefono = telefono;
	this->menus = menus;
	this->numMesas = numMesas;
	this->trabajadores = trabajadores;
}
Restaurante::Restaurante(){
	this->nombre = NULL;
	this->direccion = NULL;
	this->id = 0;
	this->menus = NULL;
	this->numMesas = 0;
	this->telefono = 0;
	this->tipoComida = NULL;
	this->trabajadores = NULL;

}
Restaurante::Restaurante(const Restaurante& r){//Tambien sirve para anyadirRestaurantes
	this->nombre = new char[strlen(r.nombre) +1];
	strcpy(this->nombre, r.nombre);
	this->direccion = new char[strlen(r.direccion) +1];
	strcpy(this->direccion, r.direccion);
	this->tipoComida = new char[strlen(r.tipoComida) +1];
	strcpy(this->tipoComida, r.tipoComida);
	this->telefono = r.telefono;
	this->menus = r.menus;
	this->numMesas = r.numMesas;
	this->trabajadores = r.trabajadores;
}
Restaurante::~Restaurante(){//Tambien sirve para eliminarRestaurantes
	delete[]this->nombre;
	delete[]this->direccion;
	delete[]this->tipoComida;
	delete[]this->menus;
	delete[]this->trabajadores;
}
int Restaurante::getId()const{
	return this->id;
}
char* Restaurante::getNombre()const{
	return this->nombre;
}
char* Restaurante::getDireccion()const{
	return this->direccion;
}
char* Restaurante::getTipoComida()const{
	return this->tipoComida;
}
int Restaurante::getTelefono()const{
	return this->telefono;
}
Menu* Restaurante::getMenus()const{
	return this->menus;
}
int Restaurante::getNumMesas()const{
	return this->numMesas;
}
Trabajador* Restaurante::getTrabajadores()const{
	return this->trabajadores;
}
void Restaurante::setNombre(char* nombre){
	this->nombre = nombre;
}
void Restaurante::setDireccion(char* direccion){
	this->direccion = direccion;
}
void Restaurante::setMenus(Menu* menus){
	this->menus = menus;
}
void Restaurante::setNumMesas(int numMesas){
	this->numMesas = numMesas;
}
void Restaurante::setTelefono(int telefono){
	this->telefono = telefono;
}
void Restaurante::setTipoComida(char* tipoComida){
	this->tipoComida = tipoComida;
}
void Restaurante::setTrabajadores(Trabajador* trabajadores){
	this->trabajadores = trabajadores;
}
void Restaurante::imprimir(){
	cout<<"Id: "<<this->id<<endl;
	cout<<"Nombre: "<<this->nombre<<endl;
	cout<<"Direccion: "<<this->direccion<<endl;
	cout<<"Tipo de comida: "<<this->tipoComida<<endl;
	cout<<"Telefono: "<<this->telefono<<endl;
	cout<<"Menus: "<<this->menus<<endl;
	cout<<"Numero de mesas: "<<this->numMesas<<endl;
	cout<<"Trabajadores: "<<this->trabajadores<<endl;
}
