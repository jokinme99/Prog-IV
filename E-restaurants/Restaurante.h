/*
 * GestionRestaurantes.h
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_
#include "Menu.h"
#include "Trabajador.h"
#include "Producto.h"
class Restaurante
{
	static int id;//id del restaurante
	char* nombre;//nombre del restaurante
	char* direccion;
	char* tipoComida;
	int telefono;
	Menu* menus;
	int numMesas;//mesas disponibles
	Trabajador* trabajadores;
public:
	Restaurante(char* nombre, char* direccion, char* tipoComida, int telefono, Menu* menus, int numMesas,Trabajador* trabajadores);//tambien para anyadirArticulo
	Restaurante();
	Restaurante(const Restaurante& r);
	~Restaurante();//destructor

	int getId() const;
	char* getNombre()const;
	char* getDireccion() const;
	char* getTipoComida()const;
	int getTelefono()const;
	Menu* getMenus()const;
	int getNumMesas()const;
	Trabajador* getTrabajadores()const;

	void setNombre(char* nombre);
	void setDireccion(char* direccion);
	void setTipoComida(char* tipoComida);
	void setTelefono(int telefono);
	void setMenus(Menu* menus);
	void setNumMesas(int numMesas);
	void setTrabajadores(Trabajador* trabajadores);
	void imprimir();

};




#endif /* RESTAURANTE_H_ */
