#include<fstream>
#include<iostream>
using namespace std;

struct Student{
	unsigned fn;
	char name[100];
};

void dump(const char* file,  Student& st){
	fstream out(file,ios::out|ios::binary);
	if(out.is_open()){
		if(out.write(reinterpret_cast<char*>(&st),sizeof(st)))
		cout<<"Nice1 ";
	out.close();
}else
	cout<<"suck balls";
}	

void load(const char* file, Student& st){
	fstream in(file,ios::in|ios::binary);
	if(in.is_open()){
		if(in.read(reinterpret_cast<char*>(&st),sizeof(st)))
			cout<<"Nice2 ";
		in.close();	
	}else
		cout<<"suck balls";
}

int main(){
	Student test;
	cout<<"haha";
	cin>>test.fn>>test.name;
	dump("test.dat",test);
	cout<<"hah2";
	Student test2;
	
	load("test.dat",test2);
	cout<<sizeof(Student)<<" "<<test2.fn<<" "<<test2.name;
return 0;
}
