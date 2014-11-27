#include <bits/stdc++.h>
#define sfi(n) scanf("%d",&n); 
using namespace std;


int g_c_d(int a,int b)
{
	if(b == 0)
		return a;
	else
	{
		return g_c_d(b,a%b);
	}
}

int gcd(int a,int b)
{
	if(a < b)
	{
		g_c_d(b,a);
	}
	else
		g_c_d(a,b);
}
int main()
{
	int n;
	sfi(n);
	int a[n];
	sfi(a[0]);sfi(a[1]);sfi(a[2]);
	int root_gcd = gcd(a[1] - a[0],a[2] - a[1]);
	for(int i = 3;i < n;i++)
	{
		sfi(a[i]);
		root_gcd = gcd(a[i] - a[i - 1],root_gcd);
	}
	int ans = 0;
	for(int i = 1;i < n;i++)
	{
		ans += ((a[i] - a[i - 1])/root_gcd - 1);
	}
	cout<<ans<<endl;
}
