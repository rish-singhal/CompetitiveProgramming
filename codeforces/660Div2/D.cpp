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


vector<vector<LL>> adj(MAXN), radj(MAXN);
vector<LL> a(MAXN), b(MAXN);

int n,m, vis[MAXN];
vector <int> tp;

void dfs(int i){
  vis[i] = 1;
  for(auto v:adj[i]){
    if(!vis[v])  
      dfs(v);
  }
  tp.pb(i);
}
vector<LL> an;
LL ans = 0;
int mrk[MAXN];

// void dfs2(int i, int va){
// 	a[i] += va;
// 	vis[i] = 1;
// 	LL di = a[i];
// 	if(a[i] >= 0){
// 		an.pb(a[i]);
// 		ans += a[i];
// 		mrk[i] = 1;
// 	}
// 	else{
// 		di = 0;
// 	}
// 	for(auto v:adj[i]){
// 		dfs2(v, di);
// 	}
// }

int main(){
  fio();
  int n; cin>>n;
  for1(i,n) cin>>a[i];
  for1(i,n) {
  	cin>>b[i];
  	if(b[i]!=-1){
  		adj[i].pb(b[i]);
  		radj[b[i]].pb(i);
  	}
  }
  for1(i,n){
    if(!vis[i]) dfs(i);
  }
  reverse(tp.begin(),tp.end());
 // debug(tp);
  for(auto i:tp){
  	if(a[i] >=0 && !mrk[i]){
  		mrk[i] = 1;
  		for(auto v:adj[i]) a[v] += a[i];
  		an.pb(i);
  		ans += a[i];
  	}
  }
  reverse(tp.begin(),tp.end());
  for(auto i:tp){
  	if(!mrk[i]){
  		an.pb(i);
  		ans += a[i];
  	}
  }
  cout<<ans<<endl;
  for(auto i:an) cout<<i<<" ";
  	cout<<endl;
  return 0;
}