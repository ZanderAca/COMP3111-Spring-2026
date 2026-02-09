#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Staff:public User{
private:
    LinkedList<Book> borrowed_books_;
public:
    Staff(const std::string _name);
    ~Staff() override;

    bool borrowBook(Book* _book);
    bool returnBook(Book* _book);
    void requestBook(Book* _book);
};

} //LibrarySystem