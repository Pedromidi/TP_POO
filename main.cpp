#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Propriedade/Propriedades.h"
#include "Processador/Processador.h"
#include "Sensor/Sensor.h"
#include "Aparelho/Aparelho.h"
#include "Terminal.h"
#include "Habitacao/Habitacao.h"
#include "Aparelho/aquecedor.h"
#include "Aparelho/lampada.h"
#include "Aparelho/aspersor.h"
#include "Aparelho/refrigerador.h"
#include <algorithm>

using namespace std;

vector<term::Window*> janelas;
int px = 1;
int py = 1;
int instante = 0;

void comandoInvalido(term::Window &w, string st) {
    w << "\nComando invalido - " + st;
}

void Comandos(vector<string> palavrasComando, int &SPA, int &idR, term::Window &w, Habitacao *habitacao){
    int idZona, valor, valorr, linha, coluna, idProcRegra, idSensor, idcomp, instantesAAvancar, skip;
    string nome, tipo, spa, regra;
    char atipo;

    if(palavrasComando.size() == 1){

        if(palavrasComando[0] == "prox") {
            w.clear();
            w << "\navanca 1 instante";
            instante+=1;
        }

        else if(palavrasComando[0] == "hrem") {
            w.clear();
            habitacao->apagaZonas();
            for(term::Window *k : janelas){
                delete k;
            }
            w << "\nApaga todo o conteudo";
        }

        else if(palavrasComando[0] == "zlista") {
            w.clear();
            auto zonas = habitacao->getZonas();
            auto j = zonas.begin();
            if (!zonas.empty()) {
                for(Zona *z : zonas) {
                    if (*j != nullptr) {
                        w << (*j)->toString() <<"\n";
                    }
                    if (j + 1 != zonas.end())
                        ++j;
                }
            }
        }

        else if(palavrasComando[0] == "plista"){
            w.clear();
            w << "\nLista de copias de processadores de regras em memoria";
        }

        else
            comandoInvalido(w, "Nao conhecido");
    }

    else if(palavrasComando.size() == 2) {
        if (palavrasComando[0] == "avanca") {
            try{
                instantesAAvancar = stoi(palavrasComando[1]);
                w.clear();
                w << "\navanca " << instantesAAvancar << " instantes";
                instante+=instantesAAvancar;
            }catch(exception &err){
                comandoInvalido(w, "Sintaxe comando avanca");
            }
        }

        else if (palavrasComando[0] == "zrem") {
            try{
                idZona = stoi(palavrasComando[1]);
                vector<Zona *> zonas = habitacao->getZonas();
                auto i = zonas.begin();
                while (i != zonas.end()) {
                    if ((*i)->getID() == idZona) {
                        for(term::Window *k : janelas){
                            if((*i)->getLinha() == k->getPx() && (*i)->getColuna() == k->getPy()) {
                                k->clear();
                            }
                        }
                        w.clear();
                        w << "\napaga zona com id  " << idZona;
                        delete *i;
                        i = zonas.erase(i);
                        return;
                    }
                    else {
                        ++i;
                    }
                }
                w << "\nZona com id " << idZona << " nao encontrada";
            }catch(exception &err){
                comandoInvalido(w, "Sintaxe comando zrem");
            }
        }

        else if (palavrasComando[0] == "zcomp") {
            try{
                idZona = stoi(palavrasComando[1]);
                w.clear();
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        w << "Lista componentes na zona com ID: " << idZona;
                        w << "\nAparelhos: ";
                        for(Aparelho *a : z->getAparelhos()){
                            w << a->toString();
                        }
                        w << "\nSensores: ";
                        for(Sensor *s : z->getSensores()){
                            w << s->toString();
                        }
                        w << "\nProcessadores: ";
                        for(Processador *p : z->getProcessadores()){
                            w << p->toString();
                        }
                        return;
                    }
                }
                w << "\nZona com id " << idZona << " nao encontrada";
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando zcomp");
            }
        }

        else if (palavrasComando[0] == "zprops") {
            try{
                idZona = stoi(palavrasComando[1]);
                w.clear();
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        w << "\nLista propriedades da zona " << idZona << "\n";
                        for(Propriedades *p : z->getProps())
                            w << p->getProp() <<"\n";
                        return;
                    }
                }
                w << "Zona nao encontrada";
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando zprops");
            }
        }

        else if (palavrasComando[0] == "prepoe") {
            try{
                nome =palavrasComando[1];
                w.clear();
                w << "\nRepoe o processador guardado em memoria com o nome " << nome;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando prepoe");
            }
        }

        else if (palavrasComando[0] == "prem") {
            try{
                nome =palavrasComando[1];
                w.clear();
                w << "\nApaga uma copia do processador guardado em memoria com o nome " << nome;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando prem");
            }
        }

        else if (palavrasComando[0] == "exec") {
            try{
                nome = palavrasComando[1];
                w.clear();
                w << "\nCarrega o ficehiro de comandos com o nome " << nome;
                string palavra;

                ifstream commandFile(nome);
                if (!commandFile.is_open()) {
                    w << "\nFicheiro nao encontrado";
                    return;
                }

                while (getline(commandFile, nome)) {
                    palavrasComando.clear();
                    istringstream iss(nome);

                    while (iss >> palavra) {
                        palavrasComando.push_back(palavra);
                    }
                    Comandos(palavrasComando, SPA, idR, w,  habitacao);
                }
                commandFile.close();
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando exec");
            }
        }

        else
            comandoInvalido(w, "Nao conhecido");
    }

    else if(palavrasComando.size() == 3) {
        if (palavrasComando[0] == "hnova") {
            try{
                linha = stoi(palavrasComando[1]);
                coluna = stoi(palavrasComando[2]);

                if(linha >=2 && linha <=4){
                    if(coluna >=2 && coluna <=4) {
                        w.clear();
                        habitacao->resetNZonas();
                        instante = 0;
                        if(!janelas.empty()){
                            habitacao->apagaZonas();
                            px=1;
                            py=1;
                            for(term::Window *v : janelas){
                                delete v;
                            }
                        }

                        w << "\nhabitacao nova de " << linha << " * " << coluna;
                        int auxlin = 0;
                        int auxcol = 0;
                        int j = 0;
                        int i = 0;
                        while (auxlin < linha) {
                            while (auxcol < coluna) {
                                auto *z = new term::Window(2 + j, 2 + i, 13, 7, true, px, py);
                                janelas.push_back(z);
                                j += 13;
                                auxcol++;
                                if(auxcol < coluna){
                                    py+=1;
                                }
                            }
                            j = 0;
                            i += 7;
                            auxlin++;
                            if(auxlin < linha){
                                py=1;
                                px+=1;
                            }
                            auxcol = 0;
                        }
                        habitacao->setLin(linha);
                        habitacao->setCol(coluna);
                    }
                    else
                        comandoInvalido(w,  "Dimensao de errada para colunas");
                }
                else
                    comandoInvalido(w,  "Dimensao de errada para linhas");

            }catch(exception &err) {
                comandoInvalido(w,  "Sintaxe comando hnova");
            }
        }

        else if (palavrasComando[0] == "znova") {
            try{
                linha = stoi(palavrasComando[1]);
                coluna = stoi(palavrasComando[2]);
                for(Zona *t : habitacao->getZonas()){
                    w.clear();
                    if(t->getLinha() == linha && t->getColuna() == coluna){
                        comandoInvalido(w,  "Espaco de habitacao ocupado");
                        return;
                    }
                    if(linha > habitacao->getlin() || coluna > habitacao->getcol()){
                        comandoInvalido(w,  "Coordenadas para zona invalidas");
                        return;
                    }
                }
                w << "\nzona nova em " << linha << ", " << coluna;
                Zona *z = new Zona(linha, coluna, habitacao->getNZonas());
                habitacao->adicionaZona(z);

            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando znova");
            }
        }

        else if (palavrasComando[0] == "rlista") {
            try{
                w.clear();
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        for(Processador *p : z->getProcessadores()){
                            if(p->getID() == idProcRegra){
                                for(Regra *r : p->getRegras()){
                                    w << "\nID: " + to_string(r->getID()) + ", Regra: " + r->getRegra();
                                }
                                return;
                            }
                        }
                        w << "Processador nao encontrado";
                        return;
                    }
                }
                w << "Zona nao encontrada";
                return;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando rlista");
            }
        }

        else
            comandoInvalido(w,  "Nao conhecido");
    }

    else if(palavrasComando.size() == 4) {
        if (palavrasComando[0] == "pmod") {
            try{
                idZona = stoi(palavrasComando[1]);
                nome = palavrasComando[2];
                valor = stoi(palavrasComando[3]);
                w.clear();
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        for(Propriedades *p : z->getProps())
                            if(p->getNome() == nome){
                                w << "Modifica o valor da propriedade " << nome;
                                p->setValor(valor);
                                return;
                            }
                        w << "Propriesdade nao encontrada";
                        return;
                    }
                }
                w << "Zona nao encontrada";
                return;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando pmod");
            }
        }

        else if (palavrasComando[0] == "cnovo") {
            w.clear();
            if(palavrasComando[2] == "s"){
                spa = palavrasComando[2];
                try {
                    idZona = stoi(palavrasComando[1]);
                    tipo = palavrasComando[3];
                    for(Zona *z : habitacao->getZonas()){
                        if(z->getID() == idZona){
                            for(Propriedades *p : z->getProps()){
                                if(tipo[0] == p->getTipo()) {
                                    Sensor *s = new Sensor(z, tipo[0], SPA+1);
                                    z->adicionaSensor(s);
                                    SPA+=1;
                                    w << "Adiciona um sensor na zona com id " << idZona;
                                    return;
                                }
                            }
                            comandoInvalido(w,  "Propriedade para sensor nao encontrada");
                        }
                    }
                } catch (exception &err) {
                    comandoInvalido(w,  "IdZona invalido");
                }
            }
            else if(palavrasComando[2] == "p" ){
                spa = palavrasComando[2];
                try {
                    idZona = stoi(palavrasComando[1]);
                    tipo = palavrasComando[3];
                    for(Zona *z : habitacao->getZonas()){
                        if(z->getID() == idZona){
                            Processador *p = new Processador(SPA+1, tipo);
                            z->adicionaProcessador(p);
                            SPA+=1;
                            w << "Adiciona um processador na zona com id " << idZona;
                            return;
                        }
                    }
                } catch (exception &err) {
                    comandoInvalido(w,  "IdZona invalido");
                }
            }
            else if(palavrasComando[2] == "a"){
                spa = palavrasComando[2];
                try {
                    idZona = stoi(palavrasComando[1]);
                    tipo = palavrasComando[3];
                    if (tipo[0] == 'a') {
                        for (Zona *z: habitacao->getZonas()) {
                            if (z->getID() == idZona) {
                                aquecedor *a = new aquecedor('a', z, SPA + 1);
                                z->adicionaAparelho(a);
                                SPA += 1;
                            }
                        }
                        w << "Adiciona um aquecedor na zona com id " << idZona;
                    }

                    else if (tipo[0] == 's') {
                        for (Zona *z: habitacao->getZonas()) {
                            if (z->getID() == idZona) {
                                aspersor *a = new aspersor('s', z, SPA + 1);
                                z->adicionaAparelho(a);
                                SPA += 1;
                            }
                        }
                        w << "Adiciona um aspersor na zona com id " << idZona;
                    }

                    else if (tipo[0] == 'l'){
                        for (Zona *z: habitacao->getZonas()) {
                            if (z->getID() == idZona) {
                                lampada *a = new lampada('l', z, SPA + 1);
                                z->adicionaAparelho(a);
                                SPA += 1;
                            }
                        }
                        w << "Adiciona uma lampada na zona com id " << idZona;
                    }

                    else if(tipo[0] == 'r'){
                        for (Zona *z: habitacao->getZonas()) {
                            if (z->getID() == idZona) {
                                refrigerador *a = new refrigerador('r', z, SPA + 1);
                                z->adicionaAparelho(a);
                                SPA += 1;
                            }
                        }
                        w << "Adiciona um refrigerador na zona com id " << idZona;
                    }

                    else {
                        comandoInvalido(w,  "Tipo de aparelho invalido");
                        return;
                    }
                } catch (exception &err) {
                    comandoInvalido(w,  "IdZona invalido");
                }
            }
            else {
                comandoInvalido(w, "Sintaxe comando cnovo");
            }
        }

        else if (palavrasComando[0] == "crem") {
            w.clear();
            try {
                idZona = stoi(palavrasComando[1]);
                spa = palavrasComando[2];
                idcomp = stoi(palavrasComando[3]);
                if(spa != "s" && spa != "p" && spa != "a"){
                    w << "Componente invalido";
                    return;
                }
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                            for(Aparelho *a : z->getAparelhos()) {
                                if(a->getID() == idcomp){
                                    w << "Remove o componete " << spa << " com id" << idcomp << " da zona " << idZona;
                                    z->removeComponente(idcomp);
                                    return;
                                }
                            }
                    }
                    w << "Zona nao encontrada";
                    return;
                }
            } catch (exception &err) {
                comandoInvalido(w,  "Sintaxe comando crem");
            }
        }

        else if (palavrasComando[0] == "pmuda") {
            w.clear();
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                tipo = palavrasComando[3];
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        for(Processador *p : z->getProcessadores()){
                            if(p->getID() == idProcRegra){
                                p->setComando(tipo);
                                w << "\nMuda o comando do processador " << idProcRegra << " da zona " << idZona << " pelo novo comando " << tipo;
                            }
                        }
                        w << "Processador nao encontrado";
                        return;
                    }
                }
                w << "Zona nao encontrada";
                return;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando pmuda");
            }
        }

        else if (palavrasComando[0] == "rrem") {
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                idcomp = stoi(palavrasComando[3]);
                w.clear();
                w << "\nRemove a regra " << idcomp << " do processador de regras " << idProcRegra << " da zona " << idZona;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando rrem");
            }
        }

        else if (palavrasComando[0] == "asoc") {
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                idcomp = stoi(palavrasComando[3]);
                w.clear();
                w << "\nEstabelece a associacao entre o processador " << idProcRegra << " da zona " << idZona << " e o aparelho " << idcomp;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando asoc");
            }
        }

        else if (palavrasComando[0] == "ades") {
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                idcomp = stoi(palavrasComando[3]);
                w.clear();
                w << "\nRemove a associacao entre o processador " << idProcRegra << " da zona " << idZona << " e o aparelho " << idcomp;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando ades");
            }
        }

        else if (palavrasComando[0] == "acom") {
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                regra = palavrasComando[3];
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                        for(Aparelho *a : z->getAparelhos()){
                            if(a->getID() == idProcRegra){
                                a->recebeComando(regra, instante);
                            }
                        }
                    }
                }
                w.clear();
                w << "\nenvia o comando  " << regra << " ao aparelho " << idProcRegra << " da zona " << idZona;
            }catch(exception &err){
                comandoInvalido(w, "Sintaxe comando acom");
            }
        }

        else if (palavrasComando[0] == "psalva") {
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                nome = palavrasComando[3];
                w.clear();
                w << "\nsalva o estado de um processador   " << idProcRegra << " associado ao nome " << nome << " da zona " << idZona;
            }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando psalva");
            }
        }

        else
            comandoInvalido(w,  "Nao conhecido");
    }

    else if(palavrasComando.size() >= 5 && palavrasComando.size() <= 7) {
        if (palavrasComando[0] == "rnova") {
            w.clear();
            try{
                idZona = stoi(palavrasComando[1]);
                idProcRegra = stoi(palavrasComando[2]);
                regra = palavrasComando[3];
                idSensor = stoi(palavrasComando[4]);
                if(palavrasComando.size() == 6)
                    valor = stoi(palavrasComando[5]);
                if(palavrasComando.size() == 7)
                    valorr = stoi(palavrasComando[6]);
                for(Zona *z : habitacao->getZonas()){
                    if(z->getID() == idZona){
                       for(Processador *p : z->getProcessadores()){
                           if(p->getID() == idProcRegra){
                               for(Sensor *s : z->getSensores()){
                                   if(s->getID() == idSensor){
                                       if(palavrasComando.size() == 6){
                                           Regra *r = new Regra(regra, valor, idR+1);
                                           p->adicionaRegra(r);
                                       }
                                       else{
                                           Regra *r = new Regra(regra, valor, valorr, idR+1);
                                            p->adicionaRegra(r);
                                       }
                                       idR+=1;
                                       w << "\nCria a nova regra de ID " << idR << " do tipo " << regra << " adicionando ao processador com id" << idProcRegra << " associado ao sensor " << idSensor << " da zona " << idZona;
                                       return;
                                   }
                               }
                               w << "Sensor nao encontrado";
                               return;
                           }
                       }
                       w << "Processador nao encontrado";
                       return;
                    }
                }
                w << "Zona nao encontrada";
                return;
                 }catch(exception &err){
                comandoInvalido(w,  "Sintaxe comando rnova");
            }
        }
    }

    else
        comandoInvalido(w,  "Nao conhecido");
}

