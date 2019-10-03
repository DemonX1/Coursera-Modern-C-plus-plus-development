#include <phone_number.h>

#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream phone_stream(international_number);

	country_code_.clear();
	city_code_.clear();
	local_number_.clear();
	
    if (phone_stream) {
        getline(phone_stream, country_code_, '-');
        getline(phone_stream, city_code_, '-');
        getline(phone_stream, local_number_, '\n');
    }
    
	if (country_code_[0] != '+') {
        throw invalid_argument("Incorrect country code - does not start with +");
    }
	if (country_code_.size() < 2) {
        throw invalid_argument("Incorrect country code - length is less than 2");
    }
	country_code_.erase(0, 1);
	    
	if (city_code_.empty()) {
        throw invalid_argument("Incorrect city code - it is empty");
    }
    
	if (local_number_.empty()) {
        throw invalid_argument("Incorrect local number - it is empty");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}