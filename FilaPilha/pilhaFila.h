//Registros
struct pilha{
    int valorPilha;
    struct pilha* proxPilha;
};

struct fila{
    int valorFila;
    struct fila* proxFila; 
};
//Criando apelidos para as duas structs
typedef struct pilha Pilha;
typedef struct fila Fila;

//Funções e Métodos
Fila* insere(Fila* p,int valor);
Pilha* push(Pilha* topo,int x);
void imprimeFila(Fila* p);
void imprimePilha(Pilha* topo);
Fila* removeFila(Fila* p);
Pilha* removePilha(Pilha* topo);
int tamanhoFila(Fila* p);
int tamanhoPilha(Pilha* topo);
int capturaFila(Fila* p);
int capturaPilha(Pilha* p);
Fila* liberaFila(Fila* p);
Pilha* liberaPilha(Pilha* topo);

//Funções para o Menu
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);
void menuPrincipal();
void menuFila();
void menuPilha();