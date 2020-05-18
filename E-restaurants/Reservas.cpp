/*
 * Reservas.cpp
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */
#include "Reserva.h"
#include <stdlib.h>
#include <iostream>

Reserva::Reserva()
{
	this->idReserva = 0;
	this->hora = 00;
	this->dia = 0;
	this->idMesa = 0;

}

Reserva::Reserva(const int idReserva, int hora, int dia, int idMesa)
{
	this->idReserva = idReserva;
	this->hora = hora;
	this->dia = dia;
	this->idMesa = idMesa;
}

Reserva::Reserva(const Reserva& r)
{
	this->idReserva = r.idReserva;
	this->hora = r.hora;
	this->dia = r.dia;
	this->idMesa = r.idMesa;
}

Reserva::~Reserva()
{

}

int Reserva::getIdReserva()const
{
	return this->idReserva;
}

void Reserva::setIdReserva(int idReserva)
{
	this->idReserva = idReserva;
}

int Reserva::getHora()const
{
	return this->hora;
}
void Reserva::setHora(int hora)
{
	this->hora = hora;
}

int Reserva::getDia()const
{
	return this->dia;
}
void Reserva::setDia(int dia)
{
	this->dia = dia;
}

int Reserva::getIdMesa()const
{
	return this->idMesa;
}
void Reserva::setIdMesa(int idMesa)
{
	this->idMesa = idMesa;
}
