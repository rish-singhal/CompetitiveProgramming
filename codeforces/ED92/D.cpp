#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	pair<LL,LL> v[2];
  	vector<pair<LL,LL>> p, q;
  	cin>>p.fi>>p.se;
	cin>>q.fi>>q.se;
	LL pv = 0 , cs = 0;
	if(q.fi < p.fi){
		swap(q, p);
	}
	if(q.se >= p.fi && p.se >= q.se){
		k -= n*(q.se - p.fi);
		pv = p.fi - q.fi +  p.se - q.se;
	}
	else if(q.se >= p.fi && p.se <= q.se){
		k -= n*(p.se - p.fi);
		pv = p.fi - q.fi +  q.se - p.se;
	}
	else if(p.fi >= q.se){
		cs = p.fi - q.se;
		pv = p.se - q.fi;
	}
	if(k <= 0){
		cout<<0<<endl;
	}
	
  }
  return 0;
}