#pragma once

#include <iostream>
#include <string>

namespace LibrarySystem{

class User{
private:
    const std::string name_;
public:
    User(const std::string _name);
    virtual ~User() = 0;

    std::string getName() const{return name_;}
};

} //LibrarySystem