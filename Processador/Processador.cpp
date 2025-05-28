//
// Created by mlvdi on 17/11/2023.
//

#include "Processador.h"

Processador::Processador(int ID, string comando) : ID(ID), comando(comando){}

void Processador::adicionaRegra(Regra *r) {
    regras.push_back(r);
}

bool Processador::processaRegras() {
    for(Regra *r : regras){
        if(r->getRegra() == "igual_a"){
                return true;
        }
        else if(r->getRegra() == "menor_que"){
                return true;
        }

        else if(r->getRegra() == "maior_que"){
                return true;
        }

        else if(r->getRegra() == "entre"){
                    return true;
            return false;
        }

        else if(r->getRegra() == "fora"){
                    return true;
            return false;
        }
        return false;
    }
    return false;
}

Processador::~Processador() {}

int Processador::getID() {
    return ID;
}

string Processador::toString() {
    return "ID: " + to_string(getID()) + ", regras: " + to_string(regras.size());
}

vector<Regra *> Processador::getRegras() {
    return regras;
}

void Processador::setComando(string com) {
    comando = com;
}
