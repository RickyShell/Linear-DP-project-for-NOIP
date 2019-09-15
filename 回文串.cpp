#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char a[10001],b[10001];
int dp[10001][10001];
int way[10001][10001];

void print(int x,int y){
	if(x==0||y==0) return;
	if(way[x][y]==1){
		print(x-1,y-1);
		cout<<a[x];
	
	} 
	if(way[x][y]==2) print(x,y-1);
	if(way[x][y]==3) print(x-1,y);	
}
int main(){
	int len;
	cin>>len;
	for(int i=1;i<=len;i++){
		cin>>a[i];
		b[len-i+1]=a[i];
	}
	//cin.getline(a,len);
	//cin.getline(b,10000);
	//int l1=strlen(a);
	//int l2=strlen(b);

	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++){
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				way[i][j]=1;
			}
			if(a[i]!=b[j]){
			    if(dp[i][j-1]>dp[i-1][j]){
			    	way[i][j]=2;
					dp[i][j]=dp[i][j-1];
				}
				else{
					way[i][j]=3;
					dp[i][j]=dp[i-1][j];
				}
			}
		}
    }
    int kll=dp[len][len];
    cout<<len-kll;
	//cout<<dp[l1][l2]<<endl;
	//print(l1,l2);
	/*BACDBA   
	ABCADAB*/
	return 0;
} 
