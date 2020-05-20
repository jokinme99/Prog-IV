/*
 * metodoDB.h
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */

#include <sqlite3.h>
#include "sqlite3.h"
#ifndef METODODB_H_
#define METODODB_H_

int crearReserva(sqlite3 *db, char usuario[20], int restaurante, int dia, int hora);








#endif /* METODODB_H_ */
