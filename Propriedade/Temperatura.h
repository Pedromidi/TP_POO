//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_TEMPERATURA_H
#define TP_TEMPERATURA_H


#include "Propriedades.h"

class Temperatura : public Propriedades {
public:
    Temperatura();
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
    int min = -273;
};


#endif //TP_TEMPERATURA_H
