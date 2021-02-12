#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int Q;
	cin >> Q;
	map<vector<string>, int> m;
	for (int i = 0; i < Q; ++i)
	{
		size_t N;
		cin >> N;
		vector<string> stops;
		stops.resize(N);
		for (auto& stop : stops)
			cin >> stop;

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