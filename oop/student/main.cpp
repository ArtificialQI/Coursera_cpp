#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct student
{
    string first_name;
    string last_name;
    long long int day;
    long long int month;
    long long int year;
};

int main()
{
    long long int N;
    cin >> N;
    vector<student> students(N);

    for (auto& item : students) {
        cin >> item.first_name >> item.last_name;
        cin >> item.day >> item.month >> item.year;
    }
    long long int M;
    cin >> M;
    for (int m = 0; m < M; ++m)
    {
        string request;
        long long int K;
        cin >> request >> K;
        int count = 0;
        if (request == "name") {
            ++count;
            if (K <= students.size() && K > 0)
                cout << students[K - 1].first_name << ' ' << students[K - 1].last_name << endl;
            else
                cout << "bad request" << endl;
        }
        else if (request == "date") {
            ++count;
            if (K <= students.size() && K > 0)
                cout << students[K - 1].day << "." << students[K - 1].month << "." << students[K - 1].year << endl;
            else
                cout << "bad request" << endl;    
        }
        else if (count == 0)
            cout << "bad request" << endl;
    }
    return 0;
}