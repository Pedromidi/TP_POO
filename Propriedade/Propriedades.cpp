//
// Created by mlvdi on 10/11/2023.
//

#include <string>
#include "Propriedades.h"

Propriedades::~Propriedades() {}

string Propriedades::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Propriedades::getValor() const {
    return valor;
}

char Propriedades::getTipo() const {
    return tipo;
}

string Propriedades::getNome() const {
    return nome;
}
