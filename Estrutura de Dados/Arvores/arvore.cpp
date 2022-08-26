#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

#include "arvores.h"

int main() {
    Arvore *raiz = NULL;
    raiz = popular(raiz);
    exibir(raiz,0);
   
    cout << "O menor e maior elemento estao no mesmo nivel? " << verificarNiveis(raiz) << endl;

    cout << "A altura desta arvore eh: " << calcularAltura(raiz) << endl;

     cout << "Menor valor: " << menorElemento(raiz)->valor << endl;
     cout << "Maior valor: " << maiorElemento(raiz)->valor << endl;

    return 1;
}