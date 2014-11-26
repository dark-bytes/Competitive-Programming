#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;


int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s,s1;
		int cost_d_ins,cost_sub,k;
		cin>>s>>s1;                                                                              //Converting String s into s1
 		int dp[s.length() + 1];
		cin>>cost_d_ins>>cost_sub>>k;
		
		for(int i = 0;i < s.length() + 1;i++)
			dp[i] = i;                                                                       //when nothing in string                                                                       //when nothing in string s1
			
		int temp;
		bool flag = 0;
		for(int i = 1;i <= s1.length();i++)
		{
			temp = dp[0];
			dp[0] = i;
			for(int j = 1;j <= s.length();j++)
			{
				int local_temp;
				if(dp[j] == INF && temp == INF && dp[j - 1] == INF)
				{
					flag = 1;	
					break;
				}
				if(s1[i - 1] == s[j - 1])
				{
					local_temp = dp[j];
					dp[j] = min(dp[j] + cost_d_ins,min(temp,dp[j - 1] + cost_d_ins));
					temp = local_temp;
					if(dp[j] > k)
						dp[j] = INF;
				}
				else
				{
					local_temp = dp[j];
					dp[j] = min(dp[j] + cost_d_ins,min(temp + cost_sub,dp[j - 1] + cost_d_ins));
					temp = local_temp;
					if(dp[j] > k)
						dp[j] = INF;
				}
			}
			if(flag == 1)
				break;
		}
		if(dp[s.length()] > k || flag == 1)
			cout<<"-1"<<endl;
		else
			cout<<dp[s.length()]<<endl;
	}
	return 0;
}
