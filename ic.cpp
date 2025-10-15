#include <iostream>
#include "ic.h"
#include <string.h>
#include <chrono>
#include <format>

#define FORMATTED_OFFSET 14
#define RAW_OFFSET 12

// Getters
const std::string IC::getFormattedNumber() const {
    std::string rV = (this->formatted_number).data();
    return rV;
};

const std::string IC::getRawNumber() const {
    std::string rV = (this->raw_number).data();
    return rV;
};

Sex IC::getSex() const {
    return this->sex;
};

StateInfo IC::getState() const {
    return this->state;
};

std::string IC::getName() const {
    return this->name;
};

std::string IC::getAddress() const {
    return this->address;
};

std::chrono::system_clock::time_point IC::getDob() const {
    return this->dob;
};

bool IC::isValid() const{
    return this->validity;
};

// Setters (optional, only if you want to allow modification)
void IC::setName(const std::string& name) {
    this->name = name;
};

void IC::setAddress(const std::string& address) {
    this->address = address;
};

// Class methods
bool validIClength(const std::string& ic_number) {

    if (ic_number.length() != 12) {
        return false;
    }

    return true;
}

bool containsTwelveDigits(std::string ic_number) {
    // Validate all characters are digits
    for (size_t raw_offset = 0; raw_offset < ic_number.length(); ++raw_offset) {
        char c = ic_number[raw_offset];

        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

void formatRawICnumber(const std::string& input, 
    std::array<char, 13>& raw_number,
    std::array<char, 15>& formatted_number
) {
    // Copying over to raw_number + null terminator
    std::size_t n = std::min(input.size(), raw_number.size() - 1);
    std::copy_n(input.begin(), n, raw_number.begin());
    raw_number[n] = '\0'; 

    
    // Formatted number
    std::string temp = std::format("{}-{}-{}",
        input.substr(0, 6),
        input.substr(6, 2),
        input.substr(8, 4)
    );

    // Copy into fixed array
    std::size_t m = std::min(temp.size(), formatted_number.size() - 1);
    std::copy_n(temp.begin(), m, formatted_number.begin());
    formatted_number[m] = '\0';

}

bool numberIsValid(std::array<char, 13> raw_number) {
    // Implement validation logic here

    std::string ic_string = std::string(raw_number.data());

    int year = std::stoi(ic_string.substr(0, 2));
    uint month = std::stoi(ic_string.substr(2, 2));
    uint day = std::stoi(ic_string.substr(4, 2));
    
    std::chrono::year_month_day ymd {
        std::chrono::year{year + 2000},
        std::chrono::month{month}, 
        std::chrono::day{day}
    };

    if (!ymd.ok()) {
        return false;
    }
    
    int state_code = std::stoi(ic_string.substr(6, 2));
    
    if (!stateCodeMap.contains(state_code)) {
        return false;
    }

    if (ic_string.length() != 12) {
        return false;
    }

    return true; // Placeholder
}

// TODO add dump()

// Constructor implementations
IC::IC() {
    this->validity = false;
    this->note = "Blank object generated through empty constructor";
};

IC::IC(const std::string& ic_number) { // Provide IC_number as raw_number

    // Validate length
    if (!validIClength(ic_number)) {
        this->validity = false;
        this->note = "IC number not valid: length";
        return;
    }

    formatRawICnumber(ic_number, this->raw_number, this->formatted_number);


};