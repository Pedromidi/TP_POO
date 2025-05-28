//
// Created by mlvdi on 09/12/2023.
//

#include "refrigerador.h"

refrigerador::refrigerador(char tipo, Zona *z, int ID) : tipo(tipo), z(z), ID(ID) {}

void refrigerador::mudaEstado() {
    if(ligado){
        tipo = ::tolower(tipo);
        ligado = false;
        return;
    }
    tipo = ::toupper(tipo);
    ligado = true;
}

string refrigerador::recebeComando(string comando, int i) {
    if(comando == "liga"){
        if(ligado)
            return "Refrigerador ja se encontra ligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'o')
                p->setValor(20);
        }
        instantes = i;
    }
    else if(comando == "desliga"){
        if(!ligado)
            return "Refrigerador ja se encontra desligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'o')
                p->setValor(-20);
        }
    }
    return "Comando desconhecido";
}

refrigerador::~refrigerador() {
    ligado = false;
}

int refrigerador::getID() {
    return ID;
}

char refrigerador::getTipo() {
    return tipo;
}

string refrigerador::getEstado() const {
    if(ligado == 1)
        return "ligado";
    return "desligado";
}

string refrigerador::toString() {
    ostringstream oss;
    oss << "ID: " << getID() << ", Tipo: Refrigerador, Estado: " << getEstado() << "; ";
    return oss.str();
}

void refrigerador::processa(int instanteatual) {
    if(!ligado)
        return;

    for(Propriedades *p : z->getProps()){
        if(p->getTipo() == 't'){
            int add = instanteatual / 3;
            p->setValor(-add);
        }
    }
}
