#include <stdio.h>
#include <stdlib.h>
#include "pilhaFila.h"
#define tam 40// Constante para a função menu

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

Pilha* push(Pilha* topo,int x){//Função que cria elementos para a Pilha
    Pilha* novo =(Pilha*)malloc(sizeof(Pilha));//Alocação Dinamica
    if(novo == NULL){//Verifica a alocação
        printf("Erro na alocacao de memoria!");
        exit(1);//encerra o programa 
    }
    novo->valorPilha=x;//Faz o nó criado receber o valor do usuário
    novo->proxPilha=topo;//Faz novo apontar para topo
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

Fila* removeFila(Fila* p){//Funçao que remove o primeiro elemento da Fila
    Fila* aux = p;//Cria uma variável auxiliar
    p = p->proxFila;//Faz o ponteiro avançar e apontar para o proximo elemento
    free(aux);//Libera aux
    return p;
}

Pilha* removePilha(Pilha* topo){//Função que remove o ultimo elemento da Pilha
    Pilha* aux = topo;//Cria uma variável auxiliar
    topo = topo->proxPilha;//Faz o ponteiro avançar e apontar para o proximo elemento
    free(aux);//Libera aux
    return topo;
}

int tamanhoFila(Fila* p){//Função que conta o tamanho da Fila
    Fila* aux = p;//Ponteiro auxiliar
    int contador = 0;//Variavel para armazenar o tamanho
    while(aux != NULL){
       contador++;//Incremento
       aux =aux->proxFila;//Percorre os elementos até chegar em NULL
    }
    printf("Tamanho: %d\n\n",contador);//Mostra na tela o tamanho da Fila
    return contador;
}

int tamanhoPilha(Pilha* topo){//Função que conta o tamanho da Pilha
    Pilha* aux = topo;//Ponteiro auxiliar
    int contador = 0;//Variavel para armazenar o tamanho
    while(aux != NULL){
       contador++;//Incrementa
       aux =aux->proxPilha;//Percorre os elementos até chegar em NULL
    }
    printf("Tamanho: %d\n\n",contador);//Mostra na tela o tamanho da Pilha
    return contador;
}

int capturaFila(Fila* p){//Funçao que pega o primeiro valor da Fila
    Fila* aux = p;//Variavel auxiliar
    int valor = aux->valorFila;//Faz a variavel receber o valor do elemento 
    return valor;//retorna o valor
}

int capturaPilha(Pilha* p){//Funçao que pega o ultimo valor da Fila
    Pilha* aux = p;//Variavel auxiliar
    int valor = aux->valorPilha;//Faz a variavel receber o valor do elemento
    return valor;//retorna o valor
}

Fila* liberaFila(Fila* p){//Destroi a Fila
    Fila* ant = p;//Ponteiro auxiliar
    //Vai avançando e liberando a memória
    while(p != NULL){
        ant = p;
        p = p->proxFila;
        free(ant);//Libera ant
    }
    free(p);//libera p
    return p;
}

Pilha* liberaPilha(Pilha* topo){//Destroi a Pilha
    Pilha* ant = topo;//Ponteiro auxiliar
    //Vai avançando e liberando a memória
    while(topo != NULL){
        ant = topo;
        topo = topo->proxPilha;
        free(ant);//Libera ant
    }
    free(topo);//Libera topo
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
   system("color F0");//Define a cor do terminal (F->Fundo e 0->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu Principal");
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Inserir na FILA");
   CriarMenu(tam,"2 - Inserir na PILHA");
   criarLinhaRodape(tam);
}

void menuFila(){
   system("color F0");//Define a cor do terminal (F->Fundo e 0->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu FILA");
   CriarMenu(tam,"1 - Faz uma copia para PILHA");
   CriarMenu(tam,"2 - Faz uma transferencia para PILHA");
   criarLinhaRodape(tam);
}

void menuPilha(){
   system("color F0");//Define a cor do terminal (F->Fundo e 0->Cor das letras)
   criarLinhaSuperior(tam);
   CriarMenu(tam,"Menu PILHA");
   CriarMenu(tam,"1 - Faz uma copia para FILA");
   CriarMenu(tam,"2 - Faz uma transferencia para FILA");
   criarLinhaRodape(tam);
}