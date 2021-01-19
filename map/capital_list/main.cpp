#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;

void print_map(const map<string, string>& object)
{
    for (const auto& [key, value] : object)
        cout << key << "/" << value << endl;
}

int main()
{
    int Q;
    cin >> Q;
    map<string, string> list;
    for (int i = 0; i < Q; ++i)
        {   
            string operation_code;
            cin >> operation_code;
            if (operation_code == "CHANGE_CAPITAL")
                {
                    string country, new_capital;
                    cin >> country >> new_capital;
                    if (list[country] == "")
                    {
                        list[country] = new_capital;
                        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                    }
                    else if (list[country] == new_capital)
                        cout << "Country " << country << " hasn't changed its capital" << endl;
                    else
                    {
                        cout << "Country " << country << " has changed its capital from " << list[country] << " to " << new_capital << endl;
                        list[country].erase();
                        list[country] = new_capital;
                    }
                }
            else if (operation_code == "RENAME")
                {
                    string old_country_name, new_country_name;
                    cin >> old_country_name >> new_country_name;
                    if (old_country_name == new_country_name || list[old_country_name] == "" || list[new_country_name] != "")
                        cout << "Incorrect rename, skip" << endl;
                    else
                    {
                        string tmp = list[old_country_name];
                        list[old_country_name].erase();
                        list[new_country_name] = tmp;
                        cout << "Country " << old_country_name << " with capital " << list[new_country_name] << " has been renamed to " << new_country_name << endl;
                    }
                }
            else if (operation_code == "ABOUT")
                {
                    string country;
                    cin >> country;
                    if (list[country] == "")
                        cout << "Country " << country << " doesn't exist" << endl;
                    else
                        cout << "Country " << country << " has capital " << list[country] << endl;
                    
                }
            else if (operation_code == "DUMP")
                {
                    int count = 0;
                    for (const auto& item : list)
                        ++count;
                
                    if (count == 1)
                        cout << "There are no countries in the world" << endl;
                    else
                        print_map(list);  
                }               
        }

    return 0;
}
