#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class ReversibleString
{
public:
	ReversibleString()
	{};
	ReversibleString(const string& str)	{this->str = str;};

	void Reverse()
	{
		reverse(this->str.begin(), this->str.end());
	};
	string ToString() const
	{
		return this->str;
	};

private:
	string str;
};



int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}
