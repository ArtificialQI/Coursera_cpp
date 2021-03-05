#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
bool IsPalindrom(std::string str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    int count = 0;
    for(int i = 0; i < str.size() / 2; ++i)
        if(tolower(str[i]) == tolower(str[str.size() - i - 1]))
            ++count;

    return (str.size() / 2 == count);
}
std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
    std::vector<std::string> tmp;
    for(int i = 0; i < words.size(); ++i)
        if(IsPalindrom(words[i]) && words[i].size() >= minLength)
            tmp.push_back(words[i]);
    return tmp;
}
int main()
{
    std::string str;
    int minLength = 4;
    std::vector<std::string> words;
    words.resize(3);
    for(auto& item: words)
        std::getline(std::cin, item);
    for(auto item: words)
        std::cout << item << std::endl;
    std::cout << IsPalindrom(str);
    for(auto item: PalindromFilter(words, minLength))
        std::cout << item;
    return 0;
}