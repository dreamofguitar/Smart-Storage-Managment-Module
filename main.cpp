#include "libreria.h"   //libreria que engloba las demas librerias y estructuras
int main(){                 //funcion principal del programa
	srand(time(NULL));     //inicializacion de la semilla para la generacion de numeros aleatorios
	portada();             //funcion que imprime la portada de precentacion
	fflush(stdin);
	getch();
	fflush(stdin);
	login();              //funcion que inicial el programa y posteriormentepresenta los menus con las funciones restantes.
	

return 0;	
}
