#@一个是最长不上升子序列，一个贪心
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int k=1,l[1001],p,h[1001],n=1;
int a[10001][4];
int top=0;
int main(){
	while(cin>>h[n]){
	a[n][1]=h[n];
	a[n][2]=1;
	
		n++;}
	n--;
	l[k]=h[k];
	for(int i=2;i<=n;i++){
		p=0;
		for(int j=1;j<=k;j++)
			if(l[j]>=h[i]){
				if(p==0)
					p=j;
				else if(l[j]<l[p])
					p=j;
			}
		if(p==0){
			k++;
			l[k]=h[i];
		}
		else l[p]=h[i];
	}
	for(int i=n;i>=1;i--){
		for(int k=i+1;k<=n;k++){
			if(a[i][2]<=a[k][2]&&a[i][1]>=a[k][1]){
				a[i][2]=a[k][2];
				a[i][3]=k;
			}
		}
		a[i][2]=a[i][2]+1;
	}

//	for(int i=1;i<=n;i++){
//		cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
//	}	
	int max=0;
	for(int i=1;i<=n;i++){
		if(max<a[i][2]){
			max=a[i][2];
		}
	}
	cout<<max-1<<endl;

	cout<<k;
	
	return 0;
}
