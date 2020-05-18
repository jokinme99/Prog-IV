/*
 * metodoDB.cpp
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */

#include "Reserva.h"
#include <iostream>
#include "sqlite3.h"
#include <stdlib.h>
#include <string.h>
using namespace std;

int crearReserva(sqlite3 *db, char usuario, int restaurante, int dia,
		int hora) {

	sqlite3_stmt *stmt;	//crear stmt

	char sql[] = "SELECT * FROM RESTAURANTE WHERE NOMBRE_RESTAURANTE = ?";

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		return rc;
	}

	rc = sqlite3_bind_text(stmt, 1, busquedaRestaurante,
			strlen(busquedaRestaurante), SQLITE_STATIC);
	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}

	/* Execute SQL statement */
	char usuario[20];
	int restaurante;
	int dia;
	int hora;

	do {
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			strcpy(id, (char*) sqlite3_column_text(stmt, 0));

		}
	} while (rc == SQLITE_ROW);

	rc = sqlite3_finalize(stmt);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(SELECT)" << endl;

		return rc;
	}

	cout << "Busqueda completada" << endl;

	return SQLITE_OK;

}

