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
const int MAXN = 2e3 +5;

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

vector<pair<pair<LL,LL>,pair<int,int>>> vv;

int n,k;
LL p; 

bool chk(LL t){
	vector<int> vis(n,0), vis2(k,0);
	int cnt = 0;
	for(auto i:vv){
		if(i.fi.fi > t) continue;
		if(vis[i.se.fi] || vis2[i.se.se]) continue; 
		cnt ++;
		vis[i.se.fi]=  vis2[i.se.se] = 1;
	}
	//debug(t,cnt);
	return cnt==n ;
}
int main(){
  fio();
  cin>>n>>k>>p;
  vector<LL> a(n),pp(k);
  forn(i,n){
  	cin>>a[i];
  }
  sort(all(a));
  LL kk = 0;
  forn(i,k){
  	cin>>pp[i];
  }
  sort(all(pp));
  forn(i,k){
  	forn(j,n){
  		LL dis = abs(pp[i]-a[j]) + abs(pp[i]-p);
  		kk = max(kk, dis);
  		vv.pb({{dis,abs(pp[i]-a[j])}, {j,i}});
  	}
  }
  LL l = 0, r = kk;
  while(l<r){
  	LL m = (l) + (r-l)/2;
  	if(chk(m)){
  		r = m;
  	} 
  	else l = m+1;
  }
  cout<<l<<endl;
  return 0;
}