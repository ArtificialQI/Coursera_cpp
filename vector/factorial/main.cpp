#include <iostream>

int fact(int n) 
{       
    if (n > 0)
        return n*fact(n - 1); 
    else
        return 1;
}

int main()
{
    int n = 10;
    std::cout << fact(n);

    return 0;
}
