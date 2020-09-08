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


void takeinput(vector<LL> &v, int n, int k){
	forn(i,k) cin>>v[i];
	LL a, b, c, d; cin>>a>>b>>c>>d;
	a %= d, b%= d, c%=d;
	for(int i = k; i < n; i++){
		v[i] = c;
		v[i] = (v[i] + (b*(v[i-1])%d)%d)%d;
		v[i] = (v[i] + (a*(v[i-2])%d)%d)%d;
		v[i]++;
	}	
}


bool chk(LL ti, vector<LL> &P, vector<LL> &Q, LL n, LL m){
	LL l = 0;
	//cout<<"ti: "<<ti<<", ";
	for(int i = 0; i < n && l < m; i++){
		if(Q[l] >= P[i]){
			LL k = upper_bound(Q.begin() + l, Q.end(), P[i] + ti) - (Q.begin() + l);
			l = l + k;
		}
		else{
			if(abs(Q[l]-P[i]) > ti) return 0;
			LL kk = ti - abs(Q[l]-P[i]);
			LL zz = upper_bound(Q.begin(), Q.end(), P[i]) - Q.begin();
			LL pk = upper_bound(Q.begin() + zz, Q.end(), P[i] + (kk/2)) - (Q.begin() + zz);
			LL k = upper_bound(Q.begin() + l, Q.end(), Q[l] + kk) - (Q.begin() + l);
			LL ky = upper_bound(Q.begin() + l, Q.end(), P[i]) - (Q.begin() + l);
			l += max({k, ky+pk});
		}
	//cout<<l<<" ";
	}
	//cout<<endl;
	return (l >= m);
}

void solve(){
	LL n,m,k,s;
	cin>>n>>m>>k>>s;
	vector<LL> P(n), Q(m);
	takeinput(P, n, k);
	takeinput(Q, m, k);
	sort(all(P));
	sort(all(Q));
	// debug(P);
	// debug(Q);
	LL L = 0, R = 1e18;
	while(L < R){
		LL M = L + (R-L)/2;
		if(chk(M, P, Q, n, m)){
			R = M;
		}
		else{
			L = M + 1;
		}
	}
	cout<<L<<endl;
}


int main(){
  fio();
  int T; cin>>T;
  for1(i,T){
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}