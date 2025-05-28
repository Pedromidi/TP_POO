//
// Created by mlvdi on 26/12/2023.
//

#include "Luz.h"

Luz::Luz() {
    nome = "Luz";
    tipo = 'm';
    valor = 0;
    unidade = " Lumens";
}

string Luz::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Luz::getValor() const {
    return valor;
}

char Luz::getTipo() const {
    return tipo;
}

string Luz::getNome() const {
    return nome;
}

void Luz::setValor(int val) {
    if(valor+=val > min){
        valor+=val;
    }
    else
        valor = min;
}
