#include <bits/stdc++.h>
using namespace std;
int main() {
	set<pair<int,string>> s; 
	int N;
	cin>>N;

	for(int i =0 ; i < N ; i++){
		string s1;
		int marks;
		cin>>s1>>marks;
		s.insert({marks,s1});
	}

	for(int i =0 ; i < N ; i++){
		auto it = --s.end();
		cout<<it->second<<" "<<it->first;
		s.erase(it);
	}
}