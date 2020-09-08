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
#define sz(x) ((int)x.size())
const int MAXN = 1e6 +5;
const LL INF = 1e17;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}


void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


LL n, m, A, B;
vector<vector<LL>> adj(MAXN);
vector<LL> cs;
vector<bool> chk;
vector<LL> val(n+1);

struct node	{
	LL v;
	node(LL val = INF): v(val){};
	void merge(const node& a, const node& b){
		v = min(a.v, b.v);
	}
};

vector<node> st;

LL b = 1;

void up(int in, LL va, bool cc = false) {
	in += b;
	if(!cc) st[in].v = min(st[in].v, va);
	else st[in].v = va;
	while(in) {
		st[in>>1].merge(st[in], st[in^1]);
		in >>= 1;
	}
}

LL qu(int in, int ql, int qr, int l = 0, int r = b-1) {
	if(ql > r || qr < l) return INF;
	if(ql <= l && r <= qr) return st[in].v;
	int m = (l+r)/2;
	return min(qu(in<<1, ql ,qr, l, m), qu(in<<1|1, ql, qr, m+1, r));
}

void dfs2(int u, int p) {
	for(auto i:adj[u]) {
		if(i!=p){
			dfs2(i, u);
			chk[u] = (chk[u] || chk[i]);
		}
	}
}

LL an = INF;

void dfs(int u, int p, LL h, LL ind) {
	//debug(u);
	LL ph = -1;
	if(h == 0) {
		up(0, 0);
	}
	else {
		LL r = h - 1;
		LL l = max(0LL, h - m);
		LL qval = qu(1, l, r);
		if(cs[u] && (qval!=INF)) cs[u] += qval;
		else cs[u] = INF;
		if(u == A){
			an = qval;
			return;
		}
		up(ind, cs[u]);
	}
	for(auto i:adj[u]){
		if(i==p) continue;
		if(chk[i]){
			ph = i;
			continue;
		}
		if(ind - 1 >= 0) dfs(i, u, h + 1, ind - 1);
	}
	if(ph != -1) dfs(ph, u, h + 1, ind + 1);
}

void solve(){
	cin>>n>>m>>A>>B;
	b = 1;
	while(b < n) b*=2;
	st.assign(2*b,node());
	cs.assign(n+1, INF);
	chk.assign(n+1, false);
	for1(i,n) adj[i].clear();
	for1(i,n){
		LL p; cin>>p>>cs[i];
		if(i!=1) {
			adj[i].pb(p);
			adj[p].pb(i);
		}
	}
	chk[A] = 1;
	dfs2(B, 0);
	dfs(B, 0, 0, 0);
	//debug(cs);
	if(an == INF) cout<<-1<<endl;
	else cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t) {
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}