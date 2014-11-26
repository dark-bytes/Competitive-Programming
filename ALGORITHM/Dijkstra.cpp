#include <iostream>
#include <vector>
using namespace std;

struct ver{
	int n;
	int weight;
};


int main(){
	int edges,vertices;
	cin>>edges>>vertices;
	vector< vector<ver> > v(vertices);
	
	for(int i = 0;i < vertices;i++){
		int w,v_1,v_2;
		cin>>v_1>>v_2>>w;
		v[v_1].push_back((ver){v_2,w});
		v[v_2].push_back((ver){v_1,w});
	}
	
}
