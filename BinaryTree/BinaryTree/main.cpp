#include <iostream>

//[file=bintree.html title=""
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    public:
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
public:
    Node* root;
public:
    BinaryTree(){root=NULL;}

    void insert(int n){
        Node* curr = root;
        if(root == NULL){
            root = new Node(n);
        }else{
            while(curr){
                if(n < curr->data){
                    if(curr->left == NULL){
                        curr->left = new Node(n);
                        break;
                    }
                    curr = curr->left;
                }else{
                    if(curr->right == NULL){
                        curr->right = new Node(n);
                        break;
                    }
                    curr = curr->right;
                }
            }
        }
    }        
    ~BinaryTree(){
        destroyTree(root); 
    }

    void destroyTree(Node* r){
        if(root){
            destroyTree(r->left);
            destroyTree(r->right);
            if(r){
                delete r;
                r = NULL;
            }
        }
    }
};

void inorder(Node* root){
    if(root){
        inorder(root->left);
        std::cout<<"["<<root->data<<"]"<<std::endl;
        inorder(root->right);
    }
}
//]



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Worlkkkd!\n";
    
    BinaryTree* bin = new BinaryTree();
    Node* root = bin->root;
    bin->insert(10);
    bin->insert(5);
    bin->insert(15);
    bin->insert(7);
    
    inorder(bin->root);
    
    
    return 0;
}
