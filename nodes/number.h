#ifndef SOLVER_NUMBER_H
#define SOLVER_NUMBER_H
#include "node.h"
using namespace std;
class number : public node {
public:
    number(string data) : node(data) {};
    float operate(){
        return stof(data);
    }
};
#endif //SOLVER_NUMBER_H
