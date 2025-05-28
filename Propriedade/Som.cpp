//
// Created by mlvdi on 26/12/2023.
//

#include "Som.h"

Som::Som() {
    nome = "Som";
    tipo = 'o';
    valor = 0;
    unidade = " Decibeis";
}

string Som::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Som::getValor() const {
    return valor;
}

char Som::getTipo() const {
    return tipo;
}

string Som::getNome() const {
    return nome;
}

void Som::setValor(int val) {
    if(valor+=val > min){
        valor+=val;
    }
    else
        valor = min;
}
