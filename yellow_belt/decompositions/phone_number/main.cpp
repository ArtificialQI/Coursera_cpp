#include "phone_number.h"
#include <iostream>

int main()
{
    std::string num{ "+1-2-coursera-cpp" };
    try {
        auto phone = new PhoneNumber(num);

        std::cout << phone->GetCityCode() << ' '
            << phone->GetCountryCode() << ' '
            << phone->GetLocalNumber() << ' '
            << phone->GetInternationalNumber() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
