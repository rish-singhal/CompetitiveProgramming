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
const int MAXN = 1e6 +5;
const LL M  = 1e9+7;

int prime[MAXN];
vector< vector<pair<LL,LL> > > pr(MAXN+5);

int l[MAXN], r[MAXN];
int ID[(MAXN<<1) + 5],VAL[MAXN];
bool VIS[MAXN];
LL incnt[MAXN];

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%M;
	if(n&1) return an*a%M;
	return an;
}

int mxcnt = 0, cur = 0;
void precalc() 
{ 
    for (int i = 2; i * i < MAXN; ++i) 
    { 
        if (!prime[i]) 
            for (int j = i * i; j < MAXN; j += i) 
                prime[j] = i; 
    } 
    for (int i = 1; i < MAXN; ++i) 
        if (!prime[i]) 
            prime[i] = i; 

    for (int i=2; i < MAXN; ++i) 
    { 
        int element = i;
        while (element > 1) 
        { 
            int div = prime[element]; 
            int cnt = 0;
            while (element % div==0) 
                {	cnt++;
                	element /= div; 
                }
            mxcnt = max(mxcnt,cnt);
            if(cnt) pr[i].pb({div,cnt});
        } 
    } 
    forn(i,MAXN){
    	incnt[i] = po((1+i),M-2);
    }
} 


int D;
struct Query
{
    int l, r, lc, idx;
    bool operator<(const Query& a) const
    {
        return (l-1)/D<(a.l-1)/D||(l-1)/D==(a.l-1)/D && r<a.r;
    };
};


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<vector<LL> > adj(MAXN);
vector<LL> val(MAXN);


int par[MAXN][30] ,ds[MAXN];
int lgn, n;

void dfs(int u, int p=-1, int d = 0){
   l[u] = ++cur; 
   ds[u] = d;
   ID[cur] = u;
  if(p!=-1) par[u][0] = p;
  for(int i=1;i<=lgn;i++)
    par[u][i] = par[par[u][i-1]][i-1];
  for(auto &v:adj[u]){
    if(v!=p)
      dfs(v,u,d+1);
  }
  r[u] = ++cur; ID[cur] = u;
}

int mov(int u, int k){
  for(int i=0;i<=lgn;i++)
    if(k>>i&1) u = par[u][i];
  return u;
}

int lca(int u, int v){
  if(ds[u] > ds[v]) swap(u,v);
  v = mov(v,ds[v]-ds[u]);
  if(u==v){
    return u;
  }
  for(int i=lgn;i>=0;i--){
    if(par[u][i]!=par[v][i]){
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

LL res = 1;
LL pcnt[MAXN];

void add(LL x)
{
    for(auto pp :pr[x]){
    	res = (res* incnt[pcnt[pp.fi]])%M;
    	pcnt[pp.fi]+=pp.se;
    	res = (res*((1+pcnt[pp.fi])%M))%M;
    }
}
void remove(LL x)
{
   for(auto pp :pr[x]){
    	res = (res* incnt[pcnt[pp.fi]])%M;
    	pcnt[pp.fi]-=pp.se;
    	res = (res*((1+pcnt[pp.fi])%M))%M;
    }
}



inline void check(LL x){
	// If (x) occurs twice, then don't consider it's value 
	if ((VIS[x]) and (--VAL[val[x]] == 0) ) {
		remove(val[x]);
	}
	else if ((!VIS[x]) and (VAL[val[x]]++ == 0) ) {
		add(val[x]);
	}
	VIS[x] ^= 1;
}

void clear(){
	cur = 0;

//int l[MAXN], r[MAXN];
//int ID[MAXN<<1],VAL[MAXN];
	forn(i,MAXN){
		VIS[i] = 0;
		VAL[i] = 0;
		ds[i]= 0;
		adj[i].clear();
		pcnt[i] = 0;
		res = 1;
		l[i] = r[i] = ID[i] = 0;
		ID[MAXN+i]=0;
		forn(j,31) par[i][j]=0;
	}
}

void solve(){
	cin>>n;
	D = sqrt(2*n);
	lgn = 32 - __builtin_clz(n);
	clear();
	forn(i,n-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	for1(i,n) cin>>val[i];
	int q; cin>>q;
	vector<Query> Q(q);
	forn(i,q){
		int u,v; cin>>u>>v;
		Q[i].lc = lca(u, v);
		if (l[u] > l[v]) swap(u, v);
		if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
		else Q[i].l = r[u], Q[i].r = l[v];
		Q[i].idx = i;

	}
	sort(all(Q));
  /// solve
	int ll = Q[0].l, rr = Q[0].l-1; 
	vector<LL> an(Q.size());
	forn(i,Q.size()){
		while (ll < Q[i].l) check(ID[ll++]);
		while (ll > Q[i].l) check(ID[--ll]);
		while (rr < Q[i].r) check(ID[++rr]);
		while (rr > Q[i].r) check(ID[rr--]);
		int u = ID[ll], v = ID[rr];
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
		an[Q[i].idx] = res;
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
	}
	for(auto i:an) cout<<i<<" ";
		cout<<endl;
}

int main(){
  fio();
  precalc();
//cout<<1<<endl;
int t; cin>>t;
while(t--){
    solve();
}
  return 0;
}