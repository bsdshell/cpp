#include<iostream>
#include<vector>
#include<map>


using namespace std;

//[file=cppdatastructure.html title=""
class Node{
public:
    int data;
public:
    Node(int n){data = n;}
};

int main(){
    // cpp vector
    vector<Node> v;
    Node n(1);
    v.push_back(n);
    
    vector<Node*> vpt;
    vpt.push_back(new Node(4));
    
//    for(int i=0; i<vpt.size(); i++){
//        std::cout<<"["<<vpt[i]->data<<"]"<<std::endl;
//    }
//    
//    for(int i=0; i<v.size(); i++){
//        std::cout<<"["<<v[i].data<<"]"<<std::endl;
//    }
    
    // cpp map g++ map
    std::map<int, Node*> map;
    map[0] = new Node(10);
    map[4] = new Node(14);
    map[3] = new Node(13);
    map.insert(make_pair(7, new Node(17)));
    std::map<int, Node*>::iterator it = map.begin();
    while(it != map.end()){
        std::cout<<"["<<it->first<<"]"<<std::endl;
        it++;
    }
    
}
//]