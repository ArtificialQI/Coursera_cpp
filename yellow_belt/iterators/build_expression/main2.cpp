#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int first, N;
	cin >> first >> N;
	string expression = to_string(first);
	string prev_operation;
	for (size_t i = 0; i < N; ++i) {

		string operation;
		int operand;
		cin >> operation >> operand;
		switch (operation[0]) {
		case '+':
			expression += " " + operation + " " + to_string(operand);
			break;
		case '-':
			expression += " " + operation + " " + to_string(operand);
			break;
		case '*':
			if (prev_operation == "+" || prev_operation == "-")
				expression = + "(" + expression + ") " + operation + " " + to_string(operand);
			else
				expression += " " + operation + " " + to_string(operand);
			break;
		case '/':
			if (prev_operation == "+" || prev_operation == "-")
				expression = + "(" + expression + ") " + operation + " " + to_string(operand);
			else
				expression += " " + operation + " " + to_string(operand);
			break;
		default:
			break;
		}
		prev_operation = operation;
	}
	cout << expression << endl;

	return 0;
}