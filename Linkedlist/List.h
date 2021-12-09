//
// Created by volkancelik on 9.12.2021.
//

#ifndef LINKEDLISTS_LIST_H
#define LINKEDLISTS_LIST_H
#include "Node.h";

template<class T>
class List{
private:
    Node<T>* dummyHead;
public:
    List(){
        dummyHead=new Node<T>(T(),NULL);
    }

    ~List();
    Node<T>* zeroth(){
        return dummyHead;
    }
    Node<T>* first(){
        return dummyHead->next;
    }
    const Node<T>* first() const{
        return dummyHead->next;
    }
    bool isEmpty() const {
        return first()==NULL;
    }

    void insert(const T& data,Node<T>* p);
    Node<T>* find(const T& data);
    void remove(const T& data);
    Node<T>* findPrevious(const T& data);
    void print() const;
    void makeEmpty();
    List& operator=(const List& rhs);
    List(const List& rhs);
};
#endif //LINKEDLISTS_LIST_H
