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

void solve(){
	string s,t; cin>>s>>t;
	vector <int> v[26];
	forn(i,s.size()){
		v[s[i]-'a'].pb(i);
	}
	int cur = 0, an = 1;
	for(auto i:t){
		if(v[i-'a'].size()==0){
			cout<<-1<<endl;
			return;
		}
	}
	for(auto i:t){
		int z = i-'a';
		auto kk = lower_bound(all(v[z]),cur);
		if(kk!=v[z].end()){
			cur = v[z][kk-v[z].begin()]+1;
		}
		else{
			an++;
			cur = v[z][0]+1;
		}
	}
	cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}