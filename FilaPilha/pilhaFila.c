#include <stdio.h>
#include <stdlib.h>
#include "pilhaFila.h"
#define tam 40

Fila* insere(Fila* p,int valor){//Função que insere um valor na Fila
     Fila* novo = (Fila*)malloc(sizeof(Fila));//Cria meu Nó através de uma alocação Dinâmica
     if(novo == NULL){//Verica a alocação
        printf("Erro na alocacao da memoria!!!");
        exit(1);//Encerra o programa
     }
         novo->valorFila=valor;//Valor digitado pelo usuário é inserido no Nó da Fila
         novo->proxFila=NULL;//Faz o Nó criado apontar para NULL
         //Se
         if(p == NULL){//Verifica se a lista está vazia e se estiver, insere um elemento no Ínicio
             p = novo;//Faz o ponteiro apontar para o elemento criado
         //Senão
         }else{//Lista tem elemento, sera inserido depois do primeiro elemento
        Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando

        while(aux->proxFila != NULL){//Enquanto o ponteiro for diferente de NULL, será executado
            aux = aux->proxFila;//Percorre até o final da lista
        }
        aux->proxFila=novo;//Faz o elemento anterior apontar para o elemento criado
    }
    return p;//retorna a Fila
}
Pilha* push(Pilha* topo,int x){
    Pilha* novo =(Pilha*)malloc(sizeof(Pilha));
    if(novo == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }
    novo->valorPilha=x;
    novo->proxPilha=topo;
    return novo;
}

void imprimeFila(Fila* p){//Exibe na tela os elementos da Fila
    Fila* aux = p;//Cria um ponteiro auxiliar e faz ele receber p ou para o ponteiro esta apontando
    if(p == NULL){
        printf("\nFila Vazia!!\n");
        return;
    }
    printf("\nFILA:");

    while(aux != NULL){
        printf(" | %d | ->",aux->valorFila);//Imprime os elementos
        aux = aux->proxFila;//Percorre até o final da Fila
    }
    printf(" NULL");
    printf("\n\n");
}

void imprimePilha(Pilha* topo){
    if(topo == NULL){
        printf("\nPilha Vazia!\n");
    }
    int i = 1;
    Pilha* p = topo;
        printf("\nPilha:\n");
         while(p != NULL){
            printf("\n| %d |",p->valorPilha);
                 if(i == 1){
                 printf(" <- TOPO");
                     i--;
                 }
            p = p->proxPilha;
         }
         printf("\n|NULL|\n\n");
}

Fila* removeFila(Fila* p){
    Fila* aux = p;
    p = p->proxFila;
    free(aux);
    return p;
}

Pilha* removePilha(Pilha* topo){
    Pilha* aux = topo;
    topo = topo->proxPilha;
    free(aux);
    return topo;
}

int tamanhoFila(Fila* p){
    Fila* aux = p;
    int contador = 0;
    while(aux != NULL){
       contador++;
       aux =aux->proxFila;
    }
    printf("Tamanho: %d\n\n",contador);
    return contador;
}

int tamanhoPilha(Pilha* topo){
    Pilha* aux = topo;
    int contador = 0;
    while(aux != NULL){
       contador++;
       aux =aux->proxPilha;
    }
    printf("Tamanho: %d\n\n",contador);
    return contador;
}

int capturaFila(Fila* p){
    Fila* aux = p;
    int valor = aux->valorFila;
    return valor;
}

int capturaPilha(Pilha* p){
    Pilha* aux = p;
    int valor = aux->valorPilha;
    return valor;
}

Fila* liberaFila(Fila* p){
    Fila* ant = p;
    while(p != NULL){
        ant = p;
        p = p->proxFila;
        free(ant);
    }
    free(p);
    return p;
}

Pilha* liberaPilha(Fila* topo){
    Fila* ant = topo;
    while(topo != NULL){
        ant = topo;
        topo = topo->proxFila;
        free(ant);
    }
    free(topo);
    return topo;
}

void criarLinhaSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i;
    printf("%c",201);
    for(i = 0;i<tamx;i++){
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
void menuPrincipal(){
   system("color F0");//Define a cor do terminal (4->Fundo e F->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu Principal");
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Inserir na FILA");
   CriarMenu(tam,"2 - Inserir na PILHA");
   criarLinhaRodape(tam);
}

void menuFila(){
   system("color F0");//Define a cor do terminal (4->Fundo e F->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu FILA");
   CriarMenu(tam,"1 - Faz uma copia para PILHA");
   CriarMenu(tam,"2 - Faz uma transferencia para PILHA");
   criarLinhaRodape(tam);
}

void menuPilha(){
   system("color F0");//Define a cor do terminal (4->Fundo e F->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu PILHA");
   CriarMenu(tam,"1 - Faz uma copia para FILA");
   CriarMenu(tam,"2 - Faz uma transferencia para FILA");
   criarLinhaRodape(tam);
}