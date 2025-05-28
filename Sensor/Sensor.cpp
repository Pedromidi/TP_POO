//
// Created by mlvdi on 17/11/2023.
//

#include "Sensor.h"

Sensor::Sensor(Zona *z, char propriedade, int ID) : z(z), propriedade(propriedade), ID(ID){}

Sensor::~Sensor() {}

int Sensor::getID() {
    return ID;
}

string Sensor::getProp() {
    for(Propriedades *p : z->getProps()){
        if(::toupper(p->getTipo()) == ::toupper(propriedade)){
            return p->getProp();
        }
    }
    return " ";
}

string Sensor::toString() {
    ostringstream oss;
    oss << "ID: " << getID() << ", Propriedade: " << getProp() << "; ";
    return oss.str();
}

char Sensor::getTipo() {
    return propriedade;
}





