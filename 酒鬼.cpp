#https://github.com/RickyShell
#include<iostream>
#include<cmath>
using namespace std;
int dp[1001];
int wine[1001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>wine[i];
	}
	dp[1]=wine[1];
	dp[2]=wine[1]+wine[2]; //要三个才能推导
	
	for(int i=1;i<=n;i++){
		int k=max(dp[i-1],dp[i-2]+wine[i]);
		dp[i]=max(dp[i-3]+wine[i]+wine[i-1],k);
		
	} 
	cout<<dp[n];
	return 0;
}
