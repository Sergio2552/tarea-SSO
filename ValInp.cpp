//Validacion de entradas
#include "stdafx.h"
#include "ValInp.h"
#include <iostream>//e/s 
#include <fstream>//archivos
#include <sstream>
#include <iomanip>//limite de var y formatos
#include <time.h>//tiempo de sistema
#include <string> 
//des habilita el warning de usar time.h en el metodo opcCheck
#pragma warning(disable:4996)
using namespace std;

//esta clase pudo haber sido una plantilla pero no le entiendo mucho a las plantillas:/

ValInp::ValInp()
{
}


ValInp::~ValInp()
{
}

//las 3 funciones hacen lo mismo solo que utilizan diferentes tipos de datos 


//generalmente se usa en menus
void ValInp::valShrRng(short &x, short min, short max)
{
	//eval short range
	bool check = false;
	do {
		try
		{
			cin >> x;
			if (x < min || x > max || cin.fail()) throw invalid_argument("Opcion no listada,fuera de rango ");
			//lanzo exc si la opcion esta fuera de rango o da error
			check = true;//si no ocurrio algun error continua
		}
		catch (const exception exp)
		{
			ofstream err("errorLog.txt", ios::app);
			time_t now = time(0);//teimpo actual para registrar error

			cout << "Opcion no listada , intente otra vez " << endl;
			err << exp.what() << std::put_time(std::localtime(&now), "%c %Z") << "\n";
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			x = 0;

		}
		catch (...) {
			cout << "Error fatal cerrando programa O.o";
		}
	} while (check == false);
}

// los dos metodos de abajo se usan para hacer un input seguro con datos numerico
void ValInp::valLngRng(long &x, long min, long max)
{
		//eval long range
	bool check = false;
	do {
		try
		{
			cin >> x;
			if (x < min || x > max || cin.fail()) throw invalid_argument("Fallo en cin , posible mismatch data type erro ");
			//lanzo exc si la opcion esta fuera de rango o da error
			check = true;//si no ocurrio algun error continua
		}
		catch (const exception exp)
		{
			ofstream err("errorLog.txt", ios::app);
			time_t now = time(0);//teimpo actual para registrar error

			cout << "Cantidad invalida, intente otra vez " << endl;
			err << exp.what() << std::put_time(std::localtime(&now), "%c %Z") << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			x = 0;

		}
		catch (...) {

			cout << "Error fatal cerrando programa O.o";
		}
	} while (check == false);
	
}

void ValInp::valLDRnf(long double &x, long double min, long double max) {
	//eval long  double range
	bool check = false;
	do {
		try
		{
			cin >> x;
			if (x < min || x > max || cin.fail()) throw invalid_argument("Fallo en cin fuera de rango, posible mismatch data type erro  ");
			//lanzo exc si la opcion esta fuera de rango o da error
			check = true;//si no ocurrio algun error continua
		}
		catch (const exception exp)
		{
			ofstream err("errorLog.txt", ios::app);
			time_t now = time(0);//teimpo actual para registrar error

			cout << "Cantidad invalida, intente otra vez  " << endl;
			err << exp.what() << std::put_time(std::localtime(&now), "%c %Z") << "\n";
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			x = 0;

		}
		catch (...) {
			cout << "Error fatal cerrando programa O.o";
		}
	} while (check == false);
}

void ValInp::valBool(bool& boolean) {

	bool check = false;
	do {
		try
		{
			cin >> boolean;
			if (cin.fail()) throw invalid_argument("Fallo en cin fuera de rango, posible mismatch data type erro  ");
			//lanzo exc si la opcion esta fuera de rango o da error
			check = true;//si no ocurrio algun error continua
		}
		catch (const exception exp)
		{
			ofstream err("errorLog.txt", ios::app);
			time_t now = time(0);//teimpo actual para registrar error

			cout << "Cantidad invalida, intente otra vez  " << endl;
			err << exp.what() << std::put_time(std::localtime(&now), "%c %Z") << "\n";
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (...) {
			cout << "Error fatal cerrando programa O.o";
		}
	} while (check == false);
	
}
