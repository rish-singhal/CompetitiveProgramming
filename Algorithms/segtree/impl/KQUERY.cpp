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


int n;

vector<int> bit;

void up(int v, int in){
	while(in <= n){
		bit[in] += v;
		in += in&-in;
	}
}

int qu(int in){
	int sum = 0;
	while(in>0){
		sum+=bit[in];
		in-=in&-in;
	}
	return sum;
}

struct query{
	int k, l, r, in;
};

int main(){
  fio();
  cin>>n;
  vector<pair<int,int>> v;
  bit.resize(2*n,0);
  for1(i,n){
  	int x; cin>>x;
  	v.pb({x,i});
  	up(1, i);
  }

  sort(all(v));
  int q; cin>>q;
  vector<query> qr;
  int cn = 0;
  while(q--){
  	int l,r,k; cin>>l>>r>>k;
  	qr.pb(query({k,l,r,cn}));
  	cn++;
  }
  sort(all(qr), [&](const query &a,const query &b){
  	return a.k<b.k;
  });
  vector<int> an(qr.size());
  cn = 0;
  for(auto i:qr){
  	while(v[cn].fi <= i.k && cn < n){
  		up(-1, v[cn].se);
  		cn++;
  	}
  	an[i.in] = qu(i.r) - qu(i.l-1);
  }
  for(auto i:an) cout<<i<<endl;
  return 0;
}