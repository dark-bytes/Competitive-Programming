#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector< vector <int> > v;
vector<int> ancestors;

bool DFS(int start){
	visited[start] = 1;
	for(int i = 0;i < v[start].size();i++){
		if(visited[v[start][i]] == 0){
			ancestors[v[start][i]] = start;
			if(DFS(v[start][i]))
				return true;
		}
		else{
			if(v[start][i] == ancestors[start]){
				continue;
			}
			else{
				return true;
			}
		}
	}
	return false;
}


int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	if(edges > nodes)
		cout<<"No";
	else{
	v.resize(nodes + 1);
	visited.resize(nodes + 1,0);
	ancestors.resize(nodes + 1,0);
	int v_1,v_2;
	for(int i = 0;i < edges;i++){
		cin>>v_1>>v_2;
		v[v_1].push_back(v_2);
		v[v_2].push_back(v_1);
	}
	bool is_cycle = DFS(1);
	for(int i = 1;i < visited.size();i++){
		if(visited[i] == 0)
			is_cycle = true;
	}
	if(is_cycle == true)
		cout<<"No";
	else
		cout<<"Yes";
	}
	return 0;
}
