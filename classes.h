#ifndef CLASSES_H
#define CLASSES_H

#ifndef PROJETOFINAL_classes_H
#define PROJETOFINAL_classes_H

#define MAX_TAM_C_STRING 1000
#define MED_TAM_C_STRING 500
#define MIN_TAM_C_STRING 100

typedef struct {
    char questao[MAX_TAM_C_STRING];
    char area[MIN_TAM_C_STRING];
    char respA[MED_TAM_C_STRING];
    char respB[MED_TAM_C_STRING];
    char respC[MED_TAM_C_STRING];
    char respD[MED_TAM_C_STRING];
    char respE[MED_TAM_C_STRING];
    char alternativa;
    int dificuldade;
} structQuestao;

typedef struct {
    char Nome[MIN_TAM_C_STRING];
    float Pontuacao;
} structJogador;

constexpr int tamStructQst{sizeof(structQuestao)};
constexpr int tamStructJog{sizeof(structJogador)};

class questoes {
private:
    std::string Questao{};
    std::string Area{};
    std::string RespostaValida{"abcdeABCDE"};
    std::vector<std::string> AlternativasValidas;
    char AlternativaCerta{};
    int Dificuldade{};

public:
    void setQuestao(std::string QuestaoLocal) {
        this->Questao = std::move(QuestaoLocal);
    }

    void setArea(std::string AreaLocal) {
        this->Area = std::move(AreaLocal);
    }

    void setAlternativaCerta(char AlternativaLocal[2]) {
        if (const size_t found = RespostaValida.find(AlternativaLocal[0]); found != std::string::npos) {
            this->AlternativaCerta = AlternativaLocal[0];
        } else {
            this->AlternativaCerta = 'a';
        }
    }

    void setRespostas(const std::string& respostaLocal) {
        AlternativasValidas.push_back(respostaLocal);
    }

    void clearVetorRespostas() {
        AlternativasValidas.clear();
    }

    void setDificuldade(const char dificuldadeChar[2]) {
        if (const int DificuldadeLocal = static_cast<int>(dificuldadeChar[0] - '0');
            DificuldadeLocal >= 1 && DificuldadeLocal <= 3)
            this->Dificuldade = DificuldadeLocal;
        else if (DificuldadeLocal < 1) {
            this->Dificuldade = 1;
        } else {
            this->Dificuldade = 3;
        }
    }

    [[nodiscard]] int getDificuldade() const {
        return Dificuldade;
    }

    [[nodiscard]] char getAlternativaCerta() const {
        return AlternativaCerta;
    }

    [[nodiscard]] std::vector<std::string> getRespostasValidas() const {
        return AlternativasValidas;
    }

    [[nodiscard]] std::string getArea() const {
        return Area;
    }

    [[nodiscard]] std::string getQuestao() const {
        return Questao;
    }
};

class jogador {
private:
    std::string Nome{};
    std::vector<float> Tempo{};
    int DificuldadeEscolhida{};
    float Pontuacao{};

public:
    void setTempo(const float TempoLocal) {
        if (TempoLocal > 0)
            this->Tempo.push_back(TempoLocal);
    }

    void setDificuldade(const char dificuldadeChar[2]) {
        if (const int DificuldadeLocal = dificuldadeChar[0] - '0'; DificuldadeLocal >= 1 && DificuldadeLocal <= 3)
            this->DificuldadeEscolhida = DificuldadeLocal;
        else if (DificuldadeLocal < 1) {
            this->DificuldadeEscolhida = 1;
        } else {
            this->DificuldadeEscolhida = 3;
        }
    }

    void setPontuacao(const float PontuacaoLocal, const float TempoTicks, const int QuantidadeQsts) {
        this->Pontuacao += (((PontuacaoLocal * TempoTicks) * 100) / QuantidadeQsts);
    }

    void setPontuacaoAtual(const float PontuacaoLocal) {
        this->Pontuacao = PontuacaoLocal;
    }

    void setNome(std::string NomeLocal) {
        this->Nome = std::move(NomeLocal);
    }

    [[nodiscard]] std::vector<float> getTempo() const {
        return Tempo;
    }

    [[nodiscard]] int getDificuldade() const {
        return DificuldadeEscolhida;
    }

    [[nodiscard]] float getPontuacao() const {
        return Pontuacao;
    }

    [[nodiscard]] std::string getNome() const {
        return Nome;
    }
};

#endif //PROJETOFINAL_classes_H

#pragma clang diagnostic pop
#endif // CLASSES_H
