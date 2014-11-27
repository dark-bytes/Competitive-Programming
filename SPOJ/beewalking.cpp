#include <iostream>
using namespace std;

int rec(int i,int times,bool flag){
	if(flag == 1 && i >= times - 1)
		return 1;
	else if(flag == 0 && i == times)
		return 1;
	else{
		times++;
		int total = 0;
		if(flag == 0)
			total = 6*rec(i,times,1);
		else{
			total =	total + 2*rec(i,times,1);
			total = total + rec(i,times,0);
		//	total = total + 6*rec(i,times);
		}
		return total;
	}
}



int main(){
	int tc;
	cin>>tc;
	int n[16];
	while(tc--){
		int n;
		cin>>n;
		int ans = rec(n,1,0);
		cout<<ans;
	}
}
