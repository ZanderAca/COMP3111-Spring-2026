#include "Student.hpp"
#include "Book.hpp"

namespace LibrarySystem{

Student::Student(const std::string _name): User(_name){}
Student::~Student(){}

bool Student::borrowBook(Book* _book){
    if(borrowed_books_.find(_book->getName())){std::cout<<"Such book has already exist"<<std::endl; return false;}
    borrowed_books_.insert(_book);
    return true;
}
bool Student::returnBook(Book* _book){
    if(!borrowed_books_.find(_book->getName())){std::cout<<"Not such book exist"<<std::endl; return false;}
    borrowed_books_.remove(_book->getName());
    return false;
}
void Student::requestBook(Book* _book){}

} //LibrarySystem