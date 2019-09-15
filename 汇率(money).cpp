#include<iostream>
#include<cstdio>
using namespace std;
double dollar[10001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dollar[i];
	}
	double mark=100.0;
	for(int i=1;i<=n-1;i++){
		if(dollar[i+1]<dollar[i]){
			mark*=(double)dollar[i]/dollar[i+1];
		}
	}
	printf("%.2f",mark);
	return 0;
}
