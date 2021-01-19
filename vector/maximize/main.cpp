#include<iostream>

void UpdateIfGreater(int first, int& second)
{
    if(first > second)
        second = first;
}

int main()
{
    int x = 5;
    int y = 3;
    UpdateIfGreater(x, y);
    std::cout << y << std::endl;

    return 0;
}