#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int Q;
	cin >> Q;
	map<string, set<string>> syn;
	for (int i = 0; i < Q; ++i)
	{
		string operation_code;
		cin >> operation_code;

		if (operation_code == "ADD")
		{
			string word_1, word_2;
			cin >> word_1 >> word_2;
			syn[word_1].insert(word_2);
			syn[word_2].insert(word_1);
		}
		else if (operation_code == "COUNT")
		{
			string word;
			cin >> word;
			if (syn.count(word) == 1)
				cout << syn[word].size() << endl;
			else
				cout << "0" << endl;
		}
		else if (operation_code == "CHECK")
		{
			string word_1, word_2;
			cin >> word_1 >> word_2;
			if (syn[word_1].find(word_2) != syn[word_1].end() || syn[word_2].find(word_1) != syn[word_2].end())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}