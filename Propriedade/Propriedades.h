//
// Created by mlvdi on 10/11/2023.
//

#ifndef TP_PROPRIEDADES_H
#define TP_PROPRIEDADES_H

#include <sstream>
#include <iostream>
using namespace std;

class Propriedades {
public:
    virtual string getProp() const = 0;
    virtual string getNome() const = 0;
    virtual int getValor() const = 0;
    virtual char getTipo() const = 0;
    virtual void setValor(int val) = 0;
    virtual ~Propriedades();
private:
    int valor;
    string nome;
    char tipo;
    string unidade;
};


#endif //TP_PROPRIEDADES_H
