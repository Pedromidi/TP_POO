//
// Created by mlvdi on 09/12/2023.
//

#ifndef TP_LAMPADA_H
#define TP_LAMPADA_H


#include "Aparelho.h"
#include "../Zona/Zona.h"
#include <cstring>

class lampada : public Aparelho{
public:
    lampada(char tipo, Zona *z, int ID);
    void mudaEstado() override;
    string recebeComando(string comando, int i) override;
    void processa(int instanteatual) override;
    int getID() override;
    char getTipo() override;
    string getEstado() const override;
    string toString() override;
    ~lampada();
private:
    Zona *z;
    int ID;
    char tipo;
};


#endif //TP_LAMPADA_H
