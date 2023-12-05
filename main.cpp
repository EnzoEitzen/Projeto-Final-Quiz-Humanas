#include <bits/stdc++.h>
#include "cadastrarLerQst.h"
#include "cadastrarLerJog.h"
#include "Jogar.h"

using namespace std;

int menu();

int main() {
    setlocale(LC_ALL, "portuguese");
    menu();
    system("pause");
    return 0;
}

int menu() {
    do {
        int op{}, qtd{};
        system("cls");
        cout << "------Menu------" << endl << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Cadastrar questao" << endl;
        cout << "3 - Ranking" << endl;
        cout << "4 - Sair" << endl << endl;
        scanf_s("%d", &op);
        fflush(stdin);
        switch (op) {
            case 1:
                jogarLogica::menuArea(cadStrarJog::cadastrarJogObj());
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "Quantas Questoes serao cadastrados: ";
                cin >> qtd;
                std::cin.sync();
                for (int i{}; i < qtd; i++) {
                    cadStrarQst::cadastrarQuestoesObj();
                }
                system("cls");
                break;
            case 3:
                jogarLogica::imprimirRanking();
                system("cls");
                break;
            case 4:
                system("cls");
                return 4;
            default:
                system("cls");
                break;
        }
    } while (true);
}
