struct fila{//Estrutura ou Registro
     int dado;//valor do tipo inteiro
     struct fila* prox;//Ponteiro que apontara para o proximo elemento ou NULL
};

typedef struct fila Fila;//Cria um apelido para chamar o Registro

//Protótipos de funções
Fila* insere(Fila* p,int valor);
Fila* removeFila(Fila* p);
Fila* removeElemento(Fila* p,int valor);
void imprime(Fila* p);
int tamanho(Fila* p);