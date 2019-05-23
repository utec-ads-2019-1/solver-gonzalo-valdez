#ifndef SOLVER_OPERA_H
#define SOLVER_OPERA_H

#include <cmath>
#include "node.h"
using namespace std;
class opera : public node {
public:
    opera(string data) : node(data) {};
    float operate(){
        if (data=="^") {
            return pow(left->operate(), right->operate());
        }
        if (data=="*") {
            return left->operate() * right->operate();
        }
        if (data=="/") {
            return left->operate() / right->operate();
        }
        if (data=="+") {
            return left->operate() + right->operate();
        }
        if (data=="-") {
            return left->operate() - right->operate();
        }
    }
};

#endif //SOLVER_OPERA_H
