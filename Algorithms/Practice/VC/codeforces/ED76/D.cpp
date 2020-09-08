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
  int t; cin>>t;
  while(t--){
  	int n ;cin>>n;
  	vector<int> mon(n);
  	forn(i,n) cin>>mon[i];
  	int m; cin>>m;
  	map<int,int> mp;
  	forn(i,m){
  		int p, e; cin>>p>>e;
  		mp[p] = max(mp[p],e);
  	}
  	vector<int> pp;
  	vector<int> ee;
  	for(auto i:mp){
  		pp.pb(i.fi);
  		ee.pb(i.se);
  	}
  	int sz = pp.size();
  	for(int i = sz-2; i>=0; i--)
  		{
  			ee[i] = max(ee[i+1],ee[i]);
  			mp[pp[i]] = ee[i];
  		}

  	int po = 0;
  	int en = 0;
  	int b = 0;
  	int an = 1;
  	forn(i,n){	
  		int npo = max(po, mon[i]);
  		int nen = en+1;

  		b |= (lower_bound(all(pp),mon[i])==pp.end());
  		if(b==1) break;
  		auto x = lower_bound(all(pp),npo);
  		if(x!=pp.end() && mp[*x]>=nen){
  			po = npo;
  			en = nen;
  		}
  		else{
  			an++;
  			po = mon[i];
  			en = 1;
  		}
  		//debug(po, en);
  	}
  	if(b==1) cout<<"-1"<<endl;
  	else cout<<an<<endl;
  }
  return 0;
}