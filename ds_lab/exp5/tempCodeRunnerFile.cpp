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
                operands.push(std::stoi(std::string(1, cur)));
            } else if (cur == ')') {
                while (operators.top() != '(') {
                    int right = operands.top();
                    operands.pop();
                    int left = operands.top();
                    operands.pop();
                    if (operators.top() == '+') {
                        operands.push(left + right);
                    } else if (operators.top() == '-') {
                        operands.push(left - right);
                    } else if (operators.top() == '*') {
                        operands.push(left * right);
                    } else if (operators.top() == '/') {
                        operands.push(left / right);
                    } else if (operators.top() == '^') {
                        operands.push(std::pow(left, right));
                    }
                    operators.pop();
                }
                operators.pop();
            } else if (cur == '(') {
                operators.push(cur);
            } else {
                while (operators.size() > 0 &&
                       precedence(operators.top()) >= precedence(cur) &&
                       operators.top() != '^') {
                    int right = operands.top();
                    operands.pop();
                    int left = operands.top();
                    operands.pop();
                    if (operators.top() == '+') {
                        operands.push(left + right);
                    } else if (operators.top() == '-') {
                        operands.push(left - right);
                    } else if (operators.top() == '*') {
                        operands.push(left * right);
                    } else if (operators.top() == '/') {
                        operands.push(left / right);
                    } else if (operators.top() == '^') {
                        operands.push(std::pow(left, right));
                    }
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
            if (operators.top() == '+') {
                operands.push(left + right);
            } else if (operators.top() == '-') {
                operands.push(left - right);
            } else if (operators.top() == '*') {
                operands.push(left * right);
            } else if (operators.top() == '/') {
                operands.push(left / right);
            } else if (operators.top() == '^') {
                operands.push(std::pow(left, right));
            }
            operators.pop();
        }

        return operands.top();
    }
};

int main() {
    Solution obj;
    std::string expression;
    std::cout << "Enter expression :";
    std::getline(std::cin, expression);

    std::cout << "Output :" << obj.evaluateExpression(expression) << std::endl;
    return 0;
}