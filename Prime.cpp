#include<iostream>
#include<vector>
using namespace std;

//[file=primecpp.html title=""
void primeNum(int n) {
    bool* prime = new bool[n];
    for(int i=0; i<n; i++)
        prime[i] = true;

    for(int i=3; i<n; i++) {
        for(int j=2; j<i && prime[i]; j++) {
            if(prime[j] && (i % j) == 0)
                prime[i] = false;
        }
    }
    
    for(int i=2; i<n; i++) {
        std::cout<<"["<<i<<"]="<<prime[i]<<endl;
    }
    delete[] prime;
}

vector<int> primeList(int n){
    vector<int> vec;
    if(n > 1)
        vec.push_back(2);

    for(int j=3; j<=n; j++){
        bool isPrime = true;
        for(int i=0; i < vec.size() && isPrime; i++){
            if(j % vec[i] == 0)
                isPrime = false;
        }
        if(isPrime)
            vec.push_back(j);
    }
    return vec;
}

vector<int> geneNPrime(int n){
    vector<int> vec;
    if(n > 0)
        vec.push_back(2);

    int count = 1;
    int num = 3;
    while(count < n){
        bool isPrime = true;
        for(int i=0; i<vec.size() && isPrime; i++){
            if(num % vec[i] == 0)
                isPrime = false;
        }
        if(isPrime){
            vec.push_back(num);
            count++;
        }
        num++;
    }
    return vec;
}
//]

void test0(){
    vector<int> vec(3);
    vec.push_back(4);
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    }

    printf("---------------------------------\n");
    vector<int> vec1;
    vec1.push_back(4);
    for(int i=0; i<vec1.size(); i++){
        std::cout<<"["<<vec1[i]<<"]"<<std::endl;
    }

}


void test1(){
    printf("---------------------------------\n");
    vector<int> vec = geneNPrime(0); 
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    }
}
void test2(){
    printf("---------------------------------\n");
    vector<int> vec = geneNPrime(1); 
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    }
}
void test3(){
    printf("---------------------------------\n");
    vector<int> vec = geneNPrime(2); 
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    }
}

void test4(){
    printf("---------------------------------\n");
    primeNum(10);
}




int main() {
    
    test0();
    test1();
    test2();
    test3();
    test4();

    clock_t startTime = clock();

    vector<int> vec = primeList(10);
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    }
    clock_t endTime = clock();

    

    clock_t diff = endTime - startTime;
    std::cout<<"diff="<<(float)diff/CLOCKS_PER_SEC<<endl;


}
