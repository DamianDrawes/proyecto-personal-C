#ifndef TADREGISTRO_H
#define TADREGISTRO_H
#include "TadCadena.h"


typedef struct{
	long Cod;	/*Codigo del personaje para ordenar.*/
	Tcad nompj;	/*Nombre del personaje.*/
	short ac;	/*Armadura del personaje*/
	short hp;	/*Vida.*/
	int arm1;	/*Arma o daño.*/
	short fue; /*Fuerza del personaje*/
	short des;	/*Destreza del personaje*/
	short sab;	/*Inteligencia del personaje*/
	int vic;	/*Cantidad de victorias.*/
	int der;	/*Cantidad de derrotas.*/
	int oro;	/*Cantidad de dinero.*/
	int estado; /*1 activo - 0 inactivo*/
}Personaje;

Personaje CargarPJ(long x);/*CARGAR PERSONAJE*/
int BuscaD(Personaje v,long busc);/*DEVUELVE -1 SI ES DISTINTO, 0 NINGUNO.*/
int BuscaM(Personaje v,long busc);//-1 BUSCADO EN MENOR , 0 NINGUNO.
void Mostrar_personaje(Personaje aux);
void MostrarNombre(Personaje aux);
short RetornaVida(Personaje aux);
int RetornarCodigo(Personaje aux);
int ComprarCodigo(Personaje a, Personaje b);
int RetornarEstado(Personaje);
int CompareDestreza(Personaje a, Personaje b);
short generarNum(int b,int a);

void VidaP(Personaje *aux, short D);
void Victoria(Personaje *aux);
void Derrota(Personaje *aux);
int Ganador(Personaje a, Personaje b);
int vergolpe(Personaje a, Personaje b);
short GenerarD(Personaje a);
void CuraDinero(Personaje *aux);
#endif
