#include <iostream>
#include <fstream>
#include "student.hpp"

int main() {
    StudentGroup stg;
    stg.addNewStudent();
    // std::cout << stg.getSize();
    // stg.printDB();
    // std::cout<<"after sorting:\n";
    // stg.sortByPESEL();
    // stg.printDB();
    // stg.sortBySurname();
    // std::cout<<"After sortign surname:\n";
    // stg.printDB();
    // stg.deleteByIndex();
    // stg.printDB();
    // std::cout<<"\nSize after deleteing: "<<stg.getSize()<<'\n';

    stg.searchByPESEL();
    stg.printDB();
    auto list = stg.returnList();
    std::ofstream out("students.txt");
    std::list<std::shared_ptr<Student>> newList;
    for(auto& a : list) {
        out << a;
    }
    out.close();
    
    std::ifstream in ("students.txt");
    Student *student = new Student();
    while (in) {
        in >> student;
        std::cout << student->name_ << student->surname_ << student->PESEL_ << student->nrIndex_;
        newList.emplace_back(student);
        student = nullptr;
    }
    in.close();
    delete student;
    
    std::cout<<"\nAfter reading from file:" << newList.size()<<'\n';
    for(auto& a : newList) {
        std::cout<<a->name_<<' '<<a->surname_<<" " << a->PESEL_ <<' '<<a->nrIndex_<<'\n';
    }

    return 0;
}