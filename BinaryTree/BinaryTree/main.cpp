#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
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

//[file=invert-btree.html title=""
Node* invert(Node* root){
    if(root){
        Node* right = invert(root->left);
        Node* left  = invert(root->right);
        root->left = left ;
        root->right = right;
        return root;
    }
    return NULL;
}

Node* invert_top_down(Node* root){
    if(root){
        Node* left = root->left;
        root->left = root->right;
        root->right = left;
        invert_top_down(root->left);
        invert_top_down(root->right);
        return root;
    }
    return NULL;
}

//]

void prettyPostOrder(Node* p, int indent) {
    if(p != NULL) {
        if(p->right) {
            prettyPostOrder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data<< "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            prettyPostOrder(p->left, indent+4);
        }
    }
}

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BinaryTree* bin = new BinaryTree();
    Node* myroot = bin->root;
    bin->insert(10);
    bin->insert(5);
    bin->insert(15);
    bin->insert(7);

    inorder(bin->root);
    printf("---------------------------------\n");
    Node* r = invert(bin->root);
    inorder(r);
    printf("---------------------------------\n");
}

void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BinaryTree* bin = new BinaryTree();
    bin->insert(10);
    inorder(bin->root);
    printf("---------------------------------\n");
    Node* r = invert(bin->root);
    inorder(r);
    printf("---------------------------------\n");
}

void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BinaryTree* bin = new BinaryTree();
    bin->insert(10);
    bin->insert(5);
    bin->insert(15);
    bin->insert(7);
    inorder(bin->root);
    printf("---------------------------------\n");
    Node* r = invert_top_down(bin->root);
    inorder(r);
    printf("---------------------------------\n");
}

int main(int argc, const char * argv[]) {
    test0();
    test1();
    test2();
    return 0;
}
