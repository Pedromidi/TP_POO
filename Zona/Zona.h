//
// Created by mlvdi on 10/11/2023.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "../Propriedade/Propriedades.h"

using namespace std;

#ifndef TP_ZONA_H
#define TP_ZONA_H

class Sensor;
class Processador;
class Aparelho;

class Zona {
public:
    Zona(int linhas, int colunas, int ID);
    void adicionaProp(Propriedades *newProp);
    void adicionaSensor(Sensor *newSensor);
    void adicionaAparelho(Aparelho *newAparelho);
    void adicionaProcessador(Processador *newProc);
    vector<Aparelho*> getAparelhos();
    vector<Sensor*> getSensores();
    vector<Processador*> getProcessadores();
    vector<Propriedades*> getProps();
    void removeComponente(int id);
    string toString();
    int getLinha();
    int getColuna();
    [[nodiscard]] int getID() const;
    ~Zona();
private:
    int linhas, colunas, ID;
    vector<Propriedades*> props;
    vector<Sensor*> sensores;
    vector<Aparelho*> aparelhos;
    vector<Processador*> processadores;
};

#endif //TP_ZONA_H
