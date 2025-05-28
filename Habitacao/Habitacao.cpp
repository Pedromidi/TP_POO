//
// Created by mlvdi on 10/11/2023.
//

#include "Habitacao.h"

int Habitacao::getlin() const {
    return linhas;
}

int Habitacao::getcol() const {
    return colunas;
}

Habitacao::Habitacao(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    this->nzonas = 0;
}

vector<Zona*> Habitacao::getZonas() const {
    return zonas;
}

void Habitacao::adicionaZona(Zona* z) {
    zonas.push_back(z);
    nzonas+=1;
}

int Habitacao::getNZonas() {
    return nzonas;
}

void Habitacao::setLin(int l) {
    linhas = l;
}

void Habitacao::setCol(int c) {
    colunas = c;
}

void Habitacao::apagaZonas() {
    auto i = zonas.begin();
    while(i != zonas.end()){
            delete *i;
            zonas.erase(i);
        }
    ++i;
}

void Habitacao::resetNZonas() {
    nzonas = 0;
}


Habitacao::~Habitacao() = default;
