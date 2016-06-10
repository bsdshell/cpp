#include<iostream>
#include<vector>

using namespace std;

//[file=kdist.html title=""
//void kdistance(Node* root, int k){
//    if(root){
//        if(k == 0){
//            std::cout<<"["<<root->data<<"]"<<std::endl;
//        }else if(k > 0){
//            kdistance(root->left, k-1);
//            kdistance(root->right, k-1);
//        }
//    }
//}
//]

//[ file=kdistgraph.html title=""
void kdistGraph(int** arr, int k, int h, int w){
    if(k == 0){
        std::cout<<"["<<h<<"]"<<std::endl;
    }else if(k > 0){
        for(int i=0; i<w; i++){
            if(h != i && arr[h][i]){
                if(k - 1 == 0)
                    std::cout<<"["<<i<<"]"<<std::endl;
                else if(k > 0)
                    kdistGraph(arr, k-1, i, w);
            }
        }
    }
    
}
//]

int kdistGraphMax(int** arr, int k, int h, int w, int sum){
    int max = 0;
    if(k == 0){
        std::cout<<"["<<h<<"]"<<std::endl;
    }else if(k > 0){

        for(int i=0; i<w; i++){
            
            if(h != i && arr[h][i]){
                
                if(k - 1 == 0){
                    
                    sum += arr[h][i];
                    max = std::max(kdistGraphMax(arr, k, h, w, sum), sum);
                    std::cout<<"["<<i<<"]"<<std::endl;
                    return max;
                    
                    
                }
                else if(k > 0)
                    return kdistGraphMax(arr, k-1, i, w, sum + arr[h][i]);
            }
        }
    }
    return max;
}

//void test0(){
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//    BST* b = new BST();
//    b->insert(10);
//    b->insert(5);
//    b->insert(15);
//    b->insert(7);
//    int k=0;
//    kdistance(b->root, k); 
//    printf("---------------------------------\n");
//}
//void test1(){
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//    BST* b = new BST();
//    b->insert(10);
//    b->insert(5);
//    b->insert(15);
//    b->insert(7);
//    int k=1;
//    kdistance(b->root, k); 
//    printf("---------------------------------\n");
//}
//
//void test2(){
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//    BST* b = new BST();
//    b->insert(10);
//    b->insert(5);
//    b->insert(15);
//    b->insert(7);
//    int k=2;
//    kdistance(b->root, k); 
//    printf("---------------------------------\n");
//} 
//
//void test3(){
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//    BST* b = new BST();
//    b->insert(10);
//    b->insert(5);
//    b->insert(15);
//    b->insert(7);
//    int k=2;
//    kdistance(b->root, k);
//    delete b;
//    printf("---------------------------------\n");
//} 
//
void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 0;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            arr[i][j] = 0;
        }
    }

    arr[0][1] = 1;
    arr[0][2] = 1;

    arr[1][2] = 1;
    arr[1][3] = 1;

    arr[2][3] = 1;
    arr[2][4] = 1;

    arr[3][4] = 1;

    int h = 0;
    kdistGraph(arr, k, h, width);


    for(int i=0; i<height; i++){
        delete[] arr[i]; 
    }
    delete[] arr;
    

    printf("---------------------------------\n");
} 

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 1;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            arr[i][j] = 0;
        }
    }
    
    arr[0][1] = 1;
    arr[0][2] = 1;
    
    arr[1][2] = 1;
    arr[1][3] = 1;
    
    arr[2][3] = 1;
    arr[2][4] = 1;
    
    arr[3][4] = 1;
    
    int h = 0;
    kdistGraph(arr, k, h, width);
    
    
    for(int i=0; i<height; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    
    printf("---------------------------------\n");
} 

void test5(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 2;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            arr[i][j] = 0;
        }
    }
    
    arr[0][1] = 1;
    arr[0][2] = 1;
    
    arr[1][2] = 1;
    arr[1][3] = 1;
    
    arr[2][3] = 1;
    arr[2][4] = 1;
    
    arr[3][4] = 1;
    
    int h = 0;
    kdistGraph(arr, k, h, width);
    
    
    for(int i=0; i<height; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    
    printf("---------------------------------\n");
} 

void test6(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 1;
    int sum = 0;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            arr[i][j] = 0;
        }
    }
    
    arr[0][1] = 2;
    arr[0][2] = 4;
    
    arr[1][2] = 3;
    arr[1][3] = 5;
    
    arr[2][3] = 7;
    arr[2][4] = 6;
    
    arr[3][4] = 1;
    
    int h = 0;
    int max = kdistGraphMax(arr, k, h, width, sum);
    std::cout<<"max=["<<max<<"]"<<std::endl;
    
    for(int i=0; i<height; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    
    printf("---------------------------------\n");
}

int main(){
//    test0();
//    test1();
//    test2();
    test3();
    test4();
    test5();
    test6();
}

