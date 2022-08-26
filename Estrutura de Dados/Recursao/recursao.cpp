#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserirR(int valor, Celula *lista) {
    if(lista && valor > lista->dado) {
        lista->prox = inserirR(valor, lista->prox);
        return lista;
    } else {
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->dado = valor;
        novo->prox = lista;
        return novo;
    }
}

void exibirR(Celula *lista) {
    if(lista) {
        cout << lista->dado << endl;
        exibirR(lista->prox);
    }
}

int contarNosR(Celula *lista) {
    if(lista) {
        return 1 + contarNosR(lista->prox);
    }
    return 0; //percorreu toda lista
}

int somarR(Celula *lista) {
    if(lista) {
        return lista->dado + somarR(lista->prox);
    }
    return 0; //percorreu toda lista
}

int contarParesR(Celula *lista) {
    if(lista) {
        if(lista->dado % 2 == 0) 
            return 1 + contarParesR(lista->prox);
        return 0 + contarParesR(lista->prox);
    }
    return 0;
}

int somarParesR(Celula *lista) {
    if(lista) {
        if(lista->dado % 2 == 0)
            return lista->dado + somarParesR(lista->prox);
        return 0 + somarParesR(lista->prox);
    }
    return 0;
}

int main () {
    Celula *lista = NULL;
    lista = inserirR(45, lista);
    lista = inserirR(5, lista);
    lista = inserirR(4, lista);
    lista = inserirR(12, lista);
    lista = inserirR(8, lista);

    exibirR(lista);
    cout << "A quantidade de elementos eh: " << contarNosR(lista) << endl;
    cout << "A soma dos elementos eh: " << somarR(lista) << endl;
    cout << "A quantidade de elementos pares eh: " << contarParesR(lista) << endl;
    cout << "A soma dos elementos pares eh: " << somarParesR(lista) << endl;
}
