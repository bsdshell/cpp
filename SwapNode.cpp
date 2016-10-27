#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

//[ file=swapnode.html title=""
void swapNode(Node* root, int n, int m, Node*& npt,  Node*& mpt) {
    if(root) {
        swapNode(root->left, n, m, npt, mpt);
        if(npt == NULL && mpt == NULL && (root->data == n || root->data == m)){
            npt = root;
        }else if(npt && (root->data == n || root->data == m)){
            mpt = root;
        }else if(npt && mpt){
            int d = npt->data;
            npt->data = mpt->data;
            mpt->data = d;
        }
        
        swapNode(root->right, n, m, npt, mpt);
    }
}
//]

//[ file=fixswapnode.html title=""
// prev = NULL, pt = NULL
void fixSwapNode(Node* curr, Node* prev, Node* pt1, Node* pt2, Node* pt){
    if(pt == NULL)
        pt = curr;
    if(curr){
        fixSwapNode(curr->left, prev, pt1, pt2, pt);
        if(prev){
            if(pt1 == NULL && pt2 == NULL && prev->data > curr->data){
                pt1 = prev;
                pt2 = curr;
            }else if(pt1 != NULL && pt2 != NULL && prev->data > curr->data){
                pt2 = curr;
            }
        }
        fixSwapNode(curr->right, curr, pt1, pt2, pt);
    }
    if(pt == curr){
        int tmp = pt1->data;
        pt1->data = pt2->data;
        pt2->data = tmp;
    }
}
//]

void test0() {
    unsigned int sz = strlen(PAD);
    begin(__PRETTY_FUNCTION__);
    BST* bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(7);
    inorder(bst->root);

    end();
    Node* npt = NULL;
    Node* mpt = NULL;
    swapNode(bst->root, 10, 5, npt, mpt);
    inorder(bst->root);
    end();
}

void test1() {
    unsigned int sz = strlen(PAD);
    begin(__PRETTY_FUNCTION__);
    BST* bst = new BST();
    bst->insert(10);
    bst->insert(5);
    inorder(bst->root);

    end();
    Node* npt = NULL;
    Node* mpt = NULL;
    swapNode(bst->root, 5, 10, npt, mpt);
    inorder(bst->root);
    end();
}


void test2() {
    unsigned int sz = strlen(PAD);
    begin(__PRETTY_FUNCTION__);
    BST* bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(6);
    bst->insert(20);
    inorder(bst->root);

    end();
    Node* npt = NULL;
    Node* mpt = NULL;
    swapNode(bst->root, 5, 20, npt, mpt);
    inorder(bst->root);
    end();
}

void test3() {
    unsigned int sz = strlen(PAD);
    begin(__PRETTY_FUNCTION__);
    BST* bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(20);
    bst->insert(14);
    inorder(bst->root);

    end();
    Node* npt = NULL;
    Node* mpt = NULL;
    swapNode(bst->root, 10, 15, npt, mpt);
    inorder(bst->root);
    end();
}


int main() {
    test0();
    test1();
    test2();
    test3();
}

