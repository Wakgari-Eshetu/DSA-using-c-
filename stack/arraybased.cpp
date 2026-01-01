#include <iostream>
#include <stack>

using namespace std;


int leli[100];
int top = -1;
int s = sizeof(leli)/sizeof(leli[0]);


void insertvalue(int value ){
    if(top == s-1){
        cout<<"stack overflow";
        return ;
    }
    
    leli[++top] = value;
}

void deletevalue(){
    if(top == -1){
        cout<<"stackunderflow";
        return ;
    }
    cout<<leli[top--];
    
}
void showtop(){
    if(top == -1){
        cout<<"underflow";
        return;
    }
    cout<<leli[top];
}
void display(){
    if(top == -1){
        cout<<"underflow";
        return;
    }
    int temp = top;
    while (temp  != -1){
        cout<<leli[temp]<<" ";
        temp--;
    }
}

string reversef(string kena){
    stack<char> s;
    for(int i=0 ;i<kena.length();i++){
        s.push(kena[i]);
    }
    
    string str;
    for(int i=0;i<kena.length();i++){
        str += s.top();
        s.pop();
    }
    
    return str;
    
}
bool checkpalindrome (string kena){
        stack<char> s;
    for(int i=0 ;i<kena.length();i++){
        s.push(kena[i]);
    }
    
    string str;
    for(int i=0;i<kena.length();i++){
        str += s.top();
        s.pop();
    }
    
    return str== kena ;
}
int precedence(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    return 0;
}
string postfix(string kena){
    stack<char> s;
    string str = "";
    for(int i= 0 ;i<kena.length();i++){
        if(isalnum(kena[i])){
            str += kena[i];
        }
        else if(kena[i] == "(" ){
            s.push(kena[i])
        }
        else if(kena[i] == ")"){
            while(!s.empty() && s.top() != "("){
                str += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.top)>precedence(kena[i])){
                str += s.top();
                s.pop();
                
            }
            s.push(kena[i]);
        }
    }
    while(!s.empty()){
        str += s.top();
        s.pop();
    }
    return str;
}
void tobinary(int kena){
    stack<int> s;
    int rem , div ;
    while(kena > 0){
        rem = kena % 2;
        div = kena / 2
        s.push(rem);
        kena = div ;

    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
void evalexpression(str kena = postfix()){
    stack<int> s;
    for(int i =0 ; i< kena.length();i++){
        if(isdigit(kena[i])){
            s.push(kena[i] - '0');
        }
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            switch(kena[i]){
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
                    s.push(a/b);
                    break;
                case '^':
                    s.push(pow(a,b));
                    break;
            }
            }
        }
        return s.top();
    }

int main(){
    cout<<reversef("lelisa")<<endl;
    if (1 == checkpalindrome("lelisa")){
        cout << true;
    }
    else{
        cout<<false;
    }
    return 0;
}


