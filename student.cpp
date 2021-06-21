#include "student.hpp"
#include <string>

Student::Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& index, const std::string& PESEL, char gender)
  : name_(name), surname_(surname), address_(address), nrIndex_(index), PESEL_(PESEL), gender_(gender) {}

void StudentGroup::addNewStudent() {
    listStudents.emplace_back(Student("Marcin", "Smoktunowicz", "Nowa 1B", "s10335","850227",'M'));
}
size_t StudentGroup::getSize() const {
    return listStudents.size();
}

void StudentGroup::printDB() const{}
void StudentGroup::searchBySurname() const{}
void StudentGroup::searchByPESEL() const{}
void StudentGroup::sortByPESEL() const {}
void StudentGroup::sortBySurname() const{}
void StudentGroup::deleteByIndex() {}