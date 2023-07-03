#include "Principal.h"
#include <stdio.h>

void iniciaT(Vector *x){//PUBLICO. INICIA TAMAÑO
	x->tam=0;
}
int SiNo(){
	int x;
	printf("Ingresar otro personaje...\nSi = 1\tNo = 0");
	do{
		printf("\nOpcion: ");
		scanf("%d",&x);
	} while(x<0 || x>1);
	return x;
}

int busqueda_binaria(Vec v,int tam, long Busc){//PRIVADO. BUSCA CODIGO
	int ini,fin,med;
	ini=1; 
	fin=tam;
	med=(ini+fin)/2;
	while((ini<=fin) && (BuscaD(v[med],Busc)==-1)){
		if(BuscaM(v[med],Busc)==-1) 
			fin= med-1;
		else
			ini= med+1;
	med=(ini+fin)/2;
	}
	if (ini<=fin) 
		return med;
	else 
		return -1;
}	

long validarCodigo(Vec v,int tam){//PRIVADO. VALIDA SI YA EXISTE EL CODIGO
	long x;
	int c;
	if (tam==0){
		printf ("Ingresa Codigo de personaje: ");
		scanf ("%ld",&x);}
	else{
		do{
			printf ("Ingresa Codigo de personaje: ");
			scanf ("%ld",&x);
			c=busqueda_binaria(v,tam,x);
		} while(c!=-1);}
	return x;
}
	
void Ordenar_Uno_Baraja_rec(Vec vec,int j){
	
	if (RetornarCodigo(vec[0])>= RetornarCodigo(vec[j]))
		vec[j+1]=vec[0];
	else {
		vec[j+1]=vec[j];
		Ordenar_Uno_Baraja_rec(vec,j-1);
	}	
}
	
void Carga_ordenado_validado_rec(Vec v, int tam){
	int pos;
	long codigo;
		
	printf("Ingrese un nro de cuenta:");
	scanf ("%ld",&codigo);
	pos = busqueda_binaria(v,tam,codigo);
		
	if (pos==-1){
		v[tam]=CargarPJ(codigo);
		v[0]= v[tam];
		Ordenar_Uno_Baraja_rec(v,tam-1);
	}	
	else
		Carga_ordenado_validado_rec(v,tam);
}

void carga_condicionada_rec(Vec v, int *tam){
	short op;
	op=SiNo();
		
	if (op!=0){
		*tam=*tam+1;
		Carga_ordenado_validado_rec(v, *tam);
		carga_condicionada_rec(v, tam);
	}
}

void Cargar_Vector(Vec v, int *tam){//PUBLICO.
	int x,j;
	long a;
	do{
		a=validarCodigo(v, *tam);
		v[0]=CargarPJ(a);
		j=*tam;
		printf ("TAMAÑO %d",*tam);
		while ((ComprarCodigo(v[0], v[j]))==-1){
			v[j+1]=v[j];
			j--;
		}	
		v[j+1]=v[0];
		*tam=*tam+1;
		x=SiNo();
	}while(x==1);
}
	
void CargarLista(Vector *x){//publico - cargar
	carga_condicionada_rec(x->PJ, &x->tam);
		
}
void CargarLista1(Vector *x){//publico - cargar
	Cargar_Vector(x->PJ, &x->tam);

}
void Mostrar_rec(Vec v, int tam){//MOSTRAR RECURSIVO.
	if (tam!=0){
		Mostrar_rec(v,tam-1);
		Mostrar_personaje(v[tam]);
	}
}
void Mostrar(Vector v){//publico
	Mostrar_rec(v.PJ,v.tam);
}

void Mostrar_elegido(Vector v){//se busca mediante el codigo y lo muestra.
	long Busc;
	int x;
	do{
		printf("Ingresa codigo de personaje a buscar: ");
		scanf ("%ld",&Busc);
		x=busqueda_binaria(v.PJ,v.tam,Busc);
	} while(x==-1);
	Mostrar_personaje(v.PJ[x]);
}
	
void Eliminar_Registro(Vec ListaPj, int tam, int posPj){ //es necesario implementar eliminar registro porque se lo va a llamar dentro del siguiente modulo
	int I;
	for(I=posPj; I<=tam; I++)
		ListaPj[I]= ListaPj[I+1]; //recorre el vector que contiene la struct "personaje"
}
		
void eliminar_pj(Vector *v){//publico
	int posPj, M=v->tam; 
	long cod;
	do{
		printf("\nIngresa codigo del personaje a eliminar: "); 
		scanf("%ld", &cod);
		posPj= busqueda_binaria(v->PJ, v->tam, cod);
	}while(posPj==-1);
	if (posPj!=-1){
		Eliminar_Registro(v->PJ, v->tam, posPj);
		v->tam=M-1;}
}
	
