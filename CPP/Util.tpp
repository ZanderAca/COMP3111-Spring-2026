#include "Util.hpp"

template<typename T>
LinkedList<T>::LinkedList():head_(nullptr){}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& _other):head_(nullptr){
    for(Node* cur_node = _other.head_;cur_node!=nullptr;cur_node = cur_node->next_){
        this->insert(cur_node->data_);
    }
}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node* last_node = nullptr;
    for(Node* cur_node = head_;cur_node!=nullptr;){
        last_node = cur_node;
        cur_node = cur_node->next_;
        delete last_node;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& _other){
    Node* last_node = nullptr;
    for(Node* cur_node = head_;cur_node!=nullptr;){
        last_node = cur_node;
        cur_node = cur_node->next_;
        delete last_node;
    }

    for(Node* cur_node = _other.head_;cur_node!=nullptr;cur_node = cur_node->next_){
        this->insert(cur_node->data_);
    }
}

template<typename T>
T* LinkedList<T>::operator[](int _index) const{
    Node* cur_node = head_;
    if(!cur_node){return nullptr;}
    for(int i = _index;i > 0;i--){
        cur_node = cur_node->next_;
        if(!cur_node){return nullptr;}
    }
    return cur_node->data_;
}

template<typename T>
T* LinkedList<T>::find(std::string _name) const{
    for(Node* cur_node = head_;cur_node != nullptr;cur_node = cur_node->next_){
        if(_name==cur_node->data_->getName()){return cur_node->data_;}
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::insert(T* _data){
    if(!head_){head_ = new Node(_data);return;}

    Node* last_node = nullptr;
    for(Node* cur_node = head_;cur_node != nullptr;last_node = cur_node, cur_node = cur_node->next_){
        if(_data->getName()==cur_node->data_->getName()){return;}
    }
    last_node->next_ = new Node(_data);
    return;
}

template<typename T>
T* LinkedList<T>::remove(std::string _name){
    if(!head_){return nullptr;}

    Node* target_node = nullptr;
    Node* last_node = nullptr;
    for(Node* cur_node = head_;cur_node != nullptr;last_node = cur_node, cur_node = cur_node->next_){
        if(_name==cur_node->data_->getName()){target_node = cur_node;break;}
    }
    if(!target_node){return nullptr;}

    T* target_data = target_node->data_;
    last_node->next_ = target_node->next_;
    target_node->next_ = nullptr;
    delete target_node;
    return target_data;
}