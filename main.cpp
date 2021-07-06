#include <fstream>
#include <iostream>
#include "student.hpp"

int main() {
    StudentGroup stg;
    //stg.addNewStudent();
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
    /*
    stg.searchByPESEL();
    stg.printDB();
    auto list = stg.returnList();
    std::ofstream out("students.txt");
    std::list<std::shared_ptr<Student>> newList;
    for(auto& a : list) {
        out << a;
    }
    out.close();
  */

    std::ifstream inputFile("students.txt");
    if (inputFile.good()) {
        stg.returnList() = stg.fillListOfStudents(inputFile);
    }

    std::cout << "\nAfter reading from file:" << stg.returnList().size() << '\n';
    for (auto& a : stg.returnList()) {
        std::cout << a->name_ << ' ' << a->surname_ << " " << a->PESEL_ << ' ' << a->nrIndex_ << '\n';
    }

    inputFile.close();
    return 0;
}