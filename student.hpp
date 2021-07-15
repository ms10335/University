#pragma once
#include <vector>
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
    friend std::ostream& operator<<(std::ostream&, const Student&);
    friend std::istream& operator>>(std::istream&, Student&);
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
    std::shared_ptr<Student> createStudent();
    size_t getSize() const;
    bool checkIsPeselExistinDB(const std::string&);
    void fillListOfStudents(std::istream&);
    std::vector<std::shared_ptr<Student>> returnList() {
        return listStudents;
    }
private:
    std::vector<std::shared_ptr<Student>> listStudents{};
};