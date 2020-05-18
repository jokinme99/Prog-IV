/*
 * Reserva.h
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */

#ifndef RESERVA_H_
#define RESERVA_H_

class Reserva
{
	private:

		int idReserva;
		int hora;
		int dia;
		int numMesa;
		char* usuario[20];

	public:

		Reserva();
		Reserva(const int, int, int, int,char*);
		Reserva(const Reserva&);
		~Reserva();

		int getIdReserva()const;
		void setIdReserva(const int);
		int getHora()const;
		void setHora(int);
		int getDia()const;
		void setDia(int);
		int getNumMesa()const;
		void setNumMesa(int);
		char* getUsuario()const;
		void setUsuario(char*);
};



#endif /* RESERVA_H_ */
