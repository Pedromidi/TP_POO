//
// Created by mlvdi on 26/12/2023.
//

#include "Fumo.h"

Fumo::Fumo() {
    nome = "Fumo";
    tipo = 'f';
    valor = 0;
    unidade = "% Obscuracao";
}
string Fumo::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Fumo::getValor() const {
    return valor;
}

char Fumo::getTipo() const {
    return tipo;
}

string Fumo::getNome() const {
    return nome;
}

void Fumo::setValor(int val) {
    if((valor+=val > min) && (valor+=val < max)){
        valor+=val;
    }
    else if(valor+=val < min){
        valor = min;
    }
    else
        valor = max;
}
