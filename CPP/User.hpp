#pragma once

#include <string>

namespace LibrarySystem{

class User{
private:
    const std::string name_;
public:
    User();
    virtual ~User() = 0;

    std::string getName() const{return name_;}
};

} //LibrarySystem