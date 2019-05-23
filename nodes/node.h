#ifndef SOLVER_NODE_H
#define SOLVER_NODE_H
#include <string>
using namespace std;

class node {
protected:
    node *left;
    node *right;
    string data;
public:
    node(string data) : right(nullptr), left(nullptr), data(data){};
    virtual float operate() = 0;
    friend class solver;
};


#endif //SOLVER_NODE_H
