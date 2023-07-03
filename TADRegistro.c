#include "TADRegistro.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


Personaje CargarPJ(long x){
	Personaje aux;
	aux.Cod=x;
	fflush(stdin);
	printf("\nIngrese nombre:");
	leecads(aux.nompj, TamMax);
	aux.ac=10;
	aux.hp=10;
	aux.arm1=6;
	aux.fue=10;
	aux.des=10;
	aux.sab=10;
	aux.vic=0;
	aux.der=0;
	aux.oro=20;
	aux.estado=1;
	return aux;
}

void Mostrar_personaje(Personaje aux){
	printf ("\nCodigo del  personaje: %ld",aux.Cod);
	printf("\nNombre: %s",aux.nompj);
	printf ("\nArmadura: %hd",aux.ac);
	printf ("\nVida: %hd",aux.hp);
	printf ("\nDaño arm del personaje: 1d%d",aux.arm1);
	printf ("\nFuerza: %hd",aux.fue);
	printf ("\nDestreza: %hd",aux.des);
	printf ("\nSaber: %hd",aux.sab);
	printf ("\nVictorias: %d",aux.vic);
	printf ("\nDerrotas: %d",aux.der);
	printf ("\nOro: %d",aux.oro);
	if (aux.estado==1)
		printf ("\nEstado: Activo\n");
	else 
		printf ("\nEstado: Inactivo\n");
}

void MostrarNombre(Personaje aux){
	printf("\nNombre: %s",aux.nompj);
}
	
int BuscaD(Personaje v,long busc){//Buscar Cod
	if (v.Cod!=busc)
		return -1;
	else
		return 0;
}
	
int BuscaM(Personaje v,long busc){//Buscar Cod}
	if (v.Cod>busc)
		return -1;
	else 
		return 0;
	}
int ComprarCodigo(Personaje a, Personaje b){
	if((a.Cod)<(b.Cod))
		return -1;
	else
		return 0;
}

int RetornarEstado(Personaje a){
	int x;
	x=a.estado;
	return x;
}

short RetornaVida(Personaje aux){
	short x;
	x=aux.hp;
	return x;
}

int RetornarCodigo(Personaje aux){
	int x;
	x=aux.Cod;
	return x;
}
void VidaP(Personaje *aux, short D){//RESTAR VIDA DE LOS PERSONAJE X DAÑO.
	(aux->hp)=((aux->hp)-D);
	if (aux->hp<=0)
		aux->estado=0;
}
		
void Victoria(Personaje *aux){ //CONTADOR DE VICTORIA.
	(aux->oro)=(aux->oro)+10;
	(aux->vic)=(aux->vic)+1;
}
			
void Derrota(Personaje *aux){ //CONTADOR DE DERROTA
	if (aux->oro>=10){
		(aux->oro)=(aux->oro)-10;
		(aux->der)=(aux->der)+1;}
	else{
		printf("\n%s No puedes pagar quedaras inactivo\n",aux->nompj);
		(aux->der)=(aux->der)+1;	
		aux->estado=0;}
}

short generarNum(int b,int a){	//modulo de generacion de numeros aleatorios.
	int na;
	na=rand()%(b-a+1)+a;
	return na;
}
		
		
int vergolpe(Personaje a, Personaje b){ //VALIDAR SI EL PERSONAJE GOLPEA A TU ENEMIGO.
	short intento;
	intento=generarNum(20,1);
	printf ("\n%s Intento a %s = %hd ", a.nompj, b.nompj, intento);
	if (b.ac<=intento){
		printf ("golpe!\n");
		return 1;}
	else
	printf ("Fallo\n");
	return 0;
}

short GenerarD(Personaje a){
	short x;
	x=generarNum(a.arm1,1);
	return x;
}

int CompareDestreza(Personaje a, Personaje b){
	if (a.des>b.des)
		return 1;
	else 
		return 0;
}
	
int Ganador(Personaje a, Personaje b){
	if (a.hp>b.hp)
		return -1;
	else 
		if (a.hp==b.hp)
			return 0;
		else
			return 1;
}

void CuraDinero(Personaje *aux){
	if (aux->oro>=5){
		(aux->oro)=(aux->oro)-5;
		(aux->hp)=10;
		printf ("\n%s Fue curado su vida actual es %hd\n",aux->nompj,aux->hp);
		printf ("Oro restante: %hd\n",aux->oro);}
	else 
		printf("No tiene oro suficiente\n");
}
