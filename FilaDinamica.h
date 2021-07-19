
struct fila{
    int elemento;
    struct fila* prox;
};

typedef struct fila Fila;

int valor;

Fila* insere(Fila* f);
Fila* remove(Fila* f);
void imprime(Fila* f);
