#include<iostream>
using namespace std;

const int N=5;
int used[N];

void init(int* arr){
	for(int i=1;i<=N;i++)
		arr[i]=0;
	arr[0]=-1;
}

void print(int i,int j){
	cout<<i<<" "<<j<<endl;
}


void varation(int* arr, int current,int position){
	if(arr[current]==-1){
		varation(arr,++current,1);	
		return;
	}
	if(position>N){
		varation(arr,++current,1);
		return;
	}
	if((current==N)&&(position==N)){
		print(current,position);
		return;
	}
	if(current==position){
		varation(arr,current,++position);
		return;
	}
	print(current, position);
	varation(arr,current,++position);
	
}

int main(){
	init(used);
	varation(used,1,1);	
	return 0;
}

