#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    vector<int> queue;
    for (int i = 0; i < Q; ++i)
    {
        string operation;
        int number;
        int people = rand() % 10;
        cin >> operation;
        if (operation == "COME")
        {
            cin >> number;
            if (number > 0)
                for (int i = 0; i < number; ++i)
                    queue.push_back(people);
            else
                for (int i = 0; i < abs(number); ++i)
                    queue.pop_back();
        }
        else if (operation == "WORRY")
        {
            cin >> number;
            queue[number] = -5;
        }
        else if (operation == "QUIET")
        {
            cin >> number;
            queue[number] = 5;
        }
        else if (operation == "WORRY_COUNT")
        {
            int count = 0;
            for (int i = 0; i < queue.size(); ++i)
                if (queue[i] == -5)
                    ++count;

            cout << count << endl;
        }
    }
    return 0;
}