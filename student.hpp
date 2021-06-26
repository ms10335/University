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
    auto searchByParameter(const std::string&) const;
    size_t getSize() const;
    friend std::ostream & operator <<(std::ostream&, Student* );
    friend std::istream & operator >> (std::istream &,  Student*);

    std::list<std::shared_ptr<Student>> returnList() {
        return listStudents;
    }

private:
    std::list<std::shared_ptr<Student>> listStudents{};
};