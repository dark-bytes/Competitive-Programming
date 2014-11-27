using namespace std;
#include <cmath>
#include <stdio.h>
long long int a[100000] = {0};
long long int b[100000] = {0};

int main(){
	long long int tc;
	scanf("%lld",&tc);
	int j = 0;
	for(int i = 2;i < 100000;i++){
		if(a[i] == 0){
			b[j++] = i;
			int k = i;
			for(k = k + i;k<100000;){
				a[k] = 1;
				k = k + i;
			}
		}			
	}
	while(tc--){
		long long int m,n;
		scanf("%lld%lld",&m,&n);
		int j = 0;
		if(m == 1)
			m++;
		if(n<100000){
			for(int i = m;i <= n;i++){
				if(a[i] == 0){
					printf("%d\n",i);
				}
			}	
		}
		else{
			for(long long int j = m;j <= n;j++){
				if(j < 100000){
					for(;j < 100000;j++){
						if(a[j] == 0)
							printf("%lld\n",j);
					}
				}
				else{
					int flag = 0;
					long long int k;
					for(k = 0;b[k]*b[k] <= j;k++){
						if(j % b[k] == 0){
							flag = 1;
							break;
						}
					}
					if(!flag)
						printf("%lld\n",j);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
