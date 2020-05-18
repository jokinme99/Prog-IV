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
		int idMesa;

	public:

		Reserva();
		Reserva(const int, int, int, int);
		Reserva(const Reserva&);
		~Reserva();

		int getIdReserva()const;
		void setIdReserva(const int);
		int getHora()const;
		void setHora(int);
		int getDia()const;
		void setDia(int);
		int getIdMesa()const;
		void setIdMesa(int);
};



#endif /* RESERVA_H_ */
