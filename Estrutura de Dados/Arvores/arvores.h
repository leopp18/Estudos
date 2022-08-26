typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
    int fb; //fator de balanceamento
} Arvore;

int calcularAltura(Arvore *raiz) {
    if (raiz) {
        int altEsq = calcularAltura(raiz->esq); //avançou completamente para a esquerda da árvore
        int altDir = calcularAltura(raiz->dir); //avançou completamente para a direita da árvore
        
        //testou a altura maior e retornou ela + 1
        if (altEsq > altDir) {
            return altEsq + 1;
        } else {
            return altDir + 1;
        }
    } else {
        return 0;
    }
}

Arvore *rodaEsquerda(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->dir;
    tmp = filho->esq;
    r = filho;
    filho->esq = pai;
    pai->dir = tmp;
    return r;
}

Arvore *rodaDireita(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->esq;
    tmp = filho->dir;
    r = filho;
    filho->dir = pai;
    pai->esq = tmp;
    return r;
}

void atualizarFB(Arvore *raiz) {
    if (raiz) {
        atualizarFB(raiz->esq);
        atualizarFB(raiz->dir);
        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);
    }
}

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else if (valor == raiz->valor) { //CONTROLE DE DUPLICADOS (EXERCICIO 1)
            return raiz;
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        raiz->fb = calcularAltura(raiz->esq) - calcularAltura(raiz->dir);

        //descobrir se esta ou nao balanceado
        if (raiz->fb == -2) { //rotacao para esquerda
            //descobrir se eh rotacao simples
            if (raiz->fb < 0 && raiz->dir->fb < 0) {
                raiz = rodaEsquerda(raiz);
            } else {
                //rotacao dupla
                //1 - rodar o filho para direita
                raiz->dir = rodaDireita(raiz->dir);
                //2 - rodar o pai para a esquerda
                raiz = rodaEsquerda(raiz);
            }
            //atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        } else if (raiz->fb == 2) { //rotacao para direita
            //descobrir se eh rotacao simples
            if (raiz->fb > 0 && raiz->esq->fb > 0) {
                raiz = rodaDireita(raiz);
            } else {
                //rotacao dupla
                //1 - rodar o filho para esquerda
                raiz->esq = rodaEsquerda(raiz->esq);
                //2 - rodar o pai para a direita
                raiz = rodaDireita(raiz);
            }
            //atualizar o fb dos nodos da raiz
            atualizarFB(raiz);
        }
        return raiz;
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;    
        novo->fb = 0; //todo nodo inserido, o fb é 0    
        return novo;
    }
}

Arvore *excluir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) { //valor localizado e pronto pra exclusão
            //eh folha
            if (!raiz->esq && !raiz->dir) {
                free(raiz);
                return NULL;
            } else {
                Arvore *novoPai;
                Arvore *p;
                if (raiz->esq) novoPai = raiz->esq;
                else novoPai = raiz->dir;
                
                for (p = novoPai; p->dir; p = p->dir);

                p->dir = raiz->dir;

                free(raiz);
                return novoPai;
            }
        } else {
            if (valor < raiz->valor) { //avancar para esquerda
                raiz->esq = excluir(valor, raiz->esq);
            } else { //avancar para direita
                raiz->dir = excluir(valor, raiz->dir);
            }
        }
        return raiz;
    }
    return NULL;
}

void exibir(Arvore *raiz, int nivel) {
    if (raiz) {
        exibir(raiz->dir, nivel + 1); //empilhando tudo para direita, busca-se exibir os maiores primeiro
        
        for (int i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << raiz->valor << "->" << raiz->fb << endl; 

        exibir(raiz->esq, nivel + 1); //empilhando tudo para esquerda, busca-se exibir os menores
    }
}

int localizarNivel(int valor, Arvore *raiz) {
    if(raiz) {
        if(valor == raiz->valor) return 0;
        if(valor < raiz->valor) {
            // Ir para esquerda
            int resposta = localizarNivel(valor, raiz->esq);
            if(resposta == -1) return -1; // Se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        } else {
            // Ir para direita
            int resposta = localizarNivel(valor, raiz->dir);
            if(resposta == -1) return -1; // Se a volta do empilhamento vem -1, continuamos enviando -1
            return resposta + 1;
        }
    } else {
        return -1; // Chegou nas folhas e o valor nao foi localizado
    }
}

Arvore *menorElemento(Arvore *raiz) {
    if (!raiz) return NULL;
    Arvore *p;
    
    for (p = raiz; p->esq; p = p->esq);

    return p;
}

Arvore *maiorElemento(Arvore *raiz) {
    if (!raiz) return NULL;

    Arvore *p;
    for (p = raiz; p->dir; p = p->dir);

    return p;
}

int verificarNiveis(Arvore *raiz) {
    int maior = maiorElemento(raiz)->valor;
    int menor = menorElemento(raiz)->valor;

    if(localizarNivel(maior, raiz)==localizarNivel(menor, raiz)){
        return 1;
    } else {
        return 0;
    }
}

int contarVezes(int valor, Arvore *raiz) {
    if (raiz) {
        int qtdVezesEsquerda = contarVezes(valor, raiz->esq);//empilhar tudo para esquerda
        int qtdVezesDireita = contarVezes(valor, raiz->dir);//empilhar tudo para direita

        //testar, ou seja, o teste vem das folhas em direção a raiz
        if (valor == raiz->valor) return 1 + qtdVezesEsquerda + qtdVezesDireita;
        return 0 + qtdVezesEsquerda + qtdVezesDireita;
    } else {
        return 0;
    }
}

Arvore *popular(Arvore *raiz){
	//ifstream -> input ou ler
	//ofstream -> output ou escrever
	
	ifstream procurador;
	char nomeArquivo[100];
	
	cout << "Insira o nome do arquivo com os valores: ";
	cin >> nomeArquivo;
	
	procurador.open(nomeArquivo);
	
	if (!procurador) {
		cout << "Arquivo nao encontrado\n";
		return NULL;
	}
	
	string linha;
	int valor;
	
	while (getline(procurador,linha)){
		stringstream pegaInteiro(linha);
		pegaInteiro >> valor;    
		raiz = inserir(valor, raiz);
	}
	
	procurador.close();
	return raiz;
}