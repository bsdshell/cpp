#ifndef NODE 
#define NODE 


template <class Type> class Node{
    public:
        Node* next;
        Node* left;
        Node* right;
        Node* prev;
        Type data;
    public:
    Node(Type n){
        data = n;
        left = NULL;
        right = NULL;
        next = NULL;
        prev = NULL;
    }
};

#endif
