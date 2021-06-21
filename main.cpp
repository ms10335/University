#include <iostream>
#include "student.hpp"
int main() {
    StudentGroup stg;
    stg.addNewStudent();

    std::cout<<stg.getSize()<<'\n';
    return 0;
}