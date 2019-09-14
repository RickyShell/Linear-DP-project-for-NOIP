# RickieShell
ONE NOI RUNNER
#include<iostream>
using namespace std;	
int n,m;
int dp[1001]={1};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(i<m) dp[i]=2*dp[i-1];
		else if(i==m) dp[i]=2*dp[i-1]-1;
		else dp[i]=2*dp[i-1]-dp[i-m-1]; //497核电站  
	} 
	cout<<dp[n];
	return 0; 
}
