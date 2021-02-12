#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<char, int> BuildCharCounters(const string& str)
{
    map<char, int> letters;
    
    for (int i = 0; i < str.size(); ++i)
        ++letters[str[i]];
    return letters;
}
int main()
{
    int N;
    string str1, str2;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> str1 >> str2;
        
        if(BuildCharCounters(str1) == BuildCharCounters(str2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}