void eliminar_inactivos(Vector *v){//ELIMINA TODOS LOS INACTIVOS.//publico
	int a=1; 
	do{
		if(RetornarEstado(v->PJ[a])==0){
			Eliminar_Registro(v->PJ, v->tam, a);
			v->tam=v->tam-1;
			}
		else
			a=a+1;
	}while(a<v->tam);
}

int CantidadActivo(Vector x){//publico.
	int c=0,i;
	for (i=1; i<=x.tam ; i++)
		if (RetornarEstado(x.PJ[i])==1)
			c=c+1;
	return c;
}

int ValidarEstado(Vec a, int NP){//Busca y validar estado del personaje.
	int y;
	long x;
	do{
		printf ("Ingresa codigo para jugador: ");
		scanf ("%ld",&x);
		y=busqueda_binaria(a,NP,x);
		if (RetornarEstado(a[y])==-1){
			y=-1;
			printf ("\nEse personaje esta inactivo busque otros..\n");}
	}while (y==-1);
	return y;
}
void SeleccionarPJ(Vector v, int *a, int *b){ //SELECCIONAR PERSONAJE PARA PELEAR.//publico.
	*a=ValidarEstado(v.PJ,v.tam);
	do{
		*b=ValidarEstado(v.PJ,v.tam);
		if(*a==*b)
			*b=-1;
	}while (*b==-1);
}
	
void SeleccionAleatorio(Vector v, int *a, int *b){//publico.
	short y,z;
	do{
		y=generarNum(v.tam,1);
	} while(RetornarEstado(v.PJ[y])==-1);
	*a=y;
	MostrarNombre(v.PJ[y]);
	do{
		z=generarNum(v.tam,1);
	} while(RetornarEstado(v.PJ[z])==-1 || y==z);
	*b=z;
	MostrarNombre(v.PJ[z]);
}

int DeterminarTurno(Vec pj, int a, int b){ //DETERMINAR TURNO
	int x;
	x=CompareDestreza(pj[a], pj[b]);
	return x;
}
	
void herida(Vec pj, int a, int b){ //VECTOR GENERAL DE DAÑO EN COMBATE.
	short D;
	if (vergolpe(pj[a], pj[b])==1){
		D=GenerarD(pj[a]);
		printf ("\nEl daño = %d\n",D);
		VidaP((&pj[a]),D);
		MostrarNombre(pj[a]);
		printf ("\nVida restante= %hd\n",RetornaVida(pj[a]));}
}

void DeterminarGanador(Vec pj, int a, int b){
	if (Ganador(pj[a], pj[b])==-1){//EL PERSONAJE QUE TENGAS MAS VIDA ES EL GANADOR
		MostrarNombre(pj[a]);
		printf (" Salio victorioso\n");
		Victoria(&pj[a]); //CONTAR LA VICTORIOS
		Derrota(&pj[b]);} //CONTAR LAS DERROTAS
	else if(Ganador(pj[a], pj[b])==0)
		printf("\nEMPATE : Ninguno gana oro\n");
	else{
		MostrarNombre(pj[b]);
		printf (" Salio victorioso\n");
		Victoria(&pj[b]);
		Derrota(&pj[a]);}
}

void Combate(Vector *x, int a, int b){ //MODULO PRINCIPAL DE COMBATE 
	int Ronda,i=1;
	int aux;
	printf ("\nIngresa cantidad de rondas:");
	scanf ("%d",&Ronda);
	if (DeterminarTurno(x->PJ,a,b)!=1){ //VERIFICAMOS QUIEN VA PRIMERO
		aux=a;
		a=b;
		b=aux;}
	do{ printf ("\nRonda %d\n",i);
	herida(x->PJ,a,b); //EL PERSONAJE QUE GOLPEA PRIMERO
	herida(x->PJ,b,a); //EL PERSONAJE QUE GOLPEA SEGUNDO
	i=i+1;
	}while(i<=Ronda && RetornaVida(x->PJ[a])>0 && RetornaVida(x->PJ[b])>0); //CANTIDAD DE RONDAS A COMBATIR O HASTA QUE ALGUNO BAJE SU VIDA 1
	DeterminarGanador(x->PJ, a, b);
}

int SiNo2(){
	int x;
	printf ("\n¿Quieres curar un personaje por 5 de oro?\nSi = 1\tNo = 0\n");
	do{
		printf("\nOpcion: ");
		scanf("%d",&x);
	} while(x<0 || x>1);
	return x;
}
		
void CurarPersonaje(Vector *pj){
	int p;
	long Busc;
	do{
		printf("\nIngrese el codido del personaje a curar: ");
		scanf ("%ld",&Busc);
		p=busqueda_binaria(pj->PJ, pj->tam, Busc);
	}while(p==-1);
	if (SiNo2()==1)
		CuraDinero(&pj->PJ[p]);
}
