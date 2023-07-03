//Parte privada del Tad.
#include <stdio.h>
#include <string.h>
#include "TadCadena.h"
void leecads(Tcad c, int tam ){
	int j=0,m;
	
	while (j<tam-1&&(m=getchar())!=EOF && m!='\n'){
		c[j]=m;
		j++;
	}
	c[j]='\0';
	while (m!=EOF && m!='\n')
		m=getchar();
}

