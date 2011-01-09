#include<iostream>
using namespace std;

const int N=4, M=6;
int marked[N][M];
int arr[N][M]={{1,1,0,0,0,0},
	       {0,0,1,1,0,1},
	       {0,0,1,0,0,1},
	       {0,1,1,0,0,1}};

int findSize(int x, int y){
	if(arr[x][y]==0)
		return 0;
	if((x>=N)||(y>=M))
		return 0;
	if(marked[x][y]!=0)
		return 0;
	marked[x][y]=1;
	return 1+findSize(x+1,y)+findSize(x,y+1)+findSize(x-1,y)+findSize(x,y-1);
}

int main(){
	int max=findSize(0,0);	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if((i==0)&&(j==0))
				continue;
			int temp=findSize(i,j);
			if(temp>max)
				max=temp;
		}
	}
	cout<<max<<endl;
return 0;
}