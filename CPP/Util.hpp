#pragma once

#include <string>

// class T{
// private:
//     std::string name_;
// public:
//     std::string getName() const{return name_;}
// };

template<typename T>
class LinkedList{
private:
    struct Node{
        T* data_;
        Node* next_;

        Node(T* _data):data_(_data),next_(nullptr){}
        Node(const Node& _other):data_(_other.data_),next_(nullptr){}
        ~Node(){}
    };

    Node* head_;
public:
    LinkedList();
    LinkedList(const LinkedList& _other);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& _other);
    T* operator[](int _index) const;

    T* find(std::string _name) const;
    void insert(T* _data);
    T* remove(std::string _name);

    void sort();
};

#include "Util.tpp"