#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    vector<int> days(N);

    float avg = 0;
    for(auto& item: days)
    {
        cin >> item;
        avg += (float)item/days.size();
    }        

    int count = 0;
    for(int item: days)
        if(item > (int)avg)
            count++;
    cout << count << endl;
    for(int i = 0; i < days.size(); ++i)
        if(days[i] > avg)
        cout << i << ' ';
    return 0;
}