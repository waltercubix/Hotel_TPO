#define _CRT_SECURE_NO_WARNINGS

#include "definiciones.h"

int main() {
	
	srand(time(NULL));

	GenerarDatos();	
	//portada();
	menuInicio();

	return EXIT_SUCCESS;
}


