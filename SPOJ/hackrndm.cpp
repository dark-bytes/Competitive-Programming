#include <iostream>
#include <map>
using namespace std;


int main(){
	
	map<int,int> a;
	int n,k;
	cin>>n>>k;
	int num;
	int max = 0;
	
	for(int i = 0;i < n;i++){
		cin>>num;
		a[num] = 1;
	}
	
	long long int ans = 0;
	for(map<int,int>::iterator i = a.begin();i != a.end();i++){
		int p = i->first;
		if(a.find(p + k) != a.end())
			ans++;
	}
	cout<<ans;
}
