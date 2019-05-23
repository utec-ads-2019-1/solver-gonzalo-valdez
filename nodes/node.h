#ifndef SOLVER_NODE_H
#define SOLVER_NODE_H
#include <string>
#include <cmath>
using namespace std;

class node {
protected:
    node *left;
    node *right;
    string data;
public:
    node(string data) : right(nullptr), left(nullptr), data(data){};
    bool isoperator(string s){
        return (s=="+" || s=="-" || s=="*" || s=="/" || s=="^");
    }
    float operate(){
        if(isoperator(data)){
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
        } else {
            return stof(data);
        }
    }

    friend class solver;
    friend class Tester;
};


#endif //SOLVER_NODE_H
