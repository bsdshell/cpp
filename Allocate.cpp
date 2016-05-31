#include<iostream>

//[file=allocate.html title=""]
int* allocate(int size){
    return new int[size];
}

void deallocate(int*& pt){
    delete[] pt;
    pt = NULL;
}
//]
int main() {
    int size = 10;
    int* pt = allocate(size);
    for(int i=0; i<size; i++){
        pt[i] = i; 
    }

    for(int i=0; i<size; i++){
        printf("[%d]\n", pt[i]); 
    }
    deallocate(pt);
    if(pt == NULL){
        printf("pt is NULL\n");
    }else{
        printf("pt is NOT NULL\n");
    }
}

