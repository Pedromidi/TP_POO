//
// Created by mlvdi on 17/11/2023.
//

#ifndef TP_PROCESSADOR_H
#define TP_PROCESSADOR_H


#include "../Regra/Regra.h"
#include <vector>

using namespace std;

class Processador {
public:
    Processador(int ID, string comando);
    void adicionaRegra(Regra *r);
    bool processaRegras();
    string toString();
    vector<Regra*> getRegras();
    void setComando(string com);
    int getID();
    ~Processador();
private:
    vector<Regra*> regras;
    int ID;
    string comando;
};


#endif //TP_PROCESSADOR_H
