#pragma once

#include "Util.hpp"

#include "User.hpp"

namespace LibrarySystem{

class Book;

class Author:public User{
private:
    LinkedList<Book> published_books_;
public:
    Author();
    ~Author() override;

    void publishBook();
    void forbiddenBook();
    void viewBookStatistics();
    void summarizeBook(); //LLM
};

} //LibrarySystem