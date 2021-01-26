#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        }
        else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}
string GetNameStoryByYear(const map<int, string>& names, int year) {
    vector<string> story;
    auto it = names.upper_bound(year);
    if (it == names.begin())
        return "";
    --it;
    auto data = *it;
    //строим вектор имен
    for (; it != names.end(); --it)
    {
        auto f = *it;              
        story.push_back(f.second);        
        if (it == names.begin())
            break;
    }
    //убираем одинаковые имена
    vector<string> temp;
    story.push_back("end");
    for (int i = 0; i < story.size() - 1; ++i)
        if (story[i] != story[i + 1])
            temp.push_back(story[i]);

    string result;
    int count = 0;
    //организуем вывод без первого имени(можно переделать но не суть)
    for (auto item : temp)
    {       
        if (item != data.second || count != 0)
            result += item + ", ";
        ++count;
    }
    //для корректного вывода строк
    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
    }    
    return result;    
}
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        }
        else {
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        string story_first = GetNameStoryByYear(first_names, year);
        string story_last = GetNameStoryByYear(last_names, year);

        if (!story_first.empty())
            story_first = " (" + story_first + ")";
        if (!story_last.empty())
            story_last = " (" + story_last + ")";
        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        }
        else if (first_name.empty()) {
            return last_name + story_last + " with unknown first name";

            // если неизвестна только фамилия
        }
        else if (last_name.empty()) {
            return first_name + story_first + " with unknown last name";

            // если известны и имя, и фамилия
        }
        else {
            return first_name + story_first + " " + last_name + story_last;
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};



int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
