//
// Created by mlvdi on 17/11/2023.
//

#ifndef TP_SENSOR_H
#define TP_SENSOR_H


#include "../Propriedade/Propriedades.h"
#include "../Zona/Zona.h"
#include <sstream>
#include <cstring>
#include <memory>

class Sensor {
public:
    Sensor(Zona *z, char propriedade, int ID);
    int getID();
    string getProp();
    string toString();
    char getTipo();
    ~Sensor();
private:
    Zona *z;
    char propriedade;
    int ID;
};


#endif //TP_SENSOR_H
