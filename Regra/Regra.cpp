//
// Created by mlvdi on 18/11/2023.
//

#include "Regra.h"

Regra::Regra(string s, int x, int ID) : s(s), x(x), ID(ID){}

Regra::Regra(string s, int x, int y, int ID) : s(s), x(x), y(y), ID(ID){}

string Regra::getRegra() const {
    return s;
}

int Regra::getID() const{
    return ID;
}

int Regra::getX() const {
    return x;
}

int Regra::getY() const {
    return y;
}

Regra::~Regra() {}
