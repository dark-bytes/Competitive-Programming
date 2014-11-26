#include<iostream>
#include<set>
using namespace std;

int main(){
		multiset<int> sumsets;
		int n,i = 0;
		cin>>n;
		
		long long int subsets[1<<15];
		//vector<long long int> subsets(2);
		long long int index = 0,index_it = 1;
		subsets[0] = 0;
		
		while(i < (1<<n)){
			long long int num;
			cin>>num;
			sumsets.insert(num);
			i++;
		}
		
		multiset<int>:: iterator newit = sumsets.find(3);
		sumsets.erase(newit);
		
		for(multiset<int>::const_iterator it(sumsets.begin()),end(sumsets.end()); it != end; it++){
			cout<<*it<<" ";
		}
}
