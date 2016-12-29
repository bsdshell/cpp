#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

template<class Type>class Stack{
    DDLinkedList<Type>* ddl;
    public:
    Stack(){
        ddl = new DDLinkedList<Type>();
    }

    void push(Type item){
        ddl->append(item);
    }
    bool empty(){
        return ddl->count() == 0;
    }
    int count(){
        return ddl->count();
    }
    Type pop(){
        Type item;
        if(ddl->tail){
            item = ddl->tail->data;
            ddl->remove(ddl->tail);
        }
        return item;
    }
};

