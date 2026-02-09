#include "Staff.hpp"
#include "Book.hpp"

namespace LibrarySystem{

Staff::Staff(const std::string _name): User(_name){}
Staff::~Staff(){}

bool Staff::borrowBook(Book* _book){
    if(borrowed_books_.find(_book->getName())){std::cout<<"Such book has already exist"<<std::endl; return false;}
    borrowed_books_.insert(_book);
    return true;
}
bool Staff::returnBook(Book* _book){
    if(!borrowed_books_.find(_book->getName())){std::cout<<"Not such book exist"<<std::endl; return false;}
    borrowed_books_.remove(_book->getName());
    return false;
}
void Staff::requestBook(Book* _book){}

} //LibrarySystem