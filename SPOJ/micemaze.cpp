#include <iostream>
#include <fstream>
using namespace std;
#define INF 1000000000

int main(){
	ifstream fin("input.txt");
	int n;
	int e;
	long long int t;
	int m;
	fin>>n>>e>>t>>m;
	long long int graph[101][101];
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			graph[i][j] = INF;
			if(i == j)
				graph[i][j] = 0;
		}
	}
	
	for(int i = 0;i < m;i++){
		long long int e1,e2,ti;
		fin>>e1>>e2>>ti;
		graph[e1][e2] = ti;
	}
	
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	
	long long int count = 0;
	for(int i = 1;i <= n;i++){
		if(graph[i][e] <= t){
			count++;
		}
	}
	cout<<count;
	
}
