#include<iostream>
#include<cmath>
using namespace std;
int dp[100001],worth[10001],weight[10001]; //一维的01背包优化 项数代表背包能放的质量 
int main(){
	int big,num;
	cin>>num>>big;
	for(int i=1;i<=num;i++){
		cin>>weight[i]>>worth[i];
		
	}
	for(int i=1;i<=num;i++){
		for(int j=big;j>=weight[i];j--){
			dp[j]=max(dp[j-weight[i]]+worth[i],dp[j]);
		}
	}
	cout<<dp[big];
	return 0;
}
/* 10 5
2 1
3 3
4 5
7 9
5 6

ans:12 */ 
