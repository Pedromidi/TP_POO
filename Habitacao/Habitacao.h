//
// Created by mlvdi on 10/11/2023.
//

#include <iostream>
#include "../Zona/Zona.h"
#include "../Terminal.h"

using namespace std;

#ifndef TP_HABITACAO_H
#define TP_HABITACAO_H


class Habitacao {
public:
    Habitacao(int linhas, int colunas);
    [[nodiscard]] int getlin() const;
    [[nodiscard]] int getcol() const;
    void setLin(int l);
    void setCol(int c);
    [[nodiscard]] vector<Zona*> getZonas() const;
    void adicionaZona(Zona* z);
    void apagaZonas();
    int getNZonas();
    void resetNZonas();
    ~Habitacao();
private:
    vector<Zona*> zonas;
    int nzonas;
    int linhas;
    int colunas;
};


#endif //TP_HABITACAO_H
