/*
 * metodoDB.cpp
 *
 *  Created on: 18 may. 2020
 *      Author: AITOR
 */

#include "Reserva.h"
#include <iostream>
#include "sqlite3.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include"metodoDB.h"
using namespace std;

int crearReserva(sqlite3 *db, char usuario[20], int restaurante, int dia,
		int hora) {

	Reserva r;
	int numMesa;
	char nomRestaurante[20];
	int idMesa;

	sqlite3_stmt *stmt;	//crear stmt

	char sql[] =
			"SELECT R.NOMBRE_RESTAURANTE, M.NUMERO_MESA, M.ID_MESA FROM RESTAURANTE R, MESA M WHERE R.ID_RESTAURANTE = ? AND R.ID_RESTAURANTE = M.ID_RESTAURANTE AND M.MESA_OCUPADA = '0'";

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error al hacer la sentencia (SELECT)" << endl;
		return rc;
	}

	rc = sqlite3_bind_int(stmt, 1, restaurante);

	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}
	//Execute SQL statement

	do {
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			strcpy(nomRestaurante, (char*) sqlite3_column_text(stmt, 0));
			numMesa = sqlite3_column_int(stmt, 1);
			idMesa = sqlite3_column_int(stmt, 2);
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

	//cout << "Select realizado con exito" << endl;

	sqlite3_stmt *stmt2;	//crear stmt

	char sql2[] =
			"INSERT INTO RESERVA (HORA, DIA, ID_MESA, USUARIO, NUMERO_MESA) VALUES (?, ?, ?, ?, ?) ";

	rc = sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error al hacer la sentencia (INSERT)" << endl;
		printf("%s\n", sqlite3_errmsg(db));
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

	//Execute SQL statement

	rc = sqlite3_step(stmt2);
	if (rc == SQLITE_DONE) {

	}

	rc = sqlite3_finalize(stmt2);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(INSERT)" << endl;
		printf("%s\n", sqlite3_errmsg(db));

		return rc;
	}
	//trabajando en ello

	sqlite3_stmt *stmt3;	//crear stmt

	char sql3[] = "UPDATE MESA SET MESA_OCUPADA = '1' WHERE ID_MESA = ?";

	rc = sqlite3_prepare_v2(db, sql3, -1, &stmt3, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error preparing statement (UPDATE)" << endl;
		printf("%s\n", sqlite3_errmsg(db));
		return rc;
	}

	rc = sqlite3_bind_int(stmt3, 1, idMesa);
	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(UPDATE)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}

	//Execute SQL statement

	rc = sqlite3_step(stmt3);
	if (rc == SQLITE_DONE) {

	}

	rc = sqlite3_finalize(stmt3);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(UPDATE)" << endl;
		printf("%s\n", sqlite3_errmsg(db));

		return rc;
	}

	//trabajando en ello
	//cout << "Insert realizado con exito" << endl;

	cout << "Su reserva se ha realizado con exito" << endl;
	cout << "Los datos de la reserva son los siguientes:" << endl;
	cout << "Restaurante: " << nomRestaurante << " Dia: " << r.getDia()
			<< " Hora: " << r.getHora() << " Mesa: " << numMesa << endl;

	return SQLITE_OK;

}

