#pragma once

#include "Util.hpp"

#include "Book.hpp"
#include "User.hpp"
#include "Author.hpp"

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

    bool dealPublish(Author*_user, Book* _book);
    bool dealForbid(Author* _user, Book* _book);
    bool dealBorrow(User* _user, Book* _book);
    bool dealReturn(User* _user, Book* _book);
};

} //LibrarySystem