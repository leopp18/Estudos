//em pilha
//LIFO

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula)); //new

    //depositar valores do parametro
    novo->dado = valor;

    //engatar o novo elemento alocado no ultimo elemento
    novo->prox = topo;

    //retornar o novo topo
    return novo;
}

void exibir(Celula *topo) {
    if (!topo) {
        cout << "Pilha vazia!\n";
        return ;
    }
    Celula *p;
    for (p = topo; p != NULL; p = p->prox) { //rotina classica para percorrer uma pilha, lista simples, uma fila, etc......
        cout << p->dado << "\n";
    }
    cout << endl;
}

int contar(Celula *topo) {
    Celula *p;
    int qtd = 0;

    if (!topo) return qtd;

    for (p = topo; p != NULL; p = p->prox) {
        qtd++;
    }

    return qtd;
}

Celula *remover(Celula *topo){
    //testar se vazia
    if (!topo) {
        cout << "Pilha vazia\n";
        return topo;
    }
    
    //apontar lixo para o topo
    Celula *lixo;
    lixo = topo;

    //avancar o topo ao proximo elemento
    topo = topo->prox;

    //liberar o lixo
    free(lixo);

    //retornar o topo deslocado
    return topo;
}

Celula *localiza(int valor, Celula *topo) {
    if (!topo) {
        cout << "Pilha vazia!";
        return NULL;
    }
    Celula *p;
    for (p = topo; p != NULL; p = p->prox) {
        if (valor == p->dado) return p; //localizado o valor e retornado o endereco desse valor em p
    }
    return NULL;
}

int main() {
    ifstream procurador;

    char nomeArquivo[200];
    cout << "Nome do arquivo fonte com os numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);
    if (!procurador) {
        cout << "Arquivo nao localizado!\n";
        exit(0);
    }

    //daqui pra baixo
    int valor;
    Celula *pilha = NULL;
    do {
        procurador >> valor;
        pilha = inserir(valor,pilha);
    } while(!procurador.eof());
    procurador.close();

    exibir(pilha);
    cout << "A pilha contem " << contar(pilha) << " elementos" << endl;
    

    return 1;
}	