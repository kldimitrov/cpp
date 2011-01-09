#include<iostream>
using namespace std;

template<typename T,bool (f)(T,T)>
void sortArray(T* arr, int count){
	for(int i=0; i<count; i++){
		for(int j=0;j<count;j++){
			if(f(arr[j],arr[i])){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

}

bool greater_than(int a, int b){
return (a>b)?true:false;
}

int main(){
int arr[]={2,4,1,4,7,5,1};
int size=sizeof(arr)/sizeof(int);
sortArray<int,&greater_than>(arr,size);
for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
}

return 0;
}