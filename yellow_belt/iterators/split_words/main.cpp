#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	for (auto it = s.begin(); it != s.end();) {
		auto space = find(it + 1, s.end(), ' ');
		if (it == s.begin())
			result.push_back({ it, space });
		else
			result.push_back({ it + 1, space });
		it += string(it, space).size();
	}
	return result;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}

