//
// Created by mlvdi on 09/12/2023.
//

#include "lampada.h"

lampada::lampada(char tipo, Zona *z, int ID) : tipo(tipo), z(z), ID(ID) {}

void lampada::mudaEstado() {
    if(ligado){
        tipo = ::tolower(tipo);
        ligado = false;
        return;
    }
    tipo = ::toupper(tipo);
    ligado = true;
}

string lampada::recebeComando(string comando, int i) {
    if(comando == "liga"){
        if(ligado)
            return "Lampada ja se encontra ligada";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'm')
                p->setValor(900);
        }
    }
    else if(comando == "desliga"){
        if(!ligado)
            return "Lampada ja se encontra desligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'm')
                p->setValor(-900);
        }
    }
    return "Comando desconhecido";
}

lampada::~lampada() {
    ligado = false;
}

int lampada::getID() {
    return ID;
}

char lampada::getTipo() {
    return tipo;
}

string lampada::getEstado() const {
    if(ligado == 1)
        return "ligado";
    return "desligado";
}

string lampada::toString() {
    ostringstream oss;
    oss << "ID: " << getID() << ", Tipo: Lampada, Estado: " << getEstado() << "; ";
    return oss.str();
}

void lampada::processa(int instanteatual) {
    return;
}
