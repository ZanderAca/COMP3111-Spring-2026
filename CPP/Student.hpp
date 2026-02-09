#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Student:public User{
private:
    LinkedList<Book> borrowed_books_;
public:
    Student(const std::string _name);
    ~Student() override;

    bool borrowBook(Book* _book);
    bool returnBook(Book* _book);
    void requestBook(Book* _book);
};

} //LibrarySystem