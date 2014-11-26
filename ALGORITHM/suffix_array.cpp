#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

struct entry{
	int nr[2],p;
}l[50000];

int p[10][50000];
int cmp(struct entry a, struct entry b){
	return (a.nr[0] == b.nr[0]) ? (a.nr[1] < b.nr[1] ? 1 : 0):(a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp(int x, int y,int len,int stp){
	int ret = 0;
	
	if(x == y) 
		return (len - x);
	
	for(int i = stp - 1; i >= 0 && x < len && y < len; i--){
		if(p[i][x] == p[i][y]){
			x += 1<<i;
			y += 1<<i;
			ret += 1<<i;
		}
	}
	return ret;
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		
		int cnt = 1,stp = 1;
		string s;
		cin>>s;
		
		int len = s.length();
		stp = ceil(log(len)/log(2));
		
		for(int i = 0; i < s.length(); i++){
			p[0][i] = s[i] - 'A';
		}
		
		for(stp = 1, cnt = 1; cnt >> 1 < len; stp++, cnt <<= 1){
			for(int i = 0; i < len; i++){
				l[i].nr[0] = p[stp - 1][i];
				l[i].nr[1] = (i + cnt < len)? (p[stp - 1][i + cnt]):-1;
				l[i].p = i;
			}
			
			sort(l, l + len, cmp);
			
			for(int i = 0; i < len; i++){
				p[stp][l[i].p] = (i>0 && (l[i].nr[0] == l[i-1].nr[0]) && (l[i].nr[1] == l[i-1].nr[1])) ? (p[stp][l[i-1].p]) : i;
			}
		}
		
		for(int i = 0; i < len; i++){
			cout<<p[stp - 1][i]<<" ";
		}
		cout<<endl;
		
		int ans = len*(len + 1)/2; 
		for(int i = 0; i < len - 1; i++){
			ans -= lcp(p[stp-1][i],p[stp-1][i+1],len,stp);
		}
		cout<<ans<<endl;
	}
}
