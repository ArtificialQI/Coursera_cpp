#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {

	auto negative = find_if(numbers.begin(), numbers.end(), [](int value) {return value < 0; });
	for (auto it = negative; it != numbers.begin();)
		cout << *(--it) << " ";
}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 }); // empty vector
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}
