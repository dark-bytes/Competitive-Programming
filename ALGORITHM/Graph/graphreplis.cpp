#include<iostream>
#include<malloc.h>
using namespace std;

class graph{
	private:
	 	typedef struct node{
	 		int data;
	 		struct node* next;
	 	}NODE;
	 	NODE* a[100];
	 	int vertices;
	public:
		graph(int p){
			vertices=p;
			for(int i=0;i<p;i++){
				a[i]=NULL;
			}
		}
		void join_graph(int p,int q){
			insert_v(p,q);
		}
		
		void ver_conn(int p){
			NODE* temp=a[p];
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		
		void insert_v(int head,int to){
			NODE* temp;
			if(a[head]==NULL){
				temp=(NODE*)malloc(sizeof(NODE));
				a[head]=temp;
				temp->data=to;
				temp->next=NULL;
			}
			else{
				temp=a[head];
				while(temp->next!=NULL){
					temp=temp->next;
				}
				NODE* create=(NODE*)malloc(sizeof(NODE));
				temp->next=create;
				create->data=to;
				create->next=NULL;
			}
		}
	  
};

int main(){
	int i;
	int edges;
	cout<<"No. of edges";
	cin>>edges;
	cout<<"NO. of nodes u want to create";
	cin>>i;
	graph g(i);
	int p,q;
	for(int i=0;i<edges;i++){
		cin>>p>>q;
		g.join_graph(p,q);
	}
	cout<<"QUERIES";
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>p;
		g.ver_conn(p);
	}
	return 0;
}
