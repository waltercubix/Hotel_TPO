#define _CRT_SECURE_NO_WARNINGS

#include "definiciones.h"

//Titulos de ventanas
char const T_ListarClientes[] =    "   LISTA DE CLIENTES  ";
char const T_MenuPrincipal[] =     "    MENU PRINCIPAL    ";
char const T_NuevaReserva[] =      "  CARGA NUEVO CLIENTE ";
char const T_ModificarReserva[] =  "   MODIFICAR CLIENTE  ";
char const T_RecuperarReserva[] =  "   RECUPERAR CLIENTE  ";
char const T_AcercaDe[] =          " ACERCA DEL           ";
char const T_Ayuda[] =             "     MENU DE AYUDA    ";
char const T_Ayuda_Mod[] =         "AYUDA > MODIFICACIONES";
char const T_Ayuda_Eli[] =         "AYUDA > ELIMINACIONES ";
char const T_Ayuda_Car[] =         "AYUDA > CARGA DE DATOS";
char const T_Ayuda_Rec[] =         "AYUDA > RECUPERACIONES";
char const T_DetallesCliente[] =   "INFORMACION DE CLIENTE";

//banderas para mostrar tabla de clientes
int const ALTAS = 0;
int const BAJAS = 1;

//definicion de precios de habitacion segun su tipo

float const DOBLE = 7677; //+1451 impuestos
float const TRIPLE = 9922; //+1875 impuestos
float const CUADRUPLE = 10394; //+1964 impuestos


//contructor de titulo
void tituloVentana(char const* Titulo) {

	system("cls");
	for (int i = 0; i < 35; i++) {
		printf(BGGBL"%c", 32); //205 doble linea //32 espacio
	}
	printf(Titulo);
	for (int i = 0; i < 35; i++) {
		printf("%c", 32);
	}
	printf(bgbtw"\n");
}
void barradeMenues() {
	printf(BGGBB"  "BGGRR"C"BGGBB"lientes   Acerca "BGGRR"D"BGGBB"e   "BGGRR"A"BGGBB"yuda   "BGGRR"S"BGGBB"alir                                                      \n\n"bgbtw);
}

