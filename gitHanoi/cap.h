/*Programa: Torres de Hanoi
 Autor: Sergi Planes
 Data: 16/06/201
 Funcionalitat: Estructura de dades del programa */

//llibrerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constants utilitzades.
#define NUMDISCOS 3 //Especifica el nombre de discs 
#define NUMTORRES 3 //Indica el nombre de torres
#define SIZERES 20 //Indica el nombre de caracters del fitxer
#define MODE 2 //Emmagatzema ap o w segons el mode escollit
#define RES 2 //Emmagatzema una resposta (Si/No)
#define ESPAIS 14 //Linia de guionets al final de cada dibuix de torres

//Estructures de dades
typedef int torres[NUMTORRES]; //Vector que emmagatzema els discs de cada torre
typedef torres *joc[NUMTORRES]; //Matriu de vectors de discs 


//Funcions utilitzades.
void imprimir_hora(FILE *f);
void imprimir_capcalera_ini(FILE *f, int nd, char mode[MODE]);
void imprimir_capcalera_fin(FILE *f, int nd, char mode[MODE]);
void visualitzacio_mov(FILE *f, int nd, char mode[MODE]);
void visualitzar_mov(int n);
int buscar_mode(char **argv);
int buscar_fitxer(char **argv);
int buscar_discos(char **argv);
void dibuixar_config_ini(FILE *f, int nd);
void dibuixar(FILE *f, int nd, int v[NUMTORRES][nd]);
void move(int nd, int towerorg, int towerdest, int depth, FILE *f);
void hanoi(int nd, int towerorg, int towerdest, int toweraux, int depth, FILE *f);
void swap(int *v, int i, int j);
void ordena_major_menor(int *v);
void alliberar_matriu(int *mat[NUMTORRES]);
//void inicialitzar_matriu((int *v)**v);
void moure_disc(int *v[NUMTORRES], int towerorg, int towerdest, int nd);




