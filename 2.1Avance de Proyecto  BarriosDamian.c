#include <stdio.h>
#include <stdlib.h>
#include "Principal.h"

short opcionmenu();		/*Validar opcion del menu.*/

short menu_inicio();//MENU PRINCIPAL
void submenu(Vector pj);//SUBMENU MOSTRAR

void submenuE(Vector *pj);//SUBMENU ELIMINAR

void submenuC(Vector *pj);//SUBMENU COMBATE
int main() {
	short opt;
	Vector pj;
	iniciaT(&pj);
	opt=menu_inicio(); //PRESIONA ENTER PARA INICIAR...
	
	do{
		system("CLS"); //Borra la pantalla
		opt=opcionmenu();
		switch (opt){ //menu
			//1.Ingresar personaje.
		case 1:	
			CargarLista(&pj);
		break;
		//2.Eliminar personaje.
		case 2:
			submenuE(&pj);
		break;
		//3.Estados del personaje.
		case 3:
			submenu(pj);
		break;
		//4.Modificar personaje.
		case 4:
			CurarPersonaje(&pj);
		break;
		//5.Combatir.
		case 5:
			submenuC(&pj);
		break;
		//0.Terminar programa.
		case 0:printf ("\nFIN DEL PROGRAMA\n");
		break;
		}
		system("PAUSE");//Pausa la ejecución del programa.
	}while (opt!=0);
	
	return 0;
}

short menu_inicio(){// enter para iniciar el programa
	char op;
	do{
		printf("-----PRESIONA ENTER PARA INICIAR-----");
		scanf("%c",&op);
	}while(op!='\n');
	return op;
}
	
short opcionmenu(){
	short opcion;
	printf ("1 - Ingresar personaje.\n");
	printf ("2 - Eliminar personaje.\n");
	printf ("3 - Mostrar personaje.\n");
	printf ("4 - Curar un personaje.\n");
	printf ("5 - Combatir.\n");
	printf ("0 - Terminar programa.\n");
	do{
		printf ("\nSeleccion opcion:");
		scanf ("%hd",&opcion);
	} while(opcion<0 || opcion>5);
	return opcion;
}
	
short submenu_1(){
	short op;
	printf("1 - Elegir cual mostrar. \n");
	printf("2 - Mostrar todos.\n");
	printf("0 - Regresar.\n");
	do{
		printf ("Seleccione una opción:");
		scanf("%hd",&op);
	}while(op<0||op>2);
	return op;
}
		
void submenu(Vector pj){
	short opsubmenu1;
	do{
		system("CLS"); //Borra la pantalla
		opsubmenu1=submenu_1();
		switch (opsubmenu1){
			case 1:
				Mostrar_elegido(pj);
				break;
			case 2:
				Mostrar(pj);
				break;
			case 0:
				break;
		};
		system("PAUSE");//Pausa la ejecución del programa.
	}while (opsubmenu1!=0);
}
	
short submenu_E(){
	short op;
	printf("1 - Elegir uno a eliminar. \n");
	printf("2 - Eliminar todos los inactivos.\n");
	printf("0 - Regresar.\n");
	do{
		printf ("Seleccione una opción:");
		scanf("%hd",&op);
	}while(op<0||op>2);
	return op;
}
		
void submenuE(Vector *pj){
	short opsubmenuE;
	do{
		system("CLS"); //Borra la pantalla
		opsubmenuE=submenu_E();
		switch (opsubmenuE){
		case 1:
			eliminar_pj(pj);
		break;
		case 2:
			eliminar_inactivos(pj);
		break;
		case 0:
			break;
		};
		system("PAUSE");//Pausa la ejecución del programa.
	}while (opsubmenuE!=0);
}

short submenu_C(){
	short op;
	printf("1 - Combate a elegir personaje. \n");
	printf("2 - Combate aleatorio. \n");
	printf("0 - Regresar.\n");
	do{
		printf ("Seleccione una opción:");
		scanf("%hd",&op);
	}while(op<0||op>2);
return op;
}
		
void submenuC(Vector *pj){
int a,b;	
short opsubmenuC;
	do{
		system("CLS"); //Borra la pantalla
		opsubmenuC=submenu_C();
		switch (opsubmenuC){
		case 1:
			if (CantidadActivo(*pj)>1){
			SeleccionarPJ(*pj,&a,&b);
			Combate(pj,a,b);}
			else
				printf("\nNo hay personajes suficientes para jugar..\n");
			break;
		case 2:
			if (CantidadActivo(*pj)>1){
			SeleccionAleatorio(*pj, &a, &b);
			Combate(pj,a,b);}
			else
				printf("\nNo hay personajes suficientes para jugar..\n");
			break;
		case 0:
			break;
		};
		system("PAUSE");//Pausa la ejecución del programa.
	}while (opsubmenuC!=0);
}
