/*Programa: Torres de Hanoi
 Autores: Sergi Planes
 Data: 16/06/2016
 Funcionalitat: Output per pantalla o per fitxer */

#include "cap.h"

void imprimir_hora(FILE *f) {
	time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        fprintf(f,"%s\n",output);
}


void imprimir_capcalera_ini(FILE *f, int nd, char mode[MODE]){
	fprintf(f, "================================================================================\n");
	//fprintf(f, "Command Line entered: %s\n",argv); 
	fprintf(f, "Number of Discs    : %d\n", nd);
	fprintf(f, "Output filename    : %s\n", f); 
	fprintf(f, "File Output Option : %s\n", mode); 
	fprintf(f, "\n");
	fprintf(f, "INIT  Time       : "); 
	imprimir_hora(f);
	fprintf(f,"\n");
	fprintf(f, "================================================================================");
}


void imprimir_capcalera_fin(FILE *f, int nd, char mode[MODE]){
	fprintf(f, "================================================================================\n");
	fprintf(f, "Number of Discs    : %d\n", nd);
	fprintf(f, "Output filename    : %s\n", f); 
	fprintf(f, "File Output Option : %s\n", mode); 
	fprintf(f, "\n");
	//fprintf(f, "Total Number Moves : %d\n",moves); 
	fprintf(f, "FIN  Time       : "); 
	imprimir_hora(f);
	fprintf(f, "================================================================================\n");
}


void dibuixar_config_ini(FILE *f, int nd) { //n: numero de discs
    int j,k,m,e,u, ralles, maximralles;
    int a=-1;
    int i=1;
    int F=nd;
    int g=nd;
    for(k=0;k<nd;k++)
    {
        fprintf(f,"D %d ",g-1);
        int count=0;
        m=i*2;
        for(j=F-1;j>0;j--)
            {
                fprintf(f,"·");
            }
        while(i<m)
        {
            fprintf(f,"-");
            i++;
            count++;
        }
       
        printf("|");
        i=i-count;
        while(i<m)
        {
            fprintf(f,"-");
            i++;
            count++;
        }
        
        for(j=F-1;j>0;j--)
        {
            fprintf(f,"·");
        }
        fprintf(f,"   ");
        for(e=0;e<NUMTORRES-1;e++)
        {
            int count2=0;
            while (u<nd)
            {
                fprintf(f,"·");
                u++;
                count2++;
            }
            u=u-count2;
            fprintf(f,"|");
            while (u<nd)
            {
                fprintf(f,"·");
                u++;
            }
            fprintf(f,"   ");
            u=0;
        }
        a++;
        fprintf(f,"\n");
        i=i-a;
        F=F-1;
        g=g-1;
    }
	maximralles=nd*(NUMTORRES*2)+ESPAIS;
    for(ralles=0;ralles<maximralles;ralles++)
    {
        fprintf(f,"-");
    }
    fprintf(f,"\n");
}

/*void inicialitzar_matriu(int *v[NUMTORRES], int nd) { //matriu de vectors ?????
	joc = (torre**)calloc(1,sizeof(nd*int)); //reservo espai per la primera fila
}*/

void visualitzacio_mov(FILE *f, int nd, char mode[MODE]) { //per la fase inicial, imprimir en fitxer tots els moviments
	imprimir_capcalera_ini(f,nd,mode);
	dibuixar_config_ini(f,nd);
	//int depth = 0;
	//inicialitzar_matriu(joc, nd); //inicialitzo matriu joc amb config inicial
    //hanoi(0,1,2,depth,f); //0,1,2 es poden posar numeros ?????????????????? si no, 3 defines
	imprimir_capcalera_fin(f,nd,mode);
}

void visualitzar_mov(int n) { //per la fase interactiva, imprimir per pantalla un moviment n concret
    /*int i;
    for(i = 0; i < moves; ++i) //imprimir la fila n-1 de la matriu joc ??????????????
		dibuixar(n);*/
}

