#include<iostream>
#include<vector>
#include<map>

using namespace std;

//[file=cpptries.html title=""
class Node{
public:
    bool terminal;
    std::map<char, Node*> map;
public:
    Node(bool t){
        terminal = t;
    }
};

class Tries{
public:
    Node* root;
public:
    Tries(){
        root = new Node(true);
    }
};

void insert(Node* root, std::string str, int i){
    if(i < str.size()){
        if(i == str.size() - 1){
            if(root->map[str[i]] != NULL)
                root->map[str[i]]->terminal = true;
            else
                root->map[str[i]] = new Node(true);
        }else{
            if(root->map[str[i]] == NULL)
                root->map[str[i]] = new Node(false);
            
            insert(root->map[str[i]], str, i+1);
        }
    }
}

bool contain(Node* root, std::string str, int i){
    if(root){
        if(str.size() == 0)
            return root->terminal;
        
        if(i == str.size() - 1){
            if(root->map[str[i]] != NULL)
                return root->map[str[i]]->terminal;
            else
                return false;
        }else{
            return contain(root->map[str[i]], str, i+1);
        }
    }else{
       return false;
    }
}
//]

void test0(){
    Tries* t = new Tries();
    int index = 0;
    Node* root = t->root;
    insert(root, "t", 0);
    
    root = t->root;
    insert(root, "t", 0);
    root = t->root;
    insert(root, "technology", 0);
    insert(root, "technologies", 0);
    insert(root, "technical", 0);
    insert(root, "techie", 0);
    insert(root, "tear", 0);
    insert(root, "ten", 0);
    insert(root, "tencent", 0);
    
    std::cout<<contain(t->root, "te", 0)<<std::endl;
    std::cout<<contain(t->root, "tech", 0)<<std::endl;
    std::cout<<contain(t->root, "", 0)<<std::endl;
    std::cout<<contain(t->root, "techie", 0)<<std::endl;
    std::cout<<contain(t->root, "techi", 0)<<std::endl;
    std::cout<<contain(t->root, "t", 0)<<std::endl;
    std::cout<<contain(t->root, "ten", 0)<<std::endl;
    std::cout<<contain(t->root, "tencen", 0)<<std::endl;
}

int main(){
    test0();
}
