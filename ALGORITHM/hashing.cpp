#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class hash{
	private:
		typedef struct node{
			int data;
			struct node* next;
		}NODE;
		vector<NODE*> a; 
	public:
		hash(int n){
			a.resize(n,NULL);
		}
		
		int hashing(int k){
			return k%9;
		}
		
		void insert(int element){
			NODE* temp;
			int index = hashing(element);
			if(a[index] == NULL){
				temp = (NODE*)malloc(sizeof(NODE));
				temp->data = element;
				temp->next = NULL;
				a[index] = temp;
			}
			else{
				NODE* temp = a[index];
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = (NODE*)malloc(sizeof(NODE));
				temp->next->data = element;
				temp->next->next = NULL;
			}
		}
		int search(int element){
			int index = hashing(element);
			NODE* temp_search = a[index];
			while(temp_search->next != NULL){
				if(temp_search->data == element){
					cout<<"Element founded";
					return 0;
				}
				temp_search = temp_search->next; 
			}
			if(temp_search == NULL)
				cout<<"Element Not founded";
			return 0;
		}
		
		int hash_delete(int element){
			int index = hashing(element);
			NODE* temp_delete = a[index];
			NODE* prev = a[index];
			if(a[index]->data == element){
				a[index] = a[index]->next;
				delete(temp_delete);
				cout<<"NUMBER DELETED";
				return 0;
			}
			while(temp_delete != NULL){
				if(temp_delete->data == element){
					prev->next = temp_delete->next;
					delete(temp_delete);
					cout<<"NUMBER DELETED";
					return 0;
				}
				prev = temp_delete;
				temp_delete = temp_delete->next; 
			}
			cout<<"NUMBER NOT FOUND";
			return 0;
		}
};

int main(){
	int n;
	cout<<"Enter Number of elements->";
	cin>>n;
	hash h(n);
	for(int i = 0;i < n;i++){
		int q ;
		cin>>q;
		h.insert(q);
	}
	int searchi;
	while(cin>>searchi){
		h.search(searchi);
	}
}
