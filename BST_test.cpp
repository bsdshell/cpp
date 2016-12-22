#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Utility.h"
#include "BST.h"

void test0() {
    begin();
    BST<int>* bst = new BST<int>();
    delete bst;
}

int main() {
    test0();
}

