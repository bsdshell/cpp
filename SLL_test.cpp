#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SLL.h"
#include "Utility.h"

void test0() {
    begin();
    SLL<int>* ddl = new SLL<int>();
    ddl->append(new Node<int>(1));
    int count = ddl->count();
    printf("[%d]", count);
    delete ddl;
}

int main() {
    test0();
}

