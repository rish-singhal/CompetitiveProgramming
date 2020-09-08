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
const int MAXN = 4e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n; 
vector<vector<int>> adj(MAXN);
LL a[MAXN], b[MAXN];

vector <int> tp;
int in[MAXN], out[MAXN];
LL c1[MAXN], c2[MAXN];

LL an = 0;

void dfs(int i,int p=-1){
  tp.pb(i);
  if(p!=-1) a[i] = min(a[i],a[p]);
  in[i] = tp.size()-1;
  for(auto j:adj[i])
    if(j!=p) dfs(j,i);
  out[i] = tp.size()-1;
}

void dfs2(int i, int p=-1){
	if(b[i]==1) c1[i] = 1;
	if(b[i]==2) c2[i] = 1;
	//cout<<i<<" "<<endl;
	for(auto j:adj[i])
    	if(j!=p) {
    		dfs2(j,i);
    		c1[i]+=c1[j];
    		c2[i]+=c2[j];
    	}
    LL m = min(c1[i],c2[i]);
    an+=2*m*a[i];
    //
    c1[i]-=m;
    c2[i]-=m;
}

int main(){
  fio();
  cin>>n;
  //vector<pair<LL,LL>> od;
  int cnt = 0, cnt2 = 0;
  forn(i,n){
   	int x,y; cin>>a[i]>>x>>y;
   	b[i] = 0;
   	if(x!=y){
   		if(x==1){
   			b[i] =1;
   			cnt++;
   		}
   		else {
   			b[i] = 2;
   			cnt2++;
   		}
   	}	
   
  }
  //cout<<cnt<<" "<<cnt2<<endl;

  if(cnt!=cnt2){
  	cout<<-1<<endl;
  	return 0;
  }
  
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	u--, v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dfs(0);
  dfs2(0);
  cout<<an<<endl;
  return 0;
}