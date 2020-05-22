/*
 * metodoDB.h
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */


#include "sqlite3.h"
#ifndef METODODB_H_
#define METODODB_H_
#include <sqlite3.h>

int crearReserva(sqlite3 *db, char usuario[20], int restaurante, int dia, int hora);
int seleccionarReserva(sqlite3 *db, char usuario[20]);
int modificarReserva(sqlite3 *db, int idReserva, int dia, int hora);
int eliminarReserva(sqlite3 *db, char usuario[20]);
int verReserva(sqlite3 *db, char usuario[20]);









#endif /* METODODB_H_ */
