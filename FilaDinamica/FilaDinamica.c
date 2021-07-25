//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"
#define tam 30
#define tamFila 4

Fila* insere(Fila* p,int valor){//Função que insere um valor na Fila
     Fila* novo = (Fila*)malloc(sizeof(Fila));//Cria meu Nó através de uma alocação Dinâmica
     if(novo == NULL){//Verica a alocação
        printf("Erro na alocacao da memoria!!!");
        exit(1);//Encerra o programa
     }
         novo->dado=valor;//Valor digitado pelo usuário é inserido no Nó da Fila
         novo->prox=NULL;//Faz o Nó criado apontar para NULL
         //Se
         if(p == NULL){//Verifica se a lista está vazia e se estiver, insere um elemento no Ínicio
             p = novo;//Faz o ponteiro apontar para o elemento criado
         //Senão
         }else{//Lista tem elemento, sera inserido depois do primeiro elemento
        Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando

        while(aux->prox != NULL){//Enquanto o ponteiro for diferente de NULL, será executado
            aux = aux->prox;//Percorre até o final da lista
        }
        aux->prox=novo;//Faz o elemento anterior apontar para o elemento criado
    }
    return p;//retorna a Fila
}

Fila* removeFila(Fila* p){//Remove apenas o primeiro elemento da Fila ou elemento que está a mais tempo na fila
    if(p == NULL){//Verifica se a lista está vazia
        printf("Lista Vazia!");
        return;
    }
    Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando
    p = p->prox;//O ponteiro  recebe ele mesmo avançando para o proximo elemento
    free(aux);//Libera ou excluir o elemento para aonde o ponteiro esta apontando

    return p;//Retorna Fila
}

Fila* removeElemento(Fila* p,int valor){//Remove qualquer elemento da fila
    if(p == NULL){//Verifica se a Fila esta Vazia
        printf("Lista Vazia!");
        return p;//Retorna a Fila
    }

    if(p->dado == valor){//Remove o primeiro elemento da fila,caso o valor digitado pelo usuario seja o mesmo do inicio da Fila
         Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando
         p = p->prox;//O ponteiro  recebe ele mesmo avançando para o proximo elemento
             free(aux);//Libera ou excluir o elemento para aonde o ponteiro esta apontando
     return p;//Retorna Fila
    }

    Fila* atual= p,*ant=NULL;//Cria dois ponteiros auxiliares e atual recebe o p(inicio da Fila)

    while(atual != NULL && atual->dado != valor){//Procura o elemento na Fila
        ant =atual;//Recebe o inicio ou anterior do ponteiro atual
        atual = atual->prox;//atual recebe ele mesmo apontando para o proximo elemento    
    }
   
    if(atual == NULL){//Se atual for NULL, elemento não encontrado na Fila
        printf("\nElemento nao encontrado!!!\n");
        return p;//retorna Fila
    }else
    ant->prox = atual->prox;//Remove o elemento que estiver no meio da Fila

    free(atual);//Libera ou remove o elemento para o ponteiro estiver apontando
    return p;//Retorna Fila
}

void imprime(Fila* p){//Exibe na tela os elementos da Fila
    Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando
    if(p == NULL){
        printf("\nLista Vazia!!\n");
        return;
    }
    printf("\nFILA:");

    while(aux != NULL){
        printf(" | %d | ->",aux->dado);//Imprime os elementos
        aux = aux->prox;//Percorre até o final da Fila
    }
    printf(" NULL");
    printf("\n\n");
}

int tamanho(Fila* p){//Função que conta os elementos da Fila
    Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando
    int Contador = 0;//Variavel que conta os elementos da Fila

    while(aux != NULL){
        Contador++;//Incrementa a Variavel
        aux = aux->prox;//Percorre até o final da Fila
    }
    printf("\nO tamanho da Fila eh %d\n",Contador);//Imprime quantos elementos tem na Fila
    return Contador;//Retorna a quantidade de elementos
}

void criarLinhaSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i;
    printf("%c",201);
    for(i = 0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void criarLinhaRodape(int tamx){//Criar linhas duplas em baixo do Menu
    int i;
    printf("%c",200);
    for(i = 0;i<tamx;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

void CriarMenu(int tamx,char str[]){//Criar linhas duplas nas laterais do Menu
   int i,contador=0;
   for(i = 0;i<tamx;i++){
       if(str[i] == '\0')
       break;
       else
          contador++;
       }
    printf("%c",186);
        printf("%s",str);
     while(contador<tamx){
         printf("%c",32);
         contador++;
     }
    
    printf("%c\n",186);
}
void menu(){
   system("color F4");//Define a cor do terminal (4->Fundo e F->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu");
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Inserir");
   CriarMenu(tam,"2 - remover");
   CriarMenu(tam,"3 - Remover elemento");
   CriarMenu(tam,"4 - Tamanho");
   CriarMenu(tam,"5 - Imprime");
   criarLinhaRodape(tam);
}