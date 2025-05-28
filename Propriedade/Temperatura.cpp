//
// Created by mlvdi on 26/12/2023.
//

#include "Temperatura.h"

Temperatura::Temperatura() {
    nome = "Temperatura";
    tipo = 't';
    valor = 0;
    unidade = " Graus celcius";
}

string Temperatura::getProp() const {
    ostringstream oss;
    oss << nome << ", valor: " << getValor() << unidade;
    return oss.str();
}

int Temperatura::getValor() const {
    return valor;
}

char Temperatura::getTipo() const {
    return tipo;
}

string Temperatura::getNome() const {
    return nome;
}

void Temperatura::setValor(int val) {
    if(val > min){
        valor=val;
    }
    else
        valor = min;
}

