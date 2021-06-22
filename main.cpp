#include <iostream>
#include "student.hpp"
int main() {
    StudentGroup stg;
    stg.addNewStudent();
    std::cout << stg.getSize();
    stg.printDB();
    std::cout<<"after sorting\n:";
    stg.sortByPESEL();
    stg.printDB();
    stg.sortBySurname();
    std::cout<<"After sortign surname:\n";
    stg.printDB();
    stg.deleteByIndex();
    stg.printDB();
    std::cout<<"\nSize after deleteing: "<<stg.getSize()<<'\n';
    return 0;
}