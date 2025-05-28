//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_RADIACAO_H
#define TP_RADIACAO_H


#include "Propriedades.h"

class Radiacao : public Propriedades {
public:
    Radiacao();
    void setValor(int val) override;
    [[nodiscard]] string getProp() const override;
    [[nodiscard]] string getNome() const override;
    [[nodiscard]] int getValor() const override;
    [[nodiscard]] char getTipo() const override;
private:
    string nome;
    char tipo;
    int valor;
    string unidade;
    int min = 0;
};


#endif //TP_RADIACAO_H
