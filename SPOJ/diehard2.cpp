#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int h,a;
		cin>>h>>a;
		int time = 0;
		bool flag = 1;
		while(h > 0 && a > 0){
			if(flag){
				h += 3;
				a += 2;
				time++;
				flag = 0;
			}
			else{
				if(h < 20){
					h -= 5;
					a -= 10;
					if(h > 0 && a > 0)
						time++; 
					flag = 1;
				}
				else if(a < 10){
					h -= 20;
					a += 5;
					if(h > 0 && a > 0)
						time++;
					flag = 1;
				}
				else if(abs(h-5 -(a - 10)) < abs(h - 20 - (a + 5))){
					h -= 5;
					a -= 10;
					if(h > 0 && a > 0)
						time++;
					flag = 1;
				}
				else{
					h -= 20;
					a += 5;
					if(h > 0 && a > 0)
						time++;
					flag = 1;
				}
			}
		}
		cout<<time<<endl;
	}
}
