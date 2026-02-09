#include "Library.hpp"

namespace LibrarySystem{

Library::Library(){}
Library::~Library(){}

Book* Library::findBook(std::string _name){return books_.find(_name);}
User* Library::findUser(std::string _name){return users_.find(_name);}
void Library::addBook(Book* _book){books_.insert(_book);}
void Library::addUser(User* _user){users_.insert(_user);}
Book* Library::removeBook(std::string _name){return books_.remove(_name);}
User* Library::removeUser(std::string _name){return users_.remove(_name);}

bool Library::dealPublish(Author* _user, Book* _book){return _user->publishBook(_book)&&_book->bePubished(_user);}
bool Library::dealForbid(Author* _user, Book* _book){return _user->forbidBook(_book)&&_book->beForbidden(_user);}
bool Library::dealBorrow(User* _user, Book* _book){}//return _user->borrowBook(_book)&&_book->beBorrowed(_user);}
bool Library::dealReturn(User* _user, Book* _book){}//return _user->returnBook(_book)&&_book->beReturned(_user);}

} //LibrarySystem