//funcion de bienvenida o caratula ** FINALIZADAS
void portada() {

	system("color 1f");
	hideCursor();
	Sleep(1000);

	FILE* logo = fopen("logo.txt", "rt");

	if (logo) {

		char letra = getc(logo);

		while (feof(logo) == 0) {
			printf("%c", letra);
			letra = getc(logo);
		}

		if (fclose(logo) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf(ERR_ABRIR_ARCHIVO);
	}

	printf("\n\n");
	Sleep(2000);

}
void UI_Principal() {
	
	system("color 17");
	tituloVentana(T_MenuPrincipal);
	barradeMenues();
	
	printf("\t\t      ");

	for (int i = 0; i < 44; i++) {

		if (i == 0) {
			printf(" %c", 201);
		}
		printf("%c", 205);
	}
	printf("%c", 187);

	printf("\n\t\t       %c Bienvenido al sistema de gesti%cn del hotel %c\n\t\t      ", 186, 162, 186);

	for (int i = 0; i < 44; i++) {
		if (i == 0) {
			printf(" %c", 200);
		}
		printf("%c", 205);
	}
	printf("%c\n\n", 188);


	for (int i = 0; i < 92; i++) {
		printf("%c", 205);
	}

	printf("\n\n");

	//imprime horizontales de botones

	for (int i = 0; i < 3; i++) {

		printf("        ");
		for (int j = 0; j < 19; j++) {
			if (j == 0) {
				printf("%c", 201);
			}
			if (j < 18) {
				printf("%c", 205);
			}
			else {
				printf("%c", 187);
			}
		}
	}
	printf("\n");

	printf("        ");

	//printf("%c1  BUSCAR RESERVA %c        %c2  NUEVA RESERVA  %c        %c3  BORRAR RESERVA %c\n", 186, 186, 186, 186, 186, 186);
	printf("%c1  VER CLIENTES   %c        %c2  NUEVO CLIENTE  %c        %c3    M/E CLIENTE  %c\n", 186, 186, 186, 186, 186, 186);

	//imprime horizontales de botones

	for (int i = 0; i < 3; i++) {

		printf("        ");
		for (int j = 0; j < 19; j++) {
			if (j == 0) {
				printf("%c", 200);
			}
			if (j < 18) {
				printf("%c", 205);
			}
			else {
				printf("%c", 188);
			}
		}
	}
	printf("\n\n\n");

	//imprime horizontales de botones

	for (int i = 0; i < 3; i++) {

		printf("        ");
		for (int j = 0; j < 19; j++) {
			if (j == 0) {
				printf("%c", 201);
			}
			if (j < 18) {
				printf("%c", 205);
			}
			else {
				printf("%c", 187);
			}
		}
	}

	printf("\n");

	printf("        ");
	//printf("%c4  REC RESERVA    %c        %c5  AYUDA          %c        %c6  ACERCA DE	   %c\n", 186, 186, 186, 186, 186, 186);
	printf("%c4  REC CLIENTE    %c        %c5      AYUDA      %c        %c6  ACERCA DE	   %c\n", 186, 186, 186, 186, 186, 186);

	//imprime horizontales de botones

	for (int i = 0; i < 3; i++) {

		printf("        ");
		for (int j = 0; j < 19; j++) {
			if (j == 0) {
				printf("%c", 200);
			}
			if (j < 18) {
				printf("%c", 205);
			}
			else {
				printf("%c", 188);
			}
		}
	}
	printf("\n\n");

	printf("\t\t Ingrese con el teclado el n%cmero de la opci%cn deseada\n\n", 163, 162);
	printf("\t\t\t     Presione %cESC%c o %cS%c para salir\n\n\n", 34, 34,34, 34);
	printf("\t\t\t\t\t   ");
}
void ayudaModificaciones() {
	tituloVentana(T_Ayuda_Mod);
	hideCursor();

	//Abro el archivo de ayuda.txt

	FILE* ayuda = fopen(AYUDA_M, "r");

	if (ayuda) {

		char letra = getc(ayuda);

		while (feof(ayuda) == 0) {

			printf(bgbtw"%c", letra);
			letra = getc(ayuda);
		}

		if (fclose(ayuda) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf(ERR_ABRIR_ARCHIVO); 
		return 1;
	}

	printf("\n");
	volverAtras();
}
void ayudaEliminaciones() {

	tituloVentana(T_Ayuda_Eli);
	hideCursor();

	//Abro el archivo de ayuda.txt

	FILE* ayuda = fopen(AYUDA_EL, "r");

	if (ayuda) {

		char letra = getc(ayuda);

		while (feof(ayuda) == 0) {
			printf(bgbtw"%c", letra);
			letra = getc(ayuda);
		}

		if (fclose(ayuda) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf(ERR_ABRIR_ARCHIVO); 
	}

	printf("\n");
	volverAtras();
}

void ayudaCargar() {

	tituloVentana(T_Ayuda_Car);
	hideCursor();

	//Abro el archivo de ayuda.txt

	FILE* ayuda = fopen(AYUDA_C, "r");

	if (ayuda) {

		char letra = getc(ayuda);

		while (feof(ayuda) == 0) {

			printf(bgbtw"%c", letra);
			letra = getc(ayuda);
		}

		if (fclose(ayuda) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf(ERR_ABRIR_ARCHIVO); return 1;
	}

	printf("\n");

	volverAtras();
}
void ayudaRecuperaciones() {

	tituloVentana(T_Ayuda_Rec);
	hideCursor();

	//Abro el archivo de ayuda.txt

	FILE* ayuda = fopen(AYUDA_R, "r");

	if (ayuda) {

		char letra = getc(ayuda);

		while (feof(ayuda) == 0) {

			printf(bgbtw"%c", letra);
			letra = getc(ayuda);
		}

		if (fclose(ayuda) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf(ERR_ABRIR_ARCHIVO); return 1;
	}

	printf("\n");

	volverAtras();
}

int ayuda() {

	tituloVentana(T_Ayuda);

	hideCursor();
	printf("\n\n    ");

	for (int j = 0; j < 83; j++) {
		if (j == 0) {
			printf(BGGB white "%c", 218); //201 218
		}
		if (j < 82) {
			printf("%c", 196); //205 196
		}
		else {
			printf(BGGB "%c", 191); //187 191
		}
	}

	printf("\n");

	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    ");

	for (int j = 0; j < 83; j++) {
		if (j == 0) {
			printf(BGGB white"%c", 192); //200 192 
		}
		if (j < 82) {
			printf(BGGB"%c", 196); //205 196
		}
		else {
			printf("%c%c", 217, 219); //188 217
		}
	}

	//sombra borde inferior

	printf(bgbtw "\n     ");
	for (int i = 0; i < 84; i++) {
		printf(bgbb"%c", 223);
	}

	printf("\n");


	//Abro el archivo de ayuda.txt

	FILE* ayuda = fopen("ayuda.txt", "r");


	if (ayuda) {

		gotoxy(7, 4);

		char letra = getc(ayuda);

		while (feof(ayuda) == 0) {

			printf(BGGB"%c", letra);
			letra = getc(ayuda);
		}

		if (fclose(ayuda) != 0) {
			printf(ERR_CERRAR_ARCHIVO);
		}
	}

	else {
		printf("El archivo no se pudo abrir correctamente"); return 1;
	}

	printf("\n");

	volverAtras();

}

void acercade() {
	tituloVentana(T_AcercaDe);
	printf(BGGRR"  S"BGGBB"alir                                                                                     \n\n"bgbtw);
	integrantesGrupo();
}

//buscarReserva()
void listarCliente() {

	tituloVentana(T_ListarClientes);
	mostrarTablaClientes(ALTAS);
	volverAtras();
}

void nuevaReserva() {

	int aux;

	tituloVentana(T_NuevaReserva);
	showCursor();
	escribirDatos();

}

void modificarReserva() {

	tituloVentana(T_ModificarReserva);
	mostrarTablaClientes(ALTAS);

	int opcion;

	printf("\n < 1 MODIFICAR REGISTRO >   < 2 ELIMINAR REGISTRO >  |  OPCION: ");
	showCursor();
	scanf(" %d", &opcion);
	getchar();


	switch (opcion)
	{
	case 0:
		menuInicio();
		break;
	case 1:
		modificarDatos();
		break;
	case 2:borrarDatos();
		break;
	default:
		break;
	}
}

void recuReserva() {

	tituloVentana(T_RecuperarReserva);
	mostrarTablaClientes(BAJAS);
	recuperarDatos();
	volverAtras();
}

void volverAtras() {

	do {

		Sleep(100); 

		char tecla = _getch();

		if (tecla == ESC || tecla == TECLA_S) { //tecla 27 es la tecla "ESC"
			menuInicio();
		}
		else {
			continue;  
		}

	} while (1); 

}

//menu inicio es la logica real del programa, en ella se muestra la interfaz de menu principal

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void showCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = TRUE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void integrantesGrupo() {

	hideCursor();

	printf("\t\t\t   ");

	for (int j = 0; j < 35; j++) {
		if (j == 0) {
			printf(BGGB white "%c", 218); //201 218
		}
		if (j < 34) {
			printf("%c", 196); //205 196
		}
		else {
			printf(BGGB "%c", 191); //187 191
		}
	}

	printf("\n");
	printf(bgbtw"                           "BGGB white"%c"BGGB"   _    _         _____  ______   %c%c\n"bgbtw, shadow); //186 179 shadow 219 o 178
	printf(bgbtw"                           "BGGB white"%c"BGGB"  | |  | |  /\\   |  __ \\|  ____|  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"  | |  | | /  \\  | |  | | |__     %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"  | |  | |/ /\\ \\ | |  | |  __|    %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"  | |__| / ____ \\| |__| | |____   %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"   \\____/_/    \\_\\_____/|______|  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"       Sofware desarrollado       %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"               por:               %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"           Carral Walter          %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"          Mateos Delfina          %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"            Vega Lucas            %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"        Garrastazul Martina       %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"     Juan Sebastian Rodriguez     %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"                           "BGGB white"%c"BGGB"            GRUPO  N%C4            %c%c\n"bgbtw, 179, 248, 179, 219);
	printf(bgbtw"                           "BGGB white"%c"BGGB"             A%CO 2022             %c%c\n"bgbtw, 179, 165, 179,219);
	printf(bgbtw"\t\t\t   ");

	for (int j = 0; j < 35; j++) {
		if (j == 0) {
			printf(BGGB white"%c", 192); //200 192 
		}
		if (j < 34) {
			printf(BGGB"%c", 196); //205 196
		}
		else {
			printf("%c%c", 217,219); //188 217
		}
	}

	//sombra borde inferior

	printf(bgbtw "\n\t\t\t     ");
	for (int i = 0; i < 35; i++) {
		printf(bgbb"%c", 223);
	}

	Sleep(550);
	printf("\n");
	printf(blink"\t\t\t      Pulse una tecla para continuar."bgbtw);
	_getch();
	menuInicio();
	
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//experimentales

void salirPrograma() {

	hideCursor();

	//Coordenadas del cartel de aviso
	int x = 28;
	int y = 9;

	gotoxy(x, y);
	for (int j = 0; j < 35; j++) {
		if (j == 0) {
			printf(BGGB white "%c", 218); //201 218
		}
		if (j < 34) {
			printf("%c", 196); //205 196
		}
		else {
			printf(BGGB "%c", 191); //187 191
		}
	}

	gotoxy(x, y+1);
	printf(BGGB white"%c"BGGB"              AVISO               %c%c"bgbtw, shadow); //186 179 shadow 219 o 178
	gotoxy(x, y+2);
	printf(BGGB white"%c"BGGB"                                  %c%c"bgbtw, shadow);
	gotoxy(x, y+3);
	printf(BGGB white"%c"BGGB"  %cEsta seguro que quiere salir?  %c%c"bgbtw, 179, 168, 179, 219);
	gotoxy(x, y+4);
	printf(BGGB white"%c"BGGB"                                  %c%c"bgbtw, shadow);
	gotoxy(x, y+5);
	printf(BGGB white"%c"BGGB"                                  %c%c"bgbtw, shadow);
	gotoxy(x, y + 6);

	printf(BGGB white"%c"BGGB,195);
	for (int j = 0; j < 34; j++) {
		printf(white"%c", 196);
	}
	
	printf(BGGB"%c%c"bgbtw, 180, 219);
	gotoxy(x, y+7);
	printf(BGGB white"%c"BGGB"      "BGrojo"[ ESC ]"BGGB"      "BGgreen"[ ENTER ]"BGGB"      %c%c"bgbtw, shadow);
	
	gotoxy(x, y+8);

	for (int j = 0; j < 35; j++) {
		if (j == 0) {
			printf(BGGB white"%c", 192); //200 192 
		}
		if (j < 34) {
			printf(BGGB"%c", 196); //205 196
		}
		else {
			printf("%c%c", 217, 219); //188 217
		}
	}

	//sombra borde inferior

	gotoxy(x+2, y+9);

	for (int i = 0; i < 35; i++) {
		printf(bgbb"%c", 223);
	}

	//LOGICA espero por teclas del teclado

	do {

		Sleep(100); //Escucho el teclado 10 veces por segundo

		char tecla = _getch();

		if (tecla == 13) {   //tecla 13 es la tecla "ENTER"
			system("color 0f");
			system("cls");
			exit(0);
		}

		if (tecla == 27) { //tecla 27 es la tecla "ESC"
			menuInicio();
		}
		else {
			continue;  //cualquier otra tecla, no pasa nada.
		}

	} while (1); //Al definir un ciclo do while con un 1 genero un ciclo infinito.

}

void menuInicio() {

	hideCursor();

	UI_Principal(); //los menus con la seleccion

	do {

		Sleep(100);
		char teclaMenu = _getch();

		switch (teclaMenu)
		{
		case UNO:
			listarCliente();
			break;
		case TECLA_C:
			//listarCliente();
			imprimirDetalleContacto();
			break;
		case DOS:
			nuevaReserva();
			break;
		case TRES:
			modificarReserva();
			break;
		case CUATRO:
			recuReserva();
			break;
		case CINCO:
			ayuda();
			break;
		case SHIFT_C:
			ayudaCargar();
			break;
		case SHIFT_M:
			ayudaModificaciones();
		case SHIFT_E:
			ayudaEliminaciones();
			break;
		case SHIFT_R:
			ayudaRecuperaciones();
			break;
		case TECLA_A:
			menuDesplegableAyuna();
			break;
		case SEIS:
			acercade();
			break;
		case TECLA_D:
			acercade();
			break;
		case ESC:
			salirPrograma();
			break;
		case TECLA_S:
			salirPrograma();
			break;
		default:
			continue;
		}
	} while (1);
}

//funcion para escribir datos

void escribirDatos() {

	cliente cliente1;
	
	FILE* datos = fopen(BASE_DATOS, "ab");

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(1);
	}
	 
	DetalleCliente_UI();

	gotoxy(6, 3);printf(BGGB"DATOS PERSONALES");
	gotoxy(6, 5); printf("Nombre:");   
	gotoxy(33, 5); printf("Fecha de Nacimiento: DD/MM/AAAA");
	gotoxy(6, 7); printf("Apellido:");
	gotoxy(33, 7); printf("Estado Civil:");
	gotoxy(6, 9); printf("DNI:");
	gotoxy(6, 11); printf("DATOS DEL DOMICILIO");
	gotoxy(6, 13); printf("Calle:");
	gotoxy(33, 13); printf("Altura:");
	gotoxy(48, 13); printf("Ciudad:");
	gotoxy(6, 15); printf("Cod. Postal:");
	gotoxy(33, 15); printf("Provincia:");
	gotoxy(66, 15); printf("Pais:");
	gotoxy(6, 17); printf("DATOS DE CONTACTO");
	gotoxy(6, 19); printf("E-Mail:");
	gotoxy(6, 21); printf("Telefono:");

	cliente1.status = 1;
	cliente1.nCliente = numeroCliente();
	int tam;

	fflush(stdin);

	gotoxy(14, 5);
	fgets(cliente1.nombre,15,stdin); //pablo\0\0
	tam = strlen(cliente1.nombre);
	cliente1.nombre[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(16, 7);
	fgets(cliente1.apellido, 15, stdin);
	tam = strlen(cliente1.apellido);
	cliente1.apellido[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(11, 9);
	scanf(" %d", &cliente1.dni);
	getchar();
	fflush(stdin);

	gotoxy(54,5);
	scanf("%d/%d/%d", &cliente1.fNacimineto.dia, &cliente1.fNacimineto.mes, &cliente1.fNacimineto.anio);
	getchar();
	fflush(stdin);

	gotoxy(47,7);
	fgets(cliente1.eCivil, 13, stdin);
	tam = strlen(cliente1.eCivil);
	cliente1.eCivil[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(13,13);
	fgets(cliente1.contacto.nCalle, 20, stdin);
	tam = strlen(cliente1.contacto.nCalle);
	cliente1.contacto.nCalle[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(41,13);
	scanf("%d", &cliente1.contacto.altura);
	getchar();
	fflush(stdin);

	gotoxy(56,13);
	fgets(cliente1.contacto.ciudad, 25, stdin);
	tam = strlen(cliente1.contacto.ciudad);
	cliente1.contacto.ciudad[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(19,15);
	scanf("%d", &cliente1.contacto.cPostal);
	getchar();
	fflush(stdin);

	gotoxy(44,15);
	fgets(cliente1.contacto.provincia, 25, stdin);
	tam = strlen(cliente1.contacto.provincia);
	cliente1.contacto.provincia[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(72,15);
	fgets(cliente1.contacto.pais, 25, stdin);
	tam = strlen(cliente1.contacto.pais);
	cliente1.contacto.pais[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(14,19);
	fgets(cliente1.contacto.email, 35, stdin);
	tam = strlen(cliente1.contacto.email);
	cliente1.contacto.email[tam - 1] = '\0';
	fflush(stdin);

	gotoxy(16,21);
	scanf("%d", &cliente1.contacto.telefono);
	getchar();
	fflush(stdin);

	Sleep(250);

	printf("\nGuardando Datos... Por favor espere.\n\n");

	fwrite(&cliente1, sizeof(cliente), 1, datos);
	
	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

	Sleep(300);

	printf("Datos guardados satisfactoriamente.\nPrecione ESC para volver al menu principal\n\n");

	volverAtras();

}

int modificarDatos() {

	FILE* datos = fopen(BASE_DATOS, "r+b");
	cliente cliente1;
	int dni;
	int existencia = 0;

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(5);
	}

	printf("\n DNI: ");
	scanf(" %d", &dni);

	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		if (dni == cliente1.dni) {
			if (cliente1.status != 0) {

				int opcion;

				printf("\n < 1 NOMBRE >  < 2 APELLIDO >  < 3 DNI >  < 4 DIRECCION >  < 5 ESTADO >  |  OPCION: ");
				scanf("%d", &opcion);
				getchar();

				switch (opcion)
				{
				case 1:

					printf("\n PREVIO: %s", cliente1.nombre);
					printf("\n NUEVO NOMBRE: ");
					scanf(" %s", &cliente1.nombre);
					break;
				case 2:
					printf("\n PREVIO: %s", cliente1.apellido);
					printf("\n NUEVO APELLIDO: ");
					scanf(" %s", &cliente1.apellido);
					break;
				case 3:
					printf("\n PREVIO: %d", cliente1.dni);
					printf("\n NUEVO DNI: ");
					scanf("%d", &cliente1.dni);
					fflush(stdin);
					break;
				case 4:
					printf("\n PREVIO: %s ", cliente1.contacto.nCalle);
					printf("\n NUEVO NOMBRE DE CALLE: ");
					fgets(cliente1.contacto.nCalle, 20, stdin);
					int lonnac = strlen(cliente1.contacto.nCalle);
					cliente1.contacto.nCalle[lonnac - 1] = '\0';
					fflush(stdin);

					printf("\n PREVIO: %d ", cliente1.contacto.altura);
					printf("\n NUEVA ALTURA: ");
					scanf("%d", &cliente1.contacto.altura);
					getchar();

					break;
				case 5:
					printf("\n PREVIO: %s ", cliente1.eCivil);
					printf("\n ESTADO CIVIL: ");
					scanf("%s", &cliente1.eCivil);
					break;
				default:
					break;
				}

				printf("\n");

				int posicion = ftell(datos) - sizeof(cliente);
				fseek(datos, posicion, SEEK_SET);

				Sleep(150);
				printf(" Guardando modificacion... Por favor espere.\n");

				fwrite(&cliente1, sizeof(cliente), 1, datos);

				Sleep(150);
				printf(" Modificacion Guardada. Presione < ESC > para volver al menu principal");

				existencia = 1;
				break;


			}
			else {

				printf("\n\nEl cliente seleccionado esta dado de BAJA. Restablecer cliente antes de modificar\n\n");
				printf("ESC para volver al menu principal, seleccione opcion 4 en el menu principal para recuperar");
				volverAtras();
			}
			
		}

		fread(&cliente1, sizeof(cliente), 1, datos);
	}

	if (existencia == 0) {
		printf("\n El registro buscado no existe.\n");
		printf(" Precione ESC para volver al menu principal\n\n");
		volverAtras();
	}

	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

}

void borrarDatos() {

	FILE* datos = fopen(BASE_DATOS, "r+b");

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(5);
	}

	cliente cliente1;
	int ncliente;

	printf("\nCliente: ");
	scanf(" %d", &ncliente);
	getchar();
	
	int existencia = 0;
	int Confirmacion = 0;

	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		if (ncliente == cliente1.nCliente) {
			if (cliente1.status != 0) {

				existencia = 1;

				printf("\n < CONFIRMAR ELIMINACION >   < 1 SI >    < 2 NO >   | OPCION: ");

				scanf(" %d", &Confirmacion);
				getchar();

				if (Confirmacion == 1) {

					cliente1.status = 0; // status -> 0 para marcar q lo elimino

					int posicion = ftell(datos) - sizeof(cliente);
					fseek(datos, posicion, SEEK_SET);

					Sleep(250);
					printf("\n Eliminando Registro... Por favor espere.\n\n");

					fwrite(&cliente1, sizeof(cliente), 1, datos);

					Sleep(250);
					printf(" El registro ha sido eliminado. Presione < ESC > para volver al menu principal");
					break;
				}

				else {

					if (fclose(datos) != 0) {
						printf(ERR_CERRAR_ARCHIVO);
						exit(5);
					}

					printf("OPERACION CANCELADA. ESC PARA VOLVER AL MENU PRINCIPAL.\n");
					volverAtras();

				}
			}
		}	
		fread(&cliente1, sizeof(cliente), 1, datos);
	}

	if (existencia == 0) {
		printf("\nEl registro buscado no existe.\n");
		printf(" Presione < ESC > para volver al menu principal");
		volverAtras();
	}

	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

	volverAtras();

}

void recuperarDatos() {
	
	int ncliente;
	printf("\nCliente: ");
	scanf(" %d", &ncliente);
	getchar();

	if (ncliente <= 0) {
		
		menuInicio();
	}

	FILE* datos = fopen(BASE_DATOS, "r+b");

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(5);
	}

	cliente cliente1;
	
	int i = 0;
	int existencia = 0;
	int pregunta = 0;

	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		if (ncliente == cliente1.nCliente) {

			existencia = 1;

			printf("\nCONFIRMAR RECUPERO DE REGISTRO    < 1 SI >    < 2 NO >    | OPCION: ");
			scanf("%d", &pregunta);

			if (pregunta == 1) {

				cliente1.status = 1;

				int posicion = ftell(datos) - sizeof(cliente);
				fseek(datos, posicion, SEEK_SET);

				Sleep(250);
				printf("Recuperando registro... Por favor espere.\n\n");

				fwrite(&cliente1, sizeof(cliente), 1, datos);

				Sleep(250);
				printf("El registro ha sido recuperado. Presione < ESC > para volver al menu principal");
				break;
			}

			else {

				break;
			}

		}

		fread(&cliente1, sizeof(cliente), 1, datos);

	}

	if (existencia == 0) {

		printf("\nEl registro buscado no existe.\n");

		printf("Precione ESC para volver al menu principal\n\n");

		volverAtras();
	}

	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}


}

void mostrarTablaClientes(int status) {

	FILE* datos = fopen(BASE_DATOS, "rb");
	cliente cliente1;
	
	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		volverAtras();
	}
	printf("\n\n   ");
	
	for (int i = 0; i < 80; i++) {
		
		if (i == 0)
			printf(BGGB"%c", 218);
		if (i == 4)
			printf("%c", 194);
		if (i == 27)
			printf("%c", 194);
		if (i == 38)
			printf("%c", 194);
		if (i == 52)
			printf("%c", 194);
		
		printf("%c", 196); //205 doble linea //32 espacio //196 linea simple
	}

	printf("%c"bgbtw"\n", 191);

	printf("   "BGGB"%c ID %c NOMBRE %c APELLIDO     %c DOCUMENTO %c EST. CIVIL   %c DOMICILIO PARTICULAR       %c"bgbtw"\n   ", 179, 179, 38, 179, 179, 179, 179);
	
	for (int i = 0; i < 80; i++) {

		if (i == 0)
			printf(BGGB"%c", 195);
		if (i == 4)
			printf("%c", 197);
		if (i == 27)
			printf("%c", 197);
		if (i == 38)
			printf("%c", 197);
		if (i == 52)
			printf("%c", 197);
	
		printf("%c", 196); //205 doble linea //32 espacio //196 linea simple
	}

	printf("%c"bgbtw"\n", 180);

	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		Sleep(10);

		char espacio[] = " ";
		char coma[] = ", ";

		//Union de nombre y apellido
		char nombreApellido[33];
		strcpy(nombreApellido, cliente1.nombre);
		strcat(nombreApellido, coma);
		strcat(nombreApellido, cliente1.apellido);

		//Union de nombre de calle y altura en un unico array de caracteres, _itoa es para pasar un int a un char, el 10, significa q el numero es en decimal.
		char auxnombre[26];
		char altura[6];
		strcpy(auxnombre,cliente1.contacto.nCalle);
		int numero = cliente1.contacto.altura;
		_itoa(numero, altura, 10);
		strcat(auxnombre, espacio);
		strcat(auxnombre, altura);

		if (cliente1.status != status) {
			printf("   "BGGB"%c%4d%c %-21s %c %9d %c %-12s %c %-26s %c"bgbtw"\n",179, cliente1.nCliente,179, nombreApellido ,179, cliente1.dni,179, cliente1.eCivil,179, auxnombre,179);
			//printf("\nFecha de nacimiento: %d/%d/%d", cliente1.fNacimineto.dia, cliente1.fNacimineto.mes, cliente1.fNacimineto.anio);

		}
		fread(&cliente1, sizeof(cliente), 1, datos);
	}
	
	printf("   ");

	for (int i = 0; i < 80; i++) {

		if (i == 0)
			printf(BGGB"%c", 192);
		if (i == 4)
			printf("%c", 193);
		if (i == 27)
			printf("%c", 193);
		if (i == 38)
			printf("%c", 193);
		if (i == 52)
			printf("%c", 193);

		printf("%c", 196); //205 doble linea //32 espacio //196 linea simple
	}

	printf("%c"bgbtw"\n", 217);


	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

}

void menuDesplegableAyuna() {

	gotoxy(23,1);
	printf(BGGB"  "BGGBR"A"BGGB"yuda  ");

	gotoxy(23,2);
	printf(BGGB"%c", 218 );
	for (int i = 0; i < 29; i++) {
		printf("%c",196);
		if (i == 28)
			printf("%c", 191);
	}
	gotoxy(23, 3);
	printf("%c Cargar Datos        Shift+C %c",179,179);
	gotoxy(23, 4);
	printf("%c Modificar Datos     Shift+M %c",179,179);
	gotoxy(23, 5);
	printf("%c Eliminar Datos      Shift+E %c",179,179);
	gotoxy(23, 6);
	printf("%c Recuperar Datos     Shift+R %c",179,179);

	gotoxy(23, 7);
	printf("%c", 192);
	for (int i = 0; i < 29; i++) {
		printf("%c", 196);
		if (i == 28)
			printf("%c"bgbtw, 217);
	}

	do {

		Sleep(100);
	
		char ch =_getch();

		switch (ch) {

		case SHIFT_C:
			ayudaCargar();
			break;
		case SHIFT_M:
			ayudaModificaciones();
			break;
		case SHIFT_E:
			ayudaEliminaciones();
			break;
		case SHIFT_R:
			ayudaRecuperaciones();
			break;
		case ESC:
			menuInicio();
			break;
		case TECLA_S:
			menuInicio();
			break;
		case TECLA_A:
			menuInicio();
			break;
		default:
			continue;
		}

	} while (1);

}

int numeroCliente() {

	int numeroCliente = rand() % (999 - 100 + 1) + 100;
	cliente cliente1;
	FILE* datos = fopen(BASE_DATOS, "rb");
	
	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(1);
	}
	
	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		if (cliente1.nCliente == numeroCliente) {
			numeroCliente = rand() % (999 - 100 + 1) + 100;
			fseek(datos, 0, SEEK_SET);
		}
		fread(&cliente1, sizeof(cliente), 1, datos);
	}

	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

	return numeroCliente;
}

void imprimirDetalleContacto() {
	
	tituloVentana(T_DetallesCliente);
	
	FILE* datos = fopen(BASE_DATOS, "rb");

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(5);
	}

	cliente cliente1;
	int dni;

	printf("\nDNI: ");
	scanf(" %d", &dni);
	getchar();

	int existencia = 0;

	fread(&cliente1, sizeof(cliente), 1, datos);

	while (feof(datos) == 0) {

		if (dni == cliente1.dni) {

			existencia = 1;

			printf("\nINFORMACION GENERAL DE CLIENTE CON [ID] > %d",cliente1.nCliente);

			printf("\n\nDatos Personales:");

			printf("\n\nNombre: %s", cliente1.nombre);
			printf("\nApellido: %s", cliente1.apellido);
			printf("\nDocumento: %d", cliente1.dni);
			printf("\nFecha de Nacimiento: %0d/%0d/%d", cliente1.fNacimineto.dia, cliente1.fNacimineto.mes, cliente1.fNacimineto.anio);
	
			printf("\n\nDomicilio:");

			printf("\n\nCalle: %s", cliente1.contacto.nCalle);
			printf("\nAltura: %d", cliente1.contacto.altura);
			printf("\nCiudad: %s", cliente1.contacto.ciudad);
			printf("\nCodigo Postal: %d", cliente1.contacto.cPostal);
			printf("\nProvincia: %s", cliente1.contacto.provincia);
			printf("\nPais: %s", cliente1.contacto.pais);

			printf("\n\nContacto:");

			printf("\n\nNumero de Telefono: %d", cliente1.contacto.telefono);
			printf("\nCorreo Electronico: %s", cliente1.contacto.email);

		}
		
		fread(&cliente1, sizeof(cliente), 1, datos);
	}

	if (existencia == 0) {

		printf("\nEl registro buscado no existe.\n");
		printf(" Presione < ESC > para volver al menu principal");
		volverAtras();
	}

	if (fclose(datos) != 0) {
		printf(ERR_CERRAR_ARCHIVO);
		exit(5);
	}

	volverAtras();

}

