#include <stdlib.h>
#include <stdio.h>
#include "FilaDinamica.h"

Fila* insere(Fila* f){
   Fila* novo = (Fila*)malloc(sizeof(Fila));
   if(novo == NULL){
       printf("Erro na alocação de Memoria!");
       exit(1);
   }
   
   printf("Digite um valor:");
   scanf("%d",&novo->elemento);

   if(f == NULL){
     novo->prox=f;
     f->prox=novo;
     return f;
   }
}

Fila* remove(Fila* f){

}

void imprime(Fila* f){

}
