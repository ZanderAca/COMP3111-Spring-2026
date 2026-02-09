#include <iostream>
#include <string>
#include "Library.hpp"
#include "Book.hpp"
#include "User.hpp"
#include "Student.hpp"
#include "Staff.hpp"
#include "Author.hpp"
#include "Librarian.hpp"

int main(){
    LibrarySystem::Library library;

    while(true){
        static LibrarySystem::User* cur_user = nullptr;
        if(!cur_user){
            std::string username;

            std::cout<<"==Welcome to the Library!=="<<std::endl;
            std::cout<<"|LOG IN=="<<std::endl;
            std::cout<<"|Username: ";
            std::cin>>username;

            cur_user = library.findUser(username);
            if(!cur_user){
                std::cout<<std::endl;
                std::cout<<"|REGISTER=="<<std::endl;
                std::cout<<"|Username: ";
                std::cin>>username;
                LibrarySystem::User* new_user = new LibrarySystem::Staff(username);
                library.addUser(new_user);
            }
        }

        char command;
        if(LibrarySystem::Student* student_user = dynamic_cast<LibrarySystem::Student*>(cur_user)){
            std::cout<<"|Student Page=="<<std::endl;
            std::cout<<"|1: borrow"<<std::endl;
            std::cout<<"|2: return"<<std::endl;
            std::cout<<"|3: request"<<std::endl;
            std::cout<<"|x: log out=="<<std::endl;
            std::cin>>command;
            if(command=='1'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealBorrow(student_user,target_book);}
            }else if(command=='2'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealReturn(student_user,target_book);}
            }else if(command=='3'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                // student_user->requestBook(&(LibrarySystem::Book(book_title,nullptr,0)));
            }else if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Staff* staff_user = dynamic_cast<LibrarySystem::Staff*>(cur_user)){
            std::cout<<"|Staff Page=="<<std::endl;
            std::cout<<"|1: borrow"<<std::endl;
            std::cout<<"|2: return"<<std::endl;
            std::cout<<"|3: request"<<std::endl;
            std::cout<<"|x: log out=="<<std::endl;
            std::cin>>command;
            if(command=='1'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealBorrow(student_user,target_book);}
            }else if(command=='2'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealReturn(staff_user,target_book);}
            }else if(command=='3'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                // staff_user->requestBook(&(LibrarySystem::Book(book_title,nullptr,0)));
            }else if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Author* author_user = dynamic_cast<LibrarySystem::Author*>(cur_user)){
            std::cout<<"|Author Page=="<<std::endl;
            std::cout<<"|1: publish"<<std::endl;
            std::cout<<"|2: forbid"<<std::endl;
            std::cout<<"|3: view statistics"<<std::endl;
            std::cout<<"|4: summarize"<<std::endl;
            std::cout<<"|x: log out=="<<std::endl;
            std::cin>>command;
            if(command=='1'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealPublish(author_user,target_book);}
            }else if(command=='2'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){library.dealForbid(author_user,target_book);}
            }else if(command=='3'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){author_user->viewBookStatistics(target_book);}
            }else if(command=='4'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                LibrarySystem::Book* target_book = library.findBook(book_title);
                if(target_book){author_user->summarizeBook(target_book);}
            }else if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Librarian* librarian_user = dynamic_cast<LibrarySystem::Librarian*>(cur_user)){
            std::cout<<"|Librarian Page=="<<std::endl;
            std::cout<<"|1: add book"<<std::endl;
            std::cout<<"|2: remove book"<<std::endl;
            std::cout<<"|3: add user"<<std::endl;
            std::cout<<"|4: remove user"<<std::endl;
            std::cout<<"|5: download"<<std::endl;
            std::cout<<"|x: log out=="<<std::endl;
            std::cin>>command;
            if(command=='1'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                // librarian_user->addBook(&(LibrarySystem::Book(book_title,nullptr,0)));
            }else if(command=='2'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                librarian_user->removeBook(book_title);
            }else if(command=='3'){
                std::string user_name;
                std::cout<<"|user name: "<<std::endl;
                std::cin>>user_name;
                // librarian_user->addUser(&(LibrarySystem::Student(user_name)));
            }else if(command=='4'){
                std::string user_name;
                std::cout<<"|user name: "<<std::endl;
                std::cin>>user_name;
                librarian_user->removeUser(user_name);
            }else if(command=='5'){
                std::string book_title;
                std::cout<<"|book title: "<<std::endl;
                std::cin>>book_title;
                librarian_user->downloadBook(book_title);
            }else if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else{
            std::cout<<"==Sorry, the user does not exist.=="<<std::endl;
        }
    }
    return 0;
}