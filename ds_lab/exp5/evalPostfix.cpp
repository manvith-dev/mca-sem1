#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

class Solution {
  public:
    std::string evaluatePostfix(std::string expression) {
        std::stack<int> st;
        int n = expression.length();
        int i = 0;

        while (i < n) {
            while (i < n && expression[i] == ' ') {
                i += 1;
            }

            std::string cur = "";
            while (i < n && expression[i] != ' ') {
                cur += expression[i];
                i += 1;
            }

            if (cur == "+" || cur == "-" || cur == "/" || cur == "*" ||
                cur == "^") {
                if (st.size() < 2) {
                    return "Invalid Expression";
                }
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                if (cur == "+") {
                    st.push(right + left);
                } else if (cur == "-") {
                    st.push(left - right);
                } else if (cur == "/") {
                    if (right == 0) {
                        std::cout << "Cannot divide by 0\n";
                        return "undefined";
                    }
                    st.push(left / right);
                } else if (cur == "*") {
                    st.push(right * left);
                } else if (cur == "^") {
                    st.push(std::pow(left, right) + 0.5);
                }
            } else {
                st.push(std::stoi(cur));
            }
        }
        if (st.empty() || st.size() > 1) {
            return "Invalid Expression";
        }
        std::string res = std::to_string(st.top());
        st.pop();
        return res;
    }
};

int main() {
    Solution solution;
    std::string expression;

    std::cout << "Enter postfix expression (space-separated): ";
    getline(std::cin, expression);

    std::string result = solution.evaluatePostfix(expression);
    if (result == "undefined" || result == "Invalid Expression") {
        std::cout << "Result: " << result << '\n';
    } else {

        std::cout << "Result: " << std::stoi(result) << '\n';
    }

    return 0;
}