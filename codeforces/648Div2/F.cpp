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

/*

1 2 3    4 5 6



*/

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<int> a(n),b(n);
  	multiset<int> ss, sp;
  	forn(i,n){
  		cin>>a[i];
  		ss.insert(a[i]);
  	}
  	forn(i,n){
  		cin>>b[i];
  		sp.insert(b[i]);
  	}
  	bool x = (ss==sp);
  	if(!x){
  		cout<<"No"<<endl;
  		continue;
  	}
  	if((n&1) && a[n/2] != b[n/2]){
  		cout<<"No"<<endl;
  		continue;
  	}
  	ss.clear(), sp.clear();
  	vector<pair<int,int>> aa,bb;
  	forn(i,n/2){
  		aa.pb({min(a[i], a[n-1-i]), max(a[i], a[n-1-i])});
  		bb.pb({min(b[i], b[n-1-i]), max(b[i], b[n-1-i])});
  	}
  	sort(all(aa));
  	sort(all(bb));
  	if(aa==bb) cout<<"Yes"<<endl;
  	else cout<<"No"<<endl;
  }
  return 0;
}