#include<iostream>
using namespace std;

const int max_size = 100;
class Stack{
    public:
    char arr[max_size];
    int top=-1;

    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top == max_size-1;
    }
    char pop(){
        if(isEmpty()){
            cout<<"\nUnderflow";
            return '\0';
        }
        else{
            return arr[top--];
        }
    }
    bool push(char data){
        if(isFull()) return false;
        else{
            arr[++top] = data;
            return true;
        } 
    }

};
int main(){
    Stack s;
    int flag =0;
    string exp;
    cout<<"\nEnter expression: ";
    cin>>exp;

    for(int i=0;i<exp.length();i++){
        if(exp[i] == '(' || exp[i]=='{' || exp[i]=='['){
            s.push(exp[i]);
        }
        else{
            if(exp[i] == ')' || exp[i] == '}' || exp[i]==']'){
               char top = s.pop();
               if(exp[i] == ')' && top == '(')
               continue;
               if(exp[i] == '}' && top == '{')
               continue;
               if(exp[i] == ']' && top=='[')
               continue;

               flag = 1;
               break;
            }
        }
    }
    if(flag == 1 || !s.isEmpty()){
        cout<<"\nNot well parenthized!!";
    }
    else{
        cout<<"\nWell parenthized";
    }

    return 0;
}
