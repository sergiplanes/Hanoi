/*Programa: Torres de Hanoi
 Autores: Sergi Planes
 Data: 16/06/2016
 Funcionalitat: resoldre el joc de les torres de Hanoi*/

#include "cap.h"

void moure_disc(int *v[NUMTORRES], int towerorg, int towerdest, int nd) {
    int i;
    int trobat = 0;
    while(trobat != 1 && i < nd) {
        if(v[towerorg][i] != -1) {
            trobat = 1;
            v[towerdest][0] = v[towerorg][i];
            v[towerorg][i] = -1;
            ordena_menor_major(v[i],nd);
        }
    }
}

void dibuixar(FILE *f, int nd, int v[NUMTORRES][nd]) { //nd: numero de discs
    int g=nd;
    int ralles, maximralles;
    int i,j,p,q;

    for(j=0;j<nd;j++){
        fprintf(f,"D %d ",g-1);
        for(i=0;i<NUMTORRES;i++){
            if(v[i][j]==-1){//cas en que no hi ha cap disc
                int k;
                for(k=0;k<nd;k++){
                    fprintf(f,"·");
                }
                fprintf(f,"|");
                for(k=0;k<nd;k++){
                    fprintf(f,"·");
                }
                fprintf(f,"   ");
            }
            else {//cas per els valors diferents a -1 de dins la matriu 
                for(p=nd;p>v[i][j]+1;p--){
                    printf("·");
                }
                for(q=0;q<v[i][j]+1;q++){
                    fprintf(f,"-");
                }
                printf("|");
                for(q=0;q<v[i][j]+1;q++){
                    fprintf(f,"-");
                }
                for(p=nd;p>v[i][j]+1;p--){
                    fprintf(f,"·");
                }
                fprintf(f,"   ");
            }
        }
        fprintf(f,"\n");
        g=g-1;
    }
    maximralles=nd*(NUMTORRES*2)+ESPAIS;//dibuix de la linia divisòria entre iteracions. 
    for(ralles=0;ralles<maximralles;ralles++)
    {
        fprintf(f,"-");
    }
    fprintf(f,"\n");
}

void move(int nd, int towerorg, int towerdest, int depth, FILE *f){ 

    static int moves = 1;
    printf("Move count %2d Rec Depth %2d : it moves one disc from %d to %d\n", moves, depth, towerorg, towerdest); //Rec Depth: profunditat de la recursivitat
    
    moure_disc(*joc, towerorg, towerdest, nd); //matriu dels discs a cada torre (un moviment a cada crida recursiva)
    dibuixar(f,nd,(*joc));
    
    int i;
    for(i = 0; i < NUMTORRES; ++i) {
        joc[i] = (torre*)calloc(1,sizeof(nd*int)); //Reserva espai per una columna nova a cada crida resursiva, inicialitzada a 0
    }
    int j;
    if(joc[i] == NULL) printf("Error: problemes de memoria.\n");
    for(i = 0; i < NUMTORRES; ++i) { //copia de la fila anterior a la fila nova
        for(j = 1; j < moves; ++j) {
            joc[i][j] = joc[i][j-1];
        }
    }
    printf("\n");
    ++moves;
   
}

void hanoi(int nd, int towerorg, int towerdest, int toweraux, int depth, FILE *f){ 
    
    static int first = 1;

    if(first == 1) {
        depth = 1;
        first = 0;
    }

    else ++depth;

    if (nd == 1){
        move(nd, towerorg, towerdest, depth, f);
    }
    else{
        hanoi(nd - 1, towerorg, toweraux, towerdest, depth, f);
        move(nd, towerorg, towerdest, depth, f);
        hanoi(nd - 1, toweraux, towerdest, towerorg, depth, f);
    }                                                     
}