#pragma once

#include "Util.hpp"

#include <iostream>
#include <string>
#include <stdint.h>

namespace LibrarySystem{

class User;
class Author;

class Book{
private:
    const std::string name_;
    Author* author_;
    
    LinkedList<User> borrowers_;
    int32_t stock_;
    int32_t borrow_count_;
    
    enum class State{
        NEW = 0,
        PUBLISHED = 1,
        BORROWED = 2
    } state_;
    
public:
    Book(const std::string _name, Author* _author, uint32_t _stock);
    ~Book();

    bool bePubished(Author* _author);
    bool beForbidden(Author* _author);
    bool beBorrowed(User* _borrower);
    bool beReturned(User* _borrower);
    void printStatistics();
    std::string getName() const{return name_;}
};

} //LibrarySystem