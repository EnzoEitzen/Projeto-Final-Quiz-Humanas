#ifndef PROJETOFINAL_CADASTRARLERJOG_H
#define PROJETOFINAL_CADASTRARLERJOG_H

#include "classes.h"
#include <iostream>
#include <algorithm>

#define ArqJogadores "ArqJogadores.bin"

namespace cadStrarJog {
    void CadastrarJogArq(const jogador& cadastroJogObj);

    jogador cadastrarJogObj() {
        jogador cadastro;
        std::string tempString{};
        char tempChar[3]{};
        system("cls");
        std::cout << "\n" << "Cadastre o nome do jogador: ";
        getline(std::cin, tempString);
        std::cin.sync();
        cadastro.setNome(tempString);
        std::cout << "\n" << "A Dificuldade - 1 até 3 ou 4 para aleatorio: ";
        std::cin.getline(tempChar, 2);
        std::cin.sync();
        cadastro.setDificuldade(tempChar);
        std::cout << "\n" << "\n" << "Clique em 'Enter' para iniciar o jogo: " << "\n";
        system("pause");
        system("cls");
        return cadastro;
    }

    void CadastrarJogArq(const jogador& cadastroJogObj) {
        structJogador escreverArq{};

        escreverArq.Pontuacao = cadastroJogObj.getPontuacao();
        strcpy(escreverArq.Nome, cadastroJogObj.getNome().c_str());
        FILE* arq = fopen(ArqJogadores, "ab");
        if (arq == nullptr) {
            printf("Ocorreu um erro na abertura do arquivo");
            exit(1);
        }
        fwrite(&escreverArq, tamStructJog, 1, arq);
        fclose(arq);
    }

} // cadStrarJog

namespace lerJog {
    std::vector<jogador> transfStructEmObj(const std::vector<structJogador>& vetorStructLocal);

    bool compararJog(const jogador& a, const jogador& b) {
        return a.getPontuacao() > b.getPontuacao();
    }

    std::vector<jogador> lerJogArq() {
        structJogador temp;
        std::vector<structJogador> vec{};
        FILE* file = fopen(ArqJogadores, "rb");
        if (file == nullptr) {
            std::cout << "Nao foi possivel abrir o arquivo";
            exit(-1);
        }
        while (fread(&temp, tamStructJog, 1, file) == 1) {
            vec.push_back(temp);
        }
        fclose(file);
        return transfStructEmObj(vec);
    }

    std::vector<jogador> transfStructEmObj(const std::vector<structJogador>& vetorStructLocal) {
        std::vector<jogador> retornoObjJog{};
        jogador jogadorTempLocal{};

        for (const auto structForTemp: vetorStructLocal) {
            jogadorTempLocal.setNome(structForTemp.Nome);
            jogadorTempLocal.setPontuacaoAtual(structForTemp.Pontuacao);
            jogadorTempLocal.setDificuldade("1");
            retornoObjJog.push_back(jogadorTempLocal);
        }
        std::sort(retornoObjJog.begin(), retornoObjJog.end(), compararJog);
        return retornoObjJog;
    }
} // lerJog

#endif //PROJETOFINAL_CADASTRARLERJOG_H
