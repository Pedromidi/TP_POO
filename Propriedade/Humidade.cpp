//
// Created by mlvdi on 26/12/2023.
//

#include "Humidade.h"

Humidade::Humidade() {
    nome = "Humidade";
    tipo = 'h';
    valor = 0;
    unidade = "%";
}

string Humidade::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Humidade::getValor() const {
    return valor;
}

char Humidade::getTipo() const {
    return tipo;
}

string Humidade::getNome() const {
    return nome;
}

void Humidade::setValor(int val) {
    if((valor+=val > min) && (valor+=val < max)){
        valor+=val;
    }
    else if(valor+=val < min){
        valor = min;
    }
    else
        valor = max;
}
