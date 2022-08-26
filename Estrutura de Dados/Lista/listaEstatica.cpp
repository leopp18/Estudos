//lista estática
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no {
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *lista){
	// 3 ponteiros; novo, p, p retaguarda
	Celula *novo, *p, *pR;
	
	//alocar
	novo = (Celula *)malloc(sizeof(Celula));
	
	//depositar
	novo->dado = valor;
	novo->prox = NULL;
	
	//localizar onde inserir
	//testar para primeira vez
	if (!lista) return novo;
	
	for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
		if (valor < p->dado) { //encontrei a posição
			break;
		} 
	}

	//engatar
	//testar no inicio
	if (p == lista) {
		novo->prox = lista;
		return novo;	
	} else if (!p) {   //testar no fim
		pR->prox = novo;
	} else {          // no meio
		pR->prox = novo;
		novo->prox = p;
	}
	//retornar o inicio da lista
	return lista;
}

void exibir(Celula *lista) {
	if (!lista) {
		cout << "Lista vazia\n";
		return;
	}
	Celula *p;
	for (p = lista; p; p=p->prox){
		cout << p->dado << endl;
	}
}

int contar(Celula *lista) {
  int contador = 0;
  Celula *p;
  for (p = lista; p ; p = p->prox) {
    contador++;
  }
  return contador;
}

int main () {
	Celula *lista = NULL;
	
	lista = inserir(2,lista);
	lista = inserir(1,lista);
	lista = inserir(10,lista);
	lista = inserir(4,lista);
	
	exibir(lista);
	
	cout << "\nA lista contem " << contar(lista) << " elementos\n";
	
	return 1;
}