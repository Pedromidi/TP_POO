//
// Created by mlvdi on 09/12/2023.
//

#ifndef TP_REFRIGERADOR_H
#define TP_REFRIGERADOR_H


#include "Aparelho.h"
#include "../Zona/Zona.h"
#include <cstring>

class refrigerador : public Aparelho{
public:
    refrigerador(char tipo, Zona *z, int ID);
    void mudaEstado() override;
    string recebeComando(string comando, int i) override;
    void processa(int instanteatual) override;
    int getID() override;
    char getTipo() override;
    string getEstado() const override;
    string toString() override;
    ~refrigerador();
private:
    Zona *z;
    int ID;
    char tipo;
    int instantes; //talvez não seja preciso para todos os aparelhos
};


#endif //TP_REFRIGERADOR_H
