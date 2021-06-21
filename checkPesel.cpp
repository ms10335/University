#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

bool isOnlyDigits(const std::string& pesel) {
    return std::all_of(pesel.begin(), pesel.end(), ::isdigit);
}
bool leapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}
bool isControlNumberValid(const std::string& pesel) {
    constexpr std::array<int, 10> weight{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::vector<int> vec{};
    vec.reserve(pesel.size());
    int sum{0};

    for (int i = 0; i < pesel.size(); ++i) {
        vec.push_back(pesel[i] - '0');
    }

    for (int i = 0; i < 10; ++i) {
        sum = sum + (vec.at(i) * weight.at(i));
    }

    int countControlNumber = (10 - sum % 10) % 10;

    if (vec.back() == countControlNumber) {
        return true;
    }
    return false;
}

int getBirthMonth(const std::string& pesel) {
    int month = std::stoi(pesel.substr(2, 2));
    if (month > 80 && month < 93) {
        month -= 80;
    } else if (month > 20 && month < 33) {
        month -= 20;
    } else if (month > 40 && month < 53) {
        month -= 40;
    } else if (month > 60 && month < 73) {
        month -= 60;
    }
    return month;
}

bool checkMonth(const std::string& pesel) {
    int month = getBirthMonth(pesel);
    if (month > 0 && month < 13) {
        return true;
    }
    return false;
}

int createYear(const std::string& pesel) {
    int month = std::stoi(pesel.substr(2, 2));
    int year = std::stoi(pesel.substr(0, 2));
    if (checkMonth(pesel)) {
        if (month > 80 && month < 93) {
            year += 1800;
        } else if (month > 0 && month < 13) {
            year += 1900;
        } else if (month > 20 && month < 33) {
            year += 2000;
        } else if (month > 40 && month < 53) {
            year += 2100;
        } else if (month > 60 && month < 73) {
            year += 2200;
        }
        return year;
    }
    return -1;
}

int getBirtDay(const std::string& pesel) {
    int day = std::stoi(pesel.substr(4, 2));
    if (day > 0 && day < 32) {
        return day;
    }
    return -1;
}

bool checkDay(const std::string& pesel) {
    if(!checkMonth(pesel)) {
        return false;
    }
    int year = createYear(pesel);
    int month = getBirthMonth(pesel);
    int day = getBirtDay(pesel);

    if (year < 0 || day < 0) {
        return false;
    }
    if ((day > 0 && day < 32) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
        return true;
    }
    if ((day > 0 && day < 31) && (month == 4 || month == 6 || month == 9 || month == 11)) {
        return true;
    }
    if ((day > 0 && day < 30 && leapYear(year)) || (day > 0 && day < 29 && !leapYear(year))) {
        return true;
    }
    return false;
}

char getGender(const std::string& pesel) {
    int gender = std::stoi(pesel.substr(9, 1));
    if (gender & 1) {
        return 'M';
    }
    return 'K';
}

bool checkPESEL(const std::string& pesel) {
    //check if pesel has 11 dig and if all are digits
    if (pesel.size() != 11 || (!isOnlyDigits(pesel))) {
        return false;
    }
    //check if controlNUmberisValid
    if (isControlNumberValid(pesel) && checkDay(pesel) ) {
        return true;
    }
    return false;
}

int main() {
    std::string pesel = "75022714812";
    bool check = checkPESEL(pesel);
    std::cout << std::boolalpha <<check << '\n';

    return 0;
}
