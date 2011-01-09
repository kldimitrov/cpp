// 
// File:   asd.cc
// Author: ritter
//
// Created on December 4, 2010, 6:11 PM
//

#include <stdlib.h>
#include<iostream>
#include<list>
#include<math.h>
using namespace std;

//
// 
//

///////////////////
bool isEven(int val){
	return (val%2==0);
}

int incrementWithFive(int val){
	return val+5;
}

int sum(int a, int b){
	return a+b;
}

int powerOfTwo(int num){
    return pow(2,num);
}

/////////////////

template<typename T>
list<T> map(list<T> l, int(*f)(T)){
	list<T> temp;
        
	for(typename list<T>::iterator iter=l.begin(); iter!=l.end();iter++){
		temp.push_back(f(*iter));	
	}
	return temp;

}

template<typename T>
int accumulator(list<T> l, int(*f)(T,T)){
	int sum=0;
	for(typename list<T>::iterator iter=l.begin(); iter!=l.end();iter++){
		sum=f(*iter,sum);
	}
	return sum;
}

template<typename T>
list<T> filter(list<T> l, bool(*f)(T)){
	list<T> temp;
	for(typename list<T>::iterator iter=l.begin(); iter!=l.end();iter++){
		if(f(*iter))
			temp.push_back(*iter);
	}
	return temp;
}

template<typename T>
list<T> unique(list<T> l){
        list<T> temp;
        for(typename list<T>::iterator iter=l.begin();iter!=l.end();iter++){
            int count=0;
            for(typename list<T>::iterator iter2=l.begin();iter2!=l.end();iter2++){
                if((*iter)==(*iter2)){
                    count++;
                }
            }
            
            if(count==1){
                temp.push_back(*iter);
            }
        }
        return temp;
}

int main(int argc, char** argv) {
    list<int> l;
//    l.push_back(1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    int s=accumulator(l,&sum);
    list<int> temp=map(l,&powerOfTwo);
    for(list<int>::iterator iter=temp.begin(); iter!=temp.end();iter++)
        cout<<*iter<<endl;
    temp=filter(l,&isEven);
    cout<<endl;
    for(list<int>::iterator iter=temp.begin(); iter!=temp.end();iter++)
        cout<<*iter<<endl;
    temp=unique(l);
    cout<<endl<<"Unique are: ";
    for(list<int>::iterator iter=temp.begin(); iter!=temp.end();iter++)
        cout<<*iter<<endl;
    cout<<"Number of elements is: "<<s;
    
    return (EXIT_SUCCESS);
}

