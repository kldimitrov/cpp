#include<iostream>
using namespace std;
class DLinkedList{
private:
	struct Node{
		int val;
		Node* prev, *next;
		Node(int val_, Node* next=NULL, Node* prev=NULL):val(val_),next(next), prev(prev){}
};
	Node* start, *rear;
public:
	DLinkedList(){
		start=rear=NULL;
	}
	~DLinkedList(){
		while(start!=NULL){
			int dummy;
			removeFromBegin(dummy);
		}
	}

	void setValues(int* array,int arraySize){
		if(!empty()){
			while(start!=NULL){
				int dummy;
				removeFromBegin(dummy);
			}
		}
		for(int i=0; i<arraySize; i++){
			addToEnd(array[i]);
		}
	}
	
	void addToBegin(int val){
		Node* newNode=new Node(val);
		if(!start)
			start=rear=newNode;
		else{
			newNode->next=start;
			start->prev=newNode;
			start=newNode;
		}
	}
	bool removeFromBegin(int& val){
			Node* newNode;
			if(!start){
				return false;
			}
			else{
				if(start==rear){
					val=start->val;
					delete start;
					start=rear=NULL;
					return true;
				}
				val=start->val;
				start->next->prev=NULL;
				newNode=start;
				start=start->next;
				delete newNode;			
			}
		return true;
		}
	
	bool removeFromEnd(int& val){
		Node* newNode;
		if(!start){
			return false;
		}else{
			if(start==rear){
				return removeFromBegin(val);
			}
			val=rear->val;
			rear->prev->next=NULL;
			newNode=rear;
			rear=rear->prev;
			delete newNode;
		}
		

	}
 
		void print(){
			Node* temp=start;
			while(temp!=NULL){
				cout<<temp->val;
				temp=temp->next;
			}
		}

		void addToEnd(int val){
			Node* newNode=new Node(val);
			if(!start){
				start=rear=newNode;
			}else{
				newNode->prev=rear;
				rear->next=newNode;
				rear=newNode;
			}	
		}

		class Iterator{
		private:
			Node* node;
		public:
			Iterator(Node* node):node(node)
			{}
			int operator*(){
				return node->val;
			}
			Node* getNode(){
				return node;
			}
			Iterator& operator++(){
                            if(isValid()){
				node=node->next;
				return *this;
                            }
			}
			Iterator& operator--(){
                            if(isValid()){
				node=node->prev;
				return *this;
                            }
			}
			Iterator& operator=(Iterator& other){
				node=other.node;
				return *this;
			}
			bool operator!=(Iterator& other)const{
				return node!=other.node;
			}
                        bool isValid(){
                            return node!=0;
                        }
		
		};

		bool empty(){
			return start==NULL;
		}

		Iterator begin()const{
			if(start!=0){
			Iterator iter(start);
			return iter;
			}
		}

		Iterator end()const{
			Iterator iter(rear);
			return iter;
		}
		
		
		void addElement(DLinkedList::Iterator currentIterator, int value){
                    if(currentIterator.isValid()){
                        Node* newNode=new Node(value);
			Node* temp=currentIterator.getNode();
                        if(temp->next&&temp->prev){
                            temp->prev->next=newNode;
                            newNode->prev=temp->prev;
                            newNode->next=temp;
                            temp->prev=newNode;
                            return;
                        }else{
                            if(!temp->next){
                                addToEnd(value);
                                return;
                            }
                            else{
                                addToBegin(value);
                                return;
                            }
                        }
                           
                    }else
                         cerr<<"Not a valid operation";
		}	
		
		void removeElement(DLinkedList::Iterator currentIterator,int& value){
			value= *currentIterator;
			Node* node= currentIterator.getNode();
                        if(node->next&&node->prev){
                            node->prev->next=node->next;
                            node->next->prev=node->prev;       
                            delete node;
                            return;
                        }else{
                            if(!node->next){         
                                removeFromEnd(value);
                                return;
                            }else{
                                removeFromBegin(value);
                                return;
                            }
                        }		
		}

};

int main()
{	DLinkedList dll;
	dll.addToBegin(1);
	dll.addToBegin(2);
	dll.addToBegin(3);
	int dum=0;
	dll.print();
	cout<<endl;
	DLinkedList::Iterator it=dll.begin();
	dll.addElement(it,dum);
	dll.print();
	++it;
	dll.print();
	int arr[4]={5,6,7,8};
	dll.setValues(arr,sizeof(arr)/sizeof(int));
	int dummy=0;
	dll.print();
	cout<<endl;
	dll.removeFromBegin(dummy);
	cout<<dummy;
	dummy=0;
	dll.removeFromBegin(dummy);
	cout<<dummy;
	return 0;
}

