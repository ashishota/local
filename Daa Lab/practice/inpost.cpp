#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

string infix_to_postfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() != '(') {
                cout << "Invalid expression\n";
                return "";
            } else {
                s.pop();
            }
        } else {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infix_to_postfix(infix);
    if (!postfix.empty()) {
        cout << "Postfix expression: " << postfix << endl;
    }

    return 0;
}
