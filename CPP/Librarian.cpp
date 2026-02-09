#include "Librarian.hpp"
#include "Library.hpp"

namespace LibrarySystem{

Librarian::Librarian(const std::string _name, Library* _library): User(_name), library_(_library){}
Librarian::~Librarian(){}

void Librarian::addBook(Book* _book){library_->addBook(_book);}
void Librarian::removeBook(std::string _name){library_->removeBook(_name);}
void Librarian::addUser(User* _user){library_->addUser(_user);}
void Librarian::removeUser(std::string _name){library_->removeUser(_name);}
void Librarian::downloadBook(std::string _name){} //web_crawler

} //LibrarySystem