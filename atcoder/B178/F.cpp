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
#define sz(x) ((LL)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  LL n; cin>>n;
  vector<LL> a(n), b(n), cnt(n+1,0 ), cnt2(n+1, 0);
  forn(i,n) cin>>a[i];
  forn(i,n) cin>>b[i];
  for(auto i:a) cnt[i]++;
  for(auto i:b) cnt2[i]++;

  vector<LL> p, po, cn(n+1, 0);

  LL ma = 0;

  for1(i, n){
  	LL dd  = min(cnt[i], cnt2[i]);
  	cn[i] = dd;
  	ma = max(cn[i], ma);
  	forn(j, dd) po.push_back(i);
  	forn(j, (cnt2[i] - dd)) p.push_back(i);
  }
  LL nn = sz(po);

  vector<LL> ps(nn);
  for(LL i = 0; i < sz(po); i++){
  	ps[i] = po[(i - ma + nn)%nn];
  }

  vector<LL> ann(n);
  int pp = 0, pp2 = 0;
  for(int i = 0; i < n; i++){
  	if(cn[a[i]]){
  		ann[i] = ps[pp++];
  		cn[a[i]]--;
  	}
  	else{
  		ann[i] = p[pp2++];
  	}
  	if(ann[i] == a[i]){
  		cout<<"No"<<endl;
  		return 0;
  	}
  }
  cout<<"Yes"<<endl;
  forn(i,n) cout<<ann[i]<<" ";
  	cout<<endl;
  return 0;
}