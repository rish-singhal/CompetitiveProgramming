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
const int MAXN = 1e5 +5;
const LL inf = 1e18;
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


int main(){
  fio();
  LL n; cin>>n;
  vector<pair<LL,LL>> v(n); 
  vector<LL> c(n);
  forn(i,n){
  	cin>>v[i].fi>>v[i].se>>c[i];
  }
  vector<LL> ans(n+1, inf);
  LL con = pow(3,n);
  for(LL msk = 0 ; msk < con; msk++){
  	int in = 0;
  	set<LL> x, y;
  	x.insert(0);
  	y.insert(0);
  	LL nmsk = msk;
  	for(LL i = 0; i < n; i++){
  		LL xy = nmsk%3;
  		if(xy == 1){
  			x.insert(v[i].fi);
  		}
  		else if(xy == 2){
  			y.insert(v[i].se);
  		}
  		if(xy) in++;
  		nmsk /= 3;
  	}
  	//debug(x,y);
  	LL an = 0;
  	for(LL i = 0; i < n; i++){
  		auto ax = x.upper_bound(v[i].fi);
  		LL valx = inf;
  		
  		if(ax==x.end()){
  			ax--;
  			valx = abs((*ax)-v[i].fi);
  		}
  		else if(ax == x.begin()){
  			valx = abs((*ax)-v[i].fi);
  		}
  		else {
  			auto axx = ax;
  			ax--;
  			valx = min(abs((*axx)-v[i].fi), abs((*ax)-v[i].fi));
  		}

  		auto ay = y.upper_bound(v[i].se);
  		LL valy = inf;
  		if(ay==y.end()){
  			ay--;
  			valy = abs((*ay)-v[i].se);
  		}
  		else if(ay == y.begin()){
  			valy = abs((*ay)-v[i].se);
  		}
  		else{
  			auto ayy = ay;
  			ay--;
  			valy = min(abs((*ayy)-v[i].se), abs((*ay)-v[i].se));
  		}
  		an += min(valy, valx)*c[i];
  	}
  	ans[in] = min(ans[in], an);
  }
  for(auto i:ans) cout<<i<<endl;
  return 0;
}