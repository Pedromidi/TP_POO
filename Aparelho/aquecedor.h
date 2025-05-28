//
// Created by mlvdi on 09/12/2023.
//

#ifndef TP_AQUECEDOR_H
#define TP_AQUECEDOR_H


#include "Aparelho.h"
#include "../Zona/Zona.h"
#include <cstring>

class aquecedor : public Aparelho{
public:
    aquecedor(char tipo, Zona *z, int ID);
    void mudaEstado() override;
    string recebeComando(string comando, int i) override;
    void processa(int instanteatual) override;
    int getID() override;
    char getTipo() override;
    string getEstado() const override;
    string toString() override;
    ~aquecedor();
private:
    Zona *z;
    int ID;
    char tipo;
    int instantes; //talvez não seja preciso para todos os aparelhos
};


#endif //TP_AQUECEDOR_H