void GenerarDatos() {

	
	float numero;
	float total = 100;
	float avance,barra,tiempo,segundosEstimados;
	int bandera, extra, minutosEstimados;

	do {
		printf("Cuantos registros quiere generar? ");
		scanf("%f", &numero);
		getchar();
		fflush(stdin);

		if (numero < 0) {
			printf("Numeros invalido. Ingrese cero o valores superiores hasta 1000.\n\n");
		}

	} while (numero < 0);

	hideCursor();

	int aux = numero;
	float contador = 0;

	const char nombres[43][15] = 
	{ 
	 "Martin","Walter","Emilio","Zoe",
     "Gonzalo","Lautaro","Cristian",
     "Florencia","Romina","Lurdes",
	 "Micaela","Martina","Noelia",
     "Delfina","Carlos","Yanina",
	 "Belen","Leandro","Cintia",
     "Bruno","Ezequiel","Victoria",
	 "Noemi","Roberto","Nestor",
     "Carina","Ana Maria", "Emiliano",
	 "Matias","Ariana","Delia","Elizabeth",
	 "Ernesto","Federico","Paloma",
	 "Ariel","Horacio","Sofia",
	 "Benjamin","Emma","Thiago","Santino","Juan"
	};
	const char apellidos[35][15] = 
	{ 
	 "Sanchez","Gonzales","Rodriguez","Lopez","Diaz","Ciancio",
	 "Rosero","Vega","Sejas","Tinelli","Ali","Garrido","Mendoza",
	 "Ramos","Torres","Martin","Vargas","Romero","Sosa","Castro",
	 "Acosta","Benitez","Carrasco","Turraca","Mucci","Irigoyen",
	 "Villalba","Luna","Ponce","Quiroga","Godoy","Herrera","Vera","Sawi","Vegas"
	};
	const char calles[58][20] = 
	{
	 "Acoyte","Albania","Corrientes","Medrano","San Martin","Pompeya",
	 "Santa Fe","Arcos","French","Navarro","Serrano","Urien","Venezuela",
     "Virreyes","Zarate","Vidal","9 de Julio","Ramon Franco","Mayor Olivero",
	 "Martin de Maria","Roca","Almafuerte","Tomas Godoy Cruz","J. Zamora",
	 "Gral. Villegas","Lituania","1 de Mayo","Gral. Miller","Santiago Derqui",
	 "Rio de Janeiro","Amancio Alcorta","Cnel. Pringles","Chaco","Manuel Maza",
	 "Veracruz","Paraguay","Entre Rios","Gdor. Oliden","Tuyuti","Pilar","Darwin",
     "Zarate","Pilcomayo","Pasillo","Cosquin","Camilo Mandelli","A. Franco","Cesar Ratti",
	 "R. Venzano","Presidente Peron","Volcan Lanin","Rio Grande","Av. Luis Vernet",
	 "Av. Cepeda","Av. Rosales","Av. Quilmes","Av. Los Incas","Av. Mariano Castex"
	};
	const char provincias[22][25] =
	{
	 "Jujuy","Salta","Formosa",
	 "Chaco","Santiago del Estero","Santa Fe",
	 "Catamarca", "Tucuman","La Rioja",
	 "Corrientes","San Juan","Mendoza",
	 "Buenos Aires","San Luis","La Pampa",
	 "Entre Rios","Neuquen","Rio Negro",
	 "Cordoba","Chubut","Santa Cruz","Tierra Del Fuego"
	};
	const char ciudades[30][25] =
	{
	 "Lozano","Risos","Berazategui","Sol de Mayo","Merlo","Pedernales","Chiclana","Valcheta","San Rafael","Villa Maria",
	 "Tafi del Valle","Cerro Colorado","Cruz del Eje","Los Llanos","Achiras","La Irene","Viamonte","Villa Rossi","Telen","Algarrobos",
	 "Punta del Agua","Pico Truncado","Pampa Alta","Bajo Caracoles","Tres Pinos","Howards","Puerto Banderas","Cerro Sombrero","Portillo","Indio Rico"
	};

	const char estados[5][13] = {"Soltero/a", "Casado/a","Divorciado/a","Viudo/a","Separado/a"};

	FILE* datos = fopen(BASE_DATOS, "wb");
	cliente cliente1;

	segundosEstimados = (numero * CK) / 1000;

	if (segundosEstimados > 60) {
		minutosEstimados = (segundosEstimados / 60);
		segundosEstimados = segundosEstimados / 60;
	}
	else {
		minutosEstimados = 0;
	}

	do{  

		if (aux == 0) {
			printf("No se crearan datos\n\n");
			Sleep(1000);
			break;
		}
		else {

			aux--;

			if (datos == NULL) {
				printf(ERR_ABRIR_ARCHIVO);
				exit(1);
			}

			int nombre = rand() % 43;
			int apellido = rand() % 35;
			int provincia = rand() % 22;
			int altura = rand() % (12000 - 25 + 1) + 25;
			int postal = rand() % (1999 - 1000 + 1) + 1000;
			int ciudad = rand() % 30;
			int calle = rand() % 58;
			int aux = rand() % (89999 - 19999 + 1) + 19999;
			int dni = (aux) * 999;
			int auxtel = rand() % (119999 - 110000 + 1) + 110000;
			int telefono = (auxtel) * 9999;
			int año = rand() % (2004 - 1955 + 1) + 1955;
			int mes = rand() % 12 + 1;
			int dia = rand() % 28 + 1;
			int estado = rand() % 5;

			cliente1.status = 1;
			cliente1.nCliente = rand() % (999 - 100 + 1) + 100;
			strcpy(cliente1.nombre, nombres[nombre]);
			strcpy(cliente1.apellido, apellidos[apellido]);
			cliente1.dni = dni;
			cliente1.contacto.telefono = telefono;
			cliente1.fNacimineto.dia = dia;
			cliente1.fNacimineto.mes = mes;
			cliente1.fNacimineto.anio = año;
			strcpy(cliente1.contacto.nCalle, calles[calle]);
			cliente1.contacto.altura = altura;
			cliente1.contacto.cPostal = postal;
			strcpy(cliente1.contacto.ciudad, ciudades[ciudad]);
			strcpy(cliente1.contacto.provincia, provincias[provincia]);
			strcpy(cliente1.eCivil, estados[estado]);
			strcpy(cliente1.contacto.pais, "Argentina");

			//generar un mail aleatorio

			char mailSeparadores[4][2] = {".","_","-",""};
			char mailTerminaciones[5][13] = { "@outlook.com","@gmail.com","@hotmail.com","@icloud.com","@yahoo.com" };
			char mail[50];
		
			int Separador = rand() % 4;
			int Terminacion = rand() % 5;

			strcpy(mail, cliente1.apellido);
			strcat(mail, mailSeparadores[Separador]);
			strcat(mail, cliente1.nombre);
			strcat(mail, mailTerminaciones[Terminacion]);
			strcpy(cliente1.contacto.email, mail);

			/*
			printf("Nombre: %s %s || ", nombres[nombre], apellidos[apellido]);
			printf("DNI: %d || Telefono: %d\n", dni, telefono)
			printf("Fecha de Nacimiento: %0d/%0d/%d\n", dia, mes, año);
			printf("Domicilio: %s %d || ", calles[calle], altura);
			printf("Codigo Postal: %d\n", postal);
			printf("Ciudad: %s || ", ciudades[ciudad]);
			printf("Provincia: %s", provincias[provincia]);
			printf("Mail: %s\n", mail);
			printf("\n\n");

			printf("Pulse una tecla para continuar...");
			_getch();
			
			*/
		
			fwrite(&cliente1, sizeof(cliente), 1, datos);

			contador++;

			avance = (contador * total) / numero;
			barra = avance/2.71;
			tiempo = (contador * CK) / 1000;
			

			gotoxy(0, 1);
			printf("\nGENERANDO REGISTRO %.f/%.f\n",contador,numero);
			gotoxy(15, 5);
			printf("%.1f%c\n\n", avance,37);
			gotoxy(0, 4);
			
			for (int i = 0; i < 37; i++) {
				printf(grey"%c", 178);
			}

			gotoxy(0, 4);


			for (int i = 0; i < barra; i++) {
				printf(yellow"%c"reset, 219);
			}

			gotoxy(0, 6);
			printf("TIEMPO: %.f segundos transcurridos\nESTIMADO: %02d:%02.f (mm/ss)", tiempo, minutosEstimados,segundosEstimados);
			Sleep(CK);

		}
		
	} while (aux != 0);
	
	fclose(datos);

	printf(green"\n\n\n     DATOS GUARDADOS EN ARCHIVO.\n\n"reset" Presione una tecla para continuar...");
	
	exportarDatos();

	//system("start C:\\Users\\walter.carral\\Desktop\\Ultima_Modificacion_HOY\\Hotel TPO\\datos_exportados.csv");

	getchar();

} 
	
