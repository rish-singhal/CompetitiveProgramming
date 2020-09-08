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


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n,m; cin>>n>>m;
  vector<vector<int>> adj(n);
  vector<int> c(n);
  forn(i,m){
  	int u,v; cin>>u>>v;
  	u--,v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  c[0] = 1;
  vector<int> cn(4);
  int k = 0;
  for(auto i:adj[0])
  	{
  		c[i] = 2;
  		k = i;
  		cn[2] ++;
  	}
  //debug(k);
  //debug(adj[k]);
  for(auto i:adj[k]){
  	if(c[i]==2) {
  		c[i] = 3;
  		cn[3]++;
  		cn[2]--;
  	//	cout<<"yy"<<endl;
  	}
  }
  cn[1] = n - cn[2] - cn[3];
  if(cn[1]*cn[2] + cn[1]*cn[3] + cn[3]*cn[2] != m || cn[1]<=0 || cn[2]<=0 || cn[3]<=0){
  	cout<<-1<<endl;
  	return 0;
  }
 // debug(cn);
 // debug(c);
  forn(i,n) c[i] = max(1,c[i]);
  forn(i,n){
  	//if(~c[i]) c[i] = 1;
  	int cnt = 0;
  	for(auto j:adj[i]){
  		if(c[j]==c[i]){
  			//debug(adj[i]);
  			//debug(i, j);
  			cout<<-1<<endl;
  			return 0;
  		}
  		cnt++;
  	}
  	if(cnt + cn[c[i]]!=n){
  		cout<<-1<<endl;
  			return 0;
  	}
  }
  forn(i,n) cout<<c[i]<<" ";
  cout<<endl;
  return 0;
}