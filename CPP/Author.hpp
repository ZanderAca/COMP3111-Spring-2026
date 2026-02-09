#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Author:public User{
private:
    LinkedList<Book> published_books_;
public:
    Author(const std::string _name);
    ~Author() override;

    bool publishBook(Book* _book);
    bool forbidBook(Book* _book);
    void viewBookStatistics(Book* _book);
    void summarizeBook(Book* _book); //LLM
};

} //LibrarySystem