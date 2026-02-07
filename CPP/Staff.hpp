#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Staff:public User{
private:
    LinkedList<Book> borrowed_books_;
public:
    Staff();
    ~Staff() override;

    void borrowBook();
    void returnBook();
    void requestBook();
};

} //LibrarySystem