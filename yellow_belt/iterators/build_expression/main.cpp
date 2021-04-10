#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int first, N;
	cin >> first >> N;
	if (N == 0) {
		cout << to_string(first) << endl;
		return 0;
	}
	string expression(N - 1, '(');
	expression += "(" + to_string(first) + ")";
	for (size_t i = 0; i < N; ++i) {
		string operation;
		int operand;
		cin >> operation >> operand;
		expression += " " + operation + " " + to_string(operand) + ")";
	}
	expression.pop_back();
	cout << expression << endl;

	return 0;
}