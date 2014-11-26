#include<iostream>
using namespace std;

int main()
{
	int a[7];
	
	for(int i = 0;i<7;i++)
	{
		cin>>a[i];
	}
	
	int ls[7] = {0};
	
	for(int i = 0;i<7;i++)
	{
		ls[i] = 1;
		
		for(int j = 0;j < i;j++)
		{
			if(a[i] > a[j] && ls[i]  <= ls[j])
			{
				ls[i] = ls[j] + 1;
			}
		}
	}
	int largest = 0;
	for(int i = 0;i < 7;i++)
	{
		if(largest < ls[i])
			largest = ls[i];
	}
	
	cout<<largest;
}