int seleccionarReserva(sqlite3 *db, char usuario[20]) {

	int horaReserva;
	int diaReserva;
	int idReserva;

	sqlite3_stmt *stmt;	//crear stmt

	char sql[] = "SELECT ID_RESERVA, HORA, DIA FROM RESERVA WHERE USUARIO = ?";

	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cout << "Error al hacer la sentencia (SELECT)" << endl;
		return rc;
	}

	rc = sqlite3_bind_text(stmt, 1, usuario, strlen(usuario), SQLITE_STATIC);

	if (rc != SQLITE_OK) {
		cout << "Error al bindear la consulta(SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return rc;
	}

	cout << "Los datos de la reserva son los siguientes:" << endl;
	do {
		rc = sqlite3_step(stmt);
		if (rc == SQLITE_ROW) {
			idReserva = sqlite3_column_int(stmt, 0);
			horaReserva = sqlite3_column_int(stmt, 1);
			diaReserva = sqlite3_column_int(stmt, 2);

			cout << "Usuario de la reserva: " << usuario << " Id Reserva: "
					<< idReserva << " Dia: " << diaReserva << " Hora: "
					<< horaReserva << endl;

		}
	} while (rc == SQLITE_ROW);

	rc = sqlite3_finalize(stmt);
	if (rc != SQLITE_OK) {
		cout << "Error al finalizar la consulta(SELECT)" << endl;

		return rc;
	}



	int seleccionId;
	int diaReserva2;
	int horaReserva2;
	cout <<"Seleccione el id de la reserva que desea modificar"<<endl;
	cin >> seleccionId;
	cout << "Introduzca la nueva fecha deseada:"<<endl;
	cin >> diaReserva2;
	cout << "Introduzca la nueva hora deseada:"<<endl;
	cout <<"1. 13:00"<<endl;
	cout <<"2. 14:00"<<endl;
	cin >> horaReserva2;

	rc = sqlite3_close(db);
	if (rc != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
		return rc;
	}
	sqlite3 *db2;
	rc = sqlite3_open("e-restaurants.db", &db2);	//abrir base de datos
	if (rc != SQLITE_OK) {
		cout << "Error opening database" << endl;
		return rc;
	}

	sqlite3_stmt *stmt2;

	char sql2[] = "UPDATE RESERVA SET DIA = ?, HORA = ? WHERE ID_RESERVA = ?";

		rc = sqlite3_prepare_v2(db2, sql2, -1, &stmt2, NULL);
		if (rc != SQLITE_OK) {
			cout << "Error al hacer la sentencia (SELECT)" << endl;
			return rc;
		}

		rc = sqlite3_bind_int(stmt2, 1, diaReserva2);
		rc = sqlite3_bind_int(stmt2, 2, horaReserva2);
		rc = sqlite3_bind_int(stmt2, 3, seleccionId);

		if (rc != SQLITE_OK) {
			cout << "Error al bindear la consulta(SELECT)" << endl;
			cout << sqlite3_errmsg(db2) << endl;

			return rc;
		}

		rc = sqlite3_step(stmt2);
				if (rc == SQLITE_DONE) {


				}

				rc = sqlite3_finalize(stmt2);
					if (rc != SQLITE_OK) {
						cout << "Error al hacer la modificacion" << endl;

						return rc;
					}




		cout<<"La reserva se ha modificado: "<<endl;

		cout << "Usuario de la reserva: " << usuario << " Id Reserva: "<< seleccionId << " Dia: " << diaReserva2 << " Hora: "<< horaReserva2 << endl;

		system("pause");







	return SQLITE_OK;

}

int eliminarReserva(sqlite3 *db, char usuario[20]){

	int horaReserva;
		int diaReserva;
		int idReserva;

		sqlite3_stmt *stmt;	//crear stmt

		char sql[] = "SELECT ID_RESERVA, HORA, DIA FROM RESERVA WHERE USUARIO = ?";

		int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			cout << "Error al hacer la sentencia (SELECT)" << endl;
			return rc;
		}

		rc = sqlite3_bind_text(stmt, 1, usuario, strlen(usuario), SQLITE_STATIC);

		if (rc != SQLITE_OK) {
			cout << "Error al bindear la consulta(SELECT)" << endl;
			cout << sqlite3_errmsg(db) << endl;

			return rc;
		}

		cout << "Sus reservas son las siguientes:" << endl;
		do {
			rc = sqlite3_step(stmt);
			if (rc == SQLITE_ROW) {
				idReserva = sqlite3_column_int(stmt, 0);
				horaReserva = sqlite3_column_int(stmt, 1);
				diaReserva = sqlite3_column_int(stmt, 2);

				cout << "Usuario de la reserva: " << usuario << " Id Reserva: "
						<< idReserva << " Dia: " << diaReserva << " Hora: "
						<< horaReserva << endl;

			}
		} while (rc == SQLITE_ROW);

		rc = sqlite3_finalize(stmt);
		if (rc != SQLITE_OK) {
			cout << "Error al finalizar la consulta(SELECT)" << endl;

			return rc;
		}



			int seleccionId;

			cout <<"Seleccione el id de la reserva que desea eliminar"<<endl;
			cin >> seleccionId;

			rc = sqlite3_close(db);
			if (rc != SQLITE_OK) {
				printf("Error closing database\n");
				printf("%s\n", sqlite3_errmsg(db));
				return rc;
			}
			sqlite3 *db2;
			rc = sqlite3_open("e-restaurants.db", &db2);	//abrir base de datos
			if (rc != SQLITE_OK) {
				cout << "Error opening database" << endl;
				return rc;
			}

			sqlite3_stmt *stmt2;

			char sql2[] = "DELETE FROM RESERVA WHERE ID_RESERVA = ?";

				rc = sqlite3_prepare_v2(db2, sql2, -1, &stmt2, NULL);
				if (rc != SQLITE_OK) {
					cout << "Error al hacer la sentencia (SELECT)" << endl;
					return rc;
				}
				rc = sqlite3_bind_int(stmt2, 1, seleccionId);

				if (rc != SQLITE_OK) {
					cout << "Error al bindear la consulta(SELECT)" << endl;
					cout << sqlite3_errmsg(db2) << endl;

					return rc;
				}

				rc = sqlite3_step(stmt2);
						if (rc == SQLITE_DONE) {


						}

						rc = sqlite3_finalize(stmt2);
							if (rc != SQLITE_OK) {
								cout << "Error al eliminar" << endl;

								return rc;
							}




				cout<<"La reserva se ha eliminado correctamente "<<endl;



				system("pause");







			return SQLITE_OK;

		}









