//
// Created by mlvdi on 26/12/2023.
//

#include "Radiacao.h"

Radiacao::Radiacao() {
    nome = "Radiacao";
    tipo = 'd';
    valor = 0;
    unidade = " Becquerel";
}

string Radiacao::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Radiacao::getValor() const {
    return valor;
}

char Radiacao::getTipo() const {
    return tipo;
}

string Radiacao::getNome() const {
    return nome;
}

void Radiacao::setValor(int val) {
    if(valor+=val > min){
        valor+=val;
    }
    else
        valor = min;
}
