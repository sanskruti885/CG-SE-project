// In any language program mostly syntax error occurs due to unbalancing delimiter 
// such as (), {}, []. Write C++ program using stack to check whether given expression 
// is well parenthesized or not.

#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100
class Stack{
    public:
        int top;
        char a[MAX];
    
    Stack(){
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    bool push(char x);
    char pop();
    char peek();
};

bool Stack::isEmpty(){
    return top==-1;
}
bool Stack ::isFull(){
    return top==MAX-1;
}
char Stack::pop(){
    if(isEmpty())
    return 0;
    else
    return a[top--];
}
bool Stack::push(char x){
    if(isFull()) return false;
    else {
        a[++top] = x;
        return true;
    }

}

int main(){
    Stack s;
    string str;
    cout<<"Enter string: ";
    cin>>str;
    int flag=0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }
        if(str[i] == '}' || str[i] == '}' || str[i] == '}'){
            char t = s.pop();
            if(str[i] == '}' and t == '{') 
            continue;
             if(str[i] == ')' and t == '(') 
            continue;
             if(str[i] == ']' and t == '[') 
            continue;

            flag=1; //mismatch
            break;
        }
    }

    if(flag ==1 or s.isEmpty()){
        cout<<"\n Not well parenterized!!!!";
    }
    else{
        cout<<"\nWell parenterized!!!";
    }
    return 0;
}