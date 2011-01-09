#include<list>
#include<iostream>
using namespace std;
class Node{
public:
    int value;
    list<Node *> children;
    Node(int val):value(val){}
    ~Node(){
        children.clear();
    }
    void addValue(int val){
        Node* insert=new Node(val);
        children.push_back(insert);
    }
    
    void addNode(Node* newNode){
        children.push_back(newNode);
                
    }
    
    void printForTestingPurposes(){
        for(list<Node *>::iterator it=children.begin();it!=children.end();it++){
            cout<<(*it)->value;
        }
            cout<<value;
   }
};
///////////
int helper=0;//helps print our root element
void print(Node* root){
    
    if(root->children.empty()){
        return;
    }
    for(list<Node *>::reverse_iterator it=root->children.rbegin();it!=root->children.rend();it++){
        helper++;
        print((*it));
        helper--;
        cout<<(*it)->value<<"->";    
    }
    if(helper==0){
        cout<<root->value<<' ';
    }
}
/////////
bool helperTwo=true;
bool helperHeap(Node* root){
    for(list<Node*>::iterator it=root->children.begin(); it!=root->children.end();it++){
        if(root->value<(*it)->value){
            helperTwo=false;
            return false;
        }
      //  helperHeap
        helperHeap(*it);
    }
}

bool isHeap(Node* root){
    helperHeap(root);
    if(helperTwo){
        return true;
    }else{
        return false;
    }
}
int main(){
    Node* root=new Node(20);
    Node* first=new Node(15);//15
    Node* second=new Node(16);//16
    //define inner
    Node* inner=new Node(10);//10
    //and now the third
    Node* third=new Node(4);//4
    //adding values
    first->addValue(4);//4
    first->addValue(13);//13
    second->addValue(2);//2
    inner->addValue(9);//9 
    third->addValue(1);//1
    third->addValue(2);//2
    third->addValue(3);//3
    //adding nodes to the root
    root->addNode(first);
    second->addNode(inner);
    root->addNode(second);
    root->addNode(third);
    print(root);
    cout<<endl;
    if(isHeap(root)){
        cout<<"Yes it is!";
    }
    return 0;
}