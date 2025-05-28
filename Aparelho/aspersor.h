//
// Created by mlvdi on 09/12/2023.
//

#ifndef TP_ASPERSOR_H
#define TP_ASPERSOR_H


#include "Aparelho.h"
#include "../Zona/Zona.h"
#include <cstring>

class aspersor : public Aparelho{
public:
    aspersor(char tipo, Zona *z, int ID);
    void mudaEstado() override;
    string recebeComando(string comando, int i) override;
    void processa(int instanteatual) override;
    int getID() override;
    char getTipo() override;
    string getEstado() const override;
    string toString() override;
    ~aspersor();
private:
    Zona *z;
    int ID;
    char tipo;
    int instantes; //talvez não seja preciso para todos os aparelhos
};


#endif //TP_ASPERSOR_H
