#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H
#include <string>
#include "nodes/number.h"
#include "nodes/opera.h"
using namespace std;

class solver {
private:
    string eq;
public:
    solver(string equ) : eq(equ) {
        char old=NULL;
        // solve +++--+-+-
        string finaleq;
        for (int i=0;i<eq.size();i++){
            char s = eq[i];
            finaleq.push_back(s);
            if(isoperator(s) && isoperator(old)){
                finaleq.pop_back();finaleq.pop_back();
                finaleq.push_back(solveoperators(s,old));
            }
            old=s;
        }
        eq = finaleq;
    };

    bool isoperator(char s){
        return (s=='+' || s=='-' || s=='*' || s=='/' || s=='^');
    }
    char solveoperators(char op1, char op2){
        if(op1=='+' and op2=='-'){
            return '-';
        }
        if(op2=='+' and op1=='-'){
            return '-';
        }

    }
    node* createnode(char s){
        string v;
        v.push_back(s);
        if(isoperator(s)){
            return new opera(v);
        } else {
            return new number(v);
        }
    }
    node* buildtrio(char s, string s1, string s2){
        auto node = createnode(s);
        auto n1 = build(s1);
        auto n2 = build(s2);
        node->left = n1;
        node->right = n2;
        return node;
    }
    node* build(string eq = this->eq){
        bool inparentesis=false;
        for(int i=0;i<eq.size();i++){
            string s1,s2;
            char s=eq[i];
            if(s=='('){
                inparentesis=true;
            }
            if(s==')'){
                inparentesis=false;
            }
            if(!inparentesis){
                if(s=='+' || s=='-'){
                    s1=eq.substr(0,eq.find(s));
                    s2=eq.substr(eq.find(s)+1);
                    return buildtrio(s,s1,s2);
                }
            }
        }
    }
};

#endif //SOLVER_SOLVER_H
