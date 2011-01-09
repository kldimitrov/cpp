#include<iostream>
using namespace std;

template<typename T>
void sortArray(T* arr, int count){
	for(int i=0; i<count; i++){
		for(int j=0;j<count;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

}

int main(){
int arr[]={2,4,1,4,7,5,1};
int size=sizeof(arr)/sizeof(int);
//cout<<size;
sortArray<int>(arr,size);
for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
}

return 0;
}