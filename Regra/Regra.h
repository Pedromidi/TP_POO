//
// Created by mlvdi on 18/11/2023.
//

#ifndef TP_REGRA_H
#define TP_REGRA_H

#include <string>
using namespace std;

class Regra {
public:
    Regra(string s, int x, int ID);
    Regra(string s, int x, int y, int ID);
    [[nodiscard]] string getRegra() const;
    [[nodiscard]] int getID() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    ~Regra();
private:
    int ID;
    string s;
    int x, y=0;
};


#endif //TP_REGRA_H
