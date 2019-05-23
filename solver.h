#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H
#include <string>
#include "nodes/node.h"
#include <map>
#include <stack>
using namespace std;

class solver {
private:
    node* root=nullptr;
    string equation;
public:
    solver(string equ) {
        char old;
        //////////////////// solve +++--+-+-
        string finaleq;
        for (int i=0;i<equ.size();i++){
            char s = equ[i];
            finaleq.push_back(s);
            if(isoperator(s) and isoperator(old)){
                finaleq.pop_back();finaleq.pop_back();
                finaleq.push_back(solveoperators(s,old));
                old=solveoperators(s,old);
            } else {
                old=s;
            }
        }
         //////////////////////////erase parenthesis//////////////////////////////////
        string finaleq2;
        for (int i=0;i<finaleq.size();i++){
            char s = finaleq[i];
            if(s!='(' and s!=')'){
                finaleq2.push_back(s);
            }
        }
        equation = finaleq2;
    };

    bool isoperator(char s){
        return (s=='+' || s=='-' || s=='*' || s=='/' || s=='^');
    }
    char solveoperators(char op1, char op2){
        if(op1=='+' and op2=='-'){
            return '-';
        } else if(op1=='-' and op2=='+'){
            return '-';
        } else if(op1=='-' and op2=='-'){
            return '+';
        } else
            return '+';
    }
    node* createnode(char s){
        string v;
        v.push_back(s);
        return new node(v);
    }

    char findop(string eq, int &it){
        char s;
        for (auto i = eq.size(); --i;) {
            if(eq.find("+")==string::npos and eq.find("-")==string::npos) break;
            s = eq[i];
            if (s == '+' or s == '-') {
                it=i;
                return s;
            }
        }
        for(auto i=eq.size();--i;) {
            if(!eq.find('/')==string::npos and !eq.find('*')==string::npos) break;
            s = eq[i];
            if(s=='*' or s=='/') {
                it=i;
                return s;
            }
        }
        for(auto i=eq.size();--i;) {
            if(!eq.find('^')==string::npos) break;
            s = eq[i];
            if(s=='^') {
                it=i;
                return s;
            }
        }
        return 'n';
    }
    node* build(string eq) {
        string s1, s2;
        int it=0;
        bool found = false;
        char s;
        s = findop(eq,it);

        if (s!='n'){
            s1 = eq.substr(0, it);
            s2 = eq.substr(it + 1);
            node *node = createnode(s);
            node->left = build(s1);
            node->right = build(s2);
            return node;

        } else {
            return new node(eq);
        }
    }

    friend class Tester;
};

#endif //SOLVER_SOLVER_H
