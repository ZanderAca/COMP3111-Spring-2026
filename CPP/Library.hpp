#pragma once

#include "Util.hpp"

#include "Book.hpp"
#include "User.hpp"

namespace LibrarySystem{

class Library{
private:
    LinkedList<Book> books_;
    LinkedList<User> users_;
public:
    Library();
    ~Library();

    Book* findBook(std::string _name);
    User* findUser(std::string _name);
    void addBook(Book* _book);
    void addUser(User* _user);
    Book* removeBook(std::string _name);
    User* removeUser(std::string _name);
};

} //LibrarySystem