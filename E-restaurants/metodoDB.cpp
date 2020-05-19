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
#include"metodoDB.h"
using namespace std;

int crearReserva(sqlite3 *db, char usuario[20], int restaurante, int dia,
		int hora) {

	Reserva r;
	int numMesa;
	char nomRestaurante [20];
	int idMesa;

	sqlite3_stmt *stmt;	//crear stmt

	char sql[] =
			"SELECT R.NOMBRE_RESTAURANTE, M.NUMERO_MESA, M.ID_MESA FROM RESTAURANTE R, MESA M WHERE R.ID_RESTAURANTE = ? AND R.ID_RESTAURANTE = M.ID_RESTAURANTE AND M.MESA_OCUPADA = '0'";

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		return rc;
	}

	rc = sqlite3_bind_int(stmt, 1, restaurante);

	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}

	/* Execute SQL statement */

	do {
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			strcpy(nomRestaurante, (char*) sqlite3_column_text(stmt, 0));
			numMesa = sqlite3_colum_int(stmt, 1);
			idMesa = sqlite3_colum_int(stmt, 2);
			r.setDia(dia);
			r.setHora(hora);
			r.setNumMesa(numMesa);
			r.setUsuario(usuario);

		}
	} while (rc == SQLITE_ROW);

	rc = sqlite3_finalize(stmt);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(SELECT)" << endl;

		return rc;
	}

	cout<<"Select realizado con exito"<<endl;

	return SQLITE_OK;

	sqlite3_stmt *stmt2;	//crear stmt

	char sql2[] =
			"INSERT INTO RESERVA (HORA, DIA, ID_MESA, USUARIO, NUMERO_MESA) VALUES (?, ?, ?, ?, ?) ";

	int rc = sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		return rc;
	}

	rc = sqlite3_bind_int(stmt2, 1, hora);
	rc = sqlite3_bind_int(stmt2, 2, dia);
	rc = sqlite3_bind_int(stmt2, 3, idMesa);
	rc = sqlite3_bind_text(stmt2, 4, usuario, strlen(usuario), SQLITE_STATIC);
	rc = sqlite3_bind_int(stmt2, 5, numMesa);
	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}

	/* Execute SQL statement */

	do {
		rc = sqlite3_step(stmt2);
		if (rc == SQLITE_ROW) {

		}
	} while (rc == SQLITE_ROW);

	rc = sqlite3_finalize(stmt2);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(INSERT)" << endl;

		return rc;
	}

	cout<<"Insert realizado con exito"<<endl;

	cout<<"Su reserva se ha realizado con exito"<<endl;
	cout<<"Los datos de la reserva son los siguientes:"<<endl;
	cout<<"Restaurante: "<<nomRestaurante<<" Dia: "<<r.getDia<<" Hora: "<<r.getHora<<" Mesa: "<<r.getNumMesa<<endl;
	return SQLITE_OK;

}

