#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {

        auto it = names.lower_bound(year);
        auto it_ = names.upper_bound(year);
        if (it != names.begin())
        {
            --it;
            auto data = *it;
            if (data.second.second != "" && names[year].first != data.second.first)
                names[year].second = data.second.second;
        }
        names[year].first = first_name;
        //if (it_ != names.begin() && it_ != names.end())
        //{
        //    auto& data = *it_;
        //    if (data.second.first != "")
        //        data.second.first = first_name;
        //}
    }
    void ChangeLastName(int year, const string& last_name) {

        auto it = names.lower_bound(year);
        auto it_ = names.upper_bound(year);
        if (it != names.begin())
        {
            --it;
            auto data = *it;
            if (data.second.first != "")
                names[year].first = data.second.first;
        }
        names[year].second = last_name;
        //if (it_ != names.begin() && it_ != names.end())
        //{
        //    auto& data = *it_;
        //    if (data.second.second != "")
        //        data.second.second = last_name;

        //}
    }
    string GetFullName(int year) {
        string str;
        auto it = names.upper_bound(year);
        if (it == names.begin())
            str = "Incognito";
        else
        {
            auto data = *(--it);
            if (data.second.first == "" && data.second.second == "")
                str = "Incognito";
            else if (data.second.first != "" && data.second.second != "")
                str = data.second.first + " " + data.second.second;
            else if (data.second.first == "" && data.second.second != "")
                str = data.second.second + " with unknown first name";
            else if (data.second.first != "" && data.second.second == "")
                str = data.second.first + " with unknown last name";
        }
        return str;


    }
private:
    map<int, pair<string, string>> names;
};



int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    person.ChangeFirstName(1968, "Marya");
    person.ChangeLastName(1968, "Solnceva");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

