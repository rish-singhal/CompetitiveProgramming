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
const LL mo = 998244353;
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
  int n, m; cin>>n>>m;
  vector<LL> a(n),aa(n);
  vector<LL> b(m);
  forn(i,n) {
  	cin>>a[i];
  	aa[i] = a[i];
  }
  forn(i,m) cin>>b[i];
  reverse(all(a));
  vector<int> in;
  for1(i,n-1){
  	a[i] = min(a[i], a[i-1]);
  }
  //reverse(all(a));
  //debug(a);
  LL an = 1;
  reverse(all(aa));
  reverse(all(b));
  int cnt = 0;
  forn(i,m){
  	int pp =-1;
  	int p2 = -1;
  	while(a[cnt]>=b[i] && cnt<n){
  		if(aa[cnt]==b[i] && pp==-1) pp=cnt;
  		if(aa[cnt]==b[i]) p2 = cnt;
  		cnt++;
  	}
  	if(pp==-1){
  		cout<<0<<endl;
  		return 0;
  	}
  	//cout<<(p2)<<" "<<pp<<endl;
  	an = (an*(p2-pp+1))%mo;
  	//cnt--;
  }
//  cout<<cnt<<endl;
  if(a[n-1]!=b[m-1]) cout<<0<<endl;
  else
  cout<<an<<endl;
  return 0;
}