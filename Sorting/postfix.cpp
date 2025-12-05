#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            st.push(ch-'0');   
        }
        else {
            int b = st.top(); 
            st.pop();
            int a = st.top(); 
            st.pop();

            switch (ch) {
                case '+': st.push(a + b); 
                break;
                case '-': st.push(a - b); 
                break;
                case '*': st.push(a * b);
                break;
                case '/': st.push(a / b);
                break;
            }
        }
    }
    return st.top();
}
int levelofop(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string convpostfix(string expr) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }
        else {
            while (!st.empty() && levelofop(st.top()) >= levelofop(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}
int main() {
    string postfix = "(a*b-(c+d)+e)";  

    cout<<convpostfix(postfix);

    return 0;
}
