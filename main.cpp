#include <fstream>
#include <iostream>
#include "checkPESEL.hpp"
#include "student.hpp"

int main() {
    StudentGroup stg;
    bool isOpenDb = true;
    enum DbFunctions { add = 1,
                       sizeDb,
                       printDb,
                       searchBySurname,
                       searchByPesel,
                       sortByPesel,
                       sortBySurname,
                       deleteByIndex,
                       writeToFile,
                       readFromFile,
                       koniec };
    int makeChoice{};
    while (isOpenDb) {
        std::cout << "\n\tEKSPERYMENTALNA BAZA DANYCH STUDENTÓW\n\n";
        std::cout << "Podaj co chcesz zrobic:\n";
        std::cout << " 1 -> add, 2 -> sizeDb, 3 -> printDb, 4 -> searchBySurname,\n";
        std::cout << " 5 -> searchByPesel, 6 -> sortByPesel, 7 -> sortBySurname, 8 -> deleteByIndex\n";
        std::cout << " 9 -> Zapis do pliku, 10 -> Odczyt z pliku, 11 -> koniec\n";
        std::cin >> makeChoice;
        switch (makeChoice) {
        case add:
            std::cout << "Dodaje studenta: \n";
            stg.addNewStudent();
            break;
        case sizeDb:
            std::cout << "Wielkość bazy studentów: " << stg.getSize() << '\n';
            break;
        case printDb:
            std::cout << "Wydrukuj liste studentow: \n";
            stg.printDB();
            break;
        case searchBySurname:
            std::cout << "Wyszukiwanie po nazwisku:\n";
            stg.searchBySurname();
            break;
        case searchByPesel:
            std::cout << "Wyszukiwanie po PESEL'u:\n";
            stg.searchByPESEL();
            break;
        case sortByPesel:
            std::cout << "Sortowanie po PESEL'u i Wyświetlenie DB:\n";
            stg.sortByPESEL();
            stg.printDB();
            break;
        case sortBySurname:
            std::cout << "Sortowanie po Naziwku i Wyświetlenie DB:\n";
            stg.sortBySurname();
            stg.printDB();
            break;
        case deleteByIndex:
            std::cout << "Usuniecie z DB studenta i wyswieltenie DB:\n";
            stg.deleteByIndex();
            stg.printDB();
            break;
        case writeToFile: {
             std::cout << "Zapis listy do pliku:\n";
            if (stg.returnList().size() != 0) {
                std::ofstream out("students.txt");
                for (auto a : stg.returnList()) {
                     out << (*(a.get())) ;
                }
                out.close();
            } else {
                std::cout << " Lista jest pusta !\n";
             }
           
            break;
        }
        case readFromFile: {
            std::cout << "Odczyt z pliku: \n";
            std::ifstream inputFile("students.txt");
            if (inputFile.good()) {
                stg.fillListOfStudents(inputFile);
                stg.printDB();
                inputFile.close();
            } else {
                std::cout << "Brak pliku do odcytu!\n";
            }
            break;
        }
        case koniec:
            std::cout << "Koniec pracy:\n";
            isOpenDb = false;
            break;
        default:
            std::cout << "Brak poprawnego wyboru, koncze prace.\n";
            isOpenDb = false;
            break;
        }
    }

    return 0;
}

/*
80011503512
65061087807
01270940111

*/
