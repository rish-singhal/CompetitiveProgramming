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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int sz[MAXN][26];
int dsu[MAXN];

int pa(int i)
{
  return dsu[i] < 0? i: dsu[i] = pa(dsu[i]);
}

void join(int u, int v){
  //cout<<u<<" "<<v<<endl;
  u = pa(u), v= pa(v);
  if(u==v) return;
  if(dsu[u] > dsu[v]) swap(u,v);
  dsu[u]+=dsu[v];
  dsu[v] = u;
  forn(i,26){
    sz[u][i]+=sz[v][i];
  }
  //cout<<dsu[u]<<" "<<u<<" "<<v<<endl;

}

LL max(LL a, LL b){
  return a>b? a:b;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    forn(i,n+5) dsu[i] = -1;
    forn(i,s.size()){
      forn(j,26) sz[i][j] =0;
      sz[i][s[i]-'a']++;
    }
   // forn(i,n) {
    //  forn(j,26) cout<<sz[i][j]<<" ";
     // cout<<endl;
   // }
    for(int i=0;i<n;i++){
      if(i+k>=n) break;
      join(i,i+k);
    }
    for(int i=0;i<n;i++)
      join(i,n-i-1);
    LL an = 0;
    for(int i=0;i<n;i++){
      if(dsu[i]>=0) continue;
      an-=dsu[i];
 //     cout<<i<<" "<<dsu[i]<<" --- "<<endl;
      LL kk = 0;
      forn(j,26){
//        cout<<sz[i][j]<<" "<<endl;
        kk = max(kk, sz[i][j]);
      }
      an-=kk;
    }
    cout<<an<<endl;
  }
  return 0;
}

