#include<iostream>
#include<vector>
#include<malloc.h>
#include<stack>
using namespace std;

typedef struct arc_datatype
{
	int point;
	struct arc_datatype* arc_point;
//	int wt;
}arc;
typedef struct vertex
{
	arc* arc_point;
}VERTEX;


class graph{
	public:

		vector<VERTEX> ver;
		
		graph(){}
		graph(int t_ver)
		{
			ver.resize(t_ver);
			for(int i = 0;i<=ver.size(); i++){
				ver[i].arc_point = NULL;
			}
		}	
	
		void join(int p,int q)
		{
			arc* temp;
			temp = (arc*)malloc(sizeof(arc));
		//	cout<<"Sudhanshu";
			if(ver[p].arc_point == NULL)
			{
				ver[p].arc_point = temp;
				temp->point = q;
			//	temp->wt = wt;
				temp->arc_point = NULL;
			}	
			else
			{
				arc* forward = ver[p].arc_point;
				while(forward->arc_point != NULL)
				{
					forward = forward->arc_point;
				}
				forward->arc_point = temp;
				temp->point = q;
			//	temp->wt = wt;
				temp->arc_point = NULL;
			}
		}
	
/*	void display(int p)
	{
		arc* next = ver[p-1].arc_point;
		cout<<"No. of nodes connected to node"<<p<<"->";
		while(next != NULL)
		{
		//	cout<<next->point<<"Weight between them is"<<next->wt<<endl;

			next = next->arc_point;
		}
	}
*/	
};

void DFS(int start,graph& g,vector<int>& exp_unexp)
{
	stack<int> s;
	s.push(start);
	exp_unexp[start] = 1;
	while(!(s.empty()))
	{
		int top = s.top();
		s.pop();
		cout<<top<<" ";
		arc* temp = g.ver[top].arc_point;
		
		while(temp!=NULL)
		{
			if(exp_unexp[temp->point] == 0)
			{
				exp_unexp[temp->point] = 1;
				s.push(temp->point);
			}
			temp = temp->arc_point;
		}	
	}
}
int main()
{
	int i;
	cin>>i;
	
	graph g(i);
	cout<<"No. of edges u want->";
	
	int edges;
	cin>>edges;
	int m,n;
	vector<int> exp_unexp(i,0);
	
	for(int i = 0;i<edges;i++)
	{
		cin>>m>>n;
		g.join(m,n);
	}
	
	
	cout<<"Enter start position->";
	int start;
	cin>>start;
	cout<<"DFS is->";
	DFS(start,g,exp_unexp);
	for(int j=0;j<exp_unexp.size();j++)
	{
		if(exp_unexp[j] == 0)
			DFS(j,g,exp_unexp); 
	}
}
