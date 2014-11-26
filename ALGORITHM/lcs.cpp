#include<iostream>
using namespace std;

int n1,n2,check,count = 0;
int lcs[500][500];

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	
	n1 = s1.length();
	n2 = s2.length();
	
	for(int i = 1;i <= n1;i++){
		lcs[i][0] = 0;
	}
	for(int i = 0;i <= n2;i++){
		lcs[0][i] = 0;
	}
	
	for(int i = 1;i <= n1;i++){
		for(int j = 1;j <= n2;j++){
			if(s1[i-1] == s2[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				if(lcs[i-1][j] >= lcs[i][j-1]){
					lcs[i][j] = lcs[i-1][j];
				}
				else{
					lcs[i][j] = lcs[i][j-1];
				}
			}
		}
	}
	
	cout<<lcs[n1][n2];
	
	return 0;
}
