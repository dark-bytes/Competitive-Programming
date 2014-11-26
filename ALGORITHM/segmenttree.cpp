/*

	Creation of segment tree
	Author : Sudhanshu Singh
	Created : 27/07/2014

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void makSegtre(int node,int start,int end,vector<int> list,int max[]){

	if(start == end)
		max[node] = start;                   //End condition for Segment tree
	
	else{
		int mid = (start + end)/2;
		makSegtre(2*node,start,mid,list,max);
		makSegtre(2*node + 1,mid + 1,end,list,max);
		
		if(list[max[2*node]] >= list[max[2*node + 1]])
			max[node] = max[2*node];
		else
			max[node] = max[2*node + 1];
	}
}

int query(int i,int j,int node,int start,int end,vector<int> a,int max[]){
	
	if(i > end || j < start)
		return -1;
	else if(i <= start && j >= end){
		return max[node];
	}
	else{
		int p1 = query(i,j,2*node,start,(start + end)/2,a,max);
		int p2 = query(i,j,2*node + 1,(start + end)/2 + 1,end,a,max);
		
		if(p1 == -1)
			return p2; 
		else if(p2 == -1)
			return p1;
		else if(a[p1] >= a[p2])
			return p1;
		return p2;
	}
}

void update(int position,int node,int start,int end,vector<int> a,int max[]){
	if(a[position] >= a[max[node]])
		max[node] = position;
	if(position < (start + end)/2 + 1){
		update(position,2*node,start,(start + end)/2,a,max);
	}
	else if(position > (start + end)/2 + 1){
		update(position,2*node + 1,(start + end)/2 + 1,end,a,max);
	}
	else if(start == end){
		
	}
}

int main(){
	int noElement;
	cin>>noElement;
	vector<int> list(noElement);
	for(int i = 0;i <noElement;i++){
		cin>>list[i];
	}
	int size_element = 2*2*(log(noElement)/log(2)) + 1;
	int max[100] = {-1};
	makSegtre(1,0,noElement - 1,list,max);
	
	cout<<"Total queries"<<endl;
	int q;
	cin>>q;
	
	for(int i = 0;i < q;i++){
		int k,l;
		cin>>k>>l;
		int p1 = query(k,l,1,0,noElement - 1,list,max);
		cout<<list[p1];
	}
	
	for(int i = 1;i <= 10;i++)
		cout<<max[i];
	return 0;
}
