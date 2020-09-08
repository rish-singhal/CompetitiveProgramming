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
  vector<int> a(n);
  forn(i,n) cin>>a[i];
  int inv = 0;
  bool same = 0;
  for(int i=0;i<n;i++)
    for(int j = 0; j<i; j++){
      if(a[j] > a[i]) inv++;
      if(a[j] == a[i]) same = 1;
    }
  if(inv %2 != 0 && !same){
    cout<<-1<<endl;
    return ;
  }
  vector<pair<int,int>> v;
  forn(i,n)
    v.emplace_back(a[i], i);
      sort(all(v));
  if(inv&1){
    bool ok = 0;
    for(int i=0;i<n;i++){
      for(int j = 0; j<i; j++){
        if(v[i].fi == v[j].fi){
             swap(v[i].se, v[j].se);
             ok = 1;
             break;
        }
      }
      if(ok) break;
    }
  }

  forn(i,n) a[v[i].se] = i;
  vector<int> pos;
  forn(i,n){
    while(i!=a[i]){
      int po = -1;
      forn(j,n) if(a[j]==i){
        po = j; break;
      }
      if((po-i)%2==0 || po == n-1){
        pos.pb(po-2);
        swap(a[po-2], a[po-1]);
        swap(a[po-2], a[po]);
      }
      else{
        pos.pb(po-1);
        swap(a[po-1], a[po]);
        swap(a[po-1], a[po+1]);
      }
    }
  }
  cout<<pos.size()<<endl;
  for(auto i:pos) cout<<i+1<<" ";
  cout<<endl;
  return;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
