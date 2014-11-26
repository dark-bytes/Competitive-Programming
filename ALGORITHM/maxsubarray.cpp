#include<iostream>
using namespace std;

int a[200];
int find_max_subarray(int[],int,int);
int find_cross(int[],int,int,int);


int main(){
	int n,i;
	cout<<"Enter length of array->";
	cin>>n;
	cout<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<find_max_subarray(a,0,n-1);
	return 0;
}


int find_max_subarray(int a[],int low,int high){
	if(low==high)
		return a[low];
	else{
		int mid=(low+high)/2;
		int left_sum=find_max_subarray(a,low,mid);
		int right_sum=find_max_subarray(a,mid+1,high);
		int cross_sum=find_cross(a,low,mid,high);
		if(left_sum>right_sum && left_sum>cross_sum)
			return left_sum;
		else if(right_sum>left_sum && right_sum>cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}


int find_cross(int a[],int low,int mid,int high){
	int left_sum=a[mid];
	int right_sum=a[mid+1];
	int sum=0;
	for(int i=mid;i>=low;i--){
		sum=sum+a[i];
		if(sum>left_sum){
			left_sum=sum;
		}
	}
	sum=0;
	for(int i=mid+1;i<=high;i++){
		sum=sum+a[i];
		if(sum>right_sum){
			right_sum=sum;
		}
	}
	return (left_sum+right_sum);
}
