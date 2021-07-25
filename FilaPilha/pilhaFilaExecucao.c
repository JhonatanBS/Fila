#include <stdio.h>
#include <stdlib.h>
#include "pilhaFila.c"

int main (){
    Fila* F=NULL;
    Pilha* P=NULL;
    int opcao=1,i,valor,v,tamanho = 0;
      
     do{
         menuPrincipal();
         printf("\nEscolha uma das opcoes:");
         scanf("%d",&opcao);
             switch(opcao){
                 case 0:
                 printf("\nPrograma finalizado com Sucesso!");
                     break;
                 case 1:
                     printf("\nQuantos elementos quer inserir na FILA:");
                     scanf("%d",&v);
                         for(i = 0;i<v;i++){
                             printf("Digite o valor para a Fila:");
                             scanf("%d",&valor);
                             F=insere(F,valor);
                         }
                         imprimeFila(F);
                         tamanhoFila(F);
                        
                         
                         menuFila();
                         printf("\nEscolha uma das opcoes:");
                         scanf("%d",&opcao);
                             tamanho = tamanhoFila(F);
                                 if(opcao == 1){
                                     Fila* aux = F;
                                         while(aux != NULL){
                                          P =push(P,aux->valorFila);
                                          aux = aux->proxFila;
                                         }
                            }else if(opcao == 2){
                                for(i = 0; i< tamanho;i++){
                                     int cap = capturaFila(F);
                                     F = removeFila(F);
                                     P = push(P,cap);
                                }
                              
                            }else{
                                printf("Opcao Invalida");
                            }
                            imprimeFila(F);
                            imprimePilha(P);
                            F = liberaFila(F);
                            P = liberaPilha(P);
                     break;
                 case 2:
                     printf("\nQuantos elementos quer inserir na PILHA:");
                     scanf("%d",&v);
                         for(i = 0;i<v;i++){
                             printf("Digite o valor para a Pilha:");
                             scanf("%d",&valor);
                             P=push(P,valor);
                         }
                         imprimePilha(P);
                         menuPilha();
                         printf("\nEscolha uma das opcoes:");
                         scanf("%d",&opcao);
                            tamanho = tamanhoPilha(P);
                            
                            if(opcao == 1){
                               Pilha* aux = P;
                                         while(aux != NULL){
                                          F =insere(F,aux->valorPilha);
                                          aux = aux->proxPilha;
                                         }
                            }else if(opcao == 2){
                                for(i = 0; i< tamanho;i++){
                                     int cap = capturaPilha(P);
                                     P = removePilha(P);
                                     F = insere(F,cap);
                                }
                              
                            }else{
                                printf("Opcao Invalida");
                            }
                            imprimePilha(P);
                            imprimeFila(F);
                            F = liberaFila(F);
                            P = liberaPilha(P);
                     break;
                 default:
                 printf("\nOpcao Invalida!\n\n"); 
                     break;
                               
             }
    
     }while (opcao != 0);
    return 1;
}