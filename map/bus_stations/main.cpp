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
	vector<pair<string, vector<string>>> bus_stops;
	for (int i = 0; i < Q; i++)
	{
		string operation_code;
		cin >> operation_code;
		if (operation_code == "NEW_BUS")
		{
			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;
			vector<string> stops;
			stops.resize(stop_count);
			pair<string, vector<string>> tmp;
			for (auto& stop : stops)
				cin >> stop;
			tmp.first.append(bus);
			tmp.second = stops;
			bus_stops.push_back(tmp);

		}
		else if (operation_code == "BUSES_FOR_STOP")
		{
			int count = 0;
			string stop;
			cin >> stop;
			for (auto item : bus_stops)
			{
				for (auto s : item.second)
					if (s == stop)
					{
						++count;
						cout << item.first << " ";
					}
			}
			if (count != 0)
				cout << endl;

			if (count == 0)
				cout << "No stop" << endl;
		}
		else if (operation_code == "STOPS_FOR_BUS")
		{
			string route;
			cin >> route;

			int exit = 0;
			for (auto item : bus_stops)
			{
				if (route == item.first)
				{
					++exit;
					for (auto i : item.second)
					{
						int count = 0;
						cout << "Stop " << i << ": ";
						for (auto item : bus_stops)
							if (find(item.second.begin(), item.second.end(), i) != item.second.end())
								if (item.first != route)
								{
									cout << item.first << " ";
									++count;
								}
						if (count == 0)
							cout << "no interchange";
						cout << endl;
					}
				}
			}

			if (exit == 0)
				cout << "No bus" << endl;
		}
		else if (operation_code == "ALL_BUSES")
		{
			map<string, vector<string>> tmp;
			for (auto item : bus_stops)
				tmp.emplace(item);

			int count = 0;
			for (auto item : tmp)
			{
				++count;
				cout << "Bus " << item.first << ": ";
				for (auto i : item.second)
					cout << i << " ";
				cout << endl;
			}

			if (count == 0)
				cout << "No buses" << endl;
		}
	}

	return 0;
}
