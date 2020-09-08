#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)

const int MAXN = 1e4 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//  freopen("RANK.IN", "rt", stdin);
 // freopen("RANK.OUT", "w", stdout);
}

vector <vector <int> > adj(MAXN);
int n,m;
vector <int> an, vis(MAXN,0), act(MAXN,0);

void dfs(int i){
    if(act[i]) {
      cout<<0<<endl;
      exit(0);
    }
    act[i]=1;
    for(auto x:adj[i])
      if(!vis[x]) dfs(x);
    act[i] = 0;
    vis[i] =1;
    an.pb(i);
}

void parse(){
  string s; cin>>s;
  int k=0;
  int x[3]={0,0,0};
  string ss = ">,";
  int b = 0;
  for(auto i: s){
    if(i==' ') continue;
    if(ss.find(i)==string::npos){
      x[k]*=10;
      x[k]+=i-'0';
    }
    else{
      k++;
      if(i=='>') b=k;
    }
  }
  if(b==1){
    adj[x[2]].pb(x[0]);
    adj[x[1]].pb(x[0]);
  }
  else{
    adj[x[2]].pb(x[0]);
    adj[x[2]].pb(x[1]);
  }
}

int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
    parse();
 }
  for1(i,n) if(!vis[i]) dfs(i);
  for(auto i:an) cout<<i<<" ";
  cout<<endl;
  return 0;
}

