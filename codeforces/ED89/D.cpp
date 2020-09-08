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
const int MAXN = 1e7 +5;

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


vector<LL> prime;
bool comp[MAXN];
LL f[MAXN];

/*
	mu(p) = -1; 
	mu(p*p*..) = 0,
*/

void sieve(){
	fill(comp, comp + MAXN, 0);
	f[1] = 1;
	for(LL i = 2; i < MAXN; i++){
		if(!comp[i]){
			prime.pb(i);
			f[i] = i;
		}
		for(auto p:prime){
			if(p*i>MAXN) break;
			comp[p*i] = 1;
			if(i%p == 0){
				f[i*p] = f[i];
				break;
			}
			f[i*p] = p;
		}
	}
}



int main(){
  fio();
  sieve();
  int n; cin>>n;
  vector<LL> a;
  vector<LL> b;
  //for1(i,10) cout<<f[i]<<" ";
  //cout<<endl;
  forn(i,n){
  	LL x; cin>>x;
  	LL zz =x;
  	vector<LL> v;
  	while(x!=1){
  		v.pb(f[x]);
  		int y = f[x];
  		while(x%y==0){
  			x /= y;
  		}
  	}
  	//debug(zz,v);
  	if(v.size()<=1){
  		a.pb(-1);
  		b.pb(-1);
  	}
  	else{
  		LL an = 1;
  		for1(i,v.size()-1)
  			an*=v[i];
  		a.pb(v[0]);
  		b.pb(an);

  	}
  }
  for(auto i:a) cout<<i<<" ";
  cout<<endl;
for(auto i:b) cout<<i<<" ";
	cout<<endl;
  return 0;
}