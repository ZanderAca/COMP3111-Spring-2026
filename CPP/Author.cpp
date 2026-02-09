#include "Author.hpp"
#include "Book.hpp"

namespace LibrarySystem{

Author::Author(const std::string _name): User(_name){}
Author::~Author(){}

bool Author::publishBook(Book* _book){
    if(published_books_.find(_book->getName())){std::cout<<"==Already published=="<<std::endl; return false;}
    published_books_.insert(_book);
    return true;
}
bool Author::forbidBook(Book* _book){
    if(!published_books_.find(_book->getName())){std::cout<<"==Not such book exist=="<<std::endl; return false;}
    published_books_.remove(_book->getName());
    return true;
}
void Author::viewBookStatistics(Book* _book){
    if(!published_books_.find(_book->getName())){std::cout<<"==Not such book exist=="<<std::endl; return;}
    _book->printStatistics();
}
void Author::summarizeBook(Book* _book){} //LLM

} //LibrarySystem