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
const LL inf = 1e18;

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

// 1, 2 -> 2, 1, 3,1,2

int main(){
  fio();
  LL a,b,c; cin>>a>>b>>c;
  LL n = a+b+c;
  vector<LL> v(n);
  forn(i,a){
  	LL x; cin>>x;
  	x--; v[x] = 0;
  }
  forn(i,b){
  	LL x; cin>>x;
  	x--; v[x] = 1;
  }
  forn(i,c){
  	LL x; cin>>x;
  	x--; v[x] = 2;
  }
  vector<vector<LL>> dp(n, vector<LL>(3,n));
  forn(i,n){
  	forn(j,3){
  		if(i==0) dp[i][j] = (LL)(v[i]!=j);
  		else{
  			if(j==0) dp[i][j] = dp[i-1][j] + (LL)(v[i]!=j);
  			else if(j==1) dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + (LL)(v[i]!=j);
  			else dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j-1]}) + (LL)(v[i]!=j);
  		}
  	}
  }
//  debug(dp);
  LL an = n;
  forn(i,3) an = min(an, dp[n-1][i]);
  an = min({an, a+b,b+c,a+c});
  cout<<an<<endl;
  return 0;
}