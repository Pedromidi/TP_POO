//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_HUMIDADE_H
#define TP_HUMIDADE_H


#include "Propriedades.h"

class Humidade : public Propriedades {
public:
    Humidade();
    void setValor(int val) override;
    [[nodiscard]] string getProp() const override;
    [[nodiscard]] string getNome() const override;
    [[nodiscard]] int getValor() const override;
    [[nodiscard]] char getTipo() const override;
private:
    int valor;
    char tipo;
    string nome;
    string unidade;
    int min = 0;
    int max = 100;
};


#endif //TP_HUMIDADE_H
