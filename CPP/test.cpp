#include <iostream>
#include <string>
#include "Library.hpp"
#include "Book.hpp"
#include "User.hpp"
#include "Student.hpp"
#include "Staff.hpp"
#include "Author.hpp"
#include "Librarian.hpp"
namespace LibrarySystem{

class TestObj {
public:
    std::string name;
    TestObj(const std::string& n) : name(n) {
        std::cout << "Created TestObj " << name << std::endl;
    }
    ~TestObj() {
        std::cout << "Destroyed TestObj " << name << std::endl;
    }
    std::string getName() const { return name; }
};

void printList(const LinkedList<TestObj>& list) {
    std::cout << "List contents: ";
    for (int i = 0; list[i] != nullptr; ++i) {
        std::cout << list[i]->getName() << " ";
    }
    std::cout << std::endl;
}

void test(){
{
    LibrarySystem::Library lib;
    Author* auth = new Author("Shakespeare");
    Book* book = new Book("Hamlet", auth, 10);
    lib.addBook(book);
    lib.addUser(auth);
    std::cout << lib.findBook("Hamlet")->getName();
    std::cout << lib.findBook("Shakespeare")->getName();
    std::cout << lib.findUser("Shakespeare")->getName();
    lib.removeBook(book->getName());
    lib.removeBook(autoh->getName());
}  // If ~Library doesn't delete books/users → leak
}
}
int main(){
    LibrarySystem::test();

    return 0;
}