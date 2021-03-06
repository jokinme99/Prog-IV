/*
 * Main.cpp
 *
 *  Created on: 8 may. 2020
 *      Author: jokin
 */

//Para poder crear un ejecutable es necesario utilizar los siguientes comandos:
//g++ main.cpp reserva.cpp metodoDB.cpp sqlite3.dll -o prueba.exe
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Restaurante.h"
#include <cstdlib>
#include <fstream>
#include "Producto.h"
#include "Menu.h"
#include <stdio.h>
#include <windows.h>
#include "Reserva.h"
#include "metodoDB.h"
#include "sqlite3.h"
#define USUARIO "usuario"
#define CONTRA "usuario"
#include <sqlite3.h>


using namespace std;
int salir, opcionAdmin, opcionUsuario, op;
string nombreAdmin;
string contraAdmin;
string linea;
string no;
string co;
string parte;
string nombreUsuario;
string contraUsuario;
int con = 0;
int opUsu;
int opcionAdminMenu1;
int busquedaMenu;
char *busqueda;
int opcionAdminMenu2;
int opcionAdminMenu3;
int opcionAdminMenu4;
int opcionAdminMenu5;
int opcionClienteMenu;
void adminMenu();
void inicio();
void adminMenu1();
void adminMenu2();
void adminMenu3();
void adminMenu4();
void adminMenu5();
void adminMenu6();
void admin();
void adminCaso1();
void adminCaso2();
void clienteMenu();
void clienteCaso1();
void clienteCaso2();
void cliente();
int menuReserva();
int verReserva();
int seleccionarReserva();
int menuModificar();
int menuEliminar();
int menuVerReserva();

