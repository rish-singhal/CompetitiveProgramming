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
	vector<vector<int>> v(26);
	forn(i,s.size()){
		v[s[i]-'a'].pb(i);
	}
	int op = 1;	
	int pos = -1;
	forn(i,t.size()){
		//cout<<pos<<endl;
		if(v[t[i]-'a'].size()==0){
			cout<<-1<<endl;
			return;
		}
		auto ps = upper_bound(all(v[t[i]-'a']),pos);
		if(ps == v[t[i]-'a'].end()){
			ps = v[t[i]-'a'].begin();
			op++;
		}
		pos = *ps;
	}
	cout<<op<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
 	solve();
  }
  return 0;
}