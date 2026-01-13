#include <iostream>
#include <stack> 
using namespace std;

int stack[100];
int top =-1;
int s = sizeof(stack)/sizeof(stack[0]);

void push(int value){
    if(top == s-1){
        cout<<"Stack overflow";
        return ;
    }
    stack[++top] = value;
}
void pop(){
    if(top == -1){
        cout<<"Stack underflow or there is nothing here ";
        return ;
    }
    cout<<stack[top--];
}

void peek(){
    if(top ==-1){
        cout<<"nope";
        return ;
    }
    cout<<stack[top];
}
void display(){
    if(top ==-1){
        cout<<"nothing to display";
        return;
    }
    int temp = top;
    while(temp !=-1){
        cout<<stack[temp]<<" ";
        temp --;
    }
}

int percedence(char op){
    if(op == '^'){
        return 3;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '+' || op == '-'){
        return 1;
    }
    return 0;
}
string postfix( string infix){
    stack<char> s ;
    string postfix = "";
    for(int i =0 ;i<infix.length();i++){
        if(isalnum(infix[i])){
            postfix += infix[i];
        }
        if else(infix[i] == '(') { 
            s.push(infix[i]);
        }
        if else (infix[i] == ')'){
            while(!s.empty() && s.top != "("){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.top()) >=  precedence(infix[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix ;
}


void tobinary(int value){
    stack<char> s;
    while(value > 0){
        rem = value % 2;
        div = kena / 2;
        s.push(rem);
        value = div;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int evalexp(string kena){
    stack<char> s;
    for(int i =0 ;i<kena.length();i++){
        if(isdigit(kena[i])){
            s.push(kena[i] - '0');
        }else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (kena[i]){
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(a+b);
                    break;
                case '^':
                    s.push(pow(a,b));
                    break;
                default:


            }

        }
    }
    
}