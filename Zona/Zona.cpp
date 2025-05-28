//
// Created by mlvdi on 10/11/2023.
//

#include "Zona.h"
#include "../Sensor/Sensor.h"
#include "../Aparelho/Aparelho.h"
#include "../Processador/Processador.h"
#include "../Propriedade/Temperatura.h"
#include "../Propriedade/Vibracao.h"
#include "../Propriedade/Luz.h"
#include "../Propriedade/Radiacao.h"
#include "../Propriedade/Humidade.h"
#include "../Propriedade/Fumo.h"
#include "../Propriedade/Som.h"

Zona::Zona(int linhas, int colunas, int ID) : linhas(linhas), colunas(colunas), ID(ID) {
    Temperatura *t = new Temperatura();
    adicionaProp(t);
    Luz *m = new Luz();
    adicionaProp(m);
    Radiacao *d = new Radiacao();
    adicionaProp(d);
    Vibracao *v = new Vibracao();
    adicionaProp(v);
    Humidade *h = new Humidade();
    adicionaProp(h);
    Fumo *f = new Fumo();
    adicionaProp(f);
    Som *s = new Som();
    adicionaProp(s);
}

void Zona::adicionaProp(Propriedades *newProp) {
    props.push_back(newProp);
}

void Zona::adicionaSensor(Sensor *newSensor) {
    sensores.push_back(newSensor);
}

void Zona::adicionaAparelho(Aparelho *newAparelho) {
    aparelhos.push_back(newAparelho);
}

void Zona::adicionaProcessador(Processador *newProc) {
    processadores.push_back(newProc);
}

Zona::~Zona(){

};

int Zona::getID() const {
    return ID;
}

void Zona::removeComponente(int id) {
    auto i = aparelhos.begin();
    while(i != aparelhos.end())
        if((*i)->getID()==id){
            delete *i;
            aparelhos.erase(i);
            return;
        }
    ++i;
    auto j = sensores.begin();
    while(j != sensores.end())
        if((*j)->getID()==id){
            delete *j;
            sensores.erase(j);
            return;
        }
    ++j;
    auto k = processadores.begin();
    while(k != processadores.end())
        if((*k)->getID()==id){
            delete *k;
            processadores.erase(k);
            return;
        }
    ++k;
}

string Zona::toString() {
    std::ostringstream oss;
    oss << "ID: " << getID();
    oss << "\nAs:";
    for(Aparelho *a : aparelhos){
        oss << a->getTipo();
    }
    oss << "\nSs:";
    for(Sensor *s : sensores){
        oss << s->getTipo();
    }
    oss << "\nPs:";
    for(Processador *p : processadores){
        oss << "p";
    }
    return oss.str();
}

int Zona::getLinha() {
    return linhas;
}

int Zona::getColuna() {
    return colunas;
}

vector<Aparelho *> Zona::getAparelhos() {
    return aparelhos;
}

vector<Sensor *> Zona::getSensores() {
    return sensores;
}

vector<Propriedades *> Zona::getProps() {
    return props;
}

vector<Processador *> Zona::getProcessadores() {
    return processadores;
};
