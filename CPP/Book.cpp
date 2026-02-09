#include "Book.hpp"
#include "User.hpp"
#include "Author.hpp"

namespace LibrarySystem{

Book::Book(const std::string _name, Author* _author, uint32_t _stock)
    :name_(_name), author_(_author), stock_(_stock), borrow_count_(0), state_(State::NEW){}
Book::~Book(){}

bool Book::bePubished(Author* _author){
    if(!dynamic_cast<Author*>(_author)){std::cout<<"==Not an author=="<<std::endl; return false;}
    if(author_){std::cout<<"==Already published=="<<std::endl; return false;}
    author_ = _author;
    state_ = State::PUBLISHED;
    return true;
}
bool Book::beForbidden(Author* _author){
    if(!dynamic_cast<Author*>(_author)){std::cout<<"==Not an author=="<<std::endl; return false;}
    if(!author_){std::cout<<"==Not published=="<<std::endl; return false;}
    if(author_->getName()!=_author->getName()){std::cout<<"==Not published by this author=="<<std::endl; return false;}
    author_ = nullptr;
    state_ = State::NEW;
    return true;

}
bool Book::beBorrowed(User* _borrower){
    if(borrowers_.find(_borrower->getName())){std::cout<<"==Such borrower has already existed.=="<<std::endl; return false;}
    if(stock_<=0){std::cout<<"==No stocks.=="<<std::endl; return false;}
    borrowers_.insert(_borrower);
    stock_--;
    borrow_count_++;
    state_ = State::BORROWED;
    return true;
}
bool Book::beReturned(User* _borrower){
    if(!borrowers_.find(_borrower->getName())){std::cout<<"==Not such borrower exist.=="<<std::endl; return false;}
    borrowers_.remove(_borrower->getName());
    stock_++;
    state_ = State::PUBLISHED;
    return true;
}

void Book::printStatistics(){
    std::cout<<"|Book: "<<name_<<std::endl;
    std::cout<<"|author: "<<author_->getName()<<std::endl;
    std::cout<<"|stock: "<<stock_<<std::endl;
    std::cout<<"|borrow count: "<<borrow_count_<<std::endl;
    if(state_==State::BORROWED){std::cout<<"|borrowed|"<<std::endl;}
}

} //LibrarySystem