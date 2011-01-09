//@autor Kiril Dimitrov
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
//@info This class represents elements which are going to be used in the PriorityQueue
class Choco{
public:
	string name;
	unsigned int price;
	unsigned int percent;
	Choco(){//set 0 value to all elements
		name.clear();//I want to be sure that my string is empty
		price=0;
		percent=0;
	
	}
//in the sake of testing
	Choco(string n,int pri,int pro){
		name=n;
		price=pri;
		percent=pro;
	}
//Predefinition of operator '=', just in case
        Choco& operator=(Choco& other){
            name=other.name;
            price=other.price;
            percent=other.percent;
        }
};
//@info This template class represent our model of PriorityQueue
template<typename Chocolate,bool (*better)(const Chocolate&,const Chocolate&)>
class PriorityQueue{
private:
        Chocolate* heapArray;//we are using pointer to declare our Chocolate array    	
	int maxSize;//maximum size of array, representing PriorityQueue
	int current;
        void exchange(Choco& a, Choco& b){//exchanges two elements
            Choco temp=a;
            a=b;
            b=temp;
        }
        
        void fixUp(int elementPosition){//here we exchange the place of our element 'til we reach the root element or better element 
            while((elementPosition>0)&&(better(heapArray[elementPosition],heapArray[elementPosition/2]))){
                exchange(heapArray[elementPosition],heapArray[elementPosition/2]);
                elementPosition/=2;
            }
                
        }
        
       void fixDown(int elementPosition){
        if(current<=2) {
            if(current<=1){
                return;
            }else{
                if(better(heapArray[1],heapArray[0])){
                    exchange(heapArray[1],heapArray[0]);
                }
            }
        }//we are making rearange of our elements 'til we reach an element worst element or limit of element's count
        int leftChild=elementPosition*2+1;
        int rightChild=leftChild+1;
        while((elementPosition<current)&&((!better(heapArray[elementPosition],heapArray[leftChild]))
                  ||(!better(heapArray[elementPosition],heapArray[rightChild])))){
                if(leftChild>current||rightChild>current) break;
                int chocoGreat=better(heapArray[leftChild],heapArray[rightChild])?leftChild:rightChild;  
                exchange(heapArray[chocoGreat],heapArray[elementPosition]);
                elementPosition=chocoGreat;
                leftChild=elementPosition*2+1;
                rightChild=leftChild+1;

          }           
        }
public:
        //the only constructor for PriorityQueue with default value of 12
	PriorityQueue(int max=12){
		maxSize=max;
		current=0;
		heapArray=new Chocolate[max];
	}

        ~PriorityQueue(){
            delete[] heapArray;
        }
        
        void push(Choco& ch){//push element and find its place in our Heap
            if(current==maxSize){
                cout<<"I can't do this. You have already reached your limit!"<<endl;
                return;
            }
            heapArray[current]=ch;//here we put new element into our array            
            fixUp(current++);//here we find the right place of the new element
            cout<<"New element is added in the right position"<<endl;
        }
            
        void pop(){//removes our high priority element
            if(empty()){
                cout<<"I can't do this. Your heap is empty"<<endl;
                return;
            }
            heapArray[0]=heapArray[--current];//here we 'remove'
            fixDown(0);//we find the right place of our last element
            cout<<"The best element is removed"<<endl;
        }
        bool empty(){//returns true if our array is empty
            return (current==0);
        }
        const Chocolate& first()const{//returns our high priority element
            return heapArray[0];
        }
};



//Define a method for selecting better element
bool isBetter(const Choco& a,const Choco& b){
	if(a.price>b.price){return true;}
	else{ if(a.price==b.price){
		if(a.percent>=b.percent){return true;}
		else{ return false;}
	}
	}
	return false;
}


int main(int argc, char** argv) {
        PriorityQueue<Choco,&isBetter> a(12);
        while(true){
            cout<<"Please make your choice: "<<endl;
            cout<<"1. Input element"<<endl;
            cout<<"2. Remove element"<<endl;
            cout<<"3. Show first element"<<endl;
            cout<<"4. Exit"<<endl;
            int i;
            cin>>i;
            switch(i){
                case(1):{
                    char temp[15]={};
                        cout<<endl<<"Please input chocolate name :"<<endl;
                        cin>>temp;
                        string name(temp);
                        cout<<"Please input the price of "<<name<<endl;
                        int price=0;
                        cin>>price;
                        cout<<"Please input the percent of pure chocolate in "<<name<<endl;
                        int percent=0;
                        cin>>percent;
                        Choco chocoInput(name, price, percent);
                        a.push(chocoInput);
                        break;
                }
                case(2):{
                        a.pop();
                        break;
                }
                case(3):{
                        if(!a.empty()){
                            cout<<"First element is "<<a.first().name<<endl;
                        }else{
                            cout<<"Array is empty"<<endl;
                        }
                        break;
                }
                case(4):{
                        cout<<"Thank you for using our product"<<endl;
                        return 0;
                        break;
                }    
                default:{
                        cout<<"You have selected incorect option"<<endl;
                        break;
                }
            
            }
        }
}

