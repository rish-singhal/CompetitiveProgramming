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
const int MAXN = (1<<11) +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n;
vector <vector <int> > adj(MAXN);
vector<int> tp;
int vis[MAXN], comp[MAXN];

void dfs(int i){
	vis[i] = 1;
	for(auto j:adj[i])
		if(!vis[j]) dfs(j);
	tp.pb(i);
}

void dfs2(int i, int c){
	comp[i] = c;
	for(auto j:adj[i])
		if(!comp[j]) dfs2(j, c);
}

int check_2sat(){
	tp.clear();
	forn(i,2*n) vis[i]=comp[i]=0;
	forn(i,2*n){
		if(!vis[i]) dfs(i);
	}
	int cc = 0;
	for(auto i:vector<int>(tp.rbegin(), tp.rend())){
		if(!comp[i]) dfs2(i,++cc);
	}
	for(int i=0;i<n;i++){
		if(comp[i<<1]==comp[i<<1|1]){
			return 0;
		}
	}
	return 1;
}

int xx(int i){
	return 2*i;
}

int cx(int i){
	return 2*i+1;
}

void addxor(int a, int b){
	//cout<<"xor"<<"--"<<endl;
	adj[cx(a)].pb(xx(b));
	adj[cx(b)].pb(xx(a));
	adj[xx(a)].pb(cx(b));
	adj[xx(b)].pb(cx(a));
}

void addinv(int a, int b){
	//cout<<"inv"<<"--"<<endl;
	adj[cx(a)].pb(cx(b));
  	adj[cx(b)].pb(cx(a));
  	adj[xx(a)].pb(xx(b));
  	adj[xx(b)].pb(xx(a));
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	cin>>n;
  	int ann = 1;
  	forn(i,MAXN) {
  		adj[i].clear();
  	}
  	int a[MAXN][MAXN], b[MAXN][MAXN]; 
  	forn(i,n) forn(j,n) cin>>a[i][j];
  	forn(i,n) forn(j,n) cin>>b[i][j];
  	forn(i,n){
  		forn(j,n){
  			if(a[i][j]==b[i][j] && a[j][i]==a[i][j] && b[i][j]==b[j][i])
  				{
            continue;
          }
  			if(a[i][j]==b[i][j] && a[j][i]==b[j][i])
  					{
              addinv(i,j);
              continue;
            }
  			if(a[j][i]==b[i][j] && a[i][j]==b[j][i])
  					{ addxor(i,j); continue;
            }

  				cout<<"No\n";
  				ann = 0;
  				break;
  		}
      if(ann==0)break;
    }
  	if(ann==0) continue;
  	cout<<(check_2sat()?"Yes\n":"No\n");
  }
  return 0;
}