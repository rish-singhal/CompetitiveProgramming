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

vector<vector<int>> adj(MAXN);
vector<LL> v(MAXN);
LL su = 0;

void dfs(int i, int p, int h){
	if(i==1){
		su += v[i];
	}
	else if(h){
		su += v[i] - v[p];
		if(v[i] < v[p]){
			cout<<-1<<endl;
			exit(0);
		}
	}
	for(auto j:adj[i])
		if(j!=p)
			dfs(j, i, h^1);

}

void dfs2(int i, int p,int h){
	LL mm = 1e17;
	for(auto j:adj[i])
		if(j!=p) {
			dfs2(j, i, h^1);
			mm = min(v[j],mm);
		}
		
	if(!h && mm!=1e17){
		v[i] = mm;
		///cout<<"yyee"<<endl;
		if(adj[i].size()){
				su += mm - v[p];
				if(mm < v[p]){
					cout<<-1<<endl;
			exit(0);
				}
			}
	}
}



int main(){
  fio();
  int n; cin>>n;
  for1(i,n-1){
  	int x;
  	cin>>x;
  	adj[x].pb(i+1);
  	adj[i+1].pb(x);
  }

  for1(i,n) cin>>v[i];
  dfs2(1, -1, 1);
  dfs(1, -1, 1);
 // for1(i,n) cout<<v[i]<<" ";
 // cout<<endl;
  cout<<su<<endl;
  return 0;
}