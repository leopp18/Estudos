// Fazer um sistema, baseado em menu, para retirar fichas normais e prioritárias em bancada de atendimento

#include <iostream>
#include <stdio.h>
#include "source.h"

using namespace std;

int main() {
    Fila filaNormal;         //numeros de 100 a 500
    Fila filaPrioritaria;    //numeros de 501 a 900
    
    int contadorFichaNormal = 100;
    int contadorFichaPrioritaria = 501;
    int ficha;
    int qtdAtendimentos = 1;

    inicializar(&filaNormal);
    inicializar(&filaPrioritaria);

    int op;
    char caracter;
    do {
        system("cls"); 
        cout << "Menu de atendimento" << endl;
        cout << "1 - Retirar ficha normal" << endl;
        cout << "2 - Retirar ficha prioritaria" << endl;
        cout << "3 - Atender ou chamar ficha" << endl;
        cout << "4 - Mostrar filas" << endl;
        cout << "5 - Sair sistema" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case 1 :
                    cout << "Retirada de ficha normal: " << contadorFichaNormal << endl;
                    inserir(contadorFichaNormal, &filaNormal);
                    contadorFichaNormal++;
                    if (contadorFichaNormal == 500) {
                        contadorFichaNormal = 100;
                    }
                    break;
            case 2 :
                    cout << "Retirada de ficha prioritaria: " << contadorFichaPrioritaria << endl;
                    inserir(contadorFichaPrioritaria, &filaPrioritaria);
                    contadorFichaPrioritaria++;
                    if (contadorFichaPrioritaria == 900) {
                        contadorFichaPrioritaria = 501;
                    }
                    break;
            case 3 :
                    if (qtdAtendimentos % 3 == 0) {
                        ficha = excluir(&filaPrioritaria);
                        if (ficha == -27) {
                            ficha = excluir(&filaNormal);
                        }
                    } else {
                        ficha = excluir(&filaNormal);
                        if (ficha == -27) {
                            ficha = excluir(&filaPrioritaria);
                        }
                    }
                    if (ficha != -27) {
                        cout << "Chamando ficha.....: " << ficha << endl;
                    } else {
                        cout << "Sem fichas para chamar... aguarde novas fichas!" << endl;
                    }
                    qtdAtendimentos++;
                    break;
            case 4 :
                    cout << "Mostrando filas de atendimento!!" << endl;
                    cout << "Fila normal" << endl;
                    exibir(filaNormal);
                    cout << "Fila prioritaria" << endl;
                    exibir(filaPrioritaria);
                    break;
            case 5 : cout << "Obrigado por usar o sistema!" << endl;
                     break;
            default: cout << "Opcao invalida." << endl;
        }
        cout << "Tecle ENTER para continuar!";
        fflush(stdin);
        caracter = getchar();

    } while (op != 5);

    return 1;
}