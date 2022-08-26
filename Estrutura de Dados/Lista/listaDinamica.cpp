//lista dinâmica (arquivo externo)
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

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
    cout << "\n";
	if (!lista) {
		cout << "Lista vazia\n";
		return;
	}
	Celula *p;
	for (p = lista; p; p=p->prox){
		cout << p->dado << endl;
	}
}

Celula *popularDoArquivo(Celula *lista){
	//ifstream -> input ou ler
	//ofstream -> output ou escrever
	
	ifstream procurador;
	char nomeArquivo[200];
	
	cout << "Informe caminho e nome do arquivo com os valores: ";
	cin >> nomeArquivo;
	
	procurador.open(nomeArquivo);
	
	if (!procurador) {
		cout << "Arquivo nao encontrado\n";
		return NULL;
	}
	
	string linha;
	int valor;
	
	while (getline(procurador,linha)){
		stringstream pegaInteiro(linha);   //Integer.parseInt em c++
		pegaInteiro >> valor;              //Integer.parseInt em c++
		
		lista = inserir(valor, lista); //inserção ordenada
	}
	
	procurador.close();
	return lista;
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
	
	lista = popularDoArquivo(lista);
	
	exibir(lista);
	
	cout << "\nA lista contem " << contar(lista) << " elementos\n";
	
	return 1;
}