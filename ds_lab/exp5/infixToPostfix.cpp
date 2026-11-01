#include <iostream>
#include <stack>
#include <string>

class Solution {
  public:
    int precedence(char op) {
        if (op == '-') {
            return 0;
        } else if (op == '+') {
            return 0;
        } else if (op == '/') {
            return 1;
        } else if (op == '*') {
            return 1;
        } else if (op == '^') {
            return 2;
        }
        return -1;
    }

    std::string infixToPostfix(std::string expression) {
        std::stack<char> st;
        std::string res = "";
        int n = expression.length();
        int i = 0;

        while (i < n) {
            char ch = expression[i];
            if (ch == ' ') {
                i++;
                continue;
            }
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                res += std::string(1, ch);
            } else {
                if (ch == '(') {
                    st.push(ch);
                } else if (ch == ')') {
                    while (st.top() != '(') {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                } else if (ch == '^') {
                    st.push(ch);
                } else {
                    while (!st.empty() &&
                           (precedence(ch) <= precedence(st.top()))) {
                        res += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
            }
            i++;
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::string expression;

    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, expression);

    std::cout << "Postfix expression: " << sol.infixToPostfix(expression)
              << '\n';

    return 0;
}