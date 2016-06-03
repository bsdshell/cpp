#include<iostream>
#include<vector>

using namespace std;

//[file=overlap.html title=""
int getMaxCount(vector<int> arr, vector<int> dep){
    const int len = arr.size(); 
    int i=0, j=0;
    int count = 0;
    int max = 0;
    vector<int> marr;

    while(i < len || j < len){
        if(i >= len){
            marr.push_back(dep[j]);
            count--;
            j++;
        }
        else if(j >= len){
            marr.push_back(arr[i]);
            count++;
            i++;
        }
        else {
            if(arr[i] <= dep[j]){
                marr.push_back(arr[i]);
                count++;
                i++;
            }else{
                marr.push_back(dep[j]);
                count--;
                j++;
            }
        }

        if(count > max)
            max = count;
    }
    return max;
}
//]

int main(){
    const int len = 5;
    vector<int> arr = {1, 2, 5, 5, 9};
    vector<int> dep = {4, 5, 9, 12, 12};
    int max = getCount(arr, dep);
    std::cout<<"max=["<<max<<"]"<<'\n';
}



