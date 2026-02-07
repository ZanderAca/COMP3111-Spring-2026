#pragma once

#include <string>
#include <stdint.h>

namespace LibrarySystem{

class User;
class Author;

class Book{
private:
    const std::string name_;
    Author* author_;
    
    User* borrower_;
    uint32_t stock_;
    uint32_t borrow_count_;
    
    enum class State{
        NEW = 0,
        PUBLISHED = 1,
        BORROWED = 2
    } state_;
    
public:
    Book();
    ~Book();

    std::string getName() const{return name_;}
};

} //LibrarySystem