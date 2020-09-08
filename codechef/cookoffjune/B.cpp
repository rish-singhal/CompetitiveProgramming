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


LL gcd(LL a, LL b){
	return b==0?a:gcd(b, a%b);
}

LL vis[MAXN];
vector<vector<LL>> adj(MAXN);
vector<vector<LL>> co(MAXN);

void dfs(LL a, LL c){
	co[c].pb(a);
	vis[a] = 1;
	for(auto j:adj[a]){
		if(!vis[j]) dfs(j,c);
	}
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL n,m; cin>>n>>m;
  	vector<LL> a(n), b(n);
  	forn(i,n){
  		vis[i]= 0;
  		adj[i].clear();
  		co[i].clear();
  	}
  	vector<pair<LL,LL>> vv;
  	map<pair<LL,LL> , vector<LL>> mk;
  	forn(i,n) cin>>a[i];  	
  	forn(i,n) cin>>b[i];
  	forn(i,n){
  		LL k = gcd(a[i],b[i]);
  		vv.pb({a[i]/k, b[i]/k});
  		mk[{a[i]/k, b[i]/k}].pb(i);
  	}
  	sort(all(vv), [&](pair<LL,LL> &a,pair<LL,LL> &b){
  		return a.fi*b.se < a.se*b.fi;
  	});
  	vector<LL> mp(n+1);
  	for(auto i:mk[vv[vv.size()-1]]){
  		mp[i] = 1;
  	}

  	forn(i,m){
  		LL u, v; cin>>u>>v;
  		u--,v--;
  		if(mp[u] && mp[v]){
  			adj[u].pb(v);
  			adj[v].pb(u);
  		}
  	}
  	int col = 0;
  	forn(i,n){
  		if(!vis[i] && mp[i]) dfs(i, col++);
  	}
  	LL ma = 0;
  	LL coo = 0;
  	forn(i,col){
  		LL pp = (LL)co[i].size();
  		if(ma < pp ){
  			coo = i;
  			ma = pp;
  		}
  	}
  	cout<<ma<<endl;
  	for(auto i:co[coo]) cout<<(i+1)<<" ";
  		cout<<endl;
  }

  return 0;
}