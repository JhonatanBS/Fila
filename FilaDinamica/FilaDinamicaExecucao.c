
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.c"

int main(){
  Fila* F = NULL;//Inicia a Fila apontando para NULL ou nada
  int opcao = 1, numero;//Variaveis

   do{
       menu();
       printf("\nDigite um valor para o Menu:");
       scanf("%d",&opcao);

       switch(opcao){
           case 0:
           printf("\nPrograma Finalizado!!!");
           break;
           case 1:
           printf("Digite um numero para ser inserido:");
           scanf("%d",&numero);
           F=insere(F,numero);
           break;
           case 2:
           F=removeFila(F);
           break;
           case 3:
           printf("Digite o valor para ser removida da Fila:");
           scanf("%d",&numero);
           F=removeElemento(F,numero);
           break;
           case 4:
           tamanho(F);
           break;
           case 5:
           imprime(F);
           break;
       }
     }while(opcao != 0);//Fim do While
     free(F);//Libero F
  return 0;
}