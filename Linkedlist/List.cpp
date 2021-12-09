//
// Created by volkancelik on 9.12.2021.
//
#include <iostream>;
#include "Node.h";
#include "List.h";
using namespace std;


template<class T>
Node<T>* List<T>::find(const T &data) {
    Node<T>* p=first();
    while(p){
        if(p->element==data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

template<class T>
Node<T>* List<T>::findPrevious(const T &data) {
    Node<T>* p=zeroth();
    while(p){
        if(p->next->element==data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

template<class T>
void List<T>::remove(const T &data) {
    Node<T>* p=findPrevious(data);
    if(p){
        Node<T>* tmp=p->next;
        p->next=tmp->next;
        delete tmp;
    }
}

template<class T>
void List<T>::insert(const T &data, Node<T> *p) {
    Node<T>* newNode=new Node<T>(data,p->next);
    p->next=newNode;
}

template<class T>
void List<T>::print() const {
    const Node<T>* p=first();
    while(p){
        std::cout<<p->element<<std::endl;
        p=p->next;
    }
}

template<class T>
void List<T>::makeEmpty() {
    while(!isEmpty()){
        Node<T>* p=first();
        remove(p->element);
    }
}

template<class T>
List<T>::~List<T>() {
    makeEmpty();
    delete dummyHead;
}

template<class T>
List<T>& List<T>::operator=(const List<T> &rhs){
    if(this!=rhs)
        makeEmpty();
        const Node<T>* r=rhs.first();
        Node<T>* p=zeroth();
        while(r){
            insert(r->element,p);
            r=r->next;
            p=p->next;
        }
    return *this;
}

template<class T>
List<T>::List(const List<T> &rhs) {
    dummyHead=new Node<T>(T(),NULL);
    *this=rhs;
}


