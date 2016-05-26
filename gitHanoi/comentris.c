/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Para la profundidad, necesitamos una variable que guarde la profundidad i
//se envie como parametro a las diferentes funciones hanoi.

//para pasar parametros al programa.
//main(int argc,char**argv)
//argv: string que recoje los diferentes parametros que se envian al programa.

/*
 * for (int i=0;i<argc;i++){
 *  if(){
 *     guardar aqui los valores.
 *  }
 * }
 * 
 */


/*
 * Punteros time
 * char *texto
 * (*texto)='z'
 * esto dice que donde apunte texto pongamos una 'z'
 * 
 * texto = 'z'
 * no funcionara
 * 
 * texto es la caja
 * *texto es el contenido de la direccion.
 * 
 * malloc ----> pedir memoria.
 * 
 * malloc(size)
 *  
 * sizeof(quanta memoria ocupa un tipo de datos)
 * 
 * Para 1 byte
 * char *t;
 * int tamaño = sizeof(char);
 * t=malloc(tamaño);
 * 
 * char *arr
 * arr = malloc(sizeof(char)*N);
 * 
 * 
 * liberar memoria
 * free(arr);
 * 
 * char *var;
 * var = malloc(sizeof( siezeof(char)*4)                        
 * 
 * var[0]='A'
 * |
 * |
 * [2]='D'
 * 
 * realloc(var,sizeof(char)+sizeof(var))
 * 
 * 
 * typedef struct{
 *  int a;
 *  int b;
 *  char c;
 * }estructura;
 * 
 *  estructura *var = malloc(sizeof(estructura)*3);
 * 
 * var[0].a =100
 * var[0].b =200
 * var[0].c ='p'
 * 
 * estructura *e;
 * e = malloc(sizeof(estructura));
 * (*e).a ='p'
 * e->a ='p'
 */ 