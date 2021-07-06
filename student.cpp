#include "student.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "checkPESEL.hpp"

Student::Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& index, const std::string& PESEL, char gender)
    : name_(name), surname_(surname), address_(address), nrIndex_(index), PESEL_(PESEL), gender_(gender) {}
Student::Student() {}

void StudentGroup::addNewStudent() {
    /*  std::shared_ptr<Student> st{new Student};
    std::cout << "Please fill data for new Student: \n";
    std::cout << "Name: ";
    std::cin >> st->name_;
    std::cout << "Surname: ";
    std::cin >> st->surname_;
    std::cout << "Address: ";
    std::cin >> st->address_;
    std::cout << "No Index: ";
    std::cin >> st->nrIndex_;
    std::cout << "PESEL: ";
    std::cin >> st->PESEL_;
    std::cout << "Gender(just only letter M or K): ";
    std::cin >> st->gender_;
*/
    listStudents.push_back(std::shared_ptr<Student>{new Student("Ma", "Asomkt", "aao", "ss100", "85022714812", 'K')});
    listStudents.push_back(std::shared_ptr<Student>{new Student("Ma", "Comkt", "aao", "ss200", "75022814812", 'M')});
    listStudents.push_back(std::shared_ptr<Student>{new Student("Ma", "Yomkt", "aao", "ss300", "85032714812", 'K')});
    listStudents.push_back(std::shared_ptr<Student>{new Student("Ma", "Womkt", "aao", "ss400", "75022814512", 'M')});

    //listStudents.push_back(st);
}
size_t StudentGroup::getSize() const {
    return listStudents.size();
}

void StudentGroup::printDB() const {
    if (listStudents.size() != 0) {
        for (auto it = listStudents.begin(); it != listStudents.end(); ++it) {
            std::cout << '\n'
                      << (*it)->name_ << ' ' << (*it)->surname_ << '\n'
                      << (*it)->PESEL_ << ' ' << (*it)->nrIndex_ << ' ' << (*it)->gender_ << '\n';
        }
    }
    else {
        std::cout<<"Students Data Base is empty !\n";
    }
}

void StudentGroup::searchBySurname() const {
    std::string searchName{};
    std::cout << "Podaj szukane nazwisko: \n";
    std::cin >> searchName;
    auto result = std::find_if(listStudents.begin(), listStudents.end(), [&](std::shared_ptr<Student> st) {
        if (st->surname_ == searchName) {
            return true;
        }
        return false;
    });
    if (result != listStudents.end()) {
        std::cout << "\nW bazie znaleziono podane nazwisko: ";
    } else {
        std::cout << "W bazie nie ma podanego nazwiska! " << *result << '\n';
    }
}

void StudentGroup::searchByPESEL() const {
    std::string PESEL{};
    std::cout << "Podaj szukany PESEL: \n";
    std::cin >> PESEL;
    //validate PESEL
    if (checkPESEL(PESEL)) {
        auto result = std::find_if(listStudents.begin(), listStudents.end(), [&](std::shared_ptr<Student> st) {
            if (checkPESEL(st->PESEL_)) {
                if (st->PESEL_ == PESEL) {
                    return true;
                }
            }
            return false;
        });
        if (result != listStudents.end()) {
            std::cout << "\nW bazie znaleziono PESEL: ";
        } else {
            std::cout << "W bazie nie ma podanego nazwiska! ";
        }
    } else {
        std::cout << "\nPodany Pesel jest błędny!\n";
    }
}

struct PESELComparator {
    bool operator()(std::shared_ptr<Student> p1, std::shared_ptr<Student> p2) {
        for (size_t i = 0; i < (p1->PESEL_).length(); i++) {
            if (p1->PESEL_[i] < p2->PESEL_[i])
                return true;
            if (p1->PESEL_[i] > p2->PESEL_[i])
                return false;
        }
        return false;
    }
};

void StudentGroup::sortByPESEL() {
    listStudents.sort(PESELComparator());
}
void StudentGroup::sortBySurname() {
    listStudents.sort([](std::shared_ptr<Student> p1, std::shared_ptr<Student> p2) {
        if (p1->surname_ == p2->surname_) {
            return p1->surname_ < p2->surname_;
        }
        return p1->surname_ < p2->surname_;
    });
}
void StudentGroup::deleteByIndex() {
    std::string index{};
    std::cout << "Podaj szukany Index: \n";
    std::cin >> index;

    auto result = std::find_if(listStudents.begin(), listStudents.end(), [&](std::shared_ptr<Student> st) {
        if (st->nrIndex_ == index) {
            return true;
        }
        return false;
    });
    if (result != listStudents.end()) {
        std::cout << "\nW bazie znaleziono index: ";
        listStudents.erase(result);
    } else {
        std::cout << "W bazie nie ma podanego indexu! ";
    }
}
std::ostream& operator<<(std::ostream& out, Student* student) {
    out << student->name_ << ' ' << student->surname_ << ' ' << student->PESEL_ << ' ' << student->nrIndex_ << '\n';
    return out;
}
std::istream& operator>>(std::istream& in, Student* student) {
    in >> student->name_ >> student->surname_ >> student->PESEL_ >> student->nrIndex_;
    return in;
}
std::list<std::shared_ptr<Student>> StudentGroup::fillListOfStudents(std::istream& file) {
    Student student;
    while(file >> &student) {
        listStudents.push_back(std::make_shared<Student>(student));
    }
    return listStudents;
}
