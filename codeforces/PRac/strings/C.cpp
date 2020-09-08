#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// array for permu
// autom for removal

int main(){
  fio();
  string s; cin>>s;
  string t; cin>>t;
 
  if (s.size()==t.size())
  {
  	vector<int> va(26,0);
  	for(auto i:s){
  		va[i-'a']++;
  	}
  	for(auto i:t){
  		va[i-'a']--;
  	}
  	forn(i,26){
  		if(va[i]!=0){
  			cout<<"need tree"<<endl;
  			return 0;
  		}
  	}
  	cout<<"array"<<endl;
  	return 0;
  }

  int l =0, r = 0;
  while(l<s.size() && r<t.size()){
  	if(s[l]==t[r]){
  		l++, r++;
  	}
  	else{
  		l++;
  	}
  }
  if(r==t.size()){
  	cout<<"automaton";
  	return 0;
  }

   vector<int> va(26,0);
  	for(auto i:s){
  		va[i-'a']++;
  	}
  	for(auto i:t){
  		va[i-'a']--;
  	}
  	forn(i,26){
  		if(va[i]<0){
  			cout<<"need tree"<<endl;
  			return 0;
  		}
  	}
  	cout<<"both"<<endl;

  return 0;
}