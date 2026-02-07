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

} //LibrarySystem