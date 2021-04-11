#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main() {
	deque<string> expression;
	int first, N;
	cin >> first >> N;
	expression.emplace_back(to_string(first));
	for (size_t i = 0; i < N; ++i) {
		string operation;
		int operand;
		cin >> operation >> operand;
		expression.emplace_back(")");
		expression.emplace_back(" " + operation + " " + to_string(operand));
		expression.emplace_front("(");
	}
	for (auto item : expression)
		cout << item;
	return 0;
}