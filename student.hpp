#pragma once
#include <string>
#include <list>
#include <memory>

struct Student {
    Student() = default;
    Student(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, char);
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string nrIndex_{};
    std::string PESEL_{};
    char gender_{};
    void setStudentDetails();
};


//class to servie group of students
class StudentGroup {
public:
    StudentGroup(const StudentGroup&) = delete;
    StudentGroup& operator=(const StudentGroup& ) = delete;
    StudentGroup() = default;
    ~StudentGroup() {
        //czy tutaj nalezy wyczyscis liste ??
    }
    void addNewStudent();
    void printDB() const;
    void searchBySurname() const;
    void searchByPESEL() const;
    void sortByPESEL() const;
    void sortBySurname() const;
    void deleteByIndex();
    size_t getSize() const;

private:
    std::list<Student> listStudents{};
};