//
// Created by mlvdi on 09/12/2023.
//

#include "aspersor.h"

aspersor::aspersor(char tipo, Zona *z, int ID) : tipo(tipo), z(z), ID(ID) {}

void aspersor::mudaEstado() {
    if(ligado){
        tipo = ::tolower(tipo);
        ligado = false;
        return;
    }
    tipo = ::toupper(tipo);
    ligado = true;
}

string aspersor::recebeComando(string comando, int i) {
    if(comando == "liga"){
        if(ligado)
            return "Lampada ja se encontra ligada";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'h')
                p->setValor(50);
            if(p->getTipo() == 'v')
                p->setValor(100);
            if(p->getTipo() == 'f')
                p->setValor(0);
        }
    }
    else if(comando == "desliga"){
        if(!ligado)
            return "Lampada ja se encontra desligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'v')
                p->setValor(-100);
        }
    }
    return "Comando desconhecido";
}

aspersor::~aspersor() {
    ligado = false;
}

int aspersor::getID() {
    return ID;
}

char aspersor::getTipo() {
    return tipo;
}

string aspersor::getEstado() const {
    if(ligado == 1)
        return "ligado";
    return "desligado";
}

string aspersor::toString() {
    ostringstream oss;
    oss << "ID: " << getID() << ", Tipo:  Aspersor, Estado: " << getEstado() << "; ";
    return oss.str();
}

void aspersor::processa(int instanteatual) {
    return;
}

