#include <iostream>
#include "Node.h";
#include "List.h";
#include "List.cpp";

void printRev(Node<int>* n){
    if(!n){
        return;
    }
    printRev(n->next);
    printf("%d\n",n->element);
}

int main(){
List<int> list;
list.insert(0,list.zeroth());
Node<int>* p=list.first();
for(int i=1;i<=10;++i){
    list.insert(i,p);
    p=p->next;
}
std::cout<<"printing list"<<std::endl;
list.print();

printRev(list.first());    //Interview question

//List<int> list2=list;
//cout<<"printing copy constructed list"<<endl;
//list2.print();
    return 0;
}
