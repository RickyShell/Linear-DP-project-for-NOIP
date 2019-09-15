#include <iostream> 
#include<cmath>
using namespace std;
int n,a[10001],dp[1001][1001],ans=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
		a[i+n]=a[i];
	}
        
    for(int len=2;len<=n;len++) //枚举区间长度
        for(int i=1;i+len-1<n*2;i++){ //枚举区间起点
            int j=i+len-1; //区间终点
            for(int k=i;k<j;k++) //枚举决策
                dp[i][j]=max(dp[i][j], dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
        
    for(int i=1;i<=n;i++)
        ans=max(dp[i][i+n-1],ans);
    cout<<ans;
    return 0;
}

/*算法结构
设F[i,j]（1<=i<=j<=n）表示区间[i,j]内的数字相加的最小代价
每次用变量k（i<=k<=j-1）将区间分为[i,k]和[k+1,j]两段
For l:=2 to n do // 枚举区间长度
for i:=1 to n do // 枚举区间的左端点
begin
j:=i+l-1; // 计算区间的右端点,因为区间长度和左端点循环嵌套枚举，保证了[i,j]内的所有子区间都被枚举到
if j>n then break; // 保证了下标不越界
for k:= i to j-1 do // 状态转移，去推出 f[i,j]
f[i , j]= max{f[ i,k]+ f[k+1,j]+ w[i,j] }
end;
*/
