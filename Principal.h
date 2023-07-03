#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "TADRegistro.h"
typedef Personaje Vec[TamMax]; //Vector de registro.

typedef struct{
	Vec PJ;
	int tam;
	
}Vector;
void iniciaT(Vector *x);
void CargarLista(Vector *);
void Mostrar(Vector );
void Mostrar_elegido(Vector );
void eliminar_pj(Vector *);
void eliminar_inactivos(Vector *);
void SeleccionarPJ(Vector, int *a, int *b );
void SeleccionAleatorio(Vector , int *a, int *b);
int CantidadActivo(Vector );
void Combate(Vector *, int a, int b);
void CurarPersonaje(Vector *);
#endif
