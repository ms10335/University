#include <gtest/gtest.h>
#include <iostream>
#include "checkPESEL.hpp"
#include "student.hpp"

TEST(CheckPESELTest, subtest1) {
    bool isValidPesel = checkPESEL("85022714812");
    EXPECT_TRUE(isValidPesel);
}

TEST(CheckPESELTest, subtest2) {
    bool isValidPesel = checkPESEL("86022714812");
    EXPECT_FALSE(isValidPesel);
}

TEST(NumberOfStudentsTest, subtest1) {
    StudentGroup students;
    students.addNewStudent();
    EXPECT_EQ(students.getSize(),4);    
}


int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
