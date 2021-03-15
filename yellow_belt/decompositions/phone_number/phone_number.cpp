#include "phone_number.h"
#include <iostream>
#include <exception>
#include <algorithm>
PhoneNumber::PhoneNumber(const std::string& international_number)
{
	if (international_number[0] == '+') {
		if (count(international_number.begin(), international_number.end(), '-') < 2)
			throw std::invalid_argument("wrong_international_number");

		auto first = find(international_number.cbegin(), international_number.cend(), '-');
		auto second = find(first + 1, international_number.cend(), '-');

		this->country_code_ = std::string(international_number.cbegin() + 1, first);
		this->city_code_ = std::string(first + 1, second);
		this->local_number_ = std::string(second + 1, international_number.end());

		if (country_code_ == "" || city_code_ == "" || local_number_ == "")
			throw std::invalid_argument("wrong_international_number");
	}
	else
		throw std::invalid_argument("wrong_international_number");
}

std::string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

std::string PhoneNumber::GetCityCode() const {
	return city_code_;
}

std::string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}