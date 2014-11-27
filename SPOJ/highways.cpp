#include <iostream>
using namespace std;
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <fstream>
#define INF 10000000

typedef struct node{
	long long int at;
	long long int time;
}high;

bool operator<(const node &left,const node &right){
	if(left.time!=right.time)
		return left.time < right.time;
	if(left.at != right.at)
		return left.at < right.at;
	
}

int main(){
	int tc;
	ifstream fin("input.txt");
	fin>>tc;
	while(tc--){
		long long int n,m,start,end;
		fin>>n>>m>>start>>end;
		vector< vector<high> > cit(n);
		high a;
		bool visited[n];
		long long int time[n];
		memset(time,INF,sizeof(time));
		long long int ini,at_i,at_t;
		for(int i = 0;i < m;i++){
			fin>>ini;
			fin>>at_i>>at_t;
			a.at = at_i - 1;
			a.time = at_t;
			cit[ini-1].push_back(a);
			a.at = ini - 1;
			cit[at_i-1].push_back(a);
		}
		priority_queue<high> q;
		q.push((high){start-1,0});
		time[start-1] = 0;
		while(q.empty() == false){
			high top = q.top();
			q.pop();
			for(int i = 0;i < cit[top.at].size();i++){
					long long int tim = (cit[top.at][i]).time;
					long long int pos = cit[top.at][i].at;
					
					if(time[pos] > time[top.at] + tim )
					{
						time[pos] = time[top.at] + tim;
						q.push(cit[top.at][i]);
					}
				}
			}
			if(time[end-1] == INF)
				cout<<"NONE"<<endl;
			else
				cout<<time[end-1]<<endl;
		}
		return 0;
	}
