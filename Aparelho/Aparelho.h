//
// Created by mlvdi on 17/11/2023.
//

#ifndef TP_APARELHO_H
#define TP_APARELHO_H

#include <sstream>
#include <iostream>

using namespace std;

class Zona;

class Aparelho {
public:
    virtual void mudaEstado() = 0;
    virtual void processa(int instanteatual) = 0;
    virtual int getID() = 0;
    virtual char getTipo() = 0;
    virtual string recebeComando(string comando, int i) = 0;
    virtual string getEstado() const = 0;
    virtual string toString() = 0;
    ~Aparelho();
private:
    int ID;
    char tipo;
protected:
    bool ligado = false;
};


#endif //TP_APARELHO_H
