//
// Created by mlvdi on 26/12/2023.
//

#ifndef TP_SOM_H
#define TP_SOM_H


#include "Propriedades.h"

class Som : public Propriedades {
public:
    Som();
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


#endif //TP_SOM_H
