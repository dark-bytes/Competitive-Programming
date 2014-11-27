#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;


int flag;

typedef struct T{
	int word;
	int prefix;
	struct T* t[10];
}trie;

void initialize(trie* tp){
	tp->prefix = 0;
	tp->word = 0;
	for(int i = 0;i < 10;i++){
		tp->t[i] = NULL;
	}
}

void addword(trie* tp,string s)
{
//	cout<<tp;
//	cout<<tp->word;
	trie* q = tp;
	for(int i = 0;i <= s.length();i++)
	{
//		cout<<q->word;
		if(i == s.length()){
			q->word = q->word + 1;
//			cout<<q->word;
			if(q->prefix > 0)
				flag = 1;
		}
		else if(q->word >= 1){
//		cout<<"NO"<<endl;
			flag = 1;
			break;
		}
		else{
			q->prefix = q->prefix + 1;
		//	string::iterator it = s.begin();
			int n;
//		cout<<tp->prefix;
			n = s[i] - 48;
			if(q->t[n] == NULL){
		//	cout<<*it - 65<<" ";
			
				q->t[n] = (trie*)malloc(sizeof(trie));
				initialize(q->t[n]);
		//	cout<<tp->t[n]<<" ";
		//	cout<<*it<<" ";
		//		q = tp->t[n];
		//	cout<<q<<" "; 
			}
			//	s.erase(s.begin());
				q = q->t[n];
	//			cout<<q<<" ";
		//		cout<<s<<" "<<tp->t[n];
		}
	}
}


int main(){
	int tc;
	cin>>tc;
	
	while(tc--){
		string s;
		trie* tp = (trie*)malloc(sizeof(trie));
		tp->word = 0;
		tp->prefix = 0;	
		for(int i = 0;i < 10;i++){
			tp->t[i] = NULL;
		}
		int n;
		cin>>n;
		flag = 0;
//		trie* home = tp;	
		for(int i = 0;i < n;i++){
			cin>>s;
			if(flag == 0)
				addword(tp,s);
		}
		if(flag == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		free(tp);
	}	
}
