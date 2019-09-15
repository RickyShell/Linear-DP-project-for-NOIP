#include<iostream>
#include<cmath>
using namespace std;
int dp[2002][2002];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dp[1][i]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=1;
	}
	for(int i=2;i<=m;i++){
		for(int j=2;j<=n;j++){
			int min=999;
			for(int x=1;x<=j;x++){
				int jkr=max(dp[i][j-x]+1,dp[i-1][x-1]+1);
				if(jkr<min) min=jkr;
			}
			dp[i][j]=min;
		} 
	}
	
	cout<<dp[m][n];
	return 0;
}