void copiarCadena(char destino[], char origen[]) {

	int i;

	for (i = 0; origen[i] != '\0'; i++) {

		destino[i] = origen[i];

	}

	destino[i] = '\0';

}

void exportarDatos() {

	FILE* datos = fopen("data.bin", "rb");
	FILE* exportado = fopen("datos_exportados.csv", "w");

	cliente cliente1;

	if (datos == NULL) {
		printf(ERR_ABRIR_ARCHIVO);
		exit(1);
	}

	fread(&cliente1, sizeof(cliente), 1, datos);

	char espacio[] = " ";
	char coma[] = ", ";

	fprintf(exportado, "NOMBRE;APELLIDO;DNI;ESTADO CIVIL;DIRECCIOM;CIUDAD;PROVINCIA;MAIL;TELEFONO;CUMPLEAÑOS\n");

	while (feof(datos) == 0) {

		//Union de nombre de calle y altura en un unico array de caracteres, _itoa es para pasar un int a un char, el 10, significa q el numero es en decimal.

		char auxnombre[26];
		char altura[6];
		strcpy(auxnombre, cliente1.contacto.nCalle);
		int numero = cliente1.contacto.altura;
		_itoa(numero, altura, 10);
		strcat(auxnombre, espacio);
		strcat(auxnombre, altura);

		fprintf(exportado, "%s;%s;%d;%s;%s;%s;%s;%s;%d;%d/%d/%d\n",cliente1.nombre,cliente1.apellido,cliente1.dni,cliente1.eCivil,auxnombre,cliente1.contacto.ciudad,cliente1.contacto.provincia,cliente1.contacto.email,cliente1.contacto.telefono,cliente1.fNacimineto.dia, cliente1.fNacimineto.mes, cliente1.fNacimineto.anio);
		fflush(stdin);

		fread(&cliente1, sizeof(cliente), 1, datos);
	}

	fclose(datos);
	fclose(exportado);
}

void DetalleCliente_UI() {


	printf("\n    ");

	for (int j = 0; j < 83; j++) {
		if (j == 0) {
			printf(BGGB white "%c", 218); //201 218
		}
		if (j < 82) {
			printf("%c", 196); //205 196
		}
		else {
			printf(BGGB "%c", 191); //187 191
		}
	}

	printf("\n");
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    "BGGB white"%c"BGGB"                                                                                  %c%c\n"bgbtw, shadow);
	printf(bgbtw"    ");

	for (int j = 0; j < 83; j++) {
		if (j == 0) {
			printf(BGGB white"%c", 192); //200 192 
		}
		if (j < 82) {
			printf(BGGB"%c", 196); //205 196
		}
		else {
			printf("%c%c", 217, 219); //188 217
		}
	}

	//sombra borde inferior

	printf(bgbtw "\n     ");
	for (int i = 0; i < 84; i++) {
		printf(bgbb"%c"bgbb, 223);
	}

	//printf("\n");

}