/*Programa: Torres de Hanoi
 Autores: Sergi Planes
 Data: 16/06/2016
 Funcionalitat: Menu Principal*/

#include "cap.h"

void alliberar_matriu(int *mat[NUMTORRES]) { //Alliberem l'espai de memoria reservat per la matriu joc, de manera que aquesta desapareix 
    /*int i;
    for(i = 0; i < NUMTORRES; ++i) {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;*/
}

int buscar_discos(char **argv) { //retorna la posicio on ha trobat -d; altrament, retorna -1
    int trobat=0;
    int i;
    while(trobat!=1)
    {
        if(strcmp(argv[i],"-d")) {
            trobat = 1;
            return i;
        }
        else i++;
    
    }
    return -1;
}

int buscar_fitxer(char **argv) { //retorna la posicio on ha trobat -f; altrament, retorna -1
    int trobat=0;
    int i;
    while(trobat!=1)
    {
        if(strcmp(argv[i],"-f")) {
            trobat = 1;
            return i;
        }
        else i++;
    
    }
    return -1;
}

int buscar_mode(char **argv) { //retorna la posicio on ha trobat -o; altrament, retorna -1
    int trobat=0;
    int i;
    while(trobat!=1)
    {
        if(strcmp(argv[i],"-o")) {
            trobat = 1;
            return i;
        }
        else i++;
    
    }
    return -1;
}

int main(int argc, char **argv) {
	//Fase inicial (resoldre el joc i guardar a memoria la llista de moviments)
    int discos;
    int pos_discos = buscar_discos(argv);
    if(pos_discos != -1) {
        *argv[pos_discos+1] -= '0'; //transformem char a int
        discos = *argv[pos_discos+1]; //guardem el num de discos
    }
    else discos = NUMDISCOS;
    int pos_mode = buscar_mode(argv);
    char mode[MODE];
    if(pos_mode != -1) strcpy(mode,argv[pos_mode+1]);
    else strcpy(mode,"ap");
    FILE *f;
    int pos_fitxer = buscar_fitxer(argv);
    char *fichero;
    if(pos_fitxer != -1) {
        if(strcmp(mode,"w")) {
            printf("Estas segur que vols sobreescriure el fitxer?(Si/no)\n");
            char resposta[RES];
            scanf("%s",&resposta);
            fichero = strcat(argv[pos_fitxer+1],".txt");
            if(strcmp(resposta,"si")) f = fopen(fichero,"w");
			else return(0);
        }
        else f = fopen(fichero, "a");
        visualitzacio_mov(f,discos,mode);
    }
    else visualitzacio_mov(stdout,discos,mode);  
    printf("El joc s'ha resolt satisfactoriament!\n");
    //Fase interactiva
    printf("Quin moviment vols consultar? (Premer -1 per acabar consultes)\n");
    int mov;
    scanf("%d",&mov);
    while(mov != -1) {
        printf("\n");
        printf("S'imprimira el moviment %d per pantalla:\n",mov);
        visualitzar_mov(mov);
        printf("Quin moviment vols consultar?\n");
        scanf("%d",&mov);
    }
    printf("El programa ha acabat.\n");
    fclose(f);
    //alliberar_matriu(joc);
    return (0);
}