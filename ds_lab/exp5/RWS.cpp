#include <cmath>
#include <iostream>
#include <stack>

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

    int solve(int left, char opr, int right) {
        if (opr == '+') {
            return (left + right);
        } else if (opr == '-') {
            return (left - right);
        } else if (opr == '*') {
            return (left * right);
        } else if (opr == '/') {
            return (left / right);
        } else if (opr == '^') {
            return std::pow(left, right) + 0.5;
        }
    }

    int evaluateExpression(std::string expression) {
        std::stack<int> operands;
        std::stack<char> operators;
        int i = 0;
        int n = expression.length();
        while (i < n) {
            char cur = expression[i];
            if (cur == ' ') {
                i++;
                continue;
            }
            if (cur >= '0' && cur <= '9') {
                std::string number = "";
                while (expression[i] >= '0' && expression[i] <= '9') {
                    number += expression[i];
                    i++;
                }
                operands.push(std::stoi(number));
                continue;
            } else if (cur == ')') {
                while (operators.top() != '(') {
                    int right = operands.top();
                    operands.pop();
                    int left = operands.top();
                    operands.pop();
                    int ans = solve(left, operators.top(), right);
                    operands.push(ans);
                    operators.pop();
                }
                operators.pop();
            } else if (cur == '(') {
                operators.push(cur);
            } else {
                while (operators.size() > 0 &&
                       precedence(operators.top()) >= precedence(cur)) {
                    if (operators.top() == '^' && cur == '^') {
                        break;
                    }
                    int right = operands.top();
                    operands.pop();
                    int left = operands.top();
                    operands.pop();
                    int ans = solve(left, operators.top(), right);
                    operands.push(ans);
                    operators.pop();
                }
                operators.push(cur);
            }
            i++;
        }

        while (operators.size() > 0) {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            int ans = solve(left, operators.top(), right);
            operands.push(ans);
            operators.pop();
        }

        return operands.top();
    }
};

int main() {
    Solution obj;
    std::string expression;
    std::cout << "====================" << std::endl;
    std::cout << "CALCULATOR" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Enter expression :";
    std::getline(std::cin, expression);
    std::cout << "====================" << std::endl;
    std::cout << "Result :" << obj.evaluateExpression(expression) << std::endl;
    std::cout << "====================" << std::endl;

    return 0;
}