/*Programa: Torres de Hanoi
 Autores: Sergi Planes
 Data: 16/06/2016
 Funcionalitat:Ordenació */

#include "cap.h"

//Intercanvia dues posicions d'un vector per fer l'ordenacio
void swap(int *v, int i, int j){
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Ordenacio pel metode bombolla del vector v de tamany n de menor a major
void ordena_menor_major(int *v, int n) { 
	int i, j;
	for(i = 0; i < n-1; ++i) {
		for(j = n-1; j > i; --j) {
			if(v[j] < v[j-i]) {
				swap(v,j,j-1);
			}
		}
	}
}