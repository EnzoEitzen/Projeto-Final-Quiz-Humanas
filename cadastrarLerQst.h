#ifndef PROJETOFINAL_CADASTRARLERQST_H
#define PROJETOFINAL_CADASTRARLERQST_H

#include "classes.h"
#include <fstream>
#include <vector>
#include <iostream>

#define ArqQuestoes "ArqQuestoes.bin"

namespace cadStrarQst {
    int CadastrarQuestoesArq(const questoes& cadastroObjQst);

    int cadastrarQuestoesObj() {
        questoes cadastro;
        std::string tempString{};
        char tempChar[4]{};
        system("cls");
        std::cout << "\n" << "Cadastre A Questão: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setQuestao(tempString);
        std::cout << "\n" << "Cadastre A Area: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setArea(tempString);
        std::cout << "\n" << "Cadastre A Alternativa: ";
        std::cin.getline(tempChar, 2);
        std::cin.sync();
        cadastro.setAlternativaCerta(tempChar);
        std::cout << "\n" << "Cadastre A Dificuldade - 1 até 3: ";
        std::cin.getline(tempChar, 2);
        std::cin.sync();
        cadastro.setDificuldade(tempChar);
        system("cls");
        std::cout << "\n" << "Cadastre A Resposta A: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setRespostas(tempString);
        std::cout << "\n" << "Cadastre A Resposta B: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setRespostas(tempString);
        std::cout << "\n" << "Cadastre A Resposta C: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setRespostas(tempString);
        std::cout << "\n" << "Cadastre A Resposta D: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setRespostas(tempString);
        std::cout << "\n" << "Cadastre A Resposta E: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setRespostas(tempString);
        system("pause");
        system("cls");
        CadastrarQuestoesArq(cadastro);
        return 0;
    }


    int CadastrarQuestoesArq(const questoes& cadastroObjQst) {
        const std::vector<std::string> respostasValidasLocal{cadastroObjQst.getRespostasValidas()};
        structQuestao escreverArq{};
        escreverArq.alternativa = cadastroObjQst.getAlternativaCerta();
        strcpy(escreverArq.area, cadastroObjQst.getArea().c_str());
        escreverArq.dificuldade = cadastroObjQst.getDificuldade();
        strcpy(escreverArq.questao, cadastroObjQst.getQuestao().c_str());
        strcpy(escreverArq.respA, respostasValidasLocal.at(0).c_str());
        strcpy(escreverArq.respB, respostasValidasLocal.at(1).c_str());
        strcpy(escreverArq.respC, respostasValidasLocal.at(2).c_str());
        strcpy(escreverArq.respD, respostasValidasLocal.at(3).c_str());
        strcpy(escreverArq.respE, respostasValidasLocal.at(4).c_str());

        if (std::ofstream arq(ArqQuestoes, std::ios::binary | std::ios::app); arq.is_open()) {
            arq.write(reinterpret_cast<char *>(&escreverArq), tamStructQst);

            arq.close();

            std::cout << "Questao salva." << "\n" << "\n";
            system("pause");
            system("cls");
        } else {
            std::cout << "Nao foi possivel salvar a questão." << "\n";
            arq.close();
            system("pause");
            system("cls");
        }
        return 0;
    }
} // cadStrar

namespace lerQst {
    std::vector<questoes> transfStructEmObj(const std::vector<structQuestao>& vetorStructLocal);

    std::vector<questoes> lerQuestoesArq() {
        std::vector<structQuestao> vetorQuestoes{};
        if (std::ifstream arq(ArqQuestoes, std::ios::binary); arq.is_open()) {
            structQuestao lidoTemp{};
            while (arq.read(reinterpret_cast<char *>(&lidoTemp), sizeof(lidoTemp))) {
                vetorQuestoes.push_back(lidoTemp);
            }
            arq.close();
            return transfStructEmObj(vetorQuestoes);
        }
        std::cout << "Não foi possivel abrir o arquivo" << "\n";
        system("pause");
        exit(-1);
    }

    std::vector<questoes> transfStructEmObj(const std::vector<structQuestao>& vetorStructLocal) {
        std::vector<questoes> retornoObjQuest{};
        questoes questTempLocal{};
        std::string tempLocalStr{};
        char charTemp[2];

        for (const auto TempAtualStruct: vetorStructLocal) {
            questTempLocal.clearVetorRespostas();
            tempLocalStr = TempAtualStruct.questao;
            questTempLocal.setQuestao(tempLocalStr);
            tempLocalStr = TempAtualStruct.area;
            questTempLocal.setArea(tempLocalStr);
            switch (TempAtualStruct.dificuldade) {
                case 1:
                    charTemp[0] = '1';
                    charTemp[1] = '\0';
                    break;
                case 2:
                    charTemp[0] = '2';
                    charTemp[1] = '\0';
                    break;
                case 3:
                    charTemp[0] = '3';
                    charTemp[1] = '\0';
                    break;
                default:
                    charTemp[0] = '1';
                    charTemp[1] = '\0';
                    break;
            }
            questTempLocal.setDificuldade(charTemp);
            tempLocalStr = TempAtualStruct.respA;
            questTempLocal.setRespostas(tempLocalStr);
            tempLocalStr = TempAtualStruct.respB;
            questTempLocal.setRespostas(tempLocalStr);
            tempLocalStr = TempAtualStruct.respC;
            questTempLocal.setRespostas(tempLocalStr);
            tempLocalStr = TempAtualStruct.respD;
            questTempLocal.setRespostas(tempLocalStr);
            tempLocalStr = TempAtualStruct.respE;
            questTempLocal.setRespostas(tempLocalStr);
            charTemp[0] = TempAtualStruct.alternativa;
            questTempLocal.setAlternativaCerta(charTemp);
            retornoObjQuest.push_back(questTempLocal);
        }
        return retornoObjQuest;
    }
} // ler

#endif //PROJETOFINAL_CADASTRARLERQST_H
