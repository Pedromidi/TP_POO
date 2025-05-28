//
// Created by mlvdi on 26/12/2023.
//

#include "Vibracao.h"

Vibracao::Vibracao() {
    nome = "Vibracao";
    tipo = 'v';
    valor = 0;
    unidade = " Hertz";
}

string Vibracao::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Vibracao::getValor() const {
    return valor;
}

char Vibracao::getTipo() const {
    return tipo;
}

string Vibracao::getNome() const {
    return nome;
}

void Vibracao::setValor(int val) {
    if(valor+=val > min){
        valor+=val;
    }
    else
        valor = min;
}
