#include<iostream>
#include<cmath>
using namespace std;
int p[1001],g[1001];
int dp[1001][1001];
int main(){
	int n;
	cout<<"请输入金矿数"<<endl; 
	cin>>n;
	int peo;
	cout<<"请输入总人数"<<endl;
	cin>>peo;
	cout<<"请分别输入各金矿所需人数，所得钱数"<<endl; 
	for(int i=1;i<=n;i++){
		cin>>p[i]>>g[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=peo;j++){
			if(j<p[i]) dp[i][j]=dp[i-1][j];
			else 
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+g[i]);
		}
	}
	cout<<"最大收益为："<<dp[n][peo];
	return 0;
}
