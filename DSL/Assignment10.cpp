// Implement C++ program for expression conversion as infix to postfix and its evaluation 
// using stack based on given conditions:  
// 1. Operands and operator, both must be single character.  
// 2. Input Postfix expression must be in a desired format.  
// 3. Only '+', '-', '*' and '/ ' operators are expected. 
#include<iostream>
using namespace std;

const int max_size = 100;

class Operation{
    public:
    char arr[max_size];
    int top = -1;

    int prec(char c){
        if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        return -1;
    }
    void push(char c){
        if(top == max_size-1){
            cout<<"\nOverflow";
        }
        else{
            arr[++top] = c;
        }
    }
    char pop(){
        if(top == -1){
            cout<<"\nEmpty";
            return '\0';
        }
        return arr[top--];
    }
    char peek(){
        if(top!=-1){
            return arr[top];
        }
        return '\0';
    }
    bool isEmpty(){
        return top==-1;
    }
    string infix_to_postfix(string s){
        string res;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                res+=s[i];
            }
            else if(s[i]=='('){
                push(s[i]);
            }
            else if(s[i] == ')'){
                while(!isEmpty() && peek()!='('){
                    res+=pop();
                }
                pop();
            }
            else{
                while(!isEmpty() && prec(s[i])<=prec(peek())){
                    res+=pop();
                }
                push(s[i]);
            }
        }
        while(!isEmpty()){
            res+=pop();
        }
        return res;
    }

    double evaluate(string str){
        double operand[max_size];
        int top=-1;
        for(char c: str){
            if(isalnum(c)){
                double value;
                cout<<"\nEnter value of "<<c<<": ";
                cin>>value;
                operand[++top] = value;
            }
            else{
                double right = operand[top--];
                double left = operand[top--];
                double result;

                switch(c){
                    case '+': 
                        result = left+right;
                        break;
                    case '-':
                        result = left-right;
                        break;
                    case '*':
                        result = left*right;
                        break;
                    case '/':
                            result = left/right;
                            break;
                    default: cout<<"\nUnkonwn Operator.";
                            return 0;
                }
                operand[++top] = result;  
            }
        }
        return operand[top];
    }
};
int main(){
    Operation o;
    string str,op,input;
    char ch= 'y';
    int n;

    while (ch=='y'){
        cout<<"\n1. Conversion";
        cout<<"\n2. Evaluate";
        cout<<"\nEnter your choice: ";
        cin>>n;

        switch(n){
            case 1: cout<<"\nEnter expression: ";
                    cin>>input;
                    str = o.infix_to_postfix(input);
                    cout<<"\nPostfix: "<<str;
                    break;
            case 2: n = o.evaluate(str);
                    cout<<"\nEvaluation: "<<n;
                    break;
            default: cout<<"\nWrong choice";
        }
        cout<<"\n'y' to continue";
        cin>>ch;
    }
    return 0;
}