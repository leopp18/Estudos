//em lista
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

typedef struct no {
	int valorGlicemia;
	string data;
	string hora;
	struct no *prox;
} Celula;

Celula *inserirLista(int valor, Celula *lista){
	// 3 ponteiros; novo, p, p retaguarda
	Celula *novo, *p, *pR;
	
	//alocar
	novo = (Celula *)malloc(sizeof(Celula));
	
	//depositar
	novo->valorGlicemia = valor;
	novo->prox = NULL;
	
	//localizar onde inserir
	//testar para primeira vez
	if (!lista) return novo;
	
	for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
		if (valor < p->valorGlicemia) { //encontrei a posição
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

void exibirLista(Celula *lista) {
	if (!lista) {
		cout << "Lista vazia\n";
		return;
	}
	Celula *p;
	for (p = lista; p; p=p->prox){
		cout << p->valorGlicemia << endl;
	}
}

int contarNos(Celula *lista) {
    int quant = 0;
    Celula *p;
    for (p = lista; p ; p = p->prox){
        quant++;
    }
    return quant;
}

float media(Celula *lista){
	float soma = 0;
	Celula *p;
	for (p = lista; p; p = p->prox){
		soma += p->valorGlicemia;
	}
	return soma / contarNos (lista);
}

float mediana(Celula *lista) {
	int quantidade = contarNos(lista);
	bool ehPar;
	
	if (quantidade % 2 == 0) {
		ehPar = true;
	}
	else {
		ehPar = false;
	}
	
	int i;
	int metade;
	Celula *p;
	if (!ehPar) {
		metade = (int)quantidade/2;
	} else {
		metade = (int)quantidade/2-1;		
	}
	for (i=0, p = lista; i < metade; i++, p = p->prox);
	
	if (!ehPar) return p->valorGlicemia;
	return (p->valorGlicemia + p->prox->valorGlicemia)/2;
}

int menor(Celula *lista) {
	if (lista) return lista->valorGlicemia;
}

int maior(Celula *lista) {
	
	Celula *p;
	for (p = lista; p->prox; p = p->prox);
	
	return p->valorGlicemia;
}

Celula *popularDoArquivoPilha(Celula *pilha){
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
	string glicemia;
	int valor;
	int posicaoEspaco;
	while (getline(procurador,linha)){
		posicaoEspaco = linha.find(" ");
	    //extrair glicemia
	    glicemia = linha.substr(0,posicaoEspaco);
		stringstream pegaInteiro(glicemia);   //Integer.parseInt em c++
		pegaInteiro >> valor;              //Integer.parseInt em c++
		
		//pilha = inserirPilha(valor, pilha); //inserção ordenada
	}
	
	procurador.close();
	return pilha;
}

Celula *popularDoArquivoLista(Celula *lista){
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
	string glicemia;
	int valor;
	int posicaoEspaco;
	while (getline(procurador,linha)){
		posicaoEspaco = linha.find(" ");
	    //extrair glicemia
	    glicemia = linha.substr(0,posicaoEspaco);
		stringstream pegaInteiro(glicemia);   //Integer.parseInt em c++
		pegaInteiro >> valor;              //Integer.parseInt em c++
		
		lista = inserirLista(valor, lista); //inserção ordenada
	}
	
	procurador.close();
	return lista;
}

int main () {
	Celula *lista = NULL;
	Celula *pilha = NULL;
	
	//pilha = popularDoArquivoPilha(pilha);
	lista = popularDoArquivoLista(lista);
	
	exibirLista(lista);
	
	cout << "A lista contem " << contarNos (lista) << " elementos.\n";
	cout << "O valor medio da lista eh " << media (lista) << ".\n";
	cout << "A mediana da lista eh " << mediana (lista) << ". \n";
	cout << "O menor valor da lista eh " << menor (lista) << ".\n";
	cout << "O maior valor da lista eh " << maior (lista) << ".\n";
	
	return 1;
}