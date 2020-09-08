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
const LL INF = 1e17;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void cmin(LL &a, LL &b){
	a = min(a,b);
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
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<LL> v(n);
  	LL an = 0;
  	forn(i,n){
  		 cin>>v[i];
  		 if(i%2==0) an+=v[i];
  	}
  	LL dp[n][3];
  	forn(i,n) forn(j,3) dp[i][j] = 0;
  	dp[0][0] = v[0];
  	dp[0][1] = 0;
  	dp[0][2] = v[0];
  	for1(i,n-1){
  		if(i%2==0) {
  			if(i>=2) dp[i][0] = dp[i-2][0] + v[i];
  			if(i>=3) dp[i][2] = max({dp[i-3][1], dp[i-2][0], dp[i-2][2]}) + v[i];
  			if(i==2) dp[i][2] = max({dp[i-2][0], dp[i-2][2]}) + v[i];
  			//if(i==1) dp[i][2] = dp[i-1][1] + v[i];
  		}
  		else{
  			if(i==1 && i+1<n) dp[i][1] = dp[i-1][0] + v[i];
  			if(i>=2 && i+1<n) dp[i][1] = max({dp[i-2][1],dp[i-1][0]}) + v[i];
  			//else if(i>=2) dp[i][1] = dp[i-2][1] + v[i];
  		}
  		forn(j,3)
  			an = max(an, (LL)dp[i][j]);
  	} 
  	forn(i,n){
  		forn(j,3)
  		an = max(an, (LL)dp[i][j]);
  	}
  	reverse(all(v));
  	forn(i,n) forn(j,3) dp[i][j] = 0;
  	dp[0][1] = v[0];
  	dp[0][0] = 0;
  	dp[0][2] = 0;
  	for1(i,n-1){
  		if(i%2==1) {
  			if(i>=2) dp[i][0] = dp[i-2][0] + v[i];
  			if(i>=3) dp[i][2] = max({dp[i-3][1], dp[i-2][0], dp[i-2][2]}) + v[i];
  			if(i==2) dp[i][2] = max({dp[i-2][0], dp[i-2][2]}) + v[i];
  			//if(i==1) dp[i][2] = dp[i-1][1] + v[i];
  		}
  		else{
  			if(i==1 && i+1<n) dp[i][1] = dp[i-1][0] + v[i];
  			if(i>=2 && i+1<n) dp[i][1] = max({dp[i-2][1],dp[i-1][0]}) + v[i];
  			//else if(i>=2) dp[i][1] = dp[i-2][1] + v[i];
  		}
  	} 
  	forn(i,n){
  		forn(j,3)
  		an = max(an, (LL)dp[i][j]);
  	}
  	cout<<an<<endl;
  }
  return 0;
}