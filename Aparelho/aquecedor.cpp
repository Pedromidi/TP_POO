//
// Created by mlvdi on 09/12/2023.
//

#include "aquecedor.h"

aquecedor::aquecedor(char tipo, Zona *z, int ID) : tipo(tipo), z(z), ID(ID) {}

void aquecedor::mudaEstado() {
    if(ligado){
        tipo = ::tolower(tipo);
        ligado = false;
        return;
    }
    tipo = ::toupper(tipo);
    ligado = true;
}

string aquecedor::recebeComando(string comando, int i) {
    if(comando == "liga"){
        if(ligado)
            return "Aquecedor ja se encontra ligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'o')
                p->setValor(5);
        }
        instantes = i;
    }
    else if(comando == "desliga"){
        if(!ligado)
            return "Aquecedor ja se encontra desligado";

        mudaEstado();
        for(Propriedades *p : z->getProps()){
            if(p->getTipo() == 'o')
                p->setValor(-5);
        }
    }
    return "Comando desconhecido";
}

aquecedor::~aquecedor() {
    ligado = false;
}

int aquecedor::getID() {
    return ID;
}

char aquecedor::getTipo() {
    return tipo;
}

string aquecedor::getEstado() const {
    if(ligado == 1)
        return "ligado";
    return "desligado";
}

string aquecedor::toString() {
    ostringstream oss;
    oss << "ID: " << getID() << ", Tipo: Aquecedor, Estado: " << getEstado() << "; ";
    return oss.str();
}

void aquecedor::processa(int instanteatual) {
    if(!ligado)
        return;

    for(Propriedades *p : z->getProps()){
        if(p->getTipo() == 't'){
            int add = instanteatual / 3;
            if (add < 50.0) {
                p->setValor(add);
            }
            else
                p->setValor(50);
        }
    }
}
