#pragma once

#include "User.hpp"
#include "Book.hpp"

namespace LibrarySystem{

class Librarian:public User{
private:
public:
    Librarian();
    ~Librarian() override;

    void addBook();
    void removeBook();
    void addUser();
    void removeUser();
    void downloadBook(); //web_crawler
};

} //LibrarySystem