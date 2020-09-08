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
const LL INF = 1e17;
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


/* 
 M, N = 4 * 10^6 

   M	 M     M 	    
 0 1 2 3 4 5 6 [7 8 9] 10 11 
     M     M     M         
 
 0 1 4 7 0 5 9 8  0 3  0 6
 [19] 20 20 19 inf 16 12 11  -1 3 -1 0
 7 + 9 + 3 = 16
 [3]
*/

void solve(){
	LL n, m; cin>>n>>m;
	vector<LL> v(n);
	forn(i,n) cin>>v[i];
	multiset<LL> ms;
	ms.insert(0);
	for(int i = n-2; i>=1; --i){
		if(v[i] && (*ms.begin())!=INF) v[i] += (*ms.begin());
		else v[i] = INF;
		//debug(i, ms);
		ms.insert(v[i]);
		if(i + m == n - 1){
			ms.erase(ms.find(0));
		}
		else if(i + m < n - 1){
			ms.erase(ms.find(v[i+m]));
		}
	}
	//debug(v);
	if((*ms.begin())==INF) cout<<-1<<endl;
	else cout<<(*ms.begin())<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t) {
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}