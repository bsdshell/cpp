#include <pthread.h>
#include <stdio.h>
#include <list>
#include "AronLib.h" 

using namespace Utility;
using namespace std;
using namespace SpaceSort;

const int N = 100; // number of threads
pthread_t threads[N];
pthread_mutex_t myLock;
int total = 0;

void sort(){
    list<int> l;
    const int NUM=100000;
    int arr[NUM];

    for(int i=0; i<NUM; i++){
        int id = arc4random_uniform(NUM);
        //pp(id);
        l.push_back(id);
        arr[i] = id;
    } 
    int lo = 0;
    int hi = NUM-1;
    quickSort(arr, lo, hi);
    for(int i=0; i<NUM; i++){
        pp(arr[i]);
    } 
}

int computeNthDigitOfPi(int n){
    printf("n=%d\n", n);
    sort();
    return 0;
}

void * expensiveComputation (void *x) {
    int v = *((int *) x);
    delete ((int *) x);
    pthread_mutex_lock (&myLock);
    int res = computeNthDigitOfPi (v);
    total += res;
    pthread_mutex_unlock (&myLock);
    return NULL;
}
void test0(){
    sort();
}

int main() {
    pthread_mutex_init (&myLock, NULL);
    for (int i=0; i<N; i++) {
        int * ptr_i = new int (i);
        pthread_create (&threads[i], NULL, expensiveComputation, (void *)ptr_i);
    }
    for (int i=0; i<N; i++) {
        pthread_join (threads[i], NULL);
    }
    printf("total: %d\n", total);

    test0();
}
