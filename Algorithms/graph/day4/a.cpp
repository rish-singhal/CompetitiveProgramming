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
const LL INF = 1e18;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,m ;
LL d[26][26];

int main(){
  fio();
  cin>>n>>m;
  string s; cin>>s;
  forn(i,26) forn(j,26) d[i][j] = (i==j?0:INF); 
  forn(i,m){
    string a,b; LL c; cin>>a>>b>>c;
    auto &x = d[a[0]-'a'][b[0]-'a'] ;
    x = min(x,c);
  }
  LL dd[26][26];
  forn(k,26)
    forn(i,26)
      forn(j,26)
        if(d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  forn(i,26)
    forn(j,26)
    {
      dd[i][j] = (i==j?0:INF);
      forn(k,26){
        if(d[i][j] !=  INF && d[j][k] !=INF &&d[i][k] + d[j][k] < dd[i][j])
          dd[i][j] = d[i][k] + d[j][k];
      }
    }
  LL an = 0;
  forn(i,(n)/2)
  {
    LL z = dd[s[i]-'a'][s[n-i-1]-'a'];
    if(z==INF) cout<<-1<<endl, exit(0);
    an+=z;
  }
  cout<<an<<endl;
  return 0;
}

