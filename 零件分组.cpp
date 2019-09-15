#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int len;
	int weight;
};
bool cmp(node a,node b){
	if(a.len<=b.len) return true;
	else return false;
}
node code[10001];
int wei[10001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>code[i].len>>code[i].weight;
	}
	sort(code+1,code+n+1,cmp);
	int zu=1;
	wei[1]=code[1].weight;
	for(int i=2;i<=n;i++){
		int min=-1;
		int num=1;
		int ji=0;
		for(int j=1;j<=zu;j++){
			if(code[i].weight>=wei[j]){
				if(wei[j]>=min) {
					min=wei[j];
					num=j;
					ji=1;
				}
			}
		}
		if(ji==1){
			wei[num]=code[i].weight;
			continue;
		}
		else if(ji==0){
			zu++;
			wei[zu]=code[i].weight;
		}
	}
	cout<<zu;
	return 0;
}
