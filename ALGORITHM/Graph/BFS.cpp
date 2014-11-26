#include<iostream>
#include<vector>
#include<malloc.h>
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
			cout<<"Sudhanshu";
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
	
	void display(int p)
	{
		arc* next = ver[p-1].arc_point;
		cout<<"No. of nodes connected to node"<<p<<"->";
		while(next != NULL)
		{
		//	cout<<next->point<<"Weight between them is"<<next->wt<<endl;
			next = next->arc_point;
		}
	}
	
};

class queue: public graph
{
	int head;
	int tail;
	vector<int> a;
	
	
	public:
		queue(int p)
		{	
			head = 0;
			tail = -1;
			a.resize(p);
		}
		void insert(int p)
		{
			if(head == 0)
			{
				a[head] = p;
				tail = head+1;
			}
			else
			{
				a[tail++] = p;
			}
		}
		int remove()
		{
			return a[head++];
		}
		bool isEmpty()
		{
			if(head == tail)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};

int main()
{
	int i;
	cin>>i;
	graph g(i);
	cout<<"No. of edges u want->";
	int edges;
	cin>>edges;
	int m,n;
	int wt;
//	cout<<"Check";
	vector<int> exp_unexp(i,0);
	//cout<<"Check";
	for(int i = 0;i<edges;i++)
	{
	//	cout<<"Inside edege";
		cin>>m>>n;
		g.join(m,n);
	}
	queue q(2*i);
	q.insert(0);
	cout<<"BFS is->";
	while(!(q.isEmpty()))
	{
		int m = q.remove();
		cout<<m<<"  ";
		exp_unexp[m] = 1;
		arc* temp = g.ver[m].arc_point;
		while(temp!=NULL)
		{
		//	cout<<temp->point;
			if(exp_unexp[temp->point] == 0)
			{
			//	cout<<temp->point;
				exp_unexp[temp->point] = 1;
				q.insert(temp->point);
			}
			temp = temp->arc_point;
		}
	}
}
