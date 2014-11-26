#include<iostream>
using namespace std;
int comp=0;
int n;

int quicksort(int a[],int f,int l,int b[]){
	int pivot=a[f];
	int boundary=f+1;
	for(int i=f+1;i<l;i++){
		if(a[i]<pivot){
			//swap(a[boundary],a[i]);
			int temp;
			temp=a[boundary];
			a[boundary]=a[i];
			a[i]=temp;
			
			temp=b[boundary];
			b[boundary]=b[i];
			b[i]=temp;
			boundary++;
		}
	}
	//swap(&a[boundary-1],&a[f]);
	int temp;
	temp=a[boundary-1];
	a[boundary-1]=a[f];
	a[f]=temp;

	temp=b[boundary-1];
	b[boundary-1]=b[f];
	b[f]=temp;
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}

			
	return (boundary-1);
}

void partition(int a[],int first,int last,int b[])
{
	
	if(first<last){
		int p=quicksort(a,first,last,b);
		comp=comp+p-2-first;
		partition(a,first,p-2,b);
		comp=comp+last-p;
		partition(a,p,last,b);
	}
//	else
//		return;
}

int main()
{
	int a[100];
	int b[100];
//	int n;
	int q;
//	while(cin>>q){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=i;
	}
	comp=comp+n-1;
	partition(a,0,n,b);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<b[i]<<"  ";
	}
	cout<<"\nNo of comparison->"<<comp;
//	}
}
