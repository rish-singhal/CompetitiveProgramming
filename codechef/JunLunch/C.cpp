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


vector<LL> pr;
int n,x; 

LL sol(int d){
	int vv = x/d;
	vector<LL> mm(vv+1);
	if(d-1 < n && pr[d-1]<=(LL)vv){
		mm[pr[d-1]]++;
	}
	for(int i = 0; i < n; i++){
		if(i+d < n) {
			LL cnn = pr[i+d] - pr[i];
			if(cnn > (LL)vv) continue;
			mm[pr[i+d] - pr[i]]++;
		}
		else break;
	}

	LL ret = 0;
	forn(i,vv+1){
		ret += (mm[i])*1LL*mm[vv-i];
	}
	return ret;
}

void solve(){
	scanf("%d%d",&n,&x);
	pr.assign(n, 0);
	forn(i,n){
		scanf("%lld",&pr[i]);
		pr[i]+=(i>=1?pr[i-1]:0LL);
	}

	vector <int> div;
	for(int i = 1; i*i<= x; i++){
		if(x%i==0){
			div.pb(i);
			if(i*i != x) div.pb(x/i);
		}
	}
	LL an = 0;
	for(auto d: div){
		an += sol(d);
	}
	printf("%lld\n",an);
}

int main(){
  //fio();
  int t; scanf("%d",&t);
  while(t--){
  	solve();
  }
  return 0;
}