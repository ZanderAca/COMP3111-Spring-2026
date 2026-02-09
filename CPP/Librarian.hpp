#pragma once

#include "User.hpp"
#include "Book.hpp"

namespace LibrarySystem{

class Library;

class Librarian:public User{
private:
    Library* library_;
public:
    Librarian(const std::string _name, Library* _library);
    ~Librarian() override;

    void addBook(Book* _book);
    void removeBook(std::string _name);
    void addUser(User* _user);
    void removeUser(std::string _name);
    void downloadBook(std::string _name); //web_crawler
};

} //LibrarySystem