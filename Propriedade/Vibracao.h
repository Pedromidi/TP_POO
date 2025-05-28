//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_VIBRACAO_H
#define TP_VIBRACAO_H


#include "Propriedades.h"

class Vibracao : public Propriedades {
public:
    Vibracao();
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
};


#endif //TP_VIBRACAO_H
