#pragma once
#include <list>
#include <memory>
#include <string>

struct Student {
    Student();
    Student(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, char);
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string nrIndex_{};
    std::string PESEL_{};
    char gender_{};
};

//class to servie group of students
class StudentGroup {
public:
    StudentGroup() = default;
    ~StudentGroup() {
        //czy tutaj nalezy wyczyscis liste ??
    }
    void addNewStudent();
    void printDB() const;
    void searchBySurname() const;
    void searchByPESEL() const;
    void sortByPESEL();
    void sortBySurname();
    void deleteByIndex();
    size_t getSize() const;
    bool compareNumbers(std::shared_ptr<Student> str1, std::shared_ptr<Student> str2);

private:
    std::list<std::shared_ptr<Student>> listStudents{};
};