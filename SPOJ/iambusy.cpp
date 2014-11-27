#include <iostream>
#include <algorithm>
using namespace std;

typedef struct a{
	int arr,dep;
}ty;

bool waytosort(ty a,ty b){return a.dep < b.dep;}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		ty a[n];
		for(int i = 0;i < n;i++){
			cin>>a[i].arr>>a[i].dep;
		}
		sort(a,a+n,waytosort);
		int finish = a[0].dep;
		int count = 1;
		for(int i = 1;i < n;i++){
			if(a[i].arr >= finish){
				count++;
				finish = a[i].dep;
			}
		}
		cout<<count<<endl;
	}	
}
