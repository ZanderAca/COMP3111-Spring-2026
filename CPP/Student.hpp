#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Student:public User{
private:
    LinkedList<Book> borrowed_books_;
public:
    Student();
    ~Student() override;

    void borrowBook();
    void returnBook();
    void requestBook();
};

} //LibrarySystem