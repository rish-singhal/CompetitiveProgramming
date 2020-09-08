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
	int n; cin>>n;
  	string a,b; cin>>a>>b;
  	vector<int> pos(26,-1);
  	vector<vector<int>> v(26);
  	forn(i,n) pos[a[i]-'a'] = i;
  	forn(i,n){
  		if(b[i]!=a[i]){
  			if(b[i]>a[i]){
  				cout<<-1<<endl;
  				return;
  			}
  			v[b[i]-'a'].pb(i);
  		}
  	}
  	vector<vector<int>> an;
  	forn(i,26){
  		if(v[i].size()==0) continue;
  		if(pos[i]==-1){
  			cout<<-1<<endl;
  			return;
  		}
  		vector<int> vv;
  		for(auto j:v[i])
  			vv.pb(j);
  		vv.pb(pos[i]);
  		an.pb(vv);
  	}
  	reverse(all(an));
  	cout<<an.size()<<endl;
  	forn(i,an.size()){
  		cout<<an[i].size()<<" ";
  		for(auto j:an[i]){
  			cout<<j<<" ";
  		}
  		cout<<endl;
  	}
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}