#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    int next = 0;
    int count = 0;
    int days_in_month = 32;
    vector<vector<string>> daily(days_in_month);
    for (size_t i = 0; i < Q; i++)
    {

        string operation;
        cin >> operation;
        int number;
        string cases;
        if (operation == "ADD")
        {
            cin >> number;
            cin >> cases;
            daily[number].push_back(cases);
        }
        else if (operation == "DUMP")
        {
            cin >> number;
            
            cout << daily[number].size() << ' ';
            for (auto item : daily[number])
                cout << item << ' ';
            cout << endl;          
        }

        else if (operation == "NEXT")
        {
            next++;
            count++;
            if (count == 7  || next == 12)
            {
                days_in_month = 32;            
                if (next == 12)
                {
                    count = 0;
                    next = 0;
                }
            }
            else
            {
                if (days_in_month == 29 || days_in_month == 31)
                {                    
                    days_in_month = 32;
                }
                else if (days_in_month == 32 && next == 1)
                {
                    days_in_month = 29;                   
                }
                else
                {
                    days_in_month = 31;
                }
            }         

            vector<vector<string>> new_vec;
            if (daily.size() <= days_in_month)
            {
                for (int i = 0; i < daily.size(); ++i)
                    new_vec.push_back(daily[i]);
                vector<string> empty;
                int j = 0;
                while (days_in_month - daily.size() > j)
                {
                    new_vec.push_back(empty);
                    j++;
                }

                daily.clear();
                copy(new_vec.begin(), new_vec.end(), back_inserter(daily));
            }
            else
            {
                for (int i = 0; i < days_in_month; ++i)
                    new_vec.push_back(daily[i]);
                int i = 0;
                while (daily.size() > days_in_month + i)
                {
                    new_vec.back().insert(new_vec.back().end(), daily[daily.size() - i - 1].begin(), daily[daily.size() - i - 1].end());
                    ++i;
                }
                daily.clear(); 
                copy(new_vec.begin(), new_vec.end(), back_inserter(daily));
            }
            
        }
    }


    return 0;
}
