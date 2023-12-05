#ifndef PROJETOFINAL_JOGAR_H
#define PROJETOFINAL_JOGAR_H
#include "cadastrarLerJog.h"
#include <algorithm>


using namespace std;

namespace jogarLogica {
    std::string to_lower(const std::string& s) {
        std::string lower;
        std::transform(s.begin(), s.end(), std::back_inserter(lower), ::tolower);
        return lower;
    }

    std::vector<questoes> encontrarAreaQst(const std::vector<questoes>& vec, const std::string& str) {
        std::vector<questoes> vetorRetornoQst;
        const std::string lower_str = to_lower(str);
        for (const auto& s: vec) {
            if (to_lower(s.getArea()).find(lower_str) != std::string::npos) {
                vetorRetornoQst.push_back(s);
            }
        }
        return vetorRetornoQst;
    }

    void jogarAreaEspecifica(jogador jogando, const std::vector<questoes>& vetorQst) {
        for (const auto& objQstTemp: vetorQst) {
            char tempChar[4];
            cout << objQstTemp.getQuestao() << "\n\n\n";
            for (const auto& qstTempFor: objQstTemp.getRespostasValidas()) {
                cout << qstTempFor << "\n\n";
            }
            const auto start = chrono::high_resolution_clock::now();
            cout << "Alternativa: ";
            scanf("%s", tempChar);
            const auto end = chrono::high_resolution_clock::now();
            const chrono::duration<float> diff = end - start;
            if (tempChar[0] == objQstTemp.getAlternativaCerta()) {
                cout << "\n\n" << "Você acertou!" << "\n";
                system("pause");
                switch (objQstTemp.getDificuldade()) {
                    case 1:
                        jogando.setPontuacao(1, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    case 2:
                        jogando.setPontuacao(2, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    case 3:
                        jogando.setPontuacao(3, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    default:
                        jogando.setPontuacao(1, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                }
                system("cls");
            } else {
                cout << "\n\n" << "Você errou, resposta certa: " << objQstTemp.getAlternativaCerta() << "\n";
                system("pause");
                system("cls");
            }
        }
        cadStrarJog::CadastrarJogArq(jogando);
    }

    void jogarAreaAleatoria(jogador jogando, const vector<questoes>& vetorQst) {
        for (const auto& objQstTemp: vetorQst) {
            char tempChar[4];
            cout << objQstTemp.getQuestao() << "\n\n\n";
            for (const auto& qstTempFor: objQstTemp.getRespostasValidas()) {
                cout << qstTempFor << "\n\n";
            }
            const auto start = chrono::high_resolution_clock::now();
            cout << "Alternativa: ";
            scanf("%s", tempChar);
            const auto end = chrono::high_resolution_clock::now();
            const chrono::duration<float> diff = end - start;
            if (tempChar[0] == objQstTemp.getAlternativaCerta()) {
                cout << "\n\n" << "Você acertou!" << "\n";
                system("pause");
                switch (objQstTemp.getDificuldade()) {
                    case 1:
                        jogando.setPontuacao(1, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    case 2:
                        jogando.setPontuacao(2, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    case 3:
                        jogando.setPontuacao(3, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                    default:
                        jogando.setPontuacao(1, diff.count(), static_cast<int>(vetorQst.size()));
                        break;
                }
                system("cls");
            } else {
                cout << "\n\n" << "Você errou, resposta certa: " << objQstTemp.getAlternativaCerta() << "\n";
                system("pause");
                system("cls");
            }
        }
        cadStrarJog::CadastrarJogArq(jogando);
    }

    void menuArea(const jogador& jogar) {
        do {
            std::string tempString;
            const std::vector<questoes> vectorLocalQst{lerQst::lerQuestoesArq()};
            std::vector<questoes> vetorAreaFormatadaQst{};
            std::vector<questoes> vetorAreaFormatadaDificuldade{};
            int op = 0;
            system("cls");
            std::cout << "------Areas------" << "\n" << "\n";
            std::cout << "1 - Sociologia" << "\n";
            std::cout << "2 - Filosofia" << "\n";
            std::cout << "3 - Historia" << "\n";
            std::cout << "4 - Artes" << "\n";
            std::cout << "5 - Portugues" << "\n";
            std::cout << "6 - Aleatorio" << "\n";
            scanf_s("%d", &op);
            system("cls");
            fflush(stdin);
            switch (op) {
                case 1:
                    vetorAreaFormatadaQst = encontrarAreaQst(vectorLocalQst, "sociologia");
                    jogarAreaEspecifica(jogar, vetorAreaFormatadaQst);
                    system("cls");
                    break;
                case 2:
                    vetorAreaFormatadaQst = encontrarAreaQst(vectorLocalQst, "filosofia");
                    jogarAreaEspecifica(jogar, vetorAreaFormatadaQst);
                    system("cls");
                    break;
                case 3:
                    vetorAreaFormatadaQst = encontrarAreaQst(vectorLocalQst, "historia");
                    jogarAreaEspecifica(jogar, vetorAreaFormatadaQst);
                    system("cls");
                    break;
                case 4:
                    vetorAreaFormatadaQst = encontrarAreaQst(vectorLocalQst, "artes");
                    jogarAreaEspecifica(jogar, vetorAreaFormatadaQst);
                    system("cls");
                    break;
                case 5:
                    vetorAreaFormatadaQst = encontrarAreaQst(vectorLocalQst, "portugues");
                    jogarAreaEspecifica(jogar, vetorAreaFormatadaQst);
                    system("cls");
                case 6:
                    jogarAreaAleatoria(jogar, vectorLocalQst);
                    system("cls");
                    break;
                default:
                    system("cls");
            }
            return;
        } while (true);
    }

    void imprimirRanking() {
        int i{};
        system("cls");
        const vector<jogador> vetorJogRank{lerJog::lerJogArq()};
        cout << "------Ranking------" << "\n\n";
        for (const auto& jogadorRankTempFor: vetorJogRank) {
            i++;
            cout << "Posicao: " << i << "\n";
            cout << "Nome: " << jogadorRankTempFor.getNome() << "\n";
            cout << "Pontos: " << jogadorRankTempFor.getPontuacao() << "\n\n";
        }
        system("pause");
    }
} // jogarLogica

#endif //PROJETOFINAL_JOGAR_H
