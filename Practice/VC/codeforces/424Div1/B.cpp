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


set<int> adj[MAXN];

vector<int> tr;
int b = 1;

int qu(int in, int ql ,int qr, int l=0 , int r=b-1){
	if(ql > r || qr < l) return 0;
	if(ql<= l && r<=qr) return tr[in];
	int m = (l+r)/2;
	return qu(in*2, ql, qr, l,m)+ qu(in*2+1, ql, qr, m+1,r);
}

void up(int in, int v){
	in+=b;
	tr[in] = v;
	while(in){
		tr[in>>1] = tr[in]+tr[in^1];
		in>>=1;
	}
}

int main(){
  fio();
  int n; cin>>n;
  while(b<=n) b*=2;
  tr.resize(2*b,0);
  vector<int> v(n);
  vector<int> vv(n);
  forn(i,n){	
  	cin>>v[i];
  	adj[v[i]].insert(i);
  	vv[i] = v[i];
  	tr[i+b] = 1;
  }
  for(int i = b-1; i>=0; i--)
  	tr[i] = tr[i<<1|1]+tr[i<<1];
  sort(all(vv));
  int pos = 0;
  LL an= 0;
  forn(i,n){
  	int nv = vv[i];
  	auto x = adj[nv].lower_bound(pos);
  	if(x == adj[nv].end()){
  		x = adj[nv].begin();
  	}
  	int pp = *x;
  	//debug(pp);
  	adj[nv].erase(x);
  	if(pp >= pos){
  		int nc = qu(1,pos, pp);
  		an+=nc;
  	}
  	else{
  		int nc = qu(1, pos, n-1);
  		nc += qu(1, 0, pp);
  		an+=nc;
  	}
  	up(pp,0);
  	//debug(an);
  	pos = pp;
  }
  cout<<(an)<<endl;
  return 0;
}