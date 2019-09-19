#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;
int dp[10001][10001],num[10001][10001];
int exa[10001];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		exa[i]=c-'0'; 
		num[i][i]=c-'0';
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			num[i][j]=10*num[i][j-1]+exa[j];
		}
	}
	for(int i=1;i<=n;i++)
	dp[i][0]=num[1][i]; 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int r=1;r<j;r++){
				dp[j][i]=max(dp[j][i],dp[r][i-1]*num[r+1][j]);
			}
		}
	}
	cout<<dp[n][k];
	return 0;
} 

/*#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ch[11],num[11][11],f[11][11];
int main(){	
cin>>n>>m;	
for(int i=1;i<=n;i++) 
scanf("%1d",ch+i);		
for(int i=1;i<=n;i++)		
for(int j=i;j<=n;j++)			
num[i][j]=num[i][j-1]*10+ch[j];//进行出预处理						
for(int i=1;i<=n;i++) f[i][0]=num[1][i]; //初始化的部分			
for(int k=1;k<=m;k++)		
for(int i=1;i<=n;i++)			
for(int j=1;j<i;j++)				
f[i][k]=max(f[i][k],f[j][k-1]*num[j+1][i]);//k个乘号有k-1个乘号推导出来	
cout<<f[n][m]<<endl;	
return 0;} 
还可以暴力搜索进行求解
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ch[11],n,k,f[11][11],num[11][11],maxn;
void dfs(int cur,int i,int s){	
if(cur==k){		
s=s*num[i+1][n];		
if(s>maxn) maxn=s;		
return ;	
}	else {		
for(int j=i+1;j<n;j++)//j后面是一个乘号 			
dfs(cur+1,j,s*num[i+1][j]);	}}
int main(){	
cin>>n;	
cin>>k;	
for(int i=1;i<=n;i++) 
scanf("%1d",&ch[i]);		
for(int i=1;i<=n;i++)		
for(int j=i;j<=n;j++)			
num[i][j]=num[i][j-1]*10+ch[j];	
for(int i=1;i<n;i++)	
dfs(1,i,num[1][i]); 	
cout<<maxn<<endl;		
return 0;} 
*/
