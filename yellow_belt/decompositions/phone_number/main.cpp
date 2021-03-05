#include "phone_number.h"
#include <iostream>

int main()
{
    std::string num { "+7-495-111-22-33" };
    try {
        auto phone = new PhoneNumber(num);

        std::cout << phone->GetCityCode() << ' '
                  << phone->GetCountryCode() << ' '
                  << phone->GetLocalNumber() << ' '
                  << phone->GetInternationalNumber() << '\n';
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}