#include<iostream>
#include<cstdio>
using namespace std;

const int MONEY = 100;

struct situation
{
	double dollar;
	double mark;
};

int main()
{
	int n;
	cin>>n;
	double value[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>value[i];
		value[i] /= 100;
	}
	situation Dp[n+1];
	for(int i=0;i<=n;i++)
	{
		if(i == 0)
		{
			Dp[i].dollar = MONEY;
			Dp[i].mark = 0;
		}
		else
		{
			Dp[i].dollar = max(Dp[i-1].mark / value[i], Dp[i-1].dollar);
			Dp[i].mark = max(Dp[i-1].dollar * value[i], Dp[i-1].mark);
		}
	}
	printf("%.2lf",Dp[n].dollar);
	return 0;
}
@原方法没有问题
@算法不同，概念不同
