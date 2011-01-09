// 
// File:   list.cc
// Author: ritter
//
// Created on November 22, 2010, 10:53 PM
//

#include <stdlib.h>
#include<iostream>
using namespace std;
template <class T>
struct node{
	T data;;)
 
	node<T> *next;
};

template <class T>
class List{
public:
	List(){
		head=NULL;
		end=NULL;
                lengh=0;
	}
        ~List(){
            while(lengh){
                int d;
                removeFromBegin(d);
                lengh--;
            }
        }
	
	void print(){
		node<T> *temp=head;
		while(temp){
			cout<<(*temp).data<<" ";
			temp=temp->next;
		}		

	}

	void addToBegin(const T& v){
		node<T> *n=new node<T>;
		n->data=v;
		n->next=head;
		if(!head){
			end=n;
		}
		head=n;
                lengh++;
	}
        
        void add(const T& v, int pos){
            if(lengh==0||lengh<pos){
                addToEnd(v);
                return;
            }
            pos++;
            node<T> *n=new node<T>;
            n->data=v;
            node<T> *temp=new node<T>;
            temp=head;
            while(lengh>pos){
                pos++;
                temp=temp->next;
            }
           n->next=temp->next;
           temp->next=n;
           lengh++;

        }
        
        void addToEnd(const T& v){
            if(lengh==0){
                addToBegin(v);
                return;
            }
            node<T> *n=new node<T>;
            n->data=v;
            node<T> *temp=new node<T>;
            temp=head;
            int pos=1;
            while(lengh>pos){
                pos++;
                temp=temp->next;
            }
           temp->next=n;
           end=temp->next;
           lengh++;
        }
        
	bool removeFromBegin(T& output){
		if(!head)
			return false;
		if(head==end){
			output=head->data;
			delete head;
			head=end=NULL;
			return true;
		}
		node<T>* temp=head;
                output=head->data;
		head=head->next;
                lengh--;
		delete temp;
		return true;
	}
        
        bool removeFromEnd(T& output){
            if(!head)
		return false;
            if(head==end){
		output=head->data;
		delete head;
		head=end=NULL;
		return true;
            }
            node<T> *temp=new node<T>;
            temp=head;
            int pos=1;
            while((lengh-1)>pos){
                pos++;
                temp=temp->next;
            }
            node<T> *t=new node<T>;
            t=temp->next;
            output=temp->next->data;
            temp->next=NULL;
            delete t;
            end=temp;
            lengh--;
            return true;
        }
        
        bool remove(T& output, int pos){
            if(pos==0||pos>=lengh){
                cout<<"Error";
                return false;
            }
            if(!head)
		return false;
            if(head==end){
		output=head->data;
		delete head;
		head=end=NULL;
		return true;
            }
            node<T> *temp=new node<T>;
            node<T> *current=new node<T>;
            
            temp=head;
            current=head;
            int i=0;
            while(pos>i){
                i++;
                current=temp;
                temp=temp->next;
            }
            current->next=temp->next;
            output=temp->data;
            temp=NULL;
            delete temp;
            lengh--;
            return true;
        }
        
        
        int getlengh()const{
            return lengh;
        }
        
        bool getAt(T& output, int pos){
            if((pos<0)||(pos>lengh)){
                return false;
            }
            node<T> *temp=new node<T>;
            temp=head;
            int i=0;
            while(pos>i){
                i++;
                temp=temp->next;
            }
            output=temp->data;
            return true;
        }
        void rev(node<T> *h){
            if(!h)
                return;
            rev(h->next);
            cout<<h->data;
        }
        
        void printrev(){
            rev(head);
        }
        
private:
	node<T> *head, *end;
        int lengh;
};




int main(int argc, char** argv)
{    

    return 0;
}

