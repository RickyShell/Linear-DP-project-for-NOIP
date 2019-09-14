#include<iostream>
#include<cmath>
using namespace std;
int main(){ 
long long dp1[10001],dp2[10001],a[10001],b[10001];
int maxn=0;
	    int n;
	    cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[n+1-i]=a[i];
		} for(int i=1;i<=n;i++){
		    dp1[i]=1;
		    for(int j=1;j<i;j++){
		    	if(a[j]<a[i])
                       dp1[i]=max(dp1[i],dp1[j]+1);
			}
		} 
for(int i=1;i<=n;i++){
        dp2[i]=1;
        for(int j=1;j<i;j++){
        		if(b[j]<b[i])dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
    for(int i=1;i<=n;i++){
			
     if(dp1[i]+dp2[n-i+1]>maxn)
                   maxn=dp1[i]+dp2[n-i+1];
		}
           cout<<n-maxn+1;
	    return 0;
}
