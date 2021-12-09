//
// Created by volkancelik on 9.12.2021.
//

#ifndef LINKEDLISTS_NODE_H
#define LINKEDLISTS_NODE_H

#include <cstddef>

template<class T>
class Node{
public:
    Node(const T& e=T(),Node* n=NULL){
        element=e;
        next=n;
    }
    T element;
    Node* next;
};


#endif //LINKEDLISTS_NODE_H
