#include<iostream>
#include<cmath>
using namespace std;
int dp[10001][10001];
int w[10001],va[10001];
int main(){
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>va[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(j>=w[i]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+va[i]);
				
			}
			else {
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][v];
	return 0;
}
/* 10 5
2 1
3 3
4 5
7 9
5 6

ans:12
*/
