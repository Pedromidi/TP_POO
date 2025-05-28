//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_LUZ_H
#define TP_LUZ_H


#include "Propriedades.h"

class Luz : public Propriedades {
public:
    Luz();
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


#endif //TP_LUZ_H
