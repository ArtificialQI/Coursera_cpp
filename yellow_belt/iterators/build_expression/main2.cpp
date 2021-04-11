#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main() {

	int first, N;
	cin >> first >> N;
	deque<string> expression;
	vector<string> operations{""};
	expression.push_back(to_string(first));
	for (size_t i = 0; i < N; ++i) {
		string operation;
		int operand;
		cin >> operation >> operand;
		switch (operation[0]) {
		case '+':
			expression.push_back(" " + operation + " " + to_string(operand));
			break;
		case '-':
			expression.push_back(" " + operation + " " + to_string(operand));
			break;
		case '*':
			if (operations.back() == "+" || operations.back() == "-") {
				expression.push_back(") " + operation + " " + to_string(operand));
				expression.push_front("(");
			}
			else
				expression.push_back(" " + operation + " " + to_string(operand));
			break;
		case '/':
			if (operations.back() == "+" || operations.back() == "-") {
				expression.push_back(") " + operation + " " + to_string(operand));
				expression.push_front("(");
			}
			else
				expression.push_back(" " + operation + " " + to_string(operand));
			break;
		default:
			break;
		}

		operations.push_back(operation);
	}
	for (auto item : expression)
		cout << item;

	return 0;
}