using namespace term;

void print_instantes(Terminal& t) {
    std::ostringstream o;
    o << "instante atual: " << instante;
    std::string str = o.str();
    t << set_color(0) << move_to(t.getNumCols()-str.length(), t.getNumRows()-1) << str;
}

int main() {
    Terminal &t = Terminal::instance();
    print_instantes(t);

    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }

    t << move_to(2, 1) << set_color(3) << "Habitacao";
    t << move_to(t.getNumCols()/2 + 1, 1) << set_color(3) << "Comandos";
    t << move_to(t.getNumCols()/2 + 1, 10) << set_color(3) <<"Notificacoes";

    Window c = Window(t.getNumCols()/2 + 1, 2, t.getNumCols()/2 - 1, 7);
    Window n = Window(t.getNumCols()/2 + 1, 11, t.getNumCols()/2 - 1, t.getNumRows()-12);

    c << set_color(0);
    n << set_color(0);

    string comando, palavra, nome;
    vector<string> palavrasComando;
    int idR = 0;
    int SPA = 0;
    int contaComandos = 0;
    auto *habitacao = new Habitacao(2,2);

    while(true) {

        auto zonas = habitacao->getZonas();
        if (!zonas.empty()) {
            for (Window *w: janelas) {
                for(Zona *z : zonas) {
                    if (w->getPx() == z->getLinha()) {
                        if (w->getPy() == z->getColuna()) {
                            w->clear();
                            for(Aparelho *a : z->getAparelhos())
                                a->processa(instante);
                            *w << z->toString();
                        }
                    }
                }
            }
        }

        palavrasComando.clear();

        c << "Comando: ";
        c.operator>>(comando);

        string inputString = comando;
        istringstream iss(inputString);

        while (iss >> palavra) {
            palavrasComando.push_back(palavra);
        }

        if(palavrasComando.size() == 1) {
            if (palavrasComando[0] == "sair") {
                n << "Encerra programa";
                break;
            }
        }

        Comandos(palavrasComando, SPA, idR, n,  habitacao);
        print_instantes(t);

        contaComandos += 1;
        if(contaComandos >= 5) {
            contaComandos = 0;
            c.clear();
        }
    }
    return 0;
}