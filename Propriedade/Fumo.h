//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_FUMO_H
#define TP_FUMO_H


#include "Propriedades.h"

class Fumo : public Propriedades {
public:
    Fumo();
    void setValor(int val) override;
    [[nodiscard]] string getProp() const override;
    [[nodiscard]] string getNome() const override;
    [[nodiscard]] int getValor() const override;
    [[nodiscard]] char getTipo() const override;
private:
    int valor;
    string nome;
    char tipo;
    string unidade;
    int min = 0;
    int max = 100;
};


#endif //TP_FUMO_H
