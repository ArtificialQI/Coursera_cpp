#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int Q;
	cin >> Q;
	map<set<string>, int> m;
	for (int i = 0; i < Q; ++i)
	{
		size_t N;
		cin >> N;
		set<string> stops;
		for (int i = 0; i < N; ++i)
		{
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		if (m.count(stops) == 1)
			cout << "Already exists for " << m[stops] << endl;
		else
		{
			cout << "New bus " << m.size() + 1 << endl;
			int tmp = m.size();
			m[stops] = tmp + 1;
		}
	}
	return 0;
}