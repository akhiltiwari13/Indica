/**
 * File              : ComptProg.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 07.06.2021
 */

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
 /* graphs can usually be represented as adjacency-list or as an adjacency-matrix. */ 

/* Goldmann sachs to solve a templated linked list. */
template <typename T>
struct node{
    T _data;
    shared_ptr<node<T>> _next;

    node(T data):_data(data), _next(nullptr){
    }

    node():_data("default_data"), _next(nullptr){
    }
};

template <typename T>
void insert_node (shared_ptr<node<T>>& head, T data){
    std::shared_ptr<node<T>> ptr{new node<T>};
    ptr->_data = data;
    ptr->_next = head;
    head= ptr;
}

template <typename T>
void print_list( shared_ptr<node<T>> head ){
    auto temp = head;
    std::cout<<"**print_list**"<<std::endl;
    while(temp){
        std::cout<<temp->_data<<std::endl;
        temp=temp->_next;
    }
}

/* Testing of features useful for competitive programming. */
int main() {
     std::cout<<"hash(\"akhil\"):="<<hash<std::string>()(std::string("akhil"))<<std::endl;

     shared_ptr<node<string>> head(new node<string> );
     head->_data="first_head";
     head->_next=nullptr;

     std::string data2{"data2"};

     insert_node(head,data2);
     insert_node(head,std::string("random_data0"));
     insert_node(head,std::string("random_data1"));
     insert_node(head,std::string("random_data2"));
     print_list(head);
     
     
    return 0;
}

