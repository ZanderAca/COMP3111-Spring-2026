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
            std::cout<<std::endl;

            cur_user = library.findUser(username);
        }

        char command;
        if(LibrarySystem::Student* student_user = dynamic_cast<LibrarySystem::Student*>(cur_user)){
            std::cout<<"|Student Page=="<<std::endl;
            std::cin>>command;
            if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Staff* staff_user = dynamic_cast<LibrarySystem::Staff*>(cur_user)){
            std::cout<<"|Staff Page=="<<std::endl;
            std::cin>>command;
            if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Author* author_user = dynamic_cast<LibrarySystem::Author*>(cur_user)){
            std::cout<<"|Author Page=="<<std::endl;
            std::cin>>command;
            if(command=='x'){
                cur_user = nullptr;
            }else{
                std::cout<<"==Invalid input. Try again=="<<std::endl;
            }
        }else if(LibrarySystem::Librarian* librarian_user = dynamic_cast<LibrarySystem::Librarian*>(cur_user)){
            std::cout<<"|Librarian Page=="<<std::endl;
            std::cin>>command;
            if(command=='x'){
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