static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*) data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}
sqlite3 *db;
char *zErrMsg = 0;
int rc;
char *sql;
const char *data = "Callback function called";
void adminMenu1() {
	do {
		cout << "1. Restaurantes" << endl;
		cout << "2. Productos" << endl;
		cout << "3. Menus" << endl;
		cout << "4. Trabajadores" << endl;
		cout << "5. Que productos tiene cada menu" << endl;
		cout << "6. Que menus tiene cada restaurante" << endl;
		cout << "7. Que trabajadores tiene cada restaurante" << endl;
		cout << "8. Volver atras" << endl;
		cin >> opcionAdminMenu1;
	} while (opcionAdminMenu1 != 1 && opcionAdminMenu1 != 2
			&& opcionAdminMenu1 != 3 && opcionAdminMenu1 != 4
			&& opcionAdminMenu1 != 5 && opcionAdminMenu1 != 6
			&& opcionAdminMenu1 != 7 && opcionAdminMenu1 != 8);
	/* ABRIMOS BASE DE DATOS */
	rc = sqlite3_open("e-restaurants.db", &db);
	switch (opcionAdminMenu1) {
	case 1: {

		/* Create SQL statement */
		sql = "SELECT * from RESTAURANTE";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();
	}
		break;
	case 2: {
		/* Create SQL statement */
		sql = "SELECT * from PRODUCTO";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();
	}
		break;
	case 3: {
		/* Create SQL statement */
		sql = "SELECT * from MENU";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();
	}
		break;
	case 4: {
		/* Create SQL statement */
		sql = "SELECT * from TRABAJADOR";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();
	}
		break;
	case 5: {
		/* Create SQL statement */
		sql = "SELECT * from MENU_TIENE_PRODUCTOS";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();
	}
		break;
	case 6: {
		/* Create SQL statement */
		sql = "SELECT * from RESTAURANTE_TIENE_MENUS";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();

	}
		break;
	case 7: {
		/* Create SQL statement */
		sql = "SELECT * from RESTAURANTE_TIENE_TRABAJADORES";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu1();

	}
		break;
	case 8: {
		adminMenu();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto" << endl;
		adminMenu1();
	}
		break;
	}
}
void adminMenu2() {

	do {
		cout << "1. Restaurantes" << endl;
		cout << "2. Productos" << endl;
		cout << "3. Menus" << endl;
		cout << "4. Trabajadores" << endl;
		cout << "5. Que productos tiene cada menu" << endl;
		cout << "6. Que menus tiene cada restaurante" << endl;
		cout << "7. Que trabajadores tiene cada restaurante" << endl;
		cout << "8. Volver atras" << endl;
		cin >> opcionAdminMenu2;
	} while (opcionAdminMenu2 != 1 && opcionAdminMenu2 != 2
			&& opcionAdminMenu2 != 3 && opcionAdminMenu2 != 4
			&& opcionAdminMenu2 != 5 && opcionAdminMenu2 != 6
			&& opcionAdminMenu2 != 7 && opcionAdminMenu2 != 8);
	rc = sqlite3_open("e-restaurants.db", &db);
	switch (opcionAdminMenu2) {
	case 1: {

		char nom[100];
		cout << "Ingrese el nombre del restaurante que desea buscar" << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from RESTAURANTE WHERE NOMBRE_RESTAURANTE = '";

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 2: {

		char nom[100];
		cout << "Ingrese el nombre del producto que desea buscar" << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from PRODUCTO WHERE NOMBRE_PRODUCTO = '"; //+ busqueda;

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 3: {

		char nom[100];
		cout << "Ingrese el numero del menu que desea buscar" << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from MENU WHERE ID_MENU = "; // + busquedaMenu;

		strcat(sql, nom);

		char fr2[] = "";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 4: {
		char nom[100];
		cout << "Ingrese el nombre del trabajador que desea buscar" << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from TRABAJADOR WHERE NOMBRE_TRABAJADOR = '";

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 5: {
		char nom[100];
		cout
				<< "Ingrese el numero de menu que desea buscar, para ver que productos contiene"
				<< endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from MENU_TIENE_PRODUCTOS WHERE ID_MENU = ";

		strcat(sql, nom);

		char fr2[] = "";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();

	}
		break;
	case 6: {
		char nom[100];
		cout
				<< "Ingrese el numero de menu que desea buscar, para ver en que restaurantes hay ese menu"
				<< endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "SELECT * from RESTAURANTE_TIENE_MENUS WHERE ID_MENU = ";

		strcat(sql, nom);

		char fr2[] = "";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 7: {
		char nom[100];
		cout
				<< "Ingrese el id de restaurante que desea buscar, para ver que trabajadores contiene"
				<< endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] =
				"SELECT * from RESTAURANTE_TIENE_TRABAJADORES WHERE ID_RESTAURANTE = ";

		strcat(sql, nom);

		char fr2[] = "";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu2();
	}
		break;
	case 8: {
		adminMenu();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto" << endl;
		adminMenu2();
	}
		break;
	}

}
void adminMenu3() {
	string nomMod;
	int canMesas;
	float dinero;
	do {
		cout << "1. Modificar numero de mesas de restaurante" << endl;
		cout << "2. Modificar precio de menu" << endl;
		cout << "3. Modificar sueldo de trabajadores" << endl;
		cout << "4. Modificar precio de producto" << endl;
		cout << "5. Volver atras" << endl;
		cin >> opcionAdminMenu3;
	} while (opcionAdminMenu3 != 1 && opcionAdminMenu3 != 2
			&& opcionAdminMenu3 != 3 && opcionAdminMenu3 != 4
			&& opcionAdminMenu3 != 5);
	rc = sqlite3_open("e-restaurants.db", &db);
	switch (opcionAdminMenu3) {
	//Este m�todo no hemos conseguido implementarlo correctamente del todo
	case 1: {
		//No ejecuta bien pero la sentencia te la crea bien!
		char n_re[100], nu_me[100];
		cout << "Ingrese el nombre del restaurante que desea modificar" << endl;
		cin >> n_re;
		cout << endl;
		cout << "Ingrese la cantidad de mensas que desea modificar" << endl;
		cin >> nu_me;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "UPDATE RESTAURANTE set NUM_MESAS = ";// + canMesas + "WHERE NOMBRE_RESTAURANTE = " + nomMod;
		char fra[] = "WHERE NOMBRE_RESTAURANTE = '";

		char con1[] = "'", con2[] = "'" , con3[] = ")", con4[] ="", con5[]="'", con6[]="'", con7[] ="'", con8[]=" ";

		strcat(sql, nu_me);
		strcat(sql, con8);
		strcat(sql, fra);
		strcat(sql, n_re);
		strcat(sql, con2);


		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu3();
	}
		break;
	case 2: {
		char numero_m[100], prec_m[100];
		cout << "Ingrese el numero del menu que desea modificar" << endl;
		cin >> numero_m;
		cout << endl;
		cout << "Ingrese el precio del menu que desea modificar" << endl;
		cin >> prec_m;
		cout << endl;

		/* Create SQL statement */

		char sql[] = "UPDATE MENU set PRECIO_MENU = ";
		char fra[] = "WHERE ID_MENU = ";


		char con1[] = "'", con2[] = "'" , con3[] = ")", con4[] ="", con5[]="'", con6[]="'", con7[] ="'", con8[]=" ";
		strcat(sql, prec_m);
		strcat(sql, con8);
		strcat(sql, fra);
		strcat(sql, numero_m);
		strcat(sql, con4);


		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu3();
	}
		break;
		//Este m�todo no hemos conseguido implementarlo correctamente del todo
	case 3: {
		//No ejecuta bien pero la sentencia te la crea bien!
		char nom_trab[100], suel_trab[100];
		cout << "Ingrese el nombre del trabajador que desea modificar" << endl;
		cin >> nom_trab;
		cout << endl;
		cout << "Ingrese el sueldo del trabajador que desea modificar" << endl;
		cin >> suel_trab;
		cout << endl;

		/* Create SQL statement */

		char sql[] = "UPDATE TRABAJADOR set SUELDO = ";
		char fra[] = "WHERE ID_TRABAJADOR = ";


		char con1[] = "'", con2[] = "'" , con3[] = ")", con4[] ="", con5[]="'", con6[]="'", con7[] ="'", con8[]=" ";

		strcat(sql, suel_trab);
		strcat(sql, con8);
		strcat(sql, fra);
		strcat(sql, nom_trab);
		strcat(sql, con4);




		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu3();
	}
		break;
	case 4: {
		char nom_prod[100], prec_prod[100];
		cout << "Ingrese el nombre del producto que desea modificar" << endl;
		cin >> nom_prod;
		cout << endl;
		cout << "Ingrese el precio del producto que desea modificar" << endl;
		cin >> prec_prod;
		cout << endl;

		/* Create SQL statement */


		char sql[] = "UPDATE PRODUCTO set PRECIO = ";
		char fra[] = "WHERE NOMBRE_PRODUCTO = '";


		char con1[] = "'", con2[] = "'" , con3[] = ")", con4[] ="", con5[]="'", con6[]="'", con7[] ="'", con8[]=" ";
		strcat(sql, prec_prod);
		strcat(sql, con8);
		strcat(sql, fra);
		strcat(sql, nom_prod);
		strcat(sql, con2);
		strcat(sql, con4);


		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu3();
	}
		break;
	case 5: {
		adminMenu();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto" << endl;
		adminMenu3();
	}
		break;
	}
}
void adminMenu4() {
	int id, telefono, numMesa, id1;
	string nombre, direccion, tipoComida, dni;
	float sueldo, precio;
	do {
		cout << "1. Restaurante" << endl;
		cout << "2. Menu" << endl;
		cout << "3. Producto" << endl;
		cout << "4. Trabajador" << endl;
		cout << "5. Producto en menu" << endl;
		cout << "6. Menu en restaurante" << endl;
		cout << "7. Trabajador en restaurante" << endl;
		cout << "8. Volver atras" << endl;
		cin >> opcionAdminMenu4;
	} while (opcionAdminMenu4 != 1 && opcionAdminMenu4 != 2
			&& opcionAdminMenu4 != 3 && opcionAdminMenu4 != 4
			&& opcionAdminMenu4 != 5 && opcionAdminMenu4 != 6
			&& opcionAdminMenu4 != 7 && opcionAdminMenu4 != 8);
	rc = sqlite3_open("e-restaurants.db", &db);
	switch (opcionAdminMenu4) {
	case 1: {
		char id_res[100], nom_res[100], dir_res[100], tipo_com[100], //a
				tel_res[100], num_mesas[100];
		cout << "Ingrese el id del restaurante que desea anyadir: ";
		cin >> id_res;
		cout << endl;
		cout << "Ingrese el nombre del restaurante que desea anyadir: ";
		cin >> nom_res;
		cout << endl;
		cout << "Ingrese el direccion del restaurante que desea anyadir: ";
		cin >> dir_res;
		cout << endl;
		cout << "Ingrese el tipo de comida del restaurante que desea anyadir: ";
		cin >> tipo_com;
		cout << endl;
		cout << "Ingrese el telefono del restaurante que desea anyadir: ";
		cin >> tel_res;
		cout << endl;
		cout
				<< "Ingrese el numero de mesas del restaurante que desea anyadir: ";
		cin >> num_mesas;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO RESTAURANTE VALUES (";

		char con1[] = ",", con2[] = "'", con3[] = "'", con4[] = ",", con5[] =
				"'", con6[] = "'", con7[] = ",", con8[] = "'", con9[] = "'",
				con10[] = ",", con11[] = ",", con12[] = "'", con13[] = ")",
				con14[] = "'", con15[] = "";

		strcat(sql, id_res);
		strcat(sql, con1);
		strcat(sql, con2);
		strcat(sql, nom_res);
		strcat(sql, con3);
		strcat(sql, con4);
		strcat(sql, con5);
		strcat(sql, dir_res);
		strcat(sql, con6);
		strcat(sql, con7);
		strcat(sql, con8);
		strcat(sql, tipo_com);
		strcat(sql, con9);
		strcat(sql, con10);
		strcat(sql, tel_res);
		strcat(sql, con11);
		strcat(sql, num_mesas);
		strcat(sql, con13);
		strcat(sql, con15);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();
	}
		break;
	case 2: {
		char id_men[100], pre_men[100];
		cout << "Ingrese el id del menu que desea anyadir: ";
		cin >> id_men;
		cout << endl;
		cout << "Ingrese el precio del menu que desea anyadir: ";
		cin >> pre_men;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO MENU VALUES (";

		char con1[] = ",", con2[] = ")", con3[] = "";

		strcat(sql, id_men);
		strcat(sql, con1);
		strcat(sql, pre_men);
		strcat(sql, con2);
		strcat(sql, con3);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();
	}
		break;
	case 3: {
		char id_prod[100], nom_prod[100], des_prod[100], prec_prod[100];
		cout << "Ingrese el id del producto que desea anyadir: ";
		cin >> id_prod;
		cout << endl;
		cout << "Ingrese el nombre del producto que desea anyadir: ";
		cin >> nom_prod;
		cout << endl;
		cout << "Ingrese la descripcion del restaurante que desea anyadir: ";
		cin >> des_prod;
		cout << endl;
		cout << "Ingrese el precio del producto que desea anyadir: ";
		cin >> prec_prod;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO PRODUCTO VALUES (";

		char con1[] = ",", con2[] = "'", con3[] = "'", con4[] = ",", con5[] =
				"'", con6[] = "'", con7[] = ",", con8[] = ")", con9[] = "";

		strcat(sql, id_prod);
		strcat(sql, con1);
		strcat(sql, con2);
		strcat(sql, nom_prod);
		strcat(sql, con3);
		strcat(sql, con4);
		strcat(sql, con5);
		strcat(sql, des_prod);
		strcat(sql, con6);
		strcat(sql, con7);
		strcat(sql, prec_prod);
		strcat(sql, con8);
		strcat(sql, con9);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();

	}
		break;
	case 4: {

		char id_tra[100], nom_tra[100], dni_tra[100], suel_tra[100];
		cout << "Ingrese el id del trabajador que desea anyadir: ";
		cin >> id_tra;
		cout << endl;
		cout << "Ingrese el nombre del trabajador que desea anyadir: ";
		cin >> nom_tra;
		cout << endl;
		cout << "Ingrese el dni del trabajador que desea anyadir: ";
		cin >> dni_tra;
		cout << endl;
		cout << "Ingrese el sueldo del trabajador que desea anyadir: ";
		cin >> suel_tra;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO TRABAJADOR VALUES (";

		char con1[] = ",", con2[] = "'", con3[] = "'", con4[] = ",", con5[] =
				"'", con6[] = "'", con7[] = ",", con8[] = ")", con9[] = "";

		strcat(sql, id_tra);
		strcat(sql, con1);
		strcat(sql, con2);
		strcat(sql, nom_tra);
		strcat(sql, con3);
		strcat(sql, con4);
		strcat(sql, con5);
		strcat(sql, dni_tra);
		strcat(sql, con6);
		strcat(sql, con7);
		strcat(sql, suel_tra);
		strcat(sql, con8);
		strcat(sql, con9);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();
	}
		break;
	case 5: {

		char id_m[100], id_p[100];
		cout << "Ingrese el id del menu que desea anyadir: ";
		cin >> id_m;
		cout << endl;
		cout << "Ingrese el id del producto que desea anyadir: ";
		cin >> id_p;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO MENU_TIENE_PRODUCTOS VALUES (";

		char con1[] = ",", con2[] = ")", con3[] = "";

		strcat(sql, id_m);
		strcat(sql, con1);
		strcat(sql, id_p);
		strcat(sql, con2);
		strcat(sql, con3);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();

	}
		break;
	case 6: {
		char id_me[100], id_re[100];
		cout << "Ingrese el id del menu que desea anyadir: ";
		cin >> id_me;
		cout << endl;
		cout << "Ingrese el id del restaurante que desea anyadir: ";
		cin >> id_re;
		cout << endl;
		//id de producto se asigna solo, autoIncremental

		/* Create SQL statement */
		char sql[] = "INSERT INTO RESTAURANTE_TIENE_MENUS VALUES (";

		char con1[] = ",", con2[] = ")", con3[] = "";

		strcat(sql, id_me);
		strcat(sql, con1);
		strcat(sql, id_re);
		strcat(sql, con2);
		strcat(sql, con3);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();
	}
		break;
	case 7: {
		char id_resta[100], id_trab[100];
		cout << "Ingrese el id del restaurante que desea anyadir: ";
		cin >> id_resta;
		cout << endl;
		cout << "Ingrese el id del trabajador que desea anyadir: ";
		cin >> id_trab;
		cout << endl;

		/* Create SQL statement */
		char sql[] = "INSERT INTO RESTAURANTE_TIENE_TRABAJADORES VALUES (";

		char con1[] = ",", con2[] = ")", con3[] = "";

		strcat(sql, id_resta);
		strcat(sql, con1);
		strcat(sql, id_trab);
		strcat(sql, con2);
		strcat(sql, con3);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu4();
	}
		break;
	case 8: {
		adminMenu();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto" << endl;
		adminMenu4();
	}
		break;
	}
}
void adminMenu5() {
	string nombreEliminar;
	int idEliminar;
	do {
		cout << "1. Restaurantes" << endl;
		cout << "2. Productos" << endl;
		cout << "3. Menus" << endl;
		cout << "4. Trabajadores" << endl;
		cout << "5. Volver atras" << endl;
		cin >> opcionAdminMenu5;
	} while (opcionAdminMenu5 != 1 && opcionAdminMenu5 != 2
			&& opcionAdminMenu5 != 3 && opcionAdminMenu5 != 4
			&& opcionAdminMenu5 != 5 && opcionAdminMenu5 != 6
			&& opcionAdminMenu5 != 7 && opcionAdminMenu5 != 8);
	/* ABRIMOS BASE DE DATOS */
	rc = sqlite3_open("e-restaurants.db", &db);
	switch (opcionAdminMenu5) {
	case 1: {
		char nom[100];
		cout << "Ingrese el nombre del restaurante que desea eliminar: "
				<< endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "DELETE from RESTAURANTE WHERE NOMBRE_RESTAURANTE = '";

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu5();
	}
		break;
	case 2: {
		char nom[100];
		cout << "Ingrese el nombre del producto que desea eliminar: " << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "DELETE from PRODUCTO WHERE NOMBRE_PRODUCTO = '";

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu5();
	}
		break;
	case 3: {
		char nom[100];
		cout << "Ingrese el numero del menu que desea eliminar: " << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "DELETE from MENU WHERE ID_MENU = ";

		strcat(sql, nom);

		char fr2[] = "";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu5();

	}
		break;
	case 4: {
		char nom[100];
		cout << "Ingrese el nombre del trabajador que desea eliminar: " << endl;
		cin >> nom;
		cout << endl;
		/* Create SQL statement */
		char sql[] = "DELETE from TRABAJADOR WHERE NOMBRE_TRABAJADOR = '";

		strcat(sql, nom);

		char fr2[] = "'";

		strcat(sql, fr2);

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*) data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Operation done successfully\n");
		}
		sqlite3_close(db);
		adminMenu5();
	}
		break;
	case 5: {
		adminMenu();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto" << endl;
		adminMenu5();

	}
		break;
	}
}
void adminMenu6() {
	inicio();
}

void adminMenu() {
	do {
		cout << "1. Ver " << endl;
		cout << "2. Buscar" << endl;
		cout << "3. Modificar" << endl;
		cout << "4. Anyadir" << endl;
		cout << "5. Eliminar" << endl;
		cout << "6. Cerrar sesion" << endl;
		cin >> opcionAdmin;
	} while (opcionAdmin != 1 && opcionAdmin != 2 && opcionAdmin != 3
			&& opcionAdmin != 4 && opcionAdmin != 5 && opcionAdmin != 6);
	switch (opcionAdmin) {
	case 1: {
		adminMenu1();
	}
		break;
	case 2: {
		adminMenu2();
	}
		break;
	case 3: {
		adminMenu3();
	}
		break;
	case 4: {
		adminMenu4();
	}
		break;
	case 5: {
		adminMenu5();
	}
		break;
	case 6: {
		admin();
	}
		break;
	default: {
		cout << "introduzca un valor correcto" << endl;
		adminMenu();
	}
		break;
	}
}

void adminCaso1() {

	cout << "Ingresa el nombre del admin: ";
	cin >> nombreAdmin;
	cout << endl;

	cout << "Ingresa la contrase�a del admin: ";
	cin >> contraAdmin;
	cout << endl;

	ofstream ofs("administradores.txt");

	ofs << nombreAdmin << "," << contraAdmin;

	ofs.close();

	cout << "Administrador creado correctamente" << endl;

}
void adminCaso2() {
	cout << "Ingresa el nombre del admin: ";
	cin >> nombreAdmin;
	cout << endl;

	cout << "Ingresa la contrasenya del admin: ";
	cin >> contraAdmin;
	cout << endl;

	ifstream ifs("administradores.txt");

	while (!ifs.eof()) {
		ifs >> linea;

		char separador = ',';
		for (size_t p = 0, q = 0; p != linea.npos; p = q) {
			parte = linea.substr(p + (p != 0),
					(q = linea.find(separador, p + 1)) - p - (p != 0));
			if (con == 0) {
				no = parte;
				//cout << "El nombre es: " << no << endl;
			} else if (con == 1) {
				co = parte;
				//cout << "La contra es: " << co << endl;
			} else {
				cout << "error";
			}
			con++;
		}

		ifs.close();

	}
	if (nombreAdmin == no && contraAdmin == co) {
		cout << "Nombre y contra introduccidos correctamente" << endl;
		cout << endl;
		cout << "---MODO ADMINISTRADOR---" << endl;
		adminMenu();
		//Contrasenya/usuario incorrecta
	} else {
		cout << "El nombre o la contra introduccidos son incorrectos" << endl;
		//adminCaso2();//Para introducir otra vez
		admin();
	}
}
void admin() {
	int op;
	do {
		cout << "1. Registrar administrador" << endl;
		cout << "2. Iniciar como administrador" << endl; //SOLO PUEDE HABER UN ADMIN
		cout << "3. VOLVER" << endl;
		cin >> op;
	} while (op != 1 && op != 2 && op != 3);
	switch (op) {
	case 1: {
		adminCaso1();
		admin();
	}
		break;
	case 2: { //Accedemos a admin
		adminCaso2();
	}
		break;
	case 3: {
		inicio();
	}
		break;
	default: {
		cout << "Introduzca un valor correcto";
	}
		break;
	}
}
void clienteMenu() {
	do {
		cout << "1. Crear Reserva" << endl;
		cout << "2. Modificar Reserva" << endl;
		cout << "3. Eliminar Reserva" << endl;
		cout << "4. Ver Reservas" << endl;
		cout << "5. Cerrar sesion" << endl;
		cin >> opcionClienteMenu;
	} while (opcionClienteMenu != 1 && opcionClienteMenu != 2
			&& opcionClienteMenu != 3 && opcionClienteMenu != 4
			&& opcionClienteMenu != 5);
	switch (opcionClienteMenu) {
	case 1: {
			menuReserva();
	}
		break;
	case 2: {
		menuModificar();
	}
		break;
	case 3: {
		menuEliminar();
	}
		break;
	case 4: {
		menuVerReserva();

			}

		break;
	case 5: {
			cliente();
				}

			break;
	default: {
		cout << "Introduzca un valor correcto";
		clienteMenu();
	}
		break;
	}
}
void clienteCaso1() {
	cout << "Ingresa el nombre del usuario: ";
	cin >> nombreUsuario;
	cout << endl;
	cout << "Ingresa la contrase�a del usuario: ";
	cin >> contraUsuario;
	cout << endl;
	ofstream ofs("usuarios.txt", ios::app);
	ofs << nombreUsuario << " " << contraUsuario << endl;
	ofs.close();
	cout << "Usuario creado correctamente" << endl;
	cliente();
}
void clienteCaso2() {
	//Accedemos al usuario
	ifstream ifs;
	ifs.open("usuarios.txt", ios::in);
	string nom, cont, nomAu, conAu;
	bool en = false;
	cout << "Ingrese el nombre del usuario: " << endl;
	cin >> nomAu;
	cout << "Ingrese la contra del usuario: " << endl;
	cin >> conAu;
	ifs >> nom;
	while (!ifs.eof() && !en) {
		ifs >> cont;
		if (nom == nomAu && cont == conAu) {
			cout << "Usuario y contrase�a correctos. Bienvenido " << nomAu
					<< endl;
			en = true;
			//parte del usuario
			cout << "---MODO USUARIO---" << endl;
			clienteMenu();
		}

		else if ((nom == nomAu && cont != conAu) || (nom != nomAu && cont == conAu)){
			cout << "El usuario y/o la contrase�a son incorrectos" << endl;
			cliente();
		}
		ifs >> nom;
	}
	ifs.close();

	if (!en) {
		cout << "Usuario NO encontrado" << endl;
		cliente();
	}

}
void cliente() {
	do {
		cout << "1. Registrar usuario" << endl;
		cout << "2. Iniciar sesion como usuario" << endl;
		cout << "3. Atras" << endl;
		cin >> opUsu;
	} while (opUsu != 1 && opUsu != 2 && opUsu != 3);
	switch (opUsu) {
	case 1: {
		clienteCaso1();
	}
		break;
	case 2: {
		clienteCaso2();
	}
		break;
	case 3: {
		inicio();
	}
		break;
	}
}
void inicio() {
	int opcion;
	do {
		cout << "-----BIENVENIDO A E-RESTAURANTS-----" << endl;
		cout << "1.Entrar como administrador" << endl;
		cout << "2.Entrar como usuario" << endl;
		cout << "3.Salir" << endl;
		cin >> opcion;
	} while (opcion != 1 && opcion != 2 && opcion != 3);

	switch (opcion) {
	case 1: {
		admin();
	}
		break;
	case 2: {
		cliente();
	}
		break;
	case 3: {
	}
		break;
	default: {
		cout << "Introduzca un valor correcto por favor" << endl;
		inicio();
	}
		break;
	}
}
int main() {
	inicio();
}

int menuReserva()
{
	char usuarioReserva[20];
	int seleccion;
	int seleccionDia;
	int seleccionHora;
	do
	{

	cout<<"Escriba su usuario para realizar la reserva:"<<endl;
	cin >> usuarioReserva;
	cout<<"En que restaurante desea hacer la reserva:"<<endl<<endl;
	cout<<"1.LaTabernaDeSanti"<< endl;
	cout<<"2.JosebarenEtxea"<< endl;
	cout<<"3.HerriHarmaila"<< endl;
	cout<<"4.Josefa"<< endl;
	cout<<"5.Atras"<< endl;

	cin >> seleccion;

	}while(seleccion < 1 || seleccion > 5);

	if(seleccion == 5)
	{
	clienteMenu();
	}else
	{

	do
	{
	cout<<"Que dia desea hacer la reserva?"<<endl;
	cin >> seleccionDia;
	}while(seleccionDia < 1 || seleccionDia > 31);

	}
	do
	{
	cout<<"Seleccione la hora:"<<endl<<endl;
	cout<<"1.13:00"<<endl;
	cout<<"2.14:00"<<endl;
	cin >> seleccionHora;
	}while(seleccionHora < 1 || seleccionHora > 2);


		rc = sqlite3_open("e-restaurants.db", &db);	//abrir base de datos
		if (rc != SQLITE_OK) {
			cout << "Error opening database" << endl;
			return rc;
		}

		//sale error por que clipse no reconoce la libreria sqlite3 bien, esta bien. //solucionado
		rc = crearReserva(db,usuarioReserva,seleccion,seleccionDia,seleccionHora);
		rc = sqlite3_close(db);
		    if (rc != SQLITE_OK) {
		        printf("Error closing database\n");
		        printf("%s\n", sqlite3_errmsg(db));
		        return rc;
		    }
		clienteMenu();


	return 0;

};

int menuModificar()
{
	char usuarioSeleccionReserva[20];
	cout<<"Introduzca su nombre de usuario para realizar la modificacion:"<<endl;
	cin >> usuarioSeleccionReserva;

	rc = sqlite3_open("e-restaurants.db", &db);	//abrir base de datos
	if (rc != SQLITE_OK) {
		cout << "Error opening database" << endl;
		return rc;
	}

	rc = seleccionarReserva(db, usuarioSeleccionReserva);
			rc = sqlite3_close(db);
			    if (rc != SQLITE_OK) {
			        printf("Error closing database\n");
			        printf("%s\n", sqlite3_errmsg(db));
			        return rc;
			    }
		clienteMenu();




	return 0;
};

int menuEliminar()
{
	char usuarioSeleccionReserva2[20];
	cout<<"Introduzca su nombre de usuario para eliminar una reserva"<<endl;
	cin >> usuarioSeleccionReserva2;

	rc = sqlite3_open("e-restaurants.db", &db);	//abrir base de datos
		if (rc != SQLITE_OK) {
			cout << "Error opening database" << endl;
			return rc;
		}

		rc = eliminarReserva(db, usuarioSeleccionReserva2);
				rc = sqlite3_close(db);
				    if (rc != SQLITE_OK) {
				        printf("Error closing database\n");
				        printf("%s\n", sqlite3_errmsg(db));
				        return rc;
				    }

	clienteMenu();
	return 0;
}

int menuVerReserva()
{
	char usuarioSeleccionReserva3[20];
	cout<<"Introduzca su nombre de usuario para ver sus reservas"<<endl;
	cin >> usuarioSeleccionReserva3;

	rc = sqlite3_open("e-restaurants.db", &db);	//abrir base de datos
			if (rc != SQLITE_OK) {
				cout << "Error opening database" << endl;
				return rc;
			}

			rc = verReserva(db, usuarioSeleccionReserva3);
					rc = sqlite3_close(db);
					    if (rc != SQLITE_OK) {
					        printf("Error closing database\n");
					        printf("%s\n", sqlite3_errmsg(db));
					        return rc;
					    }

		clienteMenu();




	return 0;
}












