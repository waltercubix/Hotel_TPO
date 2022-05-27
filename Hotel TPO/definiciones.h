//librerias
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ERR_ABRIR_ARCHIVO   "ERROR! NO se pudo abrir el archivo de datos.\n< ESC > Para volver."
#define ERR_CERRAR_ARCHIVO  "ERROR! NO se pudo cerrar el archivo de datos.\n< ESC > Para volver."

#define BASE_DATOS          "data.bin"
#define AYUDA_M             "ayudaMod.txt"
#define AYUDA_EL            "ayudaEli.txt"
#define AYUDA_C             "ayudaCar.txt"
#define AYUDA_R             "ayudaRec.txt"

#define ESC      27           //Tecla Escape   
#define TECLA_A  97
#define TECLA_C  99
#define TECLA_D  100
#define TECLA_S  115
#define ENTER    13           //Tecla Enter
#define UNO      49           //Tecla Uno
#define DOS      50           //Tecla Dos
#define TRES     51           //Tecla Tres
#define CUATRO   52           //Tecla Cuatro
#define CINCO    53           //Tecla Cinco
#define SEIS     54           //Tecla Seis
#define T_DER    77           //Tecla Flecha Derecha
#define SHIFT_M  77
#define SHIFT_E  69
#define SHIFT_C  67
#define SHIFT_R  82
#define T_IZQ    75           //Tecla Flecha Izquierda
#define T_ARR    72           //Tecla Flecha Arriba
#define T_ABA    80           //Tecla Flecha Abajo
#define CK       80           //Clock Speed


//estructuras de datos

typedef struct { char nCalle[20], ciudad[25], provincia[25], pais[25], email[50]; int altura, cPostal, telefono;}direccion;
typedef struct { int anio, mes, dia; }fecha;
typedef struct { int nCliente; char nombre[15]; char apellido[15]; int dni; char eCivil[13]; int status; fecha fNacimineto; direccion contacto; }cliente;
typedef struct { float precio; char tipoHabitacion[12];}habitacion;
typedef struct { int nReserva; int noches; cliente huesped; habitacion tipo; }reserva;

//funciones
void portada();
void UI_Principal();
void DetalleCliente_UI();
void GenerarDatos();

//funciones para trabajar base de datos
void listarCliente();
void nuevaReserva();
void modificarReserva();
void recuReserva();
void escribirDatos();
int modificarDatos();
void borrarDatos();
void recuperarDatos();
int numeroCliente();
void imprimirDetalleContacto();
//void nuevaReserva();

//procedimientos
int ayuda();
void ayudaModificaciones();
void ayudaEliminaciones();
void ayudaCargar();
void ayudaRecuperaciones();
void acercade();
void volverAtras();
void integrantesGrupo();

//funciones para controlar la visibilidad del cursor y su posicion relativa

void hideCursor();
void showCursor();
void gotoxy(int x, int y);

//experimentales

void menuInicio();
void salirPrograma(); // cartel flotante usando coordenadas de x y
void barradeMenues();
void menuDesplegableAyuna();
void copiarCadena(char destino[], char origen[]);
void exportarDatos();


void tituloVentana(char const* Titulo);
void mostrarTablaClientes(int status);

//definiciones de formato para strings

#define reset    "\x1b[0m"
#define BGCWW    "\x1b[46m"  "\x1b[34m"   //fondo Cyan Letras Negro
#define BGgreen  "\x1b[42m"
#define BGcyan   "\x1b[46m"              //Fndo Cyan
#define BGWW     "\x1b[47m"              //Fondo Blanco
#define grey     "\x1b[90m"              //Letra Gris
#define BGWBB    "\x1b[47m"  "\x1b[34m"  //Fondo Blanco Letras Azul
#define yellow   "\x1b[33m"              //Letra Amarilla
#define red      "\x1b[31m"              //Letra Roja
#define Black    "\x1b[30m"              //letra negras
#define blue     "\x1b[34m"              //Letra Azul
#define green    "\x1b[32m"              //Letra Verde
#define BGrojo   "\x1b[41m"              //FondoRojo
#define BGGBL    "\x1b[106m" "\x1b[30m"   //Fondo Verde Letras negras
#define bgbtw    "\x1b[44m"  "\x1b[37m"  //fondo azul letra blanca
#define bgbb     "\x1b[44m"  "\x1b[30m"  //fondo azul letra negra
#define bgblack  "\x1b[40m"  "\x1b[37m"
#define white    "\x1b[97m"
#define BGGB     "\x1b[47m" "\x1b[30m"  //fondo gris claro letras en negro
#define BGGBR     "\x1b[47m" "\x1b[31m"  //fondo gris claro letras en rojo
#define BGGRR     "\x1b[100m" "\x1b[31m"    //fondo gris oscuro letras en rojo
#define BGGBB     "\x1b[100m" "\x1b[30m" //fondo gris oscuro letras en negro
//#define BGGWW    "\x1b[100m" "\x1b[97m"  //fondo gris letras en blanco
#define blink    "\x1b[37m"  "\x1b[5m"   //hace q el texto parpadee en blanco y gris claro
#define shadow   179,179,219             //Define las sombras de las ventanas
