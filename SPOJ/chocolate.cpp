#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define pb push_back
#define all(c) c.begin(),c.end()
#include <numeric>

bool waytosort(int i,int j){return i>j;}


int main(){
	int tc;
	cin>>tc;
	cout<<endl;
	while(tc--){
		int m,n;
		cin>>m>>n;
		vector<int> row;
		vector<int> column;
		int freq_r = 1;
		int freq_c = 1;
		int element;
	//	int front_c = 0,front_r = 0;
		long long int ans = 0;
	//	long long int sum_r = 0,sum_c = 0;
		for(int i = 0;i < m - 1;i++){
			cin>>element;
			row.pb(element);
		//	sum_r += element;
		}
		sort(row.begin(),row.end(),waytosort);
		
		
		for(int i = 0;i < n - 1;i++){
			cin>>element;
			column.pb(element);
		//	sum_c += element;
		}
		sort(column.begin(),column.end(),waytosort);
		int i = 0,j = 0;
		
		while(i < m - 1 || j < n -1){
			if(j == n - 1 ||( i < m - 1 && row[i] > column[j])){
				ans += (row[i]*freq_r);
				i++;
				freq_c++;
			}
			else{
				ans += (column[j]*freq_c);
				j++;
				freq_r++;
			}
		}
		cout<<ans<<endl;
	}
}
