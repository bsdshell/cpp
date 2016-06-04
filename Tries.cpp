#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Node{
    bool terminal;
    public:
    std::map<char, vector<Node>> map; 
    public:
    Node(bool t){
        terminal = t;
    }
};

class Tries{
    public:
        shared_ptr<Node> root;
    public:
        Tries(){
            shared_ptr<Node> pt(new Node(false));
            pt.terminal = true;
            root = pt; 
        }
        void insert(std::string str, int i){
            if(i < str.size()){
                vector<Node> v = map[str[i]];
                if(v == nullptr){
                    Node* node;
                    if(i == str.size() -1)
                        node = new Node(true);
                    else
                        node = new Node(false);
                    map[str[i]] = node; 
                }
                insert(str, i+1);
            }
        }
}

int main(){
    printf("bug\n"); 
    vector<int> v;
    v.push_back(1);
    printVector(v);
}

