#include <iostream>
using namespace std;
//cnt--计数;sum--求和;fac--求积 
int n;
int a[10000]={0},cnt=0;
bool b[10000];
int ss(int x,int y){
	int sum=x+y;
	if(sum<=1) return 0;
	else {
		int d=0; 
		for(int i=2;i<=sum/i;i++){
			if(sum%i==0)
				return 0;
		}
		return 1;
	}
}
void print(){
	cnt++;
	printf("<%d>:",cnt);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void dfs(int t){
	for(int i=1;i<=n;i++){
		if(ss(a[t-1],i) && (!b[i])){
			a[t]=i;
			b[i]=1;
			if(t==n){
				if(ss(a[n],a[1])) print();
			}
			else dfs(t+1);
			b[i]=0;
		}
	}
}
int main() {
	cin>>n;
	dfs(1);
	printf("%d%d"); 
	printf("%d",cnt);
	return 0;